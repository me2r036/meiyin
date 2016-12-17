<?php

/**
 * @file Rules integration
 */

/**
 * Implements hook_rules_action_info().
 */
function referral_rules_action_info() {
  $actions = array();

  $actions['flag_referral'] = array(
    'label' => t('Flag referral'),
    'group' => t('user referral'),
    'base' => 'rules_action_flag_referral',
    'parameter' => array(
      'user' => array(
        'type'  => 'user',
        'label' => t('The user whose referral record you want to flag'),
      ),
    ),
  );

  $actions['unflag_referral'] = array(
    'label' => t('Unflag referral'),
    'group' => t('user referral'),
    'base' => 'rules_action_unflag_referral',
    'parameter' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('The user whose referral record you want to unflag'),
      ),
    ),
  );

  $actions['change_referral'] = array(
    'label' => t('Change referral for user'),
    'group' => t('user referral'),
    'base' => 'rules_action_change_referral',
    'parameter' => array(
      'target_user' => array(
        'type' => 'user',
        'label' => t('Target user'),
        'description' => t('The user you want to change the referral record for'),
      ),
      'referring_user' => array(
        'type' => 'user',
        'label' => t('New referring user'),
        'description' => t('The user you want to say referred the target user'),
      ),
    ),
  );

  $actions['new_referral'] = array(
    'label' => t('Set new referral for user'),
    'group' => t('user referral'),
    'base' => 'rules_action_new_referral',
    'parameter' => array(
      'target_user' => array(
        'type' => 'user',
        'label' => t('Target user'),
        'description' => t('The user you want to set the new referral record for'),
      ),
      'referring_user' => array(
        'type' => 'user',
        'label' => t('New referring user'),
        'description' => t('The user you want to say referred the target user'),
      ),
      'host' => array(
        'type' => 'text',
        'label' => t('Host'),
        'description' => t('The host you to say the new user came from'),
        'optional' => TRUE,
      ),
      'uri' => array(
        'type' => 'text',
        'label' => t('URI'),
        'description' => t('The URI you want to say the new user came from'),
        'optional' => TRUE,
      ),
    ),
  );

  $actions['fetch_referring_user'] = array(
    'label' => t('Fetch referring user'),
    'group' => t('user referral'),
    'base' => 'rules_action_fetch_referring_user',
    'parameter' => array(
      'user' => array(
        'type'  => 'user',
        'label' => t('The user whose referring user you want to fetch.'),
      ),
    ),
    'provides' => array(
      'referring_user' => array(
        'type' => 'user',
        'label' => t('The referring user'),
      ),
    ),
  );

  return $actions;
}

/**
 * Implements hook_rules_condition_info().
 */
function referral_rules_condition_info() {
  $conditions = array();

  $conditions['referral_is_flagged'] = array(
    'label' => t('Referral is flagged'),
    'group' => t('user referral'),
    'base' => 'rules_condition_referral_is_flagged',
    'parameter' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('The user you want to see if their referral record has been flagged'),
      ),
    ),
  );

  $conditions['user_referred'] = array(
    'label' => t('User was referred by another user.'),
    'group' => t('user referral'),
    'base' => 'rules_condition_user_referred',
    'parameter' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('The user you want to check if they were referred by another user'),
      ),
    ),
  );

  return $conditions;
}

/**
 * Implements hook_rules_event_info().
 */
function referral_rules_event_info() {
  $defaults = array(
    'group' => t('user referral'),
    'module' => 'referral',
    'access callback' => 'user_referral_rules_access',
  );
  return array(
    'referral_recorded' => $defaults + array(
      'label' => t('After a new referral is recorded'),
      'variables' => array(
        'referring_user' => array(
          'type' => 'user',
          'label' => t('The user who owned the referral link'),
        ),
        'new_user' => array(
          'type' => 'user',
          'label' => t('The new user who visted the site through the referral link'),
        ),
      ),
    ),
  );
}

/**
 * Rules condition callback
 */
function rules_condition_referral_is_flagged($user) {
  $result = db_query_range('SELECT flag FROM {referral} WHERE uid = :uid', 0, 1, array('uid' => $user->uid))->fetchField();
  return $result;
}

/**
 * Rules condition callback
 */
function rules_condition_user_referred($user) {
  $result = db_query_range('SELECT referral_uid FROM {referral} WHERE uid = :uid', 0, 1, array('uid' => $user->uid))->fetchField();
  return $result;
}

/**
 * Rules action callback
 */
function rules_action_flag_referral($user) {
  db_update('referral')
    ->fields(array(
      'flag' => 1,
      'flag_timestamp' => time(),
    ))
    ->condition('uid', $user->uid)
    ->execute();
}

/**
 * Rules action callback
 */
function rules_action_unflag_referral($user) {
  db_update('referral')
    ->fields(array(
      'flag' => 0,
      'flag_timestamp' => 0,
    ))
    ->condition('uid', $user->uid)
    ->execute();
}

/**
 * Rules action callback
 */
function rules_action_change_referral($target_user, $ref_user) {
  db_update('referral')
    ->fields(array(
      'referral_uid' => $ref_user->uid,
      'created' => time(),
    ))
    ->condition('uid', $target_user->uid)
    ->execute();
}

/**
 * Rules action callback
 */
function rules_action_new_referral($target_user, $ref_user, $host = 'system', $uri = 'system') {
  $result = db_query_range('SELECT referral_uid FROM {referral} WHERE uid = :uid', 0, 1, array('uid' => $user->uid))->fetchField();

  if (!$result) {
    $query = db_insert('referral')
      ->fields(array(
        'uid' => $target_user->uid,
        'referral_uid' => $ref_user->uid,
        'created' => time(),
        'host' => $host,
        'http_referer' => $uri,
      ))
      ->execute();
    if (!$query) {
      watchdog('rules', 'INSERT of referral data failed.', array(), WATCHDOG_ERROR);
      return FALSE;
    }
  }
  else {
    return FALSE;
  }
}

/**
 * Rules action callback
 */
function rules_action_fetch_referring_user($user) {
  $query = db_select('referral', 'r')
    ->fields('r', array('referral_uid'))
    ->condition('uid', $user->uid)
    ->execute()
    ->fetchAll();

  $referral_uid = isset($query[0]->referral_uid) ? $query[0]->referral_uid : NULL;
  $referrer = $referral_uid ? user_load($referral_uid) : NULL;

  return array(
    'referring_user' => $referrer,
  );
}

/**
 *
 */
function user_referral_rules_access() {
  return user_access('administer referral');
}
