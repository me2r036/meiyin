<?php
//put export code here
$view = new view();
$view->name = 'meiyin_feedback';
$view->description = 'Feedback block and feedback on sidebar block used with the Meiyin theme.';
$view->tag = 'meiyin';
$view->base_table = 'field_collection_item';
$view->human_name = 'Meiyin: Feedback';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Field: Field: Description */
$handler->display->display_options['fields']['field_description']['id'] = 'field_description';
$handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
$handler->display->display_options['fields']['field_description']['field'] = 'field_description';
$handler->display->display_options['fields']['field_description']['label'] = '';
$handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_description']['element_default_classes'] = FALSE;
/* Field: Field collection item: Avatar */
$handler->display->display_options['fields']['field_avatar']['id'] = 'field_avatar';
$handler->display->display_options['fields']['field_avatar']['table'] = 'field_data_field_avatar';
$handler->display->display_options['fields']['field_avatar']['field'] = 'field_avatar';
$handler->display->display_options['fields']['field_avatar']['label'] = '';
$handler->display->display_options['fields']['field_avatar']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_avatar']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_avatar']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_avatar']['settings'] = array(
  'image_style' => 'avatar_100x45',
  'image_link' => '',
);
/* Field: Field collection item: Customer */
$handler->display->display_options['fields']['field_customer']['id'] = 'field_customer';
$handler->display->display_options['fields']['field_customer']['table'] = 'field_data_field_customer';
$handler->display->display_options['fields']['field_customer']['field'] = 'field_customer';
$handler->display->display_options['fields']['field_customer']['label'] = '';
$handler->display->display_options['fields']['field_customer']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_customer']['element_default_classes'] = FALSE;
/* Field: Field collection item: Date */
$handler->display->display_options['fields']['field_date']['id'] = 'field_date';
$handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
$handler->display->display_options['fields']['field_date']['field'] = 'field_date';
$handler->display->display_options['fields']['field_date']['label'] = '';
$handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_date']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Sort criterion: Global: Random */
$handler->display->display_options['sorts']['random']['id'] = 'random';
$handler->display->display_options['sorts']['random']['table'] = 'views';
$handler->display->display_options['sorts']['random']['field'] = 'random';

/* Display: Block: Feedback */
$handler = $view->new_display('block', 'Block: Feedback', 'feedback');

/* Display: Block: Feedback Only One */
$handler = $view->new_display('block', 'Block: Feedback Only One', 'feedbackonly1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';

/* Display: Block: Feedback Sidebar */
$handler = $view->new_display('block', 'Block: Feedback Sidebar', 'feedbacksidebar');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '客户评价';
$handler->display->display_options['display_description'] = 'Feedback block on sidebar';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$translatables['meiyin_feedback'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Block: Feedback'),
  t('Block: Feedback Only One'),
  t('Block: Feedback Sidebar'),
  t('客户评价'),
  t('Feedback block on sidebar'),
);

$views[$view->name] = $view;
