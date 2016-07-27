<?php
//put export code here
$view = new view();
$view->name = 'meiyin_services';
$view->description = 'Services landing page and sidebar blocks used with the Meiyin theme.';
$view->tag = 'meiyin';
$view->base_table = 'node';
$view->human_name = 'Meiyin: Service';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Services';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'span4';
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Unfiltered text */
$handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['header']['area_text_custom']['table'] = 'views';
$handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Sort criterion: Field: Weight (field_weight) */
$handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
$handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
$handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'service' => 'service',
);

/* Display: Page: Services */
$handler = $view->new_display('page', 'Page: Services', 'services');
$handler->display->display_options['enabled'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Content: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Subtitle */
$handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['label'] = '';
$handler->display->display_options['fields']['field_subtitle']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['text'] = '<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h2>[title]</h2>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]</p>
</span>
</a>';
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_class'] = 'servicewrap span4';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '600',
);
$handler->display->display_options['path'] = 'services';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = '服务';
$handler->display->display_options['menu']['description'] = '全程服务';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Block: Services Menu */
$handler = $view->new_display('block', 'Block: Services Menu', 'servicesmenu');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'block-sidebar-menu';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'services';
$handler->display->display_options['style_options']['wrapper_class'] = '';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Content: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Subtitle */
$handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['label'] = '';
$handler->display->display_options['fields']['field_subtitle']['alter']['text'] = '<a href="[path]" target="_self" class="service-menu">
<div class="serviceicon-menu"><div class="[field_icon]"></div></div>
<h2>[title]</h2>
<h5>[field_subtitle]</h5>
</a>';
$handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_subtitle']['element_default_classes'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'service' => 'service',
);

/* Display: Block: Services (4 Col) */
$handler = $view->new_display('block', 'Block: Services (4 Col)', 'serv4col');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'servicemodifier row-fluid clearfix';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'services';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'span3';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Unfiltered text */
$handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['header']['area_text_custom']['table'] = 'views';
$handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['header']['area_text_custom']['label'] = 'Divider';
$handler->display->display_options['header']['area_text_custom']['content'] = '<div class="divider"></div>';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = 'See All Services (link)';
$handler->display->display_options['header']['area']['content'] = '<div class="linktext top-25"><a href="<?php print $GLOBALS[\'base_url\'].\'/services\'; ?>">全程服务</a></div>';
$handler->display->display_options['header']['area']['format'] = 'php_code';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Unfiltered text */
$handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
$handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['label'] = 'Divider';
$handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="divider"></div>';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Content: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Subtitle */
$handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['label'] = '';
$handler->display->display_options['fields']['field_subtitle']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['text'] = '<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h1>[title]</h1>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]<br>
<span class="hlink">Learn More +</span></p>
</span>
</a>';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '600',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Global: Random */
$handler->display->display_options['sorts']['random']['id'] = 'random';
$handler->display->display_options['sorts']['random']['table'] = 'views';
$handler->display->display_options['sorts']['random']['field'] = 'random';

/* Display: Block: Services (3 Col) */
$handler = $view->new_display('block', 'Block: Services (3 Col)', 'serv3col');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'servicemodifier row-fluid clearfix';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'services';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'span4';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = 'See All Services (link)';
$handler->display->display_options['header']['area']['content'] = '<div class="linktext top-25"><a href="<?php print $GLOBALS[\'base_url\'].\'/services\'; ?>">全程服务</a></div>';
$handler->display->display_options['header']['area']['format'] = 'php_code';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Unfiltered text */
$handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
$handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['label'] = 'Divider';
$handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="divider"></div>';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Content: Icon */
$handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
$handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
$handler->display->display_options['fields']['field_icon']['label'] = '';
$handler->display->display_options['fields']['field_icon']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Subtitle */
$handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
$handler->display->display_options['fields']['field_subtitle']['label'] = '';
$handler->display->display_options['fields']['field_subtitle']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['text'] = '<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h1>[title]</h1>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]</p>
</span>
</a>';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '600',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Global: Random */
$handler->display->display_options['sorts']['random']['id'] = 'random';
$handler->display->display_options['sorts']['random']['table'] = 'views';
$handler->display->display_options['sorts']['random']['field'] = 'random';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$translatables['meiyin_services'] = array(
  t('Master'),
  t('Services'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Page: Services'),
  t('<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h2>[title]</h2>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]</p>
</span>
</a>'),
  t('Block: Services Menu'),
  t('<a href="[path]" target="_self" class="service-menu">
<div class="serviceicon-menu"><div class="[field_icon]"></div></div>
<h2>[title]</h2>
<h5>[field_subtitle]</h5>
</a>'),
  t('Block: Services (4 Col)'),
  t('Divider'),
  t('<div class="divider"></div>'),
  t('See All Services (link)'),
  t('<div class="linktext top-25"><a href="<?php print $GLOBALS[\'base_url\'].\'/services\'; ?>">全程服务</a></div>'),
  t('<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h1>[title]</h1>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]<br>
<span class="hlink">Learn More +</span></p>
</span>
</a>'),
  t('Block: Services (3 Col)'),
  t('<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h1>[title]</h1>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]</p>
</span>
</a>'),
  t('Block'),
);

$views[$view->name] = $view;
