<?php

/**
 * @file
 * General theme settings elements.
 */

function meiyin_settings_submit($form, &$form_state) {
	$types = node_type_get_names();
	$images = array($form_state['values']['backgroundCustom'], $form_state['values']['iphoneIconRegular'], 
			$form_state['values']['ipadRegularIcon'], $form_state['values']['appleRetinaIcon']);

	foreach ($images as $item) {
		if (!empty($item)) {
			/* Permanently Save Managed Files */
			$fid = $item;
			$file = file_load($fid);
			$file->status = FILE_STATUS_PERMANENT;
			file_save($file);
			file_usage_add($file, 'meiyin', 'meiyin', $item);
		}
	}
}

function meiyin_form_system_theme_settings_alter(&$form, &$form_state) {
	
	$form['meiyin_settings'] = array(
			'#type' => 'vertical_tabs',
			'#weight' => -10,
			'#prefix' => t('<h3>Meiyin Settings</h3>'),
			'#attached' => array(
					'css' => array(drupal_get_path('theme', 'meiyin') . '/css/admin.css'),
					'js' => array(
						drupal_get_path('theme', 'meiyin') . '/js/admin/colorpicker.js',
						drupal_get_path('theme', 'meiyin') . '/js/admin/admin.js',
					),
			),
	);
	
	
	/* GENERAL SETTINGS */
	
	$form['meiyin_settings']['miscellaneous'] = array(
			'#type' => 'fieldset',
			'#title' => t('Miscellaneous'),
			'#weight' => 5,
	);
	
	$form['meiyin_settings']['miscellaneous']['homeSlider']= array(
			'#type' => 'fieldset',
			'#title' => t('Homepage Slider'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['meiyin_settings']['miscellaneous']['homeSlider']['parallax-toggle'] = array(
			'#type'          => 'checkbox',
			'#title'         => t('Enable Parallax Effect'),
			'#description'         => t('Checking this option will enable a parallax effect for homepage slider captions on scroll.'),
			'#default_value' => theme_get_setting('parallax-toggle'),
	);
	
	$form['meiyin_settings']['miscellaneous']['google-maps']= array(
			'#type' => 'fieldset',
			'#title' => t('Google Maps'),
			'#description' => t('Enter the latitude/longitude coordinates of your address. To lookup a set of coordinates, visit
					<a href="http://itouchmap.com/latlong.html" target="_blank">iTouchMap.com</a> and enter the street address.'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['meiyin_settings']['miscellaneous']['google-maps']['latitude'] = array(
			'#type' => 'textfield',
			'#title' => t('Longitude'),
			'#default_value' => theme_get_setting('latitude'),
	);
	
	$form['meiyin_settings']['miscellaneous']['google-maps']['longitude'] = array(
			'#type' => 'textfield',
			'#title' => t('Longitude'),
			'#default_value' => theme_get_setting('longitude'),
	);
	
	
	$form['meiyin_settings']['miscellaneous']['iphone-regular']= array(
			'#type' => 'fieldset',
			'#title' => t('iPhone Icon (Regular screens)'),
			'#description' => t('Upload a 57x57 pixel icon to be used on iPhones and iPads (non-retina screens).'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['meiyin_settings']['miscellaneous']['iphone-regular']['iphoneRegularIcon'] = array(
			'#type' => 'managed_file',
			'#upload_validators' => array(
					'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
			),
			'#upload_location' => 'public://meiyin/',
			'#description' => t("Upload an image."),
			'#default_value' => theme_get_setting('iphoneRegularIcon'),
	);
	
	$form['meiyin_settings']['miscellaneous']['ipad-regular']= array(
			'#type' => 'fieldset',
			'#title' => t('iPad Icon (Regular screens)'),
			'#description' => t('Upload a 72x72 pixel icon to be used on iPads (regular screens).'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['meiyin_settings']['miscellaneous']['ipad-regular']['ipadRegularIcon'] = array(
			'#type' => 'managed_file',
			'#upload_validators' => array(
					'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
			),
			'#upload_location' => 'public://meiyin/',
			'#description' => t("Upload an image."),
			'#default_value' => theme_get_setting('ipadRegularIcon'),
	);
	
	$form['meiyin_settings']['miscellaneous']['apple-retina']= array(
			'#type' => 'fieldset',
			'#title' => t('iPad/iPhone Icon (Retina screens)'),
			'#description' => t('Upload a 114x114 pixel icon to be used on iPads (retina screens).'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
	);
	
	$form['meiyin_settings']['miscellaneous']['apple-retina']['appleRetinaIcon'] = array(
			'#type' => 'managed_file',
			'#upload_validators' => array(
					'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
			),
			'#upload_location' => 'public://meiyin/',
			'#description' => t("Upload an image."),
			'#default_value' => theme_get_setting('appleRetinaIcon'),
	);
	
	/* LAYOUT SETTINGS */
	
	$form['meiyin_settings']['layout'] = array(
			'#type' => 'fieldset',
			'#title' => t('Layout'),
			'#weight' => 2,
	);
	
	$form['meiyin_settings']['layout']['layoutWidth'] = array(
			'#type' => 'radios',
			'#field_prefix' => t('Select the layout width. If a background color and/or image is being used, the "boxed" width is recommended.<br/><br/>'),
			'#title' => t('Layout Width'),
			'#options' => array(
					'fullwidthlayout' => t('Full Width'),
					'boxedlayout' => t('Boxed')
			),
			'#default_value' => theme_get_setting('layoutWidth')
	);
	
	$form['meiyin_settings']['layout']['layoutColor'] = array(
			'#title' => t('Color Scheme'),
			'#field_prefix' => t('Select a color scheme. Stylesheets for each color scheme can be found in the theme CSS folder.<br/><br/>'),
			'#type'          => 'radios',
			'#default_value' => theme_get_setting('layoutColor'),
			'#options'       => array(
					'green' => t('Green'),
					'blue' => t('Blue'),
					'orange' => t('Orange'),
					'red' => t('Red'),
					'navy' => t('Navy'),
			),
	);
	
	$form['meiyin_settings']['layout']['responsive'] = array(
			'#type'          => 'checkbox',
			'#prefix'		 => '<label class="custom-label">Responsive Layout</label>',
			'#title'         => t('Enable Responsive Layout?'),
			'#description'         => t('Checking this option will enable a responsive layout on tablet/mobile devices.'),
			'#default_value' => theme_get_setting('responsive'),
	);
	
	$form['meiyin_settings']['layout']['sticky-header'] = array(
			'#type'          => 'checkbox',
			'#prefix'		 => '<label class="custom-label">Sticky Header</label>',
			'#title'         => t('Enable Sticky Header?'),
			'#description'         => t('Checking this option will enable a sticky header on desktop/widescreen devices.'),
			'#default_value' => theme_get_setting('sticky-header'),
	);

	
	/* BACKGROUND SETTINGS */
	
	$form['meiyin_settings']['background'] = array(
			'#type' => 'fieldset',
			'#title' => t('Background'),
			'#description' => t('Set the background image and background color. If an alternate image is needed, <a href="http://www.subtlepatterns.com/" target="_blank">Subtle Patterns</a> offers 
					hundreds of options. Custom background images can be uploaded by selecting the "Upload Image" button. <br/><br/>'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#weight' => 3
	);
	
	$form['meiyin_settings']['background']['backgroundColor'] = array(
			'#type' => 'textfield',
			'#field_prefix' => '#',
			'#title' => t('Background color:'),
			'#maxlength' => 7,
			'#description' => t('Select a background color.'),
			'#default_value' => theme_get_setting('backgroundColor'),
	);
	
	$form['meiyin_settings']['background']['backgroundImage'] = array(
			'#title' => t('Background Image:'),
			'#type'          => 'radios',
			'#default_value' => theme_get_setting('backgroundImage'),
			'#options'       => array(
					'no-background' => t('No Background Image'),
					'wood' => t('Wood'),
					'greywall' => t('Greywall'),
					'grunge' => t('Grunge'),
					'wavegrid' => t('Wave Grid'),
					'grid' => t('Grid'),
					'custom' => t('Upload Image'),
			),
	);
	
	
	$form['meiyin_settings']['background']['backgroundCustom'] = array(
			'#title' => 'Upload Custom Background',
			'#type' => 'managed_file',
			'#upload_validators' => array(
					'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
			),
			'#upload_location' => 'public://meiyin/',
			'#description' => t("Upload an image."),
			'#default_value' => theme_get_setting('backgroundCustom'),
			'#states' => array(
					'visible' => array(      // Action to take: check the checkbox.
							':input[name="backgroundImage"]' =>  array('value' => 'custom'),
					),
			),
	);
	
	/* GLOBAL SETTINGS */
	meiyin_settings_global_tab($form);
	
	/* REGION SETTINGS */
  
	$form['meiyin_settings']['regions'] = array(
  		'#type' => 'fieldset',
  		'#title' => t('Regions'),
  		'#description' => t('Configure the region settings.'),
		'#weight' => 4,
	);

	$sections = array('header', 'prescript', 'main', 'postscript', 'footer', 'custom');
	
	foreach($sections as $item) {
		$form['meiyin_settings']['regions'][$item] = array(
				'#type' => 'fieldset',
				'#title' => $item,
				'#collapsible' => TRUE,
				'#collapsed' => TRUE,
		);		
	}
	
	foreach (system_region_list('meiyin') as $region => $title) {
		switch($region){
			case 'header_top_left': case 'header_top_right': case 'header': 
				$parent = 'header'; 
			break;
			case 'prescript_first': case 'prescript_second': case 'prescript_third': case 'prescript_fourth': 
				$parent = 'prescript'; 
			break;
			case 'sidebar_first': case 'sidebar_second': case 'content': 
				$parent = 'main'; 
			break;
			case 'postscript_first': case 'postscript_second': case 'postscript_third': case 'postscript_fourth':
				 $parent = 'postscript'; 
			break;
			case 'footer_first': case 'footer_second': case 'footer_third': case 'footer_fourth': case 'footer_fifth': case 'footer_sixth':
				$parent = 'footer';
			break;
			default: $parent = 'custom';
		}
		
		if (($region !== 'dashboard_main') && ($region !== 'dashboard_sidebar') && ($region !== 'dashboard_inactive')) {
			$form['meiyin_settings']['regions'][$parent][$region] = array(
					'#type' => 'fieldset',
					'#title' => $title,
					'#description' => t('Configure the ' . $title . ' region settings.'),
					'#collapsible' => TRUE,
					'#collapsed' => TRUE,
	
			);
			
			$form['meiyin_settings']['regions'][$parent][$region][$region . '_grid'] = array(
				'#type'          => 'select',
		  		'#title'         => t('Width'),
		  		'#default_value' => theme_get_setting($region . '_grid'),
		  		'#options'       => array(
					'0' => t('Default'),
					'1' => t('span1'),
					'2' => t('span2'),
					'3' => t('span3'),
					'4' => t('span4'),
					'5' => t('span5'),
					'6' => t('span6'),
					'7' => t('span7'),
					'8' => t('span8'),
					'9' => t('span9'),
					'10' => t('span10'),
					'11' => t('span11'),
					'12' => t('span12'),
				),
			);
			
			$form['meiyin_settings']['regions'][$parent][$region][$region . '_css'] = array(
					'#type'          => 'textfield',
					'#title'         => t('CSS Classes:'),
					'#description' => t('Attach additional CSS classes to this region.'),
					'#default_value' => theme_get_setting($region . '_css'),
			);
		}
	}
		
}

function meiyin_settings_global_tab(&$form) {
	// Toggles
	$form['theme_settings']['toggle_logo']['#default_value'] = theme_get_setting('toggle_logo');
	$form['theme_settings']['toggle_name']['#default_value'] = theme_get_setting('toggle_name');
	$form['theme_settings']['toggle_slogan']['#default_value'] = theme_get_setting('toggle_slogan');
	$form['theme_settings']['toggle_node_user_picture']['#default_value'] = theme_get_setting('toggle_node_user_picture');
	$form['theme_settings']['toggle_comment_user_picture']['#default_value'] = theme_get_setting('toggle_comment_user_picture');
	$form['theme_settings']['toggle_comment_user_verification']['#default_value'] = theme_get_setting('toggle_comment_user_verification');
	$form['theme_settings']['toggle_favicon']['#default_value'] = theme_get_setting('toggle_favicon');
	$form['theme_settings']['toggle_secondary_menu']['#default_value'] = theme_get_setting('toggle_secondary_menu');


	$form['logo']['default_logo']['#default_value'] = theme_get_setting('default_logo');
	$form['logo']['settings']['logo_path']['#default_value'] = theme_get_setting('logo_path');
	$form['favicon']['default_favicon']['#default_value'] = theme_get_setting('default_favicon');
	$form['favicon']['settings']['favicon_path']['#default_value'] = theme_get_setting('favicon_path');

	$form['meiyin_settings']['global_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Global'),
			'#weight' => 1,
	);
	$form['theme_settings']['#collapsible'] = TRUE;
	$form['theme_settings']['#collapsed'] = TRUE;
	$form['logo']['#collapsible'] = TRUE;
	$form['logo']['#collapsed'] = FALSE;
	$form['favicon']['#collapsible'] = TRUE;
	$form['favicon']['#collapsed'] = FALSE;
	$form['meiyin_settings']['global_settings']['logo'] = $form['logo'];
	$form['meiyin_settings']['global_settings']['favicon'] = $form['favicon'];
	$form['meiyin_settings']['global_settings']['theme_settings'] = $form['theme_settings'];

	unset($form['theme_settings']);
	unset($form['logo']);
	unset($form['favicon']);
}