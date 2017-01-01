<?php

/*
* Copyright (c) 2016 Jinfeng Ren (j.ren@meiyin.co) on 26, Dec. 2016
*
* SmsClient - sending messages to mobile phone.
* Using BaiduBCE PHP SDK v0.8.20, requires PHP 5.3.20 or higher version.
*
* Licensed under the Apache License, Version 2.0 (the "License"); you may not
* use this file except in compliance with the License. You may obtain a copy of
* the License at
*
* Http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations under
* the License.
*/

include 'BaiduBce.phar';

use BaiduBce\Auth\BceV1Signer;
use BaiduBce\Auth\SignOptions;
use BaiduBce\Bce;
use BaiduBce\BceClientConfigOptions;
use BaiduBce\BceBaseClient;
use BaiduBce\Exception\BceClientException;
use BaiduBce\Exception\BceServiceException;
use BaiduBce\Http\BceHttpClient;
use BaiduBce\Http\HttpHeaders;
use BaiduBce\Http\HttpContentTypes;
use BaiduBce\Http\HttpMethod;
use BaiduBce\Util\Time;
use BaiduBce\Util\MimeTypes;
use BaiduBce\Util\HashUtils;
use BaiduBce\Util\HttpUtils;
use BaiduBce\Util\StringUtils;
use BaiduBce\Services\Bos\BosOptions;

/**
 * Define SmsClient class
 */
class SmsClient extends BceBaseClient {
  /**
   * @var \BaiduBce\Auth\SignerInterface
   */
  private $signer;
  private $httpClient;

  /**
   * The SmsClient constructor
   *
   * @param array $config The client configuration
   */
  function __construct(array $config) {
     parent::__construct($config, 'SmsClient');
     $this->signer = new BceV1Signer();
     $this->httpClient = new BceHttpClient();
  }

  /**
   * Send message.
   */
  public function sendMessage($invokeId, $phoneNumber, $templateCode, $contentVar, $options = array()) {
    if (empty($invokeId)) {
      throw new BceClientException('The invoke id must be specified.');
    }
    if (empty($phoneNumber)) {
      throw new BceClientException('Please specify mobile phone number of the message receiver.');
    }
    if (empty($templateCode)) {
      throw new BceClientException('The message template code must be specified.');
    }
    list($config) = $this->parseOptions($options, BosOptions::CONFIG);

    return $this->sendRequest(
      HttpMethod::POST,
      array(
        BosOptions::CONFIG => $config,
        'body' => json_encode(array(
          'invokeId' => $invokeId,
          'phoneNumber' => $phoneNumber,
          'templateCode' => $templateCode,
          'contentVar' => $contentVar,
        )),
        'options' => $options,
      ),
      '/bce/v2/message');
  }

  /**
   * Get current quota.
   */
  public function getQuota($options = array()) {
    list($config) = $this->parseOptions($options, BosOptions::CONFIG);
    return $this->sendRequest(
      HttpMethod::GET,
      array(
        BosOptions::CONFIG => $config,
        'options' => $options,
      ),
      '/v1/quota');
  }

  /**
   * Sends request by calling HttpClient
   * @param string $httpMethod: http request method
   * @param array $varArgs: extra arguments
   * @param string $requestPath: path to request for service
   * @return mixed, http response and headers.
   */
  private function sendRequest($httpMethod, array $varArgs, $requestPath = '/') {
    $defaultArgs = array(
      BosOptions::CONFIG => array(),
      'body' => NULL,
      'headers' => array(),
      'params' => array(),
      'outputStream' => NULL,
      'parseUserMetadata' => false
    );

    $args = array_merge($defaultArgs, $varArgs);
    if (empty($args[BosOptions::CONFIG])) {
      $config = $this->config;
    }
    else {
      $config = array_merge(
        array(),
        $this->config,
        $args[BosOptions::CONFIG]);
    }

    if (!isset($args['headers'][HttpHeaders::CONTENT_TYPE])) {
      $args['headers'][HttpHeaders::CONTENT_TYPE] = HttpContentTypes::JSON;
    }
    // prevent low version curl add a default pragma:no-cache
    if (!isset($args['headers'][HttpHeaders::PRAGMA])) {
      $args['headers'][HttpHeaders::PRAGMA] = '';
    }

    if (!isset($args['headers'][HttpHeaders::CONTENT_MD5])) {
      $args['headers'][HttpHeaders::CONTENT_MD5] = base64_encode(md5($args['body'], true));
    }

    // Add x-bce-content-sha256 header
    if ($httpMethod == HttpMethod::POST || $httpMethod == HttpMethod::PUT) {
      $args['headers'][HttpHeaders::BCE_CONTENT_SHA256] = hash('sha256', $args['body']);
    }

    // 1. Have to specify headers need to sign explicitly due to a bug in the BaiduBce sdk 
    //  function BceV1Signer::getHeadersToSign($headers, $headersToSign). It calls the function
    //  BceV1Signer::isDefaultHeaderToSign($header) with 2 arguments ($k, $headersToSign).
    // 2. Headers to sign is defined as headers (with value) array, rather than only header names,
    //  hence have to define keys.
    // 3. Has to be in this format as the function BceV1Signer::getHeadersTosign($headers, $headersToSign)
    //  evaluates array values - "foreach ($headersToSign as $header)"..
    //  whereas later on in the callback it uses "array_keys($headersToSign)".
    $args['options'] = array(
      SignOptions::HEADERS_TO_SIGN => array(
        'content-length' => 'content-length',
        'content-md5' => 'content-md5',
        'content-type' => 'content-type',
        'host' => 'host',
        'x-bce-date' => 'x-bce-date',
      ),
    );

    $response = $this->httpClient->sendRequest(
      $config,
      $httpMethod,
      $requestPath,
      $args['body'],
      $args['headers'],
      $args['params'],
      $this->signer,
      $args['outputStream'],
      $args['options']
    );

    if ($args['outputStream'] === NULL) {
      $result = $this->parseJsonResult($response['body']);
    }
    else {
      $result = new \stdClass();
    }
    $result->metadata =
    $this->convertHttpHeadersToMetadata($response['headers']);
    if ($args['parseUserMetadata']) {
      $userMetadata = array();
      foreach ($response['headers'] as $key => $value) {
        if (StringUtils::startsWith($key, HttpHeaders::BCE_USER_METADATA_PREFIX)) {
          $key = substr($key, strlen(HttpHeaders::BCE_USER_METADATA_PREFIX));
          $userMetadata[urldecode($key)] = urldecode($value);
        }
      }
      $result->metadata[BosOptions::USER_METADATA] = $userMetadata;
    }

    return $result;
  }
}
   