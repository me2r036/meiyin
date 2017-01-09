<?php
//put export code here
$view = new view();
$view->name = 'meiyin_webform_submissions';
$view->description = '';
$view->tag = 'webform';
$view->base_table = 'webform_submissions';
$view->human_name = 'Meiyin: Webform Submissions';
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
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 200, 500, 1000';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'view_submission' => 'view_submission',
  'submitted' => 'submitted',
  'name' => 'name',
  'remote_addr' => 'remote_addr',
  'view_submission_1' => 'view_submission_1',
  'edit_submission' => 'view_submission_1',
  'delete_submission' => 'view_submission_1',
);
$handler->display->display_options['style_options']['default'] = 'view_submission';
$handler->display->display_options['style_options']['info'] = array(
  'view_submission' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'submitted' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'remote_addr' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'view_submission_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => ' &nbsp; ',
    'empty_column' => 0,
  ),
  'edit_submission' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'delete_submission' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['sticky'] = TRUE;
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* Header: Global: Result summary with an additional token to change the items/page */
$handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
$handler->display->display_options['header']['webform_result']['table'] = 'views';
$handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
$handler->display->display_options['header']['webform_result']['content'] = '<div class="webform-results-per-page">Showing @start - @end of @total. &nbsp; @items_per_page_links</div>';
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no submissions for this form. <a href="/node/!1">View this form</a>.';
$handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
/* Relationship: Webform submissions: User */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Webform submissions: View link */
$handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
$handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
$handler->display->display_options['fields']['view_submission']['label'] = '#';
$handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_submission']['text'] = '[serial]';
$handler->display->display_options['fields']['view_submission']['access_check'] = 1;
/* Field: Webform submissions: Submitted */
$handler->display->display_options['fields']['submitted']['id'] = 'submitted';
$handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['submitted']['field'] = 'submitted';
$handler->display->display_options['fields']['submitted']['date_format'] = 'short';
$handler->display->display_options['fields']['submitted']['second_date_format'] = 'long';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'User';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Webform submissions: Remote address */
$handler->display->display_options['fields']['remote_addr']['id'] = 'remote_addr';
$handler->display->display_options['fields']['remote_addr']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['remote_addr']['field'] = 'remote_addr';
$handler->display->display_options['fields']['remote_addr']['label'] = 'IP address';
/* Field: Webform submissions: View link */
$handler->display->display_options['fields']['view_submission_1']['id'] = 'view_submission_1';
$handler->display->display_options['fields']['view_submission_1']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['view_submission_1']['field'] = 'view_submission';
$handler->display->display_options['fields']['view_submission_1']['label'] = 'Operations';
$handler->display->display_options['fields']['view_submission_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_submission_1']['access_check'] = 0;
/* Field: Webform submissions: Edit link */
$handler->display->display_options['fields']['edit_submission']['id'] = 'edit_submission';
$handler->display->display_options['fields']['edit_submission']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['edit_submission']['field'] = 'edit_submission';
$handler->display->display_options['fields']['edit_submission']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['edit_submission']['access_check'] = 1;
/* Field: Webform submissions: Delete link */
$handler->display->display_options['fields']['delete_submission']['id'] = 'delete_submission';
$handler->display->display_options['fields']['delete_submission']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['delete_submission']['field'] = 'delete_submission';
$handler->display->display_options['fields']['delete_submission']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['delete_submission']['access_check'] = 1;
/* Contextual filter: Webform submissions: Node */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'webform_submissions';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = '115';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
/* Contextual filter: Webform submissions: User */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'webform_submissions';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

