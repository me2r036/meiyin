<?php

/**
 * @file
 * Definition of views_handler_field_referral_referral_link.
 */

/**
 * Field handler to present the referral link of a user
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_referral_referral_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  function access() {
    return user_access('use referral');
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $uid = $this->get_value($values, 'uid');
    $uid_sanitized = $this->sanitize_value($uid);
    $uri = url('referral/' . _referral_uid2ref($uid_sanitized), array('absolute' => TRUE));

    return $uri;
  }
}
