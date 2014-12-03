<?php

/**
 * @file
 * RevolutionSlider type editing UI.
 */

/**
 * UI controller.
 */
class RevolutionSliderTypeUIController extends EntityDefaultUIController {

	/**
	 * Overrides hook_menu() defaults.
	 */
	public function hook_menu() {
		$items = parent::hook_menu();
		$items[$this->path]['title'] = 'Revolution Slider';
		$items[$this->path]['description'] = 'Manage Revolution Slider entity types, including adding
		and removing fields and the display of fields.';
		
		unset($items[$this->path . '/import']);
		
		return $items;
	}
	
	/**
	     * Overrides EntityDefaultUIController::overviewTableHeaders().
	     */
//    protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
// 		$parent = parent::overviewTableHeaders($conditions, $rows, $additional_header);
// 		dpm($parent);
// 		return parent::overviewTableHeaders($conditions, $rows, $additional_header);
// 	}
		
// 	protected function overviewTableRow($conditions, $id, $entity, $additional_cols = array()) {
//        $parent = parent::overviewTableRow($conditions, $id, $entity, $additional_cols);
//        foreach($parent as $key => $value) {
//        	unset($key[1]);
// //        	dpm($value);
//        }
//        return parent::overviewTableRow($conditions, $id, $entity, $additional_cols);
// 	}
}

/**
 * Generates the revolution_slider type editing form.
 */
