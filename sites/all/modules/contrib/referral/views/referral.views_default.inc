<?php

/**
 * @file
 * Define default views for referral.module
 *
 * @author Ahmad Hejazee <mngafa@gmail.com>
 */

/**
 * Implements hook_views_default_views().
 */
function referral_views_default_views() {
  $path = dirname(__FILE__) . '/default_views/';
  $views = array();

  // Add View
  require_once $path . 'referral_my_referrals.views_export.inc';
  $views[$view->name] = $view;

  return $views;
}
