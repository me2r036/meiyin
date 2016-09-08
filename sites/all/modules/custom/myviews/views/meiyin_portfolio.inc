<?php
//put export code here
$view = new view();
$view->name = 'meiyin_portfolio';
$view->description = 'A set of filterable portfolio pages, along with related projects / recent / random projects blocks used with the Meiyin theme.';
$view->tag = 'meiyin';
$view->base_table = 'node';
$view->human_name = 'Meiyin: Portfolio';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = '缤纷婚礼';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'isotope_grid';
$handler->display->display_options['style_options']['data_fields'] = array(
  'field_portfolio_tags' => 'field_portfolio_tags',
  'field_image' => 0,
  'field_fancybox' => 0,
  'field_back_cover' => 0,
  'title' => 0,
);
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = 'Introductory Text';
$handler->display->display_options['header']['area']['content'] = '<div class="span12" style="margin-bottom: 14px;">
  <h3>美音婚礼™以你的期望，预算和实际的场地规划设计最适合你的创意婚礼。</h3><p>美音汇™汇集了行业内最高素质的服务团队，从前期的沟通、设计、统筹到后期的创意实现，从主持人、影像、督导，到婚礼的每一个流程步骤，从婚礼现场的布置搭建到完成婚礼的气氛营造，美音婚礼全程贴心服务，精致于微处，为你呈现高品质的婚礼盛典，与你共同喜悦。</p>
</div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
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
$handler->display->display_options['fields']['field_image']['alter']['text'] = '[field_image]
<div class="cover"></div>
<a href="[path]"><div class="link icon-plus notalone"></div></a>
<a title="Big City Company" href="http://themetastic.damojothemes.com/wp-content/uploads/2012/10/folio12.jpg"  class="fancybox"><div class="show icon-search notalone"></div></a>';
$handler->display->display_options['fields']['field_image']['element_type'] = 'div';
$handler->display->display_options['fields']['field_image']['element_class'] = 'mediaholder';
$handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'isotope_portfolio__400x225_',
  'image_link' => '',
);
/* Field: Content: Tags */
$handler->display->display_options['fields']['field_portfolio_tags_1']['id'] = 'field_portfolio_tags_1';
$handler->display->display_options['fields']['field_portfolio_tags_1']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags_1']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags_1']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags_1']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle">[title]</h5>
<span class="itemcategories">[field_portfolio_tags_1]</span>
</div>
</div>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Isotope Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['ui_name'] = 'Content: Isotope Tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['element_type'] = 'div';
$handler->display->display_options['fields']['field_portfolio_tags']['element_class'] = 'isotope-filter';
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_portfolio_tags']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['delta_offset'] = '0';
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
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
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'portfolio' => 'portfolio',
);
/* Filter criterion: Content: Post date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'node';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '2012-12-31 23:59:59';

/* Display: Portfolio - 5 Columns */
$handler = $view->new_display('page', 'Portfolio - 5 Columns', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Portfolio 5 Columns';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio fivecol';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'isotope_grid';
$handler->display->display_options['style_options']['data_fields'] = array(
  'field_portfolio_tags' => 'field_portfolio_tags',
  'path' => 0,
  'field_image' => 0,
  'field_fancybox' => 0,
  'field_back_cover' => 0,
  'title' => 0,
);
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
$handler->display->display_options['header']['area']['label'] = 'Introductory Text';
$handler->display->display_options['header']['area']['content'] = '<div class="span12" style="margin-bottom: 14px;">
  <h3>美音婚礼™以你的期望，预算和实际的场地规划设计最适合你的创意婚礼。</h3><p>美音汇™汇集了行业内最高素质的服务团队，从前期的沟通、设计、统筹到后期的创意实现，从主持人、影像、督导，到婚礼的每一个流程步骤，从婚礼现场的布置搭建到完成婚礼的气氛营造，美音婚礼全程贴心服务，精致于微处，为你呈现高品质的婚礼盛典，与你共同喜悦。</p>
</div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['view']['id'] = 'view';
$handler->display->display_options['header']['view']['table'] = 'views';
$handler->display->display_options['header']['view']['field'] = 'view';
$handler->display->display_options['header']['view']['label'] = 'Portfolio Filter';
$handler->display->display_options['header']['view']['view_to_insert'] = 'meiyin_taxonomy:block_portfolio_filter';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Field: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_type'] = 'div';
$handler->display->display_options['fields']['field_image']['element_class'] = 'holderwrap';
$handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'portfolio_isotope_small_400x192',
  'image_link' => 'content',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_fancybox']['type'] = 'list_key';
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Isotope Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['ui_name'] = 'Content: Isotope Tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_type'] = 'div';
$handler->display->display_options['fields']['field_portfolio_tags']['element_class'] = 'isotope-filter';
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_portfolio_tags']['element_default_classes'] = FALSE;
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
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['path'] = 'portfolio-5col';