function revolution_slider_type_form($form, &$form_state, $revolution_slider_type, $op = 'edit') {

	$human_readable = strtolower($revolution_slider_type->label);
	$machine_readable = preg_replace('@[^a-z0-9_]+@','_',$human_readable);
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'revolution_slider');
	$result = $query->execute();

	if (isset($result['revolution_slider'])) {
		$news_items_nids = array_keys($result['revolution_slider']);
		$news_items = entity_load('revolution_slider', $news_items_nids);
	}

	if ($op == 'clone') {
		$hideops = '.views-field-operations, ul.action-links, p.no-slides { display: none; }';
		$revolution_slider_type->label .= ' (cloned)';
		$revolution_slider_type->type = '';
		drupal_add_css($hideops, 'inline', array('preprocess' => TRUE));
	}
	
	if($revolution_slider_type->label == NULL) {
		$add = '';
	} else {
		$add = '<ul class="action-links"><li><a href="'.$GLOBALS['base_url'].'/admin/content/revolution_slider/add/'.$revolution_slider_type->type.'">Add new slide</a></li></ul>';
	}
	
	if(views_embed_view('revolution_slider', $display_id = 'revolution_slider_admin_block') == '') {
		($revolution_slider_type->label == NULL) ? $slides = '' : $slides = '<p class="no-slides">No Slides have been created.</p>';
	} else {
		$slides = views_embed_view('revolution_slider', $display_id = 'revolution_slider_admin_block');
	}
	
	$form['label'] = array(
			'#title' => t('Slider Name'),
			'#suffix' => $add.$slides,
			'#type' => 'textfield',
			'#default_value' => $revolution_slider_type->label,
			'#description' => t('The human-readable name of this Revolution Slider.'),
			'#required' => TRUE,
			'#size' => 30,
	);

	// Machine-readable type name.
	$form['type'] = array(
			'#type' => 'machine_name',
			'#default_value' => isset($revolution_slider_type->type) ? $revolution_slider_type->type : '',
			'#maxlength' => 32,
			//    '#disabled' => $revolution_slider_type->isLocked() && $op != 'clone',
			'#machine_name' => array(
					'exists' => 'revolution_slider_get_types',
					'source' => array('label'),
			),
			'#description' => t('A unique machine-readable name for this revolution_slider type. It must only contain lowercase letters, numbers, and underscores.'),
	);

	$form['data']['#tree'] = TRUE;
	$form['data']['sample_data'] = array(
			'#type' => 'textfield',
			'#attributes' => array('class' => array('element-invisible')),
			'#default_value' => $machine_readable
	);

	// Revolution Slider: Global Settings
	$form['data']['global'] = array(
			'#type' => 'fieldset',
			'#title' => t('Global Settings')
	);
	
	$form['data']['global']['delay'] = array(
			'#type' => 'textfield',
			'#title' => t('Delay'),
			'#maxlength' => 5,
			'#default_value' => isset($revolution_slider_type->data['delay']) ? $revolution_slider_type->data['delay'] : '9000'
	);
	
	$form['data']['global']['startwidth'] = array(
			'#type' => 'textfield',
			'#title' => t('Start Width'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['global']['startwidth']) ? $revolution_slider_type->data['global']['startwidth'] : '960'
	);
	
	$form['data']['global']['startheight'] = array(
			'#type' => 'textfield',
			'#title' => t('Start Height'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['global']['startheight']) ? $revolution_slider_type->data['global']['startheight'] : '500'
	);
	
	// Revolution Slider: Global Settings
	$form['data']['navigation'] = array(
			'#type' => 'fieldset',
			'#title' => t('Navigation Settings')
	);
	
	$form['data']['navigation']['onHoverStop'] = array(
			'#type' => 'radios',
			'#title' => t('onHoverStop'),
			'#options' => array(
					'"on"' => t('On'),
					'"off"' => t('Off')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['onHoverStop']) ? $revolution_slider_type->data['navigation']['onHoverStop'] : '"on"'
	);
	
	$form['data']['navigation']['thumbWidth'] = array(
			'#type' => 'textfield',
			'#title' => t('thumbWidth'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['thumbWidth']) ? $revolution_slider_type->data['navigation']['thumbWidth'] : '100'
	);
	
	$form['data']['navigation']['thumbHeight'] = array(
			'#type' => 'textfield',
			'#title' => t('thumbHeight'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['thumbHeight']) ? $revolution_slider_type->data['navigation']['thumbHeight'] : '50'
	);
	
	$form['data']['navigation']['thumbAmount'] = array(
			'#type' => 'textfield',
			'#title' => t('thumbAmount'),
			'#maxlength' => 2,
			'#default_value' => isset($revolution_slider_type->data['navigation']['thumbAmount']) ? $revolution_slider_type->data['navigation']['thumbAmount'] : '3'
	);
	
	$form['data']['navigation']['hideThumbs'] = array(
			'#type' => 'textfield',
			'#title' => t('hideThumbs'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['hideThumbs']) ? $revolution_slider_type->data['navigation']['hideThumbs'] : '0'
	);
	
	$form['data']['navigation']['navigationType'] = array(
			'#type' => 'select',
			'#title' => t('navigationType'),
			'#options' => array(
					'"bullet"' => t('Bullet'),
					'"thumb"' => t('Thumb'),
					'"none"' => t('None')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['navigationType']) ? $revolution_slider_type->data['navigation']['navigationType'] : '"bullet"'
	);
	
	$form['data']['navigation']['navigationArrows'] = array(
			'#type' => 'radios',
			'#title' => t('navigationArrows'),
			'#options' => array(
					'"solo"' => t('Solo'),
					'"nexttobullets"' => t('Next To Bullets')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['navigationArrows']) ? $revolution_slider_type->data['navigation']['navigationArrows'] : '"solo"'
	);
	
	$form['data']['navigation']['navigationStyle'] = array(
			'#type' => 'radios',
			'#title' => t('navigationStyle'),
			'#options' => array(
					'"round"' => t('Round'),
					'"square"' => t('Square')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['navigationStyle']) ? $revolution_slider_type->data['navigation']['navigationStyle'] : '"round"'
	);
	
	$form['data']['navigation']['navigationHAlign'] = array(
			'#type' => 'radios',
			'#title' => t('navigationHAlign'),
			'#options' => array(
					'"left"' => t('Left'),
					'"center"' => t('Center'),
					'"right"' => t('Right')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['navigationHAlign']) ? $revolution_slider_type->data['navigation']['navigationHAlign'] : '"center"'
	);
	
	$form['data']['navigation']['navigationVAlign'] = array(
			'#type' => 'radios',
			'#title' => t('navigationVAlign'),
			'#options' => array(
					'"top"' => t('Top'),
					'"center"' => t('Center'),
					'"bottom"' => t('Bottom')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['navigationVAlign']) ? $revolution_slider_type->data['navigation']['navigationVAlign'] : '"center"'
	);
	
	$form['data']['navigation']['navigationHOffset'] = array(
			'#type' => 'textfield',
			'#title' => t('navigationHOffset'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['navigationHOffset']) ? $revolution_slider_type->data['navigation']['navigationHOffset'] : '0'
	);
	
	$form['data']['navigation']['navigationVOffset'] = array(
			'#type' => 'textfield',
			'#title' => t('navigationVOffset'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['navigationVOffset']) ? $revolution_slider_type->data['navigation']['navigationVOffset'] : '0'
	);
	
	$form['data']['navigation']['soloArrowLeftHalign'] = array(
			'#type' => 'radios',
			'#title' => t('soloArrowLeftHalign'),
			'#options' => array(
					'"left"' => t('Left'),
					'"center"' => t('Center'),
					'"right"' => t('Right')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowLeftHalign']) ? $revolution_slider_type->data['navigation']['soloArrowLeftHalign'] : '"center"'
	);
	
	$form['data']['navigation']['soloArrowLeftValign'] = array(
			'#type' => 'radios',
			'#title' => t('soloArrowLeftValign'),
			'#options' => array(
					'"top"' => t('Top'),
					'"center"' => t('Center'),
					'"bottom"' => t('Bottom')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowLeftValign']) ? $revolution_slider_type->data['navigation']['soloArrowLeftValign'] : '"center"'
	);
	
	$form['data']['navigation']['soloArrowLeftHOffset'] = array(
			'#type' => 'textfield',
			'#title' => t('soloArrowLeftHOffset'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowLeftHOffset']) ? $revolution_slider_type->data['navigation']['soloArrowLeftHOffset'] : '0'
	);
	
	$form['data']['navigation']['soloArrowLeftVOffset'] = array(
			'#type' => 'textfield',
			'#title' => t('soloArrowLeftVOffset'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowLeftVOffset']) ? $revolution_slider_type->data['navigation']['soloArrowLeftVOffset'] : '0'
	);
	
	$form['data']['navigation']['soloArrowRightHalign'] = array(
			'#type' => 'radios',
			'#title' => t('soloArrowRightHalign'),
			'#options' => array(
					'"left"' => t('Right'),
					'"center"' => t('Center'),
					'"right"' => t('Right')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowRightHalign']) ? $revolution_slider_type->data['navigation']['soloArrowRightHalign'] : '"center"'
	);
	
	$form['data']['navigation']['soloArrowRightValign'] = array(
			'#type' => 'radios',
			'#title' => t('soloArrowRightValign'),
			'#options' => array(
					'"top"' => t('Top'),
					'"center"' => t('Center'),
					'"bottom"' => t('Bottom')
			),
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowRightValign']) ? $revolution_slider_type->data['navigation']['soloArrowRightValign'] : '"center"'
	);
	
	$form['data']['navigation']['soloArrowRightHOffset'] = array(
			'#type' => 'textfield',
			'#title' => t('soloArrowRightHOffset'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowRightHOffset']) ? $revolution_slider_type->data['navigation']['soloArrowRightHOffset'] : '0'
	);
	
	$form['data']['navigation']['soloArrowRightVOffset'] = array(
			'#type' => 'textfield',
			'#title' => t('soloArrowRightVOffset'),
			'#maxlength' => 4,
			'#default_value' => isset($revolution_slider_type->data['navigation']['soloArrowRightVOffset']) ? $revolution_slider_type->data['navigation']['soloArrowRightVOffset'] : '0'
	);
	
	// Revolution Slider: Layout Settings
	$form['data']['layout'] = array(
			'#type' => 'fieldset',
			'#title' => t('Layout Settings')
	);
	
	$form['data']['layout']['fullWidth'] = array(
			'#type' => 'radios',
			'#title' => t('fullWidth'),
			'#options' => array(
					'"on"' => t('On'),
					'"off"' => t('Off')
			),
			'#default_value' => isset($revolution_slider_type->data['layout']['fullWidth']) ? $revolution_slider_type->data['layout']['fullWidth'] : '"on"'
	);
	
	$form['data']['layout']['fullScreen'] = array(
			'#type' => 'radios',
			'#title' => t('Fullscreen'),
			'#options' => array(
					'"on"' => t('On'),
					'"off"' => t('Off')
			),
			'#default_value' => isset($revolution_slider_type->data['layout']['fullScreen']) ? $revolution_slider_type->data['layout']['fullScreen'] : '"off"'
	);
	
	$form['data']['layout']['shadow'] = array(
			'#type' => 'select',
			'#title' => t('Shadow'),
			'#options' => array(
					'0' => t('0'),
					'1' => t('1'),
					'2' => t('2'),
					'3' => t('3')
			),
			'#default_value' => isset($revolution_slider_type->data['layout']['shadow']) ? $revolution_slider_type->data['layout']['shadow'] : '"off"'
	);
	
	$form['data']['layout']['videoJsPath'] = array(
			'#type' => 'textfield',
			'#title' => t('videoJsPath'),
			'#default_value' => isset($revolution_slider_type->data['layout']['videoJsPath']) ? $revolution_slider_type->data['layout']['videoJsPath'] : '"rs-plugin/videojs/"'
	);
	
	$form['actions'] = array('#type' => 'actions');
	$form['actions']['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Save Revolution Slider'),
			'#weight' => 40,
	);

	return $form;
}

/**
 * Form API submit callback for the type form.
 */
function revolution_slider_type_form_submit(&$form, &$form_state) {
	$revolution_slider_type = entity_ui_form_submit_build_entity($form, $form_state);

	if($revolution_slider_type->data['sample_data'] == '') {
		$new = 'true';
	} else {
		$new = 'false';
	}

	$human_readable = strtolower($revolution_slider_type->label);
	$machine_readable = preg_replace('@[^a-z0-9_]+@','_',$human_readable);

	if(($new == 'true') && ($form_state['op'] != 'clone')) {
		
		/* Create Instances of Fields for New Slider */
		field_create_instance(array(
				'field_name' => 'field_image',
				'label' => 'Image',
				'entity_type' => 'revolution_slider',
				'bundle' => $machine_readable,
		));
		
		field_create_instance(array(
				'field_name' => 'field_weight',
				'label' => 'Weight',
				'entity_type' => 'revolution_slider',
				'bundle' => $machine_readable,
		));
		
		field_create_instance(array(
				'field_name' => 'field_slide_settings',
				'label' => 'Slide Settings',
				'entity_type' => 'revolution_slider',
				'bundle' => $machine_readable,
		));
		
		field_create_instance(array(
				'field_name' => 'field_layer_settings',
				'label' => 'Layer Settings',
				'entity_type' => 'revolution_slider',
				'bundle' => $machine_readable,
		));
	}
	
	$revolution_slider_type->save();

	if($form_state['op'] == 'clone') {
		 
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'revolution_slider')
		->entityCondition('bundle', $revolution_slider_type->data['sample_data']);
		 
		$result = $query->execute();
		 
		if (isset($result['revolution_slider'])) {
			$news_items_nids = array_keys($result['revolution_slider']);
			$news_items = entity_load('revolution_slider', $news_items_nids);
			
			foreach($news_items as $item) {
				$clone = replicate_clone_entity('revolution_slider', $item);
				$clone->revolution_slider_id = '';
				$clone->type = $machine_readable;
				entity_save('revolution_slider', $clone);
			}
		}
		 
	}

	$form_state['redirect'] = 'admin/structure/revolution_slider';
}

/**
 * Form API submit callback for the delete button.
 */
function revolution_slider_type_form_submit_delete(&$form, &$form_state) {
	$form_state['redirect'] = 'admin/structure/revolution_slider/manage/' . $form_state['revolution_slider_type']->type . '/delete';
}