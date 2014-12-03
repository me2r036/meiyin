<?php

/**
 * @file
 * Providing extra functionality for the RevolutionSlider UI via views.
 */


/**
 * Implements hook_views_data()
 */

function revolution_slider_views_data_alter(&$data) {
	
	// allow for intergration with all entity types
	$types = entity_get_info();
	foreach ($types as $key => $type) {
		// create a structured link in the view to replicate entity
		$data['views_entity_' . $key]['replicate_ui_link'] = array(
				'field' => array(
						'title' => t('replicate link'),
						'help' => t('Provide a simple link to replicate the entity'),
						'handler' => 'views_handler_field_replicate_ui_link',
				),
		);
	}

	$data['revolution_slider']['link_revolution_slider'] = array(
			'field' => array(
					'title' => t('Link'),
					'help' => t('Provide a link to the revolution_slider.'),
					'handler' => 'revolution_slider_handler_link_field',
			),
	);
	$data['revolution_slider']['edit_revolution_slider'] = array(
			'field' => array(
					'title' => t('Edit Link'),
					'help' => t('Provide a link to the edit form for the revolution_slider.'),
					'handler' => 'revolution_slider_handler_edit_link_field',
			),
	);
	$data['revolution_slider']['delete_revolution_slider'] = array(
			'field' => array(
					'title' => t('Delete Link'),
					'help' => t('Provide a link to delete the revolution_slider.'),
					'handler' => 'revolution_slider_handler_delete_link_field',
			),
	);
	// This content of this field are decided based on the menu structure that
	// follows revolution_slider/revolution_slider/%revolution_slider_id/op
	$data['revolution_slider']['operations'] = array(
			'field' => array(
					'title' => t('Operations links'),
					'help' => t('Display all operations available for this revolution_slider.'),
					'handler' => 'revolution_slider_handler_revolution_slider_operations_field',
			),
	);
}


/**
 * Implements hook_views_default_views().
 */
function revolution_slider_views_default_views() {
	$views = array();

	$view = new view;
	$view->name = 'revolution_slider';
	$view->description = 'A list of all revolution_slider';
	$view->tag = 'revolution_slider';
	$view->base_table = 'revolution_slider';
	$view->human_name = 'Revolution Slider';
	$view->core = 7;
	$view->api_version = '3.0-alpha1';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Revolution Slider';
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
	$handler->display->display_options['style_options']['override'] = 1;
	$handler->display->display_options['style_options']['sticky'] = 0;
	$handler->display->display_options['style_options']['empty_table'] = 0;
	/* No results behavior: Global: Text area */
	$handler->display->display_options['empty']['area']['id'] = 'area';
	$handler->display->display_options['empty']['area']['table'] = 'views';
	$handler->display->display_options['empty']['area']['field'] = 'area';
	$handler->display->display_options['empty']['area']['label'] = 'Empty ';
	$handler->display->display_options['empty']['area']['empty'] = FALSE;
	$handler->display->display_options['empty']['area']['content'] = 'No revolution_slider have been created yet';
	/* Field: RevolutionSlider: RevolutionSlider ID */
	$handler->display->display_options['fields']['revolution_slider_id']['id'] = 'revolution_slider_id';
	$handler->display->display_options['fields']['revolution_slider_id']['table'] = 'revolution_slider';
	$handler->display->display_options['fields']['revolution_slider_id']['field'] = 'revolution_slider_id';
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['external'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['alter']['html'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['element_label_colon'] = 1;
	$handler->display->display_options['fields']['revolution_slider_id']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['revolution_slider_id']['hide_empty'] = 0;
	$handler->display->display_options['fields']['revolution_slider_id']['empty_zero'] = 0;
	/* Field: RevolutionSlider: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'revolution_slider';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['name']['alter']['external'] = 0;
	$handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['name']['alter']['html'] = 0;
	$handler->display->display_options['fields']['name']['element_label_colon'] = 1;
	$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['name']['hide_empty'] = 0;
	$handler->display->display_options['fields']['name']['empty_zero'] = 0;
	/* Field: RevolutionSlider: Link */
	$handler->display->display_options['fields']['link_revolution_slider']['id'] = 'link_revolution_slider';
	$handler->display->display_options['fields']['link_revolution_slider']['table'] = 'revolution_slider';
	$handler->display->display_options['fields']['link_revolution_slider']['field'] = 'link_revolution_slider';
	$handler->display->display_options['fields']['link_revolution_slider']['label'] = 'View';
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['external'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['alter']['html'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['element_label_colon'] = 1;
	$handler->display->display_options['fields']['link_revolution_slider']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['link_revolution_slider']['hide_empty'] = 0;
	$handler->display->display_options['fields']['link_revolution_slider']['empty_zero'] = 0;
	/* Field: RevolutionSlider: Operations links */
	$handler->display->display_options['fields']['operations']['id'] = 'operations';
	$handler->display->display_options['fields']['operations']['table'] = 'revolution_slider';
	$handler->display->display_options['fields']['operations']['field'] = 'operations';
	$handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['external'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['operations']['alter']['html'] = 0;
	$handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
	$handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['operations']['hide_empty'] = 0;
	$handler->display->display_options['fields']['operations']['empty_zero'] = 0;

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'revolution_slider_admin_page');
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
			t('RevolutionSliders'),
			t('more'),
			t('Apply'),
			t('Reset'),
			t('Sort by'),
			t('Asc'),
			t('Desc'),
			t('Items per page'),
			t('- All -'),
			t('Offset'),
			t('Empty '),
			t('No revolution_slider have been created yet'),
			t('RevolutionSlider ID'),
			t('.'),
			t(','),
			t('Name'),
			t('View'),
			t('Operations links'),
			t('Page'),
	);
	$views[] = $view;
	return $views;

}