/* Display: Portfolio - 4 Columns */
$handler = $view->new_display('page', 'Portfolio - 4 Columns', 'page_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio fourcol';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'isotope_grid';
$handler->display->display_options['style_options']['data_fields'] = array(
  'field_portfolio_tags' => 'field_portfolio_tags',
  'path' => 0,
  'field_image' => 0,
  'field_fancybox' => 0,
  'field_back_cover' => 0,
  'title' => 0,
);
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
$handler->display->display_options['header']['area']['label'] = 'Introductory Text';
$handler->display->display_options['header']['area']['content'] = '<div class="span12" style="margin-bottom: 14px;">
  <h3>美音婚礼™以你的期望，预算和实际的场地规划设计最适合你的创意婚礼。</h3><p>美音汇™汇集了行业内最高素质的服务团队，从前期的沟通、设计、统筹到后期的创意实现，从主持人、影像、督导，到婚礼的每一个流程步骤，从婚礼现场的布置搭建到完成婚礼的气氛营造，美音婚礼全程贴心服务，精致于微处，为你呈现高品质的婚礼盛典，与你共同喜悦。</p>
</div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['view']['id'] = 'view';
$handler->display->display_options['header']['view']['table'] = 'views';
$handler->display->display_options['header']['view']['field'] = 'view';
$handler->display->display_options['header']['view']['label'] = 'Portfolio Filter';
$handler->display->display_options['header']['view']['view_to_insert'] = 'meiyin_taxonomy:block_portfolio_filter';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Field: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_type'] = 'div';
$handler->display->display_options['fields']['field_image']['element_class'] = 'holderwrap';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => '',
  'image_link' => 'content',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_fancybox']['type'] = 'list_key';
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Isotope Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['ui_name'] = 'Content: Isotope Tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_type'] = 'div';
$handler->display->display_options['fields']['field_portfolio_tags']['element_class'] = 'isotope-filter';
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_default_classes'] = FALSE;
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
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
/* Filter criterion: Content: Post date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'node';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '2012-12-31 23:59:59';
$handler->display->display_options['path'] = 'portfolio';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = '案例';
$handler->display->display_options['menu']['description'] = '缤纷婚礼';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 1;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Portfolio - 3 Columns */
$handler = $view->new_display('page', 'Portfolio - 3 Columns', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Portfolio 3 Columns';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio threecol';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'isotope_grid';
$handler->display->display_options['style_options']['data_fields'] = array(
  'field_portfolio_tags' => 'field_portfolio_tags',
  'path' => 0,
  'field_image' => 0,
  'field_fancybox' => 0,
  'field_back_cover' => 0,
  'title' => 0,
);
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
$handler->display->display_options['header']['area']['label'] = 'Introductory Text';
$handler->display->display_options['header']['area']['content'] = '<div class="span12" style="margin-bottom: 14px;">
  <h3>美音婚礼™以你的期望，预算和实际的场地规划设计最适合你的创意婚礼。</h3><p>美音汇™汇集了行业内最高素质的服务团队，从前期的沟通、设计、统筹到后期的创意实现，从主持人、影像、督导，到婚礼的每一个流程步骤，从婚礼现场的布置搭建到完成婚礼的气氛营造，美音婚礼全程贴心服务，精致于微处，为你呈现高品质的婚礼盛典，与你共同喜悦。</p>
</div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['view']['id'] = 'view';
$handler->display->display_options['header']['view']['table'] = 'views';
$handler->display->display_options['header']['view']['field'] = 'view';
$handler->display->display_options['header']['view']['label'] = 'Portfolio Filter';
$handler->display->display_options['header']['view']['view_to_insert'] = 'meiyin_taxonomy:block_portfolio_filter';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
/* Field: Field: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'portfolio_isotope_small_400x192',
  'image_link' => 'content',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_fancybox']['type'] = 'list_key';
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Isotope Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['ui_name'] = 'Content: Isotope Tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_type'] = 'div';
$handler->display->display_options['fields']['field_portfolio_tags']['element_class'] = 'isotope-filter';
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_default_classes'] = FALSE;
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
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['path'] = 'portfolio-3col';

/* Display: Block: Portfolio (5 col) */
$handler = $view->new_display('block', 'Block: Portfolio (5 col)', 'proj5col');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio fivecol';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'isotope-element';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'isotope-container';
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
$handler->display->display_options['fields']['field_image']['element_type'] = 'div';
$handler->display->display_options['fields']['field_image']['element_class'] = 'mediaholder';
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
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
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
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;

/* Display: Block: Portfolio (4 col) */
$handler = $view->new_display('block', 'Block: Portfolio (4 col)', 'proj4col');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio fourcol';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '8';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'isotope-element';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'isotope-container';
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
$handler->display->display_options['fields']['field_image']['element_type'] = 'div';
$handler->display->display_options['fields']['field_image']['element_class'] = 'mediaholder';
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
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
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
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;

/* Display: Block: Portfolio (3 col) */
$handler = $view->new_display('block', 'Block: Portfolio (3 col)', 'proj3col');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio threecol';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_2';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'isotope-element';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'isotope-container';
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
$handler->display->display_options['fields']['field_image']['element_type'] = 'div';
$handler->display->display_options['fields']['field_image']['element_class'] = 'mediaholder';
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
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
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
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;

/* Display: Block: Related Projects */
$handler = $view->new_display('block', 'Block: Related Projects', 'relatedprojects');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '相关婚礼';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio fourcol';
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'isotope-element';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'isotope-container';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
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
$handler->display->display_options['fields']['field_image']['element_type'] = 'div';
$handler->display->display_options['fields']['field_image']['element_class'] = 'mediaholder';
$handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'portfolio_isotope_small_400x192',
  'image_link' => 'content',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_type'] = 'div';
$handler->display->display_options['fields']['field_fancybox']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_fancybox']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_fancybox']['element_default_classes'] = FALSE;
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_default_classes'] = FALSE;
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
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Has taxonomy term ID */
$handler->display->display_options['arguments']['tid']['id'] = 'tid';
$handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
$handler->display->display_options['arguments']['tid']['field'] = 'tid';
$handler->display->display_options['arguments']['tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
$handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
$handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
  'portfolio' => 'portfolio',
);
$handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['not'] = TRUE;

