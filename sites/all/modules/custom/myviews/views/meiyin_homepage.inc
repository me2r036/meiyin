<?php
//put export code here
$view = new view();
$view->name = 'meiyin_homepage';
$view->description = 'A set of blocks displaying services, portfolio items, and blog posts to be used on the homepage of the Meiyin theme.';
$view->tag = 'meiyin';
$view->base_table = 'node';
$view->human_name = 'Meiyin: Homepage';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'ThemeTastic: Homepage';
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '8';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'servicewrap';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = 'See All Services (link)';
$handler->display->display_options['header']['area']['content'] = '<div class="linktext top-25"><a href="<?php print $GLOBALS[\'base_url\'].\'/services\'; ?>">全程服务</a></div>';
$handler->display->display_options['header']['area']['format'] = 'php_code';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

/* Display: Block: Portfolio (5 col) */
$handler = $view->new_display('block', 'Block: Portfolio (5 col)', 'proj5col');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'From Our Portfolio';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'fivecol';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'isotope';
$handler->display->display_options['style_options']['wrapper_class'] = '';
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
$handler->display->display_options['header']['area']['label'] = 'See Full Portfolio (Link)';
$handler->display->display_options['header']['area']['content'] = '<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/portfolio-5col\'; ?>">See Full Portfolio</a></div>';
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
/* Field: Field: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_image']['alter']['text'] = '<div class="mediaholder">[field_image]</div>';
$handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
/* Field: Content: Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle"><a href="[path]">[title]</a></h5>
<span class="itemcategories">[field_portfolio_tags]</span>
</div>
</div>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  'portfolio' => 'portfolio',
);

/* Display: Block: Portfolio (4 col) */
$handler = $view->new_display('block', 'Block: Portfolio (4 col)', 'proj4col');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '缤纷婚礼';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'fourcol';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'isotope';
$handler->display->display_options['style_options']['wrapper_class'] = '';
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
$handler->display->display_options['header']['area']['label'] = 'See Full Portfolio (link)';
$handler->display->display_options['header']['area']['content'] = '<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/portfolio\'; ?>">更多婚礼</a></div>';
$handler->display->display_options['header']['area']['format'] = 'php_code';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Unfiltered text */
$handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
$handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="divider"></div>';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Field: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_image']['alter']['text'] = '<div class="mediaholder">[field_image]</div>';
$handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
/* Field: Content: Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle"><a href="[path]">[title]</a></h5>
<span class="itemcategories">[field_portfolio_tags]</span>
</div>
</div>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  'portfolio' => 'portfolio',
);

/* Display: Block: Portfolio (3 col) */
$handler = $view->new_display('block', 'Block: Portfolio (3 col)', 'proj3col');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'From Our Portfolio';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'threecol';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'isotope';
$handler->display->display_options['style_options']['wrapper_class'] = '';
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
$handler->display->display_options['header']['area']['label'] = 'See Full Portfolio (Link)';
$handler->display->display_options['header']['area']['content'] = '<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/portfolio-5col\'; ?>">See Full Portfolio</a></div>';
$handler->display->display_options['header']['area']['format'] = 'php_code';
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
/* Field: Field: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_image']['alter']['text'] = '<div class="mediaholder">[field_image]</div>';
$handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
/* Field: Content: Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle"><a href="[path]">[title]</a></h5>
<span class="itemcategories">[field_portfolio_tags]</span>
</div>
</div>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_type'] = '0';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  'portfolio' => 'portfolio',
);

/* Display: Block: Services (4 col) */
$handler = $view->new_display('block', 'Block: Services (4 col)', 'serv4col');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'servicemodifier row-fluid';
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
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_class'] = 'servicewrap';
$handler->display->display_options['fields']['body']['element_label_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '600',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
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

/* Display: Block: Services (3 col) */
$handler = $view->new_display('block', 'Block: Services (3 col)', 'serv3col');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'servicemodifier row-fluid';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
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
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_class'] = 'servicewrap';
$handler->display->display_options['fields']['body']['element_label_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
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

/* Display: Block: From The Blog */
$handler = $view->new_display('block', 'Block: From The Blog', 'block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '最新资讯';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'relatedposts relatedwrap';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'homepost';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = 'Visit Blog (Link)';
$handler->display->display_options['header']['area']['content'] = '<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/blog\'; ?>">更多资讯</a></div>';
$handler->display->display_options['header']['area']['format'] = 'php_code';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Post date (Day) */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['ui_name'] = 'Content: Post date (Day)';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'j';
/* Field: Content: Post date (Month) */
$handler->display->display_options['fields']['created_1']['id'] = 'created_1';
$handler->display->display_options['fields']['created_1']['table'] = 'node';
$handler->display->display_options['fields']['created_1']['field'] = 'created';
$handler->display->display_options['fields']['created_1']['ui_name'] = 'Content: Post date (Month)';
$handler->display->display_options['fields']['created_1']['label'] = '';
$handler->display->display_options['fields']['created_1']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['created_1']['alter']['text'] = '<div class="date">
<div class="day">[created]</div>
<div class="month">[created_1]</div>
</div>';
$handler->display->display_options['fields']['created_1']['element_type'] = '0';
$handler->display->display_options['fields']['created_1']['element_label_type'] = '0';
$handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created_1']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created_1']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
$handler->display->display_options['fields']['created_1']['custom_date_format'] = 'M';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Comment count */
$handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['label'] = '';
$handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['comment_count']['alter']['text'] = '<div class="comments">[comment_count]</div>';
$handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['comment_count']['suffix'] = ' comments';
/* Field: Content: Categories */
$handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
$handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
$handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
$handler->display->display_options['fields']['field_categories']['label'] = '';
$handler->display->display_options['fields']['field_categories']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['text'] = '[body-summary]...';
$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_class'] = 'post';
$handler->display->display_options['fields']['body']['element_label_type'] = '0';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '125',
);
/* Field: Content: HTML Output */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'Content: HTML Output';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postbody">
<h4>[title]</h4>
<div class="postinfo"><div class="categories">[field_categories]</div>[comment_count]</div>
<div class="posttext">[body]</div>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  'blog_post' => 'blog_post',
);
$translatables['meiyin_homepage'] = array(
  t('Master'),
  t('ThemeTastic: Homepage'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('See All Services (link)'),
  t('<div class="linktext top-25"><a href="<?php print $GLOBALS[\'base_url\'].\'/services\'; ?>">全程服务</a></div>'),
  t('Block: Portfolio (5 col)'),
  t('From Our Portfolio'),
  t('See Full Portfolio (Link)'),
  t('<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/portfolio-5col\'; ?>">See Full Portfolio</a></div>'),
  t('Divider'),
  t('<div class="divider"></div>'),
  t('<div class="mediaholder">[field_image]</div>'),
  t('<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle"><a href="[path]">[title]</a></h5>
<span class="itemcategories">[field_portfolio_tags]</span>
</div>
</div>'),
  t('Block: Portfolio (4 col)'),
  t('缤纷婚礼'),
  t('See Full Portfolio (link)'),
  t('<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/portfolio\'; ?>">更多婚礼</a></div>'),
  t('Block: Portfolio (3 col)'),
  t('Block: Services (4 col)'),
  t('<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h1>[title]</h1>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]<br>
<span class="hlink">Learn More +</span></p>
</span>
</a>'),
  t('Block: Services (3 col)'),
  t('<a href="[path]" target="_self" class="service">
<div class="serviceicon"><div class="[field_icon]"></div></div>
<h1>[title]</h1>
<h5>[field_subtitle]</h5>
<span class="text">
<p>[body-summary]</p>
</span>
</a>'),
  t('Block: From The Blog'),
  t('最新资讯'),
  t('Visit Blog (Link)'),
  t('<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/blog\'; ?>">更多资讯</a></div>'),
  t('<div class="date">
<div class="day">[created]</div>
<div class="month">[created_1]</div>
</div>'),
  t('<div class="comments">[comment_count]</div>'),
  t('.'),
  t(','),
  t(' comments'),
  t('[body-summary]...'),
  t('<div class="postbody">
<h4>[title]</h4>
<div class="postinfo"><div class="categories">[field_categories]</div>[comment_count]</div>
<div class="posttext">[body]</div>
</div>'),
);

$views[$view->name] = $view;
