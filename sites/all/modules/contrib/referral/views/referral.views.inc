<?php

/**
 * @file
 * Views integration for referral.module
 *
 * @author Ahmad Hejazee <mngafa@gmail.com>
 */

/**
 * Implements hook_views_data().
 */
function referral_views_data() {
  $data = array();

  $data['referral']['table']['group'] = t('Referrals');
  $data['referral']['table']['base'] = array(
    'field' => 'uid',
    'title' => t('Referrals'),
    'help' => t('Referral records contains all referred users and their referrers and related info.'),
  );

  /**
   * Implicit join for when the 'users' table is the base table.
   * referral table will be automatically joined and its fields will be available.
   */
  $data['referral']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  /**
   * The uid field
   */
  $data['referral']['uid'] = array(
    'title' => t('Invited user uid'),
    'help' => t('The uid of the user who was invited.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'title' => t('Invited user'),
      'help' => t('Relate the referral record to the user who was invited.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'base field' => 'uid',
      'label' => t('Invited user'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  /**
   * The referral_uid field
   */
  $data['referral']['referral_uid'] = array(
    'title' => t('Referrer uid'),
    'help' => t('The user uid of the referer.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'title' => t('Referrer user'),
      'help' => t('Relate the referral record to the referrer user.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'referral_uid',
      'base field' => 'uid',
      'label' => t('Referrer user'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  /**
   * The created field
   */
  $data['referral']['created'] = array(
    'title' => t('Create date'),
    'help' => t('The date the invited user was registered.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  /**
   * Pseudo argument for the created field
   */
  $data['referral']['created_fulldate'] = array(
    'title' => t('Created full date'),
    'help' => t('Date in the form of CCYYMMDD of when the invited user was registered.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  /**
   * Pseudo argument for the created field
   */
  $data['referral']['created_year_month'] = array(
    'title' => t('Created year + month'),
    'help' => t('Date in the form of YYYYMM of when the invited user was registered.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  /**
   * Pseudo argument for the created field
   */
  $data['referral']['created_year'] = array(
    'title' => t('Created year'),
    'help' => t('Date in the form of YYYY of when the invited user was registered.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  /**
   * Pseudo argument for the created field
   */
  $data['referral']['created_month'] = array(
    'title' => t('Created month'),
    'help' => t('Date in the form of MM (01 - 12) of when the invited user was registered.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  /**
   * Pseudo argument for the created field
   */
  $data['referral']['created_day'] = array(
    'title' => t('Created day'),
    'help' => t('Date in the form of DD (01 - 31) of when the invited user was registered.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  /**
   * The flag field
   */
  $data['referral']['flag'] = array(
    'title' => t('Flag'),
    'help' => t('Boolean indicating whether the referral record is flagged.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Flagged'),
      'type' => 'yes-no',
      // use flag = 1 instead of flag <> 0 in WHERE statement.
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  /**
   * The flag_timestamp field
   */
  $data['referral']['flag_timestamp'] = array(
    'title' => t('Flag date'),
    'help' => t('The date when the referral record was flagged.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  /**
   * Pseudo argument for the flag_timestamp field
   */
  $data['referral']['flag_timestamp_fulldate'] = array(
    'title' => t('Flagged full date'),
    'help' => t('Date in the form of CCYYMMDD of when the referral record was flagged.'),
    'argument' => array(
      'field' => 'flag_timestamp',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  /**
   * Pseudo argument for the flag_timestamp field
   */
  $data['referral']['flag_timestamp_year_month'] = array(
    'title' => t('Flagged year + month'),
    'help' => t('Date in the form of YYYYMM of when the referral record was flagged.'),
    'argument' => array(
      'field' => 'flag_timestamp',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  /**
   * Pseudo argument for the flag_timestamp field
   */
  $data['referral']['flag_timestamp_year'] = array(
    'title' => t('Flagged year'),
    'help' => t('Date in the form of YYYY of when the referral record was flagged.'),
    'argument' => array(
      'field' => 'flag_timestamp',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  /**
   * Pseudo argument for the flag_timestamp field
   */
  $data['referral']['flag_timestamp_month'] = array(
    'title' => t('Flagged month'),
    'help' => t('Date in the form of MM (01 - 12) of when the referral record was flagged.'),
    'argument' => array(
      'field' => 'flag_timestamp',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  /**
   * Pseudo argument for the flag_timestamp field
   */
  $data['referral']['flag_timestamp_day'] = array(
    'title' => t('Flagged day'),
    'help' => t('Date in the form of DD (01 - 31) of when the referral record was flagged.'),
    'argument' => array(
      'field' => 'flag_timestamp',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  /**
   * The host field
   */
  $data['referral']['host'] = array(
    'title' => t('Invited user IP'),
    'help' => t('The IP address of the invited user, for when he clicked on the invitation link.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  /**
   * The http_referer field
   */
  $data['referral']['http_referer'] = array(
    'title' => t('Invited user: previous page'),
    'help' => t('The URL of the page from which the invited user came. This is the page where the invitaion link was placed. This is calculated using HTTP_REFERER header.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function referral_views_data_alter(&$data) {
  $data['users']['referral_link'] = array(
    'title' => t('Referral link'),
    'help' => t('The referral link that the user can give to others in order to refer them.'),
    'field' => array(
      'handler' => 'views_handler_field_referral_referral_link',
    ),
  );
}