/* Display: Block: Latest Projects */
$handler = $view->new_display('block', 'Block: Latest Projects', 'latestprojects');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '最新案例';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'block-projects';
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '8';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['wrapper_class'] = '';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['label'] = '';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
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
/* Field: Content: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['ui_name'] = 'Content: Image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_image']['alter']['text'] = '<a href="[path]" data-rel="tooltip" data-original-title="[title]">[field_image]</a>';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'portfolio_thumbnail_112x112',
  'image_link' => '',
);
$handler->display->display_options['defaults']['arguments'] = FALSE;

/* Display: Block: Random Projects */
$handler = $view->new_display('block', 'Block: Random Projects', 'randomprojects');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '缤纷婚礼';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'block-projects';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['ui_name'] = 'Content: Image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['alter']['text'] = '<a href="[path]" data-rel="tooltip" data-original-title="[title]">[field_image]</a>';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'portfolio_random_small_130x62',
  'image_link' => 'content',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Global: Random */
$handler->display->display_options['sorts']['random']['id'] = 'random';
$handler->display->display_options['sorts']['random']['table'] = 'views';
$handler->display->display_options['sorts']['random']['field'] = 'random';
$handler->display->display_options['defaults']['arguments'] = FALSE;

/* Display: Portfolio w/Sidebar */
$handler = $view->new_display('page', 'Portfolio w/Sidebar', 'withsidebar');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Portfolio With Sidebar';
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'portfolio threecol';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'isotope_grid';
$handler->display->display_options['style_options']['data_fields'] = array(
  'field_portfolio_tags' => 'field_portfolio_tags',
  'field_image' => 0,
  'field_fancybox' => 0,
  'field_back_cover' => 0,
  'title' => 0,
);
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
$handler->display->display_options['header']['area']['label'] = 'Introductory Text';
$handler->display->display_options['header']['area']['content'] = '<div class="span12" style="margin-bottom: 14px;">
  <h3>美音婚礼™以你的期望，预算和实际的场地规划设计最适合你的创意婚礼。</h3><p>美音汇™汇集了行业内最高素质的服务团队，从前期的沟通、设计、统筹到后期的创意实现，从主持人、影像、督导，到婚礼的每一个流程步骤，从婚礼现场的布置搭建到完成婚礼的气氛营造，美音婚礼全程贴心服务，精致于微处，为你呈现高品质的婚礼盛典，与你共同喜悦。</p>
</div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Header: Global: View area */
$handler->display->display_options['header']['view']['id'] = 'view';
$handler->display->display_options['header']['view']['table'] = 'views';
$handler->display->display_options['header']['view']['field'] = 'view';
$handler->display->display_options['header']['view']['label'] = 'Portfolio Filter';
$handler->display->display_options['header']['view']['view_to_insert'] = 'meiyin_taxonomy:block_portfolio_filter';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Field: Image */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'portfolio_isotope_small_400x192',
  'image_link' => 'content',
);
/* Field: Content: Toggle Fancybox */
$handler->display->display_options['fields']['field_fancybox']['id'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['table'] = 'field_data_field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['field'] = 'field_fancybox';
$handler->display->display_options['fields']['field_fancybox']['label'] = '';
$handler->display->display_options['fields']['field_fancybox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_fancybox']['type'] = 'list_key';
/* Field: Content: Back Cover */
$handler->display->display_options['fields']['field_back_cover']['id'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['table'] = 'field_data_field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['field'] = 'field_back_cover';
$handler->display->display_options['fields']['field_back_cover']['label'] = '';
$handler->display->display_options['fields']['field_back_cover']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_back_cover']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_back_cover']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_back_cover']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Tags */
$handler->display->display_options['fields']['field_portfolio_tags']['id'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['table'] = 'field_data_field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['field'] = 'field_portfolio_tags';
$handler->display->display_options['fields']['field_portfolio_tags']['label'] = '';
$handler->display->display_options['fields']['field_portfolio_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_type'] = 'div';
$handler->display->display_options['fields']['field_portfolio_tags']['element_class'] = 'isotope-filter';
$handler->display->display_options['fields']['field_portfolio_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_portfolio_tags']['delta_offset'] = '0';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle">[title]</h5>
<span class="itemcategories">[field_portfolio_tags]</span>
</div>
</div>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['path'] = 'portfolio-sidebar';
$translatables['meiyin_portfolio'] = array(
  t('Master'),
  t('缤纷婚礼'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Introductory Text'),
  t('<div class="span12" style="margin-bottom: 14px;">
  <h3>美音婚礼™以你的期望，预算和实际的场地规划设计最适合你的创意婚礼。</h3><p>美音汇™汇集了行业内最高素质的服务团队，从前期的沟通、设计、统筹到后期的创意实现，从主持人、影像、督导，到婚礼的每一个流程步骤，从婚礼现场的布置搭建到完成婚礼的气氛营造，美音婚礼全程贴心服务，精致于微处，为你呈现高品质的婚礼盛典，与你共同喜悦。</p>
</div>'),
  t('[field_image]
<div class="cover"></div>
<a href="[path]"><div class="link icon-plus notalone"></div></a>
<a title="Big City Company" href="http://themetastic.damojothemes.com/wp-content/uploads/2012/10/folio12.jpg"  class="fancybox"><div class="show icon-search notalone"></div></a>'),
  t('<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle">[title]</h5>
<span class="itemcategories">[field_portfolio_tags_1]</span>
</div>
</div>'),
  t('Toggle Fancybox'),
  t('Portfolio - 5 Columns'),
  t('Portfolio 5 Columns'),
  t('Portfolio Filter'),
  t('<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle"><a href="[path]">[title]</a></h5>
<span class="itemcategories">[field_portfolio_tags]</span>
</div>
</div>'),
  t('Portfolio - 4 Columns'),
  t('Portfolio - 3 Columns'),
  t('Portfolio 3 Columns'),
  t('Block: Portfolio (5 col)'),
  t('See Full Portfolio (Link)'),
  t('<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/portfolio-5col\'; ?>">See Full Portfolio</a></div>'),
  t('Divider'),
  t('<div class="divider"></div>'),
  t('<div class="mediaholder">[field_image]</div>'),
  t('Block: Portfolio (4 col)'),
  t('See Full Portfolio (link)'),
  t('<div class="linktext"><a href="<?php print $GLOBALS[\'base_url\'].\'/portfolio\'; ?>">更多婚礼</a></div>'),
  t('Block: Portfolio (3 col)'),
  t('Block: Related Projects'),
  t('相关婚礼'),
  t('All'),
  t('Block: Latest Projects'),
  t('最新案例'),
  t('<a href="[path]" data-rel="tooltip" data-original-title="[title]">[field_image]</a>'),
  t('Block: Random Projects'),
  t('Portfolio w/Sidebar'),
  t('Portfolio With Sidebar'),
  t('<div class="foliotextholder">
<div class="foliotextwrapper">
<h5 class="itemtitle">[title]</h5>
<span class="itemcategories">[field_portfolio_tags]</span>
</div>
</div>'),
);

$views[$view->name] = $view;