/* Display: Page: My Customers */
$handler = $view->new_display('page', 'Page: My Customers', 'page_my_customers');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '我推荐的客户';
$handler->display->display_options['display_description'] = 'Displays user referred customers';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access own webform submissions';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '3';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 200, 500, 1000';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'sid' => 'sid',
  'submitted' => 'submitted',
  'name' => 'name',
  'value' => 'value',
  'value_1' => 'value_1',
  'value_2' => 'value_2',
  'value_3' => 'value_3',
  'value_6' => 'value_6',
  'value_4' => 'value_4',
  'value_5' => 'value_5',
);
$handler->display->display_options['style_options']['default'] = 'sid';
$handler->display->display_options['style_options']['info'] = array(
  'sid' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'submitted' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_2' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_3' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_6' => array(
    'sortable' => 0,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_4' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_5' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Result summary with an additional token to change the items/page */
$handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
$handler->display->display_options['header']['webform_result']['table'] = 'views';
$handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
$handler->display->display_options['header']['webform_result']['content'] = '<div class="webform-results-per-page">Showing @start - @end of @total. &nbsp; @items_per_page_links</div>';
$handler->display->display_options['header']['webform_result']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = '没有符合所选条件的提交. <a href="/node/!1">查看表单</a>.';
$handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Webform submissions: User */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Relationship: Webform submissions: Data */
$handler->display->display_options['relationships']['data']['id'] = 'data';
$handler->display->display_options['relationships']['data']['table'] = 'webform_submissions';
$handler->display->display_options['relationships']['data']['field'] = 'data';
$handler->display->display_options['relationships']['data']['label'] = 'Wedding Status';
$handler->display->display_options['relationships']['data']['webform_nid'] = '115';
$handler->display->display_options['relationships']['data']['webform_cid'] = '6';
/* Relationship: Webform submissions: Data */
$handler->display->display_options['relationships']['data_1']['id'] = 'data_1';
$handler->display->display_options['relationships']['data_1']['table'] = 'webform_submissions';
$handler->display->display_options['relationships']['data_1']['field'] = 'data';
$handler->display->display_options['relationships']['data_1']['label'] = 'Commission Status';
$handler->display->display_options['relationships']['data_1']['webform_nid'] = '115';
$handler->display->display_options['relationships']['data_1']['webform_cid'] = '7';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Webform submissions: Sid */
$handler->display->display_options['fields']['sid']['id'] = 'sid';
$handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['sid']['field'] = 'sid';
$handler->display->display_options['fields']['sid']['label'] = 'Submission ID';
$handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
/* Field: Webform submissions: Submitted */
$handler->display->display_options['fields']['submitted']['id'] = 'submitted';
$handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['submitted']['field'] = 'submitted';
$handler->display->display_options['fields']['submitted']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['submitted']['date_format'] = 'short';
$handler->display->display_options['fields']['submitted']['second_date_format'] = 'long';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Submitted by';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value']['field'] = 'value';
$handler->display->display_options['fields']['value']['label'] = '';
$handler->display->display_options['fields']['value']['webform_nid'] = '115';
$handler->display->display_options['fields']['value']['webform_cid'] = '1';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_1']['id'] = 'value_1';
$handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_1']['field'] = 'value';
$handler->display->display_options['fields']['value_1']['label'] = '';
$handler->display->display_options['fields']['value_1']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_1']['webform_cid'] = '2';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_2']['id'] = 'value_2';
$handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_2']['field'] = 'value';
$handler->display->display_options['fields']['value_2']['label'] = '';
$handler->display->display_options['fields']['value_2']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_2']['webform_cid'] = '3';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_3']['id'] = 'value_3';
$handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_3']['field'] = 'value';
$handler->display->display_options['fields']['value_3']['label'] = '';
$handler->display->display_options['fields']['value_3']['exclude'] = TRUE;
$handler->display->display_options['fields']['value_3']['custom_label'] = 'none';
$handler->display->display_options['fields']['value_3']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_3']['webform_cid'] = '4';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_6']['id'] = 'value_6';
$handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_6']['field'] = 'value';
$handler->display->display_options['fields']['value_6']['label'] = '婚礼日期';
$handler->display->display_options['fields']['value_6']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['value_6']['alter']['text'] = '<a href="/node/[value_6]">[value_3]</a>';
$handler->display->display_options['fields']['value_6']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['value_6']['empty'] = '[value_3]';
$handler->display->display_options['fields']['value_6']['custom_label'] = 'custom';
$handler->display->display_options['fields']['value_6']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_6']['webform_cid'] = '8';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_4']['id'] = 'value_4';
$handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_4']['field'] = 'value';
$handler->display->display_options['fields']['value_4']['label'] = '';
$handler->display->display_options['fields']['value_4']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_4']['webform_cid'] = '6';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_5']['id'] = 'value_5';
$handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_5']['field'] = 'value';
$handler->display->display_options['fields']['value_5']['label'] = '男方姓名';
$handler->display->display_options['fields']['value_5']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_5']['webform_cid'] = '7';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Webform submissions: Node */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'webform_submissions';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['breadcrumb_enable'] = TRUE;
$handler->display->display_options['arguments']['nid']['breadcrumb'] = '%1';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = '115';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
/* Contextual filter: Webform submissions: User */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'webform_submissions';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid']['breadcrumb_enable'] = TRUE;
$handler->display->display_options['arguments']['uid']['breadcrumb'] = '%2';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
$handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = TRUE;
$handler->display->display_options['arguments']['uid']['validate_options']['roles'] = array(
  6 => '6',
  7 => '7',
  3 => '3',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Webform submissions: Draft */
$handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
$handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
$handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
$handler->display->display_options['filters']['is_draft']['value'] = array(
  0 => '0',
);
$handler->display->display_options['filters']['is_draft']['group'] = 1;
/* Filter criterion: Webform submission data: Data field */
$handler->display->display_options['filters']['data']['id'] = 'data';
$handler->display->display_options['filters']['data']['table'] = 'webform_submitted_data';
$handler->display->display_options['filters']['data']['field'] = 'data';
$handler->display->display_options['filters']['data']['relationship'] = 'data';
$handler->display->display_options['filters']['data']['group'] = 1;
$handler->display->display_options['filters']['data']['exposed'] = TRUE;
$handler->display->display_options['filters']['data']['expose']['operator_id'] = 'data_op';
$handler->display->display_options['filters']['data']['expose']['label'] = 'Data field';
$handler->display->display_options['filters']['data']['expose']['operator'] = 'data_op';
$handler->display->display_options['filters']['data']['expose']['identifier'] = 'data';
$handler->display->display_options['filters']['data']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['data']['group_info']['label'] = '订单状态';
$handler->display->display_options['filters']['data']['group_info']['identifier'] = 'data';
$handler->display->display_options['filters']['data']['group_info']['remember'] = 1;
$handler->display->display_options['filters']['data']['group_info']['group_items'] = array(
  1 => array(
    'title' => '客户 - 未咨询',
    'operator' => '=',
    'value' => '未咨询',
  ),
  2 => array(
    'title' => '客户 - 已咨询',
    'operator' => '=',
    'value' => '已咨询',
  ),
  3 => array(
    'title' => '客户 - 已订单',
    'operator' => '=',
    'value' => '已订单',
  ),
  4 => array(
    'title' => '客户 - 已确认',
    'operator' => '=',
    'value' => '已确认',
  ),
  5 => array(
    'title' => '客户 - 未成功',
    'operator' => '=',
    'value' => '未成功',
  ),
  6 => array(
    'title' => '客户 - 已完成',
    'operator' => '=',
    'value' => '已完成',
  ),
);
/* Filter criterion: Webform submission data: Data field */
$handler->display->display_options['filters']['data_1']['id'] = 'data_1';
$handler->display->display_options['filters']['data_1']['table'] = 'webform_submitted_data';
$handler->display->display_options['filters']['data_1']['field'] = 'data';
$handler->display->display_options['filters']['data_1']['relationship'] = 'data_1';
$handler->display->display_options['filters']['data_1']['group'] = 1;
$handler->display->display_options['filters']['data_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['data_1']['expose']['operator_id'] = 'data_1_op';
$handler->display->display_options['filters']['data_1']['expose']['label'] = 'Data field';
$handler->display->display_options['filters']['data_1']['expose']['operator'] = 'data_1_op';
$handler->display->display_options['filters']['data_1']['expose']['identifier'] = 'data_1';
$handler->display->display_options['filters']['data_1']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['data_1']['group_info']['label'] = '佣金状态';
$handler->display->display_options['filters']['data_1']['group_info']['identifier'] = 'data_1';
$handler->display->display_options['filters']['data_1']['group_info']['group_items'] = array(
  1 => array(
    'title' => '佣金 - 未支付',
    'operator' => '=',
    'value' => '未支付',
  ),
  2 => array(
    'title' => '佣金 - 已支付',
    'operator' => '=',
    'value' => '已支付',
  ),
  3 => array(
    'title' => '',
    'operator' => '=',
    'value' => '',
  ),
);
$handler->display->display_options['path'] = 'my-customers';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = '我推荐的客户';
$handler->display->display_options['menu']['description'] = '查看我推荐的客户';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'user-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Page: Referral Customers */
$handler = $view->new_display('page', 'Page: Referral Customers', 'page_referral_customers');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '隶属专员的客户';
$handler->display->display_options['display_description'] = 'Displays referral refferred customers';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  7 => '7',
);
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '3';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 200, 500, 1000';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'view_submission' => 'view_submission',
  'submitted' => 'submitted',
  'value' => 'value',
  'value_1' => 'value_1',
  'value_2' => 'value_2',
  'value_3' => 'value_3',
  'value_4' => 'value_4',
  'value_5' => 'value_5',
);
$handler->display->display_options['style_options']['default'] = 'view_submission';
$handler->display->display_options['style_options']['info'] = array(
  'view_submission' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'submitted' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_2' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_3' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_4' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_5' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Result summary with an additional token to change the items/page */
$handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
$handler->display->display_options['header']['webform_result']['table'] = 'views';
$handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
$handler->display->display_options['header']['webform_result']['content'] = '<div class="webform-results-per-page">Showing @start - @end of @total. &nbsp; @items_per_page_links</div>';
$handler->display->display_options['header']['webform_result']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = '没有符合所选条件的提交. <a href="/node/!1">查看表单</a>.';
$handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Webform submissions: User */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Relationship: Webform submissions: Data */
$handler->display->display_options['relationships']['data']['id'] = 'data';
$handler->display->display_options['relationships']['data']['table'] = 'webform_submissions';
$handler->display->display_options['relationships']['data']['field'] = 'data';
$handler->display->display_options['relationships']['data']['label'] = 'Wedding Status';
$handler->display->display_options['relationships']['data']['webform_nid'] = '115';
$handler->display->display_options['relationships']['data']['webform_cid'] = '6';
/* Relationship: Webform submissions: Data */
$handler->display->display_options['relationships']['data_1']['id'] = 'data_1';
$handler->display->display_options['relationships']['data_1']['table'] = 'webform_submissions';
$handler->display->display_options['relationships']['data_1']['field'] = 'data';
$handler->display->display_options['relationships']['data_1']['label'] = 'Commission Status';
$handler->display->display_options['relationships']['data_1']['webform_nid'] = '115';
$handler->display->display_options['relationships']['data_1']['webform_cid'] = '7';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Webform submissions: Sid */
$handler->display->display_options['fields']['sid']['id'] = 'sid';
$handler->display->display_options['fields']['sid']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['sid']['field'] = 'sid';
$handler->display->display_options['fields']['sid']['label'] = 'Submission ID';
$handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
/* Field: Webform submissions: Submitted */
$handler->display->display_options['fields']['submitted']['id'] = 'submitted';
$handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['submitted']['field'] = 'submitted';
$handler->display->display_options['fields']['submitted']['date_format'] = 'short';
$handler->display->display_options['fields']['submitted']['second_date_format'] = 'long';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Submitted by';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value']['field'] = 'value';
$handler->display->display_options['fields']['value']['label'] = '男方姓名';
$handler->display->display_options['fields']['value']['webform_nid'] = '115';
$handler->display->display_options['fields']['value']['webform_cid'] = '1';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_1']['id'] = 'value_1';
$handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_1']['field'] = 'value';
$handler->display->display_options['fields']['value_1']['label'] = '';
$handler->display->display_options['fields']['value_1']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_1']['webform_cid'] = '2';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_2']['id'] = 'value_2';
$handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_2']['field'] = 'value';
$handler->display->display_options['fields']['value_2']['label'] = '手机号码';
$handler->display->display_options['fields']['value_2']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_2']['webform_cid'] = '3';
$handler->display->display_options['fields']['value_2']['webform_datatype'] = 'number';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_3']['id'] = 'value_3';
$handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_3']['field'] = 'value';
$handler->display->display_options['fields']['value_3']['label'] = '';
$handler->display->display_options['fields']['value_3']['exclude'] = TRUE;
$handler->display->display_options['fields']['value_3']['custom_label'] = 'none';
$handler->display->display_options['fields']['value_3']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_3']['webform_cid'] = '4';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_6']['id'] = 'value_6';
$handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_6']['field'] = 'value';
$handler->display->display_options['fields']['value_6']['label'] = '婚礼日期';
$handler->display->display_options['fields']['value_6']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['value_6']['alter']['text'] = '<a href="/node/[value_6]">[value_3]</a>';
$handler->display->display_options['fields']['value_6']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['value_6']['empty'] = '[value_3]';
$handler->display->display_options['fields']['value_6']['custom_label'] = 'custom';
$handler->display->display_options['fields']['value_6']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_6']['webform_cid'] = '8';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_4']['id'] = 'value_4';
$handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_4']['field'] = 'value';
$handler->display->display_options['fields']['value_4']['label'] = '';
$handler->display->display_options['fields']['value_4']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_4']['webform_cid'] = '6';
/* Field: Webform submission data: Value */
$handler->display->display_options['fields']['value_5']['id'] = 'value_5';
$handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
$handler->display->display_options['fields']['value_5']['field'] = 'value';
$handler->display->display_options['fields']['value_5']['label'] = '';
$handler->display->display_options['fields']['value_5']['webform_nid'] = '115';
$handler->display->display_options['fields']['value_5']['webform_cid'] = '7';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Webform submissions: Node */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'webform_submissions';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['breadcrumb_enable'] = TRUE;
$handler->display->display_options['arguments']['nid']['breadcrumb'] = '%1';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = '115';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
$handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
/* Contextual filter: Referrals: Referrer uid */
$handler->display->display_options['arguments']['referral_uid']['id'] = 'referral_uid';
$handler->display->display_options['arguments']['referral_uid']['table'] = 'referral';
$handler->display->display_options['arguments']['referral_uid']['field'] = 'referral_uid';
$handler->display->display_options['arguments']['referral_uid']['relationship'] = 'uid';
$handler->display->display_options['arguments']['referral_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['referral_uid']['breadcrumb_enable'] = TRUE;
$handler->display->display_options['arguments']['referral_uid']['breadcrumb'] = '%2';
$handler->display->display_options['arguments']['referral_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['referral_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['referral_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['referral_uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['referral_uid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['referral_uid']['validate']['type'] = 'user';
$handler->display->display_options['arguments']['referral_uid']['validate_options']['restrict_roles'] = TRUE;
$handler->display->display_options['arguments']['referral_uid']['validate_options']['roles'] = array(
  7 => '7',
  3 => '3',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Webform submissions: Draft */
$handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
$handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
$handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
$handler->display->display_options['filters']['is_draft']['value'] = array(
  0 => '0',
);
$handler->display->display_options['filters']['is_draft']['group'] = 1;
/* Filter criterion: Webform submission data: Data field */
$handler->display->display_options['filters']['data']['id'] = 'data';
$handler->display->display_options['filters']['data']['table'] = 'webform_submitted_data';
$handler->display->display_options['filters']['data']['field'] = 'data';
$handler->display->display_options['filters']['data']['relationship'] = 'data';
$handler->display->display_options['filters']['data']['group'] = 1;
$handler->display->display_options['filters']['data']['exposed'] = TRUE;
$handler->display->display_options['filters']['data']['expose']['operator_id'] = 'data_op';
$handler->display->display_options['filters']['data']['expose']['label'] = 'Data field';
$handler->display->display_options['filters']['data']['expose']['operator'] = 'data_op';
$handler->display->display_options['filters']['data']['expose']['identifier'] = 'data';
$handler->display->display_options['filters']['data']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['data']['group_info']['label'] = '订单状态';
$handler->display->display_options['filters']['data']['group_info']['identifier'] = 'data';
$handler->display->display_options['filters']['data']['group_info']['remember'] = 1;
$handler->display->display_options['filters']['data']['group_info']['group_items'] = array(
  1 => array(
    'title' => '客户 - 未咨询',
    'operator' => '=',
    'value' => '未咨询',
  ),
  2 => array(
    'title' => '客户 - 已咨询',
    'operator' => '=',
    'value' => '已咨询',
  ),
  3 => array(
    'title' => '客户 - 已订单',
    'operator' => '=',
    'value' => '已订单',
  ),
  4 => array(
    'title' => '客户 - 已确认',
    'operator' => '=',
    'value' => '已确认',
  ),
  5 => array(
    'title' => '客户 - 未成功',
    'operator' => '=',
    'value' => '未成功',
  ),
  6 => array(
    'title' => '客户 - 已完成',
    'operator' => '=',
    'value' => '已完成',
  ),
);
/* Filter criterion: Webform submission data: Data field */
$handler->display->display_options['filters']['data_1']['id'] = 'data_1';
$handler->display->display_options['filters']['data_1']['table'] = 'webform_submitted_data';
$handler->display->display_options['filters']['data_1']['field'] = 'data';
$handler->display->display_options['filters']['data_1']['relationship'] = 'data_1';
$handler->display->display_options['filters']['data_1']['group'] = 1;
$handler->display->display_options['filters']['data_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['data_1']['expose']['operator_id'] = 'data_1_op';
$handler->display->display_options['filters']['data_1']['expose']['label'] = 'Data field';
$handler->display->display_options['filters']['data_1']['expose']['operator'] = 'data_1_op';
$handler->display->display_options['filters']['data_1']['expose']['identifier'] = 'data_1';
$handler->display->display_options['filters']['data_1']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['data_1']['group_info']['label'] = '佣金状态';
$handler->display->display_options['filters']['data_1']['group_info']['identifier'] = 'data_1';
$handler->display->display_options['filters']['data_1']['group_info']['group_items'] = array(
  1 => array(
    'title' => '佣金 - 未支付',
    'operator' => '=',
    'value' => '未支付',
  ),
  2 => array(
    'title' => '佣金 - 已支付',
    'operator' => '=',
    'value' => '已支付',
  ),
  3 => array(
    'title' => '',
    'operator' => '=',
    'value' => '',
  ),
);
$handler->display->display_options['path'] = 'referral-customers';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = '隶属专员客户';
$handler->display->display_options['menu']['description'] = '我推荐的专员推荐的客户';
$handler->display->display_options['menu']['weight'] = '-44';
$handler->display->display_options['menu']['name'] = 'user-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['webform_submissions'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('All'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('<div class="webform-results-per-page">Showing @start - @end of @total. &nbsp; @items_per_page_links</div>'),
  t('There are no submissions for this form. <a href="/node/!1">View this form</a>.'),
  t('Webform Submission User'),
  t('#'),
  t('[serial]'),
  t('Submitted'),
  t('User'),
  t('IP address'),
  t('Operations'),
  t('view'),
  t('edit'),
  t('delete'),
  t('Page: My Customers'),
  t('我推荐的客户'),
  t('Displays user referred customers'),
  t('没有符合所选条件的提交. <a href="/node/!1">查看表单</a>.'),
  t('Wedding Status'),
  t('Commission Status'),
  t('Submission ID'),
  t('.'),
  t(','),
  t('Submitted by'),
  t('婚礼日期'),
  t('<a href="/node/[value_6]">[value_3]</a>'),
  t('[value_3]'),
  t('男方姓名'),
  t('%1'),
  t('%2'),
  t('Data field'),
  t('订单状态'),
  t('佣金状态'),
  t('Page: Referral Customers'),
  t('隶属专员的客户'),
  t('Displays referral refferred customers'),
  t('手机号码'),
);

$views[$view->name] = $view;
