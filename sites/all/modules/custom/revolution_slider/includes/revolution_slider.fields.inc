<?php 

/**
 * @file
 * Create compound field using the Field Types API.
 *
 * @see field_types
 * @see field
 */

/***************************************************************
 * Add Slide Builder Javascript/CSS
***************************************************************/
function revolution_slider_preprocess_html(&$vars) {
	if (path_is_admin(current_path())) {
		drupal_add_library('system', 'ui.draggable');
		drupal_add_js(drupal_get_path('module', 'revolution_slider') . '/js/admin.js');
		drupal_add_css($theme_path = drupal_get_path('theme', variable_get('theme_default', NULL)) . '/css/slider.css');
	}
	drupal_add_js(drupal_get_path('module', 'revolution_slider') . '/js/jquery.themepunch.revolution.min.js');
	drupal_add_js(drupal_get_path('theme', 'meiyin') . '/js/admin/admin.js');
	drupal_add_css(drupal_get_path('module', 'revolution_slider') . '/css/settings.css');
}

/**
 * Implements hook_css_alter().
 */
function revolution_slider_css_alter(&$css) {
	if (path_is_admin(current_path())) {
		drupal_add_css(drupal_get_path('module', 'revolution_slider') . '/css/admin.css');
	}
}

/***************************************************************
 * Field Type API hooks
***************************************************************/

/**
 * Implements hook_field_info().
 *
 * Provides the description of the field.
 */

function revolution_slider_field_info() {
	return array(
			'revolution_slider_layer' => array(
					'label' => t('Layer Settings'),
					'description' => t("This field stores PC layer values"),
					'default_widget' => 'revolution_slider_layer',
					'default_formatter' => 'revolution_slider_layer',
			),
			'revolution_slider_slide' => array(
					'label' => t('Slide Settings'),
					'description' => t("This field stores PC layer values"),
					'default_widget' => 'revolution_slider_slide',
					'default_formatter' => 'revolution_slider_slide',
			),

	);
}

/**
 * Implements hook_field_validate().
 *
 * This hook gives us a chance to validate content that's in our
 * field.
 *
 * @see revolution_slider_field_widget_error()
 */
function revolution_slider_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
	foreach ($items as $delta => $item) {
		// ...
	}
}


/**
 * Implements hook_field_is_empty().
 *
 * hook_field_is_emtpy() is where Drupal asks us if this field is empty.
 * Return TRUE if it does not contain data, FALSE if it does. This lets
 * the form API flag an error when required fields are empty.
 */
function revolution_slider_field_is_empty($item, $field) {
	$temp = array_keys($field['columns']);
	$key = array_shift($temp);
	return empty($item[$key]);
}

/**
 * Implements hook_field_formatter_info().
 *
 * We need to tell Drupal that we have two different types of formatters
 * for this field. One will change the text color, and the other will
 * change the background color.
 *
 * @see revolution_slider_field_formatter_view()
 */
function revolution_slider_field_formatter_info() {
	return array(
			'revolution_slider_layer' => array(
					'label' => t('layer fields'),
					'field types' => array('revolution_slider_layer'),
			),
			'revolution_slider_slide' => array(
					'label' => t('slide fields'),
					'field types' => array('revolution_slider_slide'),
			),
	);
}

function revolution_slider_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
	// Make sure that each file which will be saved with this object has a
	// permanent status, so that it will not be removed when temporary files are
	// cleaned up.

	switch ($instance['widget']['type']) {
		case 'revolution_slider_layer':

			foreach ($items as $delta => $item) {
				if ($item['img'] != 0) {
					$file = file_load($item['img']);
					if (!$file->status) {
						$file->status = FILE_STATUS_PERMANENT;
						file_save($file);
						file_usage_add($file, 'revolution_slider', 'revolution_slider', $item['img']);
					}
				}
			}
			break;

	}
}

/**
 * Implements hook_field_formatter_view().
 *
 * Two formatters are implemented.
 * - revolution_slider_simple_text just outputs markup indicating the color that
 *   was entered and uses an inline style to set the text color to that value.
 * - revolution_slider_color_background does the same but also changes the
 *   background color of div.region-content.
 *
 * @see revolution_slider_field_formatter_info()
 */
