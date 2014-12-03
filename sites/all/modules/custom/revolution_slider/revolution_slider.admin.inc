<?php

/**
 * @file
 * RevolutionSlider editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class RevolutionSliderUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    // Change the overview menu type for the list of revolution_slider.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a slide',
      'description' => 'Add a new Revolution Slider slide',
      'page callback'  => 'revolution_slider_add_page',
      'access callback'  => 'revolution_slider_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'revolution_slider.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );
    
    if (!empty($this->entityInfo['exportable'])) {
    	$items[$this->path . '/import']['title'] = entity_ui_get_action_title('import', $this->entityType);
    	unset($items[$this->path . '/import']['title callback']);
    	unset($items[$this->path . '/import']['title arguments']);
    }
    
    // Add menu items to add each different type of entity.
    foreach (revolution_slider_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'revolution_slider_form_wrapper',
        'page arguments' => array(revolution_slider_create(array('type' => $type->type))),
        'access callback' => 'revolution_slider_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'revolution_slider.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing revolution_slider entities
    $items[$this->path . '/slide/' . $wildcard] = array(
      'page callback' => 'revolution_slider_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'revolution_slider_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'revolution_slider.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/slide/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/slide/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'revolution_slider_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'revolution_slider_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'revolution_slider.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing revolution_slider
    $items['slide/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'revolution_slider_page_title',
      'title arguments' => array(1),
      'page callback' => 'revolution_slider_page_view',
      'page arguments' => array(1),
      'access callback' => 'revolution_slider_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );

    return $items;
  }
  
  
  /**
   * Create the markup for the add RevolutionSlider Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('revolution_slider_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a revolution_slider.
 *
 * @param $revolution_slider
 *   The revolution_slider object being edited by this form.
 *
 * @see revolution_slider_edit_form()
 */
function revolution_slider_form_wrapper($revolution_slider) {
  // Add the breadcrumb for the form's location.
  revolution_slider_set_breadcrumb();
  return drupal_get_form('revolution_slider_edit_form', $revolution_slider);
}


/**
 * Form callback wrapper: delete a revolution_slider.
 *
 * @param $revolution_slider
 *   The revolution_slider object being edited by this form.
 *
 * @see revolution_slider_edit_form()
 */
function revolution_slider_delete_form_wrapper($revolution_slider) {
  // Add the breadcrumb for the form's location.
  //revolution_slider_set_breadcrumb();
  return drupal_get_form('revolution_slider_delete_form', $revolution_slider);
}


/**
 * Form callback: create or edit a revolution_slider.
 *
 * @param $revolution_slider
 *   The revolution_slider object to edit or for a create form an empty revolution_slider object
 *     with only a revolution_slider type defined.
 */
function revolution_slider_edit_form($form, &$form_state, $revolution_slider) {
  $data = db_query("SELECT data from revolution_slider_type where type = '".$revolution_slider->type."'")->fetchAssoc();
  $groups = unserialize($data['data']);

  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide Name'),
  	'#prefix' => '<div class="dimensions" data-width="'.$groups['global']['startwidth'].'" data-height="'.$groups['global']['startheight'].'">',
  	'#suffix' => '</div>',
    '#default_value' => isset($revolution_slider->name) ? $revolution_slider->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  // Add the field related form elements.
  $form_state['revolution_slider'] = $revolution_slider;
  field_attach_form('revolution_slider', $revolution_slider, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Slide'),
    '#submit' => $submit + array('revolution_slider_edit_form_submit'),
  );
  
  if (!empty($revolution_slider->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete slide'),
      '#suffix' => l(t('Cancel'), 'admin/content/revolution_slider'),
      '#submit' => $submit + array('revolution_slider_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'revolution_slider_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the revolution_slider form
 */
function revolution_slider_edit_form_validate(&$form, &$form_state) {
  $revolution_slider = $form_state['revolution_slider'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('revolution_slider', $revolution_slider, $form, $form_state);
}


/**
 * Form API submit callback for the revolution_slider form.
 * 
 * @todo remove hard-coded link
 */
function revolution_slider_edit_form_submit(&$form, &$form_state) {
  
  $revolution_slider = entity_ui_controller('revolution_slider')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the revolution_slider and go back to the list of revolution_slider
  
  // Add in created and changed times.
  if ($revolution_slider->is_new = isset($revolution_slider->is_new) ? $revolution_slider->is_new : 0){
    $revolution_slider->created = time();
  }

  $revolution_slider->changed = time();
  
  $revolution_slider->save();
  $form_state['redirect'] = 'admin/structure/revolution_slider/manage/'.$revolution_slider->type;
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function revolution_slider_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/revolution_slider/slide/' . $form_state['revolution_slider']->revolution_slider_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a revolution_slider.
 *
 * @param $revolution_slider
 *   The revolution_slider to delete
 *
 * @see confirm_form()
 */
function revolution_slider_delete_form($form, &$form_state, $revolution_slider) {
  $form_state['revolution_slider'] = $revolution_slider;

  $form['#submit'][] = 'revolution_slider_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete slide %name?', array('%name' => $revolution_slider->name)),
    'admin/content/revolution_slider/slide',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for revolution_slider_delete_form
 */
function revolution_slider_delete_form_submit($form, &$form_state) {
  $revolution_slider = $form_state['revolution_slider'];

  revolution_slider_delete($revolution_slider);

  drupal_set_message(t('The slide %name has been deleted.', array('%name' => $revolution_slider->name)));
  watchdog('revolution_slider', 'Deleted slide %name.', array('%name' => $revolution_slider->name));

  $form_state['redirect'] = 'admin/structure/revolution_slider/';
}



/**
 * Page to add RevolutionSlider Entities.
 *
 * @todo Pass this through a proper theme function
 */
function revolution_slider_add_page() {
  $controller = entity_ui_controller('revolution_slider');
  return $controller->addPage();
}


/**
 * Displays the list of available revolution_slider types for revolution_slider creation.
 *
 * @ingroup themeable
 */
function theme_revolution_slider_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="revolution_slider-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer revolution_slider types')) {
      $output = '<p>' . t('RevolutionSlider Entities cannot be added because you have not created any revolution_slider types yet. Go to the <a href="@create-revolution_slider-type">revolution_slider type creation page</a> to add a new revolution_slider type.', array('@create-revolution_slider-type' => url('admin/structure/revolution_slider/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No revolution_slider types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative revolution_slider pages.
 */
function revolution_slider_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Revolution Slider'), 'admin/content/revolution_slider'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
