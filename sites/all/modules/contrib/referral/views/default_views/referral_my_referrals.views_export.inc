<?php

$view = new view();
$view->name = 'referral_my_referrals';
$view->description = 'Displays a list of invited users by a specific user.';
$view->tag = 'Referrals';
$view->base_table = 'referral';
$view->human_name = 'My referrals';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My referrals';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'use referral';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'rid' => 'rid',
  'flag' => 'flag',
  'created' => 'created',
);
$handler->display->display_options['style_options']['default'] = 'created';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'rid' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'flag' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'You have no referred users yet. Try inviting people using your invitation link.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Relationship: Referrals: Invited user */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'referral';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['relationships']['uid']['required'] = TRUE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'User';
/* Field: User: Roles */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['relationship'] = 'uid';
/* Field: Referrals: Flag */
$handler->display->display_options['fields']['flag']['id'] = 'flag';
$handler->display->display_options['fields']['flag']['table'] = 'referral';
$handler->display->display_options['fields']['flag']['field'] = 'flag';
$handler->display->display_options['fields']['flag']['not'] = 0;
/* Field: Referrals: Create date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'referral';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Registration date';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Contextual filter: Referrals: Referrer uid */
$handler->display->display_options['arguments']['referral_uid_1']['id'] = 'referral_uid_1';
$handler->display->display_options['arguments']['referral_uid_1']['table'] = 'referral';
$handler->display->display_options['arguments']['referral_uid_1']['field'] = 'referral_uid';
$handler->display->display_options['arguments']['referral_uid_1']['default_action'] = 'default';
$handler->display->display_options['arguments']['referral_uid_1']['exception']['value'] = '';
$handler->display->display_options['arguments']['referral_uid_1']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['referral_uid_1']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['referral_uid_1']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['referral_uid_1']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['referral_uid_1']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['referral_uid_1']['validate']['type'] = 'user';
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'uid';
$handler->display->display_options['filters']['status']['value'] = '1';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'my-referrals';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'My referrals';
$handler->display->display_options['menu']['description'] = 'List of my referrals';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Show all';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'User';
/* Field: Referrals: Create date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'referral';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Registration date';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
$handler->display->display_options['block_description'] = 'My referrals';
$translatables['referral_my_referrals'] = array(
  t('Master'),
  t('My referrals'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('You have no referred users yet. Try inviting people using your invitation link.'),
  t('Invited user'),
  t('User'),
  t('Roles'),
  t('Flag'),
  t('Registration date'),
  t('All'),
  t('Page'),
  t('Block'),
  t('Show all'),
);