function revolution_slider_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
	$element = array();

	switch ($display['type']) {
		case 'revolution_slider_layer':

			foreach ($items as $delta => $item) {

				$layer_value = '';
				$tag = '';
				$image = '';
				$speed = ($item['speed'] != '') ? 'data-speed="'.$item['speed'].'"' : '';
				$start = ($item['startafter'] != '') ? 'data-start="'.$item['startafter'].'"' : '';
				$endspeed = ($item['endspeed'] != '') ? 'data-endspeed="'.$item['endspeed'].'"' : '';
				$end = ($item['end'] != '') ? 'data-end="'.$item['end'].'"' : '';
				$endeasing = ($item['endeasing'] != '') ? 'data-endeasing="'.$item['endeasing'].'"' : '';
				$max_delta = count($items) - 1;
				$max_format = ($delta == $max_delta) ? '</li>' : '';
					
				if (!empty($item['img'])) {
					$img_path = '<img src="'.file_create_url(file_load($item['img'])->uri).'" />';
				} else {
					$img_path = '&nbsp;';
				}

				switch ($item['layer']) {
					case "img": $layer_value = $img_path; break;
					case "div": $layer_value = $item['markup']; break;
					case "h1": $layer_value = $item['markup']; break;
					case "h2": $layer_value = $item['markup']; break;
					case "h3": $layer_value = $item['markup']; break;
					case "h4": $layer_value = $item['markup']; break;
					case "h5": $layer_value = $item['markup']; break;
					case "h6": $layer_value = $item['markup']; break;
					default: $layer_value = ""; break;
				}
					
				if ($item['layer'] == 'img') {
					$tag = 'div';
				} else { $tag = $item['layer'];
				}
					
				$element[$delta] = array('#markup' => '<'.$tag.' class="caption '
						.$item['layer'].' '
						.$item['css'].' '
						.$item['animation'].'" data-easing="'
						.$item['easing'].'" data-x="'
						.$item['data_x'].'" data-y="'
						.$item['data_y'].'" '
						.$speed.' '
						.$start.' '
						.$end.' '
						.$endspeed.' '
						.$endeasing.'>'.$layer_value.'</'.$tag.'>'.$max_format);
			}
			break;

		case 'revolution_slider_slide':

			foreach ($items as $delta => $item) {
					
				$slide_value = '';
				$slide_data = array('slotamount', 'target', 'linktoslide', 'delay', 'link', 'fstransition', 'fsmasterspeed', 'fsslotamount');

				foreach($slide_data as $data) {
					if ($item[$data] != NULL) {
						$slide_value .= ' data-'.$data.'="'.$item[$data].'"';
					}
				}
					
				$element[$delta] = array('#markup' => '<li data-transition="' .
						$item['transition'] . '" data-masterspeed="'.$item['masterspeed'].'" '.$slide_value.'>');
			}
			break;
	}
	return $element;
}

/**
 * Implements hook_field_widget_info().
 *
 * These widget types will eventually show up in hook_field_widget_form,
 * where we will have to flesh them out.
 *
 * @see revolution_slider_field_widget_form()
 */
function revolution_slider_field_widget_info() {
	return array(
			'revolution_slider_layer' => array(
					'label' => t('Layer values'),
					'field types' => array('revolution_slider_layer'),
			),
			'revolution_slider_slide' => array(
					'label' => t('Slide values'),
					'field types' => array('revolution_slider_slide'),
			),
	);
}

/**
 * Implements hook_field_widget_form().
 *
 * hook_widget_form() is where Drupal tells us to create form elements for
 * our field's widget.
 */
