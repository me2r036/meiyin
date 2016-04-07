<?php
//put export code here
$view = new view();
$view->name = 'revolution_slider';
$view->description = 'A list of all revolution_slider';
$view->tag = 'revolution_slider';
$view->base_table = 'revolution_slider';
$view->human_name = 'Revolution Slider';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Revolution Slider';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'create any revolution_slider type';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'revolution_slider_id' => 'revolution_slider_id',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'revolution_slider_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'Empty ';
$handler->display->display_options['empty']['area']['content'] = 'No revolution_slider have been created yet';
/* Field: Slide: Slide ID */
$handler->display->display_options['fields']['revolution_slider_id']['id'] = 'revolution_slider_id';
$handler->display->display_options['fields']['revolution_slider_id']['table'] = 'revolution_slider';
$handler->display->display_options['fields']['revolution_slider_id']['field'] = 'revolution_slider_id';
/* Field: Slide: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'revolution_slider';
$handler->display->display_options['fields']['name']['field'] = 'name';
/* Field: Slide: Link */
$handler->display->display_options['fields']['link_revolution_slider']['id'] = 'link_revolution_slider';
$handler->display->display_options['fields']['link_revolution_slider']['table'] = 'revolution_slider';
$handler->display->display_options['fields']['link_revolution_slider']['field'] = 'link_revolution_slider';
$handler->display->display_options['fields']['link_revolution_slider']['label'] = 'View';
/* Field: Slide: Operations links */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'revolution_slider';
$handler->display->display_options['fields']['operations']['field'] = 'operations';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'revolution_slider_admin_page');
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['path'] = 'admin/content/revolution_slider/list';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'List';
$handler->display->display_options['menu']['weight'] = '-10';
$handler->display->display_options['tab_options']['type'] = 'tab';
$handler->display->display_options['tab_options']['title'] = 'Slides';
$handler->display->display_options['tab_options']['description'] = 'Manage Revolution Slider';
$handler->display->display_options['tab_options']['weight'] = '0';
$handler->display->display_options['tab_options']['name'] = 'management';
$translatables['revolution_slider'] = array(
  t('Master'),
  t('Revolution Slider'),
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
  t('Empty '),
  t('No revolution_slider have been created yet'),
  t('Slide ID'),
  t('.'),
  t(','),
  t('Name'),
  t('View'),
  t('Operations links'),
  t('Page'),
);

$views[$view->name] = $view;