function revolution_slider_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
	switch ($instance['widget']['type']) {

		case 'revolution_slider_layer':

			$settings = $form_state['field'][$instance['field_name']][$langcode]['field']['settings'];

			$field_name = $instance['field_name'];

			$element['#attributes']['autocomplete'] = 'off';
			$element['layer'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-layer'), 'title' => t('')),
					'#type' => 'select',
					'#title' => t('Layer Type:'),
					'#description' => t('HTML Wrapper'),
					'#options'       => array(
							'0' => t('Select type:'),
							'img' => t('Image'),
							'div' => t('DIV'),
							'h1' => t('H1'),
							'h2' => t('H2'),
							'h3' => t('H3'),
							'h4' => t('H4'),
							'h5' => t('H5'),
							'h6' => t('H6'),
					),
			);

			$element['animation'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-animation'), 'title' => t('')),
					'#type' => 'select',
					'#title' => t('data-animation'),
					'#description' => t('Animation effect'),
					'#options'       => array(
							'sft' => t('Short from Top'),
							'sfb' => t('Short from Bottom'),
							'sfr' => t('Short from Right'),
							'sfl' => t('Short from Left'),
							'lft' => t('Long from Top'),
							'lfb' => t('Long from Bottom'),
							'lfr' => t('Long from Right'),
							'lfl' => t('Long from Left'),
							'fade' => t('Fading'),
							'randomrotate' => t('Random Rotate'),
					),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
							'disabled' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);

			$element['easing'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-easing'), 'title' => t('')),
					'#type' => 'select',
					'#title' => t('data-easing'),
					'#description' => t('Easing effect.'),
					'#options'       => array(
							'easeOutBack' => t('easeOutBack'),
							'easeInQuad' => t('easeInQuad'),
							'easeOutQuad' => t('easeOutQuad'),
							'easeInOutQuad' => t('easeInOutQuad'),
							'easeInCubic' => t('easeInCubic'),
							'easeOutCubic' => t('easeOutCubic'),
							'easeInOutCubic' => t('easeInOutCubic'),
							'easeInQuart' => t('easeInQuart'),
							'easeOutQuart' => t('easeOutQuart'),
							'easeInOutQuart' => t('easeInOutQuart'),
							'easeInQuint' => t('easeInQuint'),
							'easeOutQuint' => t('easeOutQuint'),
							'easeInOutQuint' => t('easeInOutQuint'),
							'easeInSine' => t('easeInSine'),
							'easeOutSine' => t('easeOutSine'),
							'easeInOutSine' => t('easeInOutSine'),
							'easeInExpo' => t('easeInExpo'),
							'easeOutExpo' => t('easeOutExpo'),
							'easeInOutExpo' => t('easeInOutExpo'),
							'easeInCirc' => t('easeInCirc'),
							'easeOutCirc' => t('easeOutCirc'),
							'easeInOutCirc' => t('easeInOutCirc'),
							'easeInElastic' => t('easeInElastic'),
							'easeOutElastic' => t('easeOutElastic'),
							'easeInOutElastic' => t('easeInOutElastic'),
							'easeInBack' => t('easeInBack'),
							'easeOutBack' => t('easeOutBack'),
							'easeInOutBack' => t('easeInOutBack'),
							'easeInBounce' => t('easeInBounce'),
							'easeOutBounce' => t('easeOutBounce'),
							'easeInOutBounce' => t('easeInOutBounce'),
					),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
							'disabled' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);

			$element['x'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-data-x'), 'title' => t('')),
					'#type' => 'textfield',
					'#maxlength' => 6,
					'#title' => t('data-x'),
					'#description' => t('x-axis'),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
							'disabled' => array(
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);
				

			$element['y'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-data-y'), 'title' => t('')),
					'#type' => 'textfield',
					'#maxlength' => 6,
					'#title' => t('data-y'),
					'#description' => t('y-axis'),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
							'disabled' => array(
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);
				
// 			$element['hoffset'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-h-offset'), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#maxlength' => 4,
// 					'#title' => t('h-offset'),
// 					'#description' => t('h-offset'),
// 					'#states' => array(
// 							'invisible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
// 							),
// 							'disabled' => array(
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
// 							),
// 					),
// 			);
				
// 			$element['voffset'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-v-offset'), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#maxlength' => 4,
// 					'#title' => t('v-offset'),
// 					'#description' => t('h-offset'),
// 					'#states' => array(
// 							'invisible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
// 							),
// 							'disabled' => array(
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
// 							),
// 					),
// 			);


// 			$element['h1'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-h1-'.$delta), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#title' => t('Markup:'),
// 					'#description' => t("Enter markup in the textfield above."),
// 					'#states' => array(
// 							'visible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'h1'),
// 							),
// 					),
// 			);

// 			$element['h2'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-h2-'.$delta), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#title' => t('Markup:'),
// 					'#description' => t("Enter markup in the textfield above."),
// 					'#states' => array(
// 							'visible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'h2'),
// 							),
// 					),
// 			);

// 			$element['h3'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-h3-'.$delta), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#title' => t('Markup:'),
// 					'#description' => t("Enter markup in the textfield above."),
// 					'#states' => array(
// 							'visible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'h3'),
// 							),
// 					),
// 			);

// 			$element['h4'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-h4-'.$delta), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#title' => t('Markup:'),
// 					'#description' => t("Enter markup in the textfield above."),
// 					'#states' => array(
// 							'visible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'h4'),
// 							),
// 					),
// 			);

// 			$element['h5'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-h5-'.$delta), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#title' => t('Markup:'),
// 					'#description' => t("Enter markup in the textfield above."),
// 					'#states' => array(
// 							'visible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'h5'),
// 							),
// 					),
// 			);

// 			$element['h6'] = array(
// 					'#attributes' => array('class' => array('edit-revolution_slider-fields-h6-'.$delta), 'title' => t('')),
// 					'#type' => 'textfield',
// 					'#title' => t('Markup:'),
// 					'#description' => t("Enter markup in the textfield above."),
// 					'#states' => array(
// 							'visible' => array(      // Action to take: check the checkbox.
// 									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'h6'),
// 							),
// 					),
// 			);

			$element['speed'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-data-speed'), 'title' => t('')),
					'#type' => 'textfield',
					'#maxlength' => 4,
					'#field_suffix' => 'ms',
					'#title' => t('data-speed:'),
					'#description' => t('Animation speed'),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);

			$element['start'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-data-startafter'), 'title' => t('')),
					'#type' => 'textfield',
					'#maxlength' => 4,
					'#field_suffix' => 'ms',
					'#title' => t('data-start:'),
					'#description' => t('Start animation'),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);

			$element['endspeed'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-data-endspeed'), 'title' => t('')),
					'#type' => 'textfield',
					'#maxlength' => 4,
					'#field_suffix' => 'ms',
					'#title' => t('data-endspeed:'),
					'#description' => t('End animation speed'),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);

			$element['end'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-data-end'), 'title' => t('')),
					'#type' => 'textfield',
					'#maxlength' => 4,
					'#field_suffix' => 'ms',
					'#title' => t('data-end:'),
					'#description' => t('End animation'),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);

			$element['endeasing'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-endeasing'), 'title' => t('')),
					'#type' => 'select',
					'#title' => t('data-endeasing:'),
					'#description' => t('End easing effect'),
					'#options'       => array(
							'easeOutBack' => t('easeOutBack'),
							'easeInQuad' => t('easeInQuad'),
							'easeOutQuad' => t('easeOutQuad'),
							'easeInOutQuad' => t('easeInOutQuad'),
							'easeInCubic' => t('easeInCubic'),
							'easeOutCubic' => t('easeOutCubic'),
							'easeInOutCubic' => t('easeInOutCubic'),
							'easeInQuart' => t('easeInQuart'),
							'easeOutQuart' => t('easeOutQuart'),
							'easeInOutQuart' => t('easeInOutQuart'),
							'easeInQuint' => t('easeInQuint'),
							'easeOutQuint' => t('easeOutQuint'),
							'easeInOutQuint' => t('easeInOutQuint'),
							'easeInSine' => t('easeInSine'),
							'easeOutSine' => t('easeOutSine'),
							'easeInOutSine' => t('easeInOutSine'),
							'easeInExpo' => t('easeInExpo'),
							'easeOutExpo' => t('easeOutExpo'),
							'easeInOutExpo' => t('easeInOutExpo'),
							'easeInCirc' => t('easeInCirc'),
							'easeOutCirc' => t('easeOutCirc'),
							'easeInOutCirc' => t('easeInOutCirc'),
							'easeInElastic' => t('easeInElastic'),
							'easeOutElastic' => t('easeOutElastic'),
							'easeInOutElastic' => t('easeInOutElastic'),
							'easeInBack' => t('easeInBack'),
							'easeOutBack' => t('easeOutBack'),
							'easeInOutBack' => t('easeInOutBack'),
							'easeInBounce' => t('easeInBounce'),
							'easeOutBounce' => t('easeOutBounce'),
							'easeInOutBounce' => t('easeInOutBounce'),
					),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);

			$element['css'] = array(
					'#attributes' => array('class' => array('add-css edit-revolution_slider-fields-css-'.$delta), 'title' => t('')),
					'#type' => 'textfield',
					'#title' => t('CSS Classes'),
					'#description' => t("Add additional CSS classes to this layer."),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);
			
			$element['img'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-image-'.$delta), 'title' => t('')),
					'#type' => 'managed_file',
					'#title' => t('Image upload'),
					'#upload_validators' => array(
							'file_validate_extensions' => array(0 => 'png jpg jpeg gif'),
					),
					'#upload_location' => 'public://default_images/',
					'#description' => t("Upload an image."),
					'#states' => array(
							'visible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'img'),
							),
					),
			);
			
			$element['markup'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-markup-'.$delta), 'title' => t('')),
					'#type' => 'textarea',
					'#title' => t('Markup:'),
					'#description' => t("Paste markup in the textarea above."),
					'#states' => array(
							'invisible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 'img'),
							),
					),
			);
				
			$element['delete'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-css-'.$delta), 'title' => t('')),
					'#type' => 'fieldset',
					'#title' => t("Select a layer type:"),
					'#description' => t("If a layer type is not selected, this layer will be deleted on save."),
					'#states' => array(
							'visible' => array(      // Action to take: check the checkbox.
									':input[name="'.$field_name.'[und]['.$delta.'][layer]"]' => array('value' => 0),
							),
					),
			);


			// Loop through all the element children and set a default value if we have one. Then set HTML wrappers.
			foreach (element_children($element) as $element_key) {
				$value = isset($items[$delta][$element_key]) ? $items[$delta][$element_key] : '';
				$element[$element_key]['#default_value'] = $value;
			}
			break;

		case 'revolution_slider_slide':
			$settings = $form_state['field'][$instance['field_name']][$langcode]['field']['settings'];


			$element['transition'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-transition'), 'title' => t('')),
					'#type' => 'select',
					'#prefix' => t('<div class="slide-settings"><label class="slide-widget">Slide Settings</label>'),
					'#title' => t('data-transition:'),
					'#description' => t('The transition style for this slide.'),
					'#attached' => array(
							'css' => array(drupal_get_path('module', 'revolution_slider') . '/css/admin.css'),
							'js' => array(drupal_get_path('module', 'revolution_slider') . '/js/admin.js'),
					),
					'#options'       => array(
							'boxslide' => t('boxslide'),
							'boxfade' => t('boxfade'),
							'slotzoom-horizontal' => t('slotzoom-horizontal'),
							'slotslide-horizontal' => t('slotslide-horizontal'),
							'slotfade-horizontal' => t('slotfade-horizontal'),
							'slotzoom-vertical' => t('slotzoom-vertical'),
							'slotslide-vertical' => t('slotslide-vertical'),
							'slotfade-vertical' => t('slotfade-vertical'),
							'curtain-1' => t('curtain-1'),
							'curtain-2' => t('curtain-2'),
							'curtain-1' => t('curtain-3'),
							'slideleft' => t('slideleft'),
							'slideright' => t('slideright'),
							'slideup' => t('slideup'),
							'slidedown' => t('slidedown'),
							'fade' => t('fade'),
							'random' => t('random'),
							'slidehorizontal' => t('slidehorizontal'),
							'slidevertical' => t('slidevertical'),
							'papercut' => t('papercut'),
							'flyin' => t('flyin'),
							'turnoff' => t('turnoff'),
							'cube' => t('cube'),
							'3dcurtain-vertical' => t('3dcurtain-vertical'),
							'3dcurtain-horizontal' => t('3dcurtain-horizontal'),
					),
			);

			$element['slotamount'] = array(
					'#type' => 'select',
					'#title' => t('data-slotamount:'),
					'#field_suffix' => t('&nbsp; slots'),
					'#description' => t('The amount of slots on transitions.'),
					'#options'       => array(
							'0' => t('0'),
							'1' => t('1'),
							'2' => t('2'),
							'3' => t('3'),
							'4' => t('4'),
							'5' => t('5'),
							'6' => t('6'),
							'7' => t('7'),
					),
			);

			$element['masterspeed'] = array(
					'#type' => 'textfield',
					'#maxlength' => 4,
					'#title' => t('data-masterspeed:'),
					'#description' => t('The slide transition speed.'),
					'#field_suffix' => t('&nbsp; milliseconds'),
			);

			$element['link'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-link'), 'title' => t('')),
					'#type' => 'textfield',
					'#title' => t('data-link:'),
					'#description' => t('Link the slide to another page.'),
			);

			$element['target'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-target'), 'title' => t('')),
					'#type' => 'textfield',
					'#title' => t('data-target:'),
					'#description' => t('Link target attribute.'),
			);

			$element['linktoslide']= array(
					'#type' => 'textfield',
					'#field_prefix' => t('<div style="float: left; margin-right: -20px; margin-left: 20px;">Slide Number: &nbsp;</div>'),
					'#title' => t('data-linktoslide:'),
					'#description' => t('Link to another slide.'),
			);

			$element['delay'] = array(
					'#type' => 'textfield',
					'#maxlength' => 4,
					'#title' => t('data-delay:'),
					'#description' => t('Slide delay time'),
					'#field_suffix' => t('&nbsp; milliseconds'),
			);

			$element['fstransition'] = array(
					'#attributes' => array('class' => array('edit-revolution_slider-fields-fstransition'), 'title' => t('')),
					'#type' => 'select',
					'#title' => t('data-fstransition:'),
					'#description' => t('Transition effect on first slide.'),
					'#options'       => array(
							'0' => t('None'),
							'boxslide' => t('boxslide'),
							'boxfade' => t('boxfade'),
							'slotzoom-horizontal' => t('slotzoom-horizontal'),
							'slotslide-horizontal' => t('slotslide-horizontal'),
							'slotfade-horizontal' => t('slotfade-horizontal'),
							'slotzoom-vertical' => t('slotzoom-vertical'),
							'slotslide-vertical' => t('slotslide-vertical'),
							'slotfade-vertical' => t('slotfade-vertical'),
							'curtain-1' => t('curtain-1'),
							'curtain-2' => t('curtain-2'),
							'curtain-1' => t('curtain-3'),
							'slideleft' => t('slideleft'),
							'slideright' => t('slideright'),
							'slideup' => t('slideup'),
							'slidedown' => t('slidedown'),
							'fade' => t('fade'),
							'random' => t('random'),
							'slidehorizontal' => t('slidehorizontal'),
							'slidevertical' => t('slidevertical'),
							'papercut' => t('papercut'),
							'flyin' => t('flyin'),
							'turnoff' => t('turnoff'),
							'cube' => t('cube'),
							'3dcurtain-vertical' => t('3dcurtain-vertical'),
							'3dcurtain-horizontal' => t('3dcurtain-horizontal'),
					),
			);

			$element['fsmasterspeed'] = array(
					'#type' => 'textfield',
					'#attributes' => array('class' => array('edit-revolution_slider-fields-fsmasterspeed'), 'title' => t('')),
					'#description' => t('Transition speed on first slide.'),
					'#maxlength' => 4,
					'#title' => t('data-fsmasterspeed:'),
					'#field_suffix' => t('&nbsp; milliseconds'),
			);

			$element['fsslotamount'] = array(
					'#type' => 'select',
					'#attributes' => array('class' => array('edit-revolution_slider-fields-fsslotamount'), 'title' => t('')),
					'#title' => t('data-fsslotamount:'),
					'#description' => t('The slot amount on first slide.'),
					'#field_suffix' => t('&nbsp; slots'),
					'#suffix' => t('</div>'),
					'#options'       => array(
							'0' => t('0'),
							'1' => t('1'),
							'2' => t('2'),
							'3' => t('3'),
							'4' => t('4'),
							'5' => t('5'),
							'6' => t('6'),
							'7' => t('7'),
					),
			);

			foreach (element_children($element) as $element_key) {
				$value = isset($items[$delta][$element_key]) ? $items[$delta][$element_key] : '';
				$element[$element_key]['#default_value'] = $value;
			}
			break;
	}



	return $element;
}

function revolution_slider_form_alter(&$form, &$form_state, $form_id) {
	$form['#attributes']['autocomplete'] = 'off';	
}