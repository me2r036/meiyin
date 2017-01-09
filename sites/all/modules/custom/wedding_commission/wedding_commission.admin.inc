<?php

/**
 * @file
 * Wedding Commission - Admin settings pages for Wedding_commission module.
 *
 * @author Jinfeng Ren (j.ren@meiyin.co) on 2016.10.04
 */

define('INIT_PROFESSIONS_AMOUNT', 'hotel|1000
restaurant|500
studio|500
other|300
referer|200');

/**
 * Settings callback for 'admin/config/content/wedding_commission' path.
 *
 */
function wedding_commission_settings($form, &$form_state) {
  $options = wedding_commission_get_field_configurations();
  $form = array();
  $description = '<p>' . t('The possible values this field can contain. Enter one value per line, in the format key|label.');
  $description .= '<br/>' . t('The key is the stored value. The label will be used in displayed values and edit forms.');
  $description .= '<br/>' . t('The label is optional: if a line contains a single number, it will be used as key and label.');
  $description .= '<br/>' . t('Lists of labels are also accepted (one label per line), only if the field does not hold any values yet. Numeric keys will be automatically generated from the positions in the list.');
  $description .= '</p>';

  $form['wedding_commission_wedding_venues'] = array(
    '#type' => 'textarea',
    '#title' => t('Accepted wedding venues') . ' ' . '(<em>field_wedding_venue</em>)',
    '#description' => $description,
    '#default_value' => isset($options['field_wedding_venue']) ? $options['field_wedding_venue'] : '',
  );

  $form['wedding_commission_professions'] = array(
    '#type' => 'textarea',
    '#title' => t('Acceptable professions') . ' ' . '(<em>field_profession</em>)',
    '#description' => $description,
    '#default_value' => isset($options['field_profession']) ? $options['field_profession'] : '',
  );

  $form['wedding_commission_studios'] = array(
    '#type' => 'textarea',
    '#title' => t('Acceptable stuidos') . ' ' . '(<em>field_studio</em>)',
    '#description' => $description,
    '#default_value' => isset($options['field_studio']) ? $options['field_studio'] : '',
    '#rows' => 18,
  );

  $form['wedding_commission_restaurants'] = array(
    '#type' => 'textarea',
    '#title' => t('Acceptable restaurants') . ' ' . '(<em>field_restaurant</em>)',
    '#description' => $description,
    '#default_value' =>isset($options['field_restaurant']) ? $options['field_restaurant'] : '',
    '#rows' => 18,
  );

  $form['wedding_commission_hotels'] = array(
    '#type' => 'textarea',
    '#title' => t('Acceptable hotels') . ' ' . '(<em>field_hotel</em>)',
    '#description' => $description,
    '#default_value' => isset($options['field_hotel']) ? $options['field_hotel'] : '',
    '#rows' => 18,      
  );

  $form['wedding_commission_professions_amount'] = array(
    '#type' => 'textarea',
    '#title' => t('Commission amount according to each profession') . ' ' . '(<em>field_professions_amount</em>)',
    '#description' => $description,
    '#default_value' => variable_get('wedding_commission_professions_amount', ''),
  );

  $form['wedding_commission_material_loss_rate'] = array(
    '#type' => 'textfield',
    '#title' => t('Wedding material loss rate'),
    '#description' => 'Please set the material loss reate for weddings. e.g. "0.05" for 5%.',
    '#default_value' => variable_get('wedding_commission_material_loss_rate', '0.05'),
  );

  $form['wedding_commission_ref_cust_webform_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Refer customer webform node id'),
    '#description' => 'Please specify the referring customer webform node id.',
    '#default_value' => variable_get('wedding_commission_ref_cust_webform_nid', REF_CUST_WEBFORM_NID),
  );

  // Overwriting default system_settings_submit() 
  $form = system_settings_form($form);
  $form['#submit'] = array('wedding_commission_settings_submit');
  return $form;
}

/**
 * Get current selectable text field configurations from other source
 *
 */
function wedding_commission_get_field_configurations() {
  $options = array(
    'field_wedding_venue' => '',
    'field_profession' => '',
    'field_studio' => '',
    'field_restaurant' => '',
    'field_hotel' => '',
  );

  foreach($options as $key => $option) {
    $field_info = field_info_field($key);
    $field_allowed_values = list_allowed_values($field_info);
    $options[$key] = list_allowed_values_string($field_allowed_values);
  }
  return $options;
}

/**
 * Update settings on submission.
 *
 */
function wedding_commission_settings_submit($form, &$form_state) {
  $options = array();
  $options['field_wedding_venue'] = $form_state['values']['wedding_commission_wedding_venues'];
  $options['field_profession'] = $form_state['values']['wedding_commission_professions'];
  $options['field_studio'] = $form_state['values']['wedding_commission_studios'];
  $options['field_restaurant'] = $form_state['values']['wedding_commission_restaurants'];
  $options['field_hotel'] = $form_state['values']['wedding_commission_hotels'];

  foreach ($options as $key => $option) {
    // Get the field info
    $field_info = field_info_field($key);

    // Get a reference to the values
    $field_values = &$field_info['settings']['allowed_values'];

    $current_values = list_extract_allowed_values($option, 'list_text', FALSE);
    if ($field_values !== $current_values) {
      // Manipulate the values
      $field_values = $current_values;

      try {
      // Save the field
        field_update_field($field_info);
      }
      catch (FieldUpdateForbiddenException $e) {
        drupal_set_message($e->getMessage(), 'error', FALSE);
      }
      drupal_set_message(t('Updated settings for field_@name.', array('@name' => $key)), 'status', FALSE);
    }
  }

  $professions_amount_old = variable_get('wedding_commission_professions_amount', '');
  $professions_amount_new = $form_state['values']['wedding_commission_professions_amount'];
  if (preg_replace('/\n/', '', $professions_amount_old) != preg_replace('/\n/', '', $professions_amount_new)) {
    variable_set('wedding_commission_professions_amount', $professions_amount_new);
    drupal_set_message(t('Updated settings for field_professions_amount.'), 'status', FALSE);
  }

  $material_loss_rate_old = variable_get('wedding_commission_material_loss_rate', '');
  $material_loss_rate_new = $form_state['values']['wedding_commission_material_loss_rate'];
  if ($material_loss_rate_old != $material_loss_rate_new) {
    variable_set('wedding_commission_material_loss_rate', $material_loss_rate_new);
    drupal_set_message(t('Updated settings for wedding material loss rate.'), 'status', FALSE);
  }

  $ref_cust_webform_nid_old = variable_get('wedding_commission_ref_cust_webform_nid', '');
  $ref_cust_webform_nid_new = $form_state['values']['wedding_commission_ref_cust_webform_nid'];
  if ($ref_cust_webform_nid_old != $ref_cust_webform_nid_new) {
    variable_set('wedding_commission_ref_cust_webform_nid', $ref_cust_webform_nid_new);
    drupal_set_message(t('Updated settings for referring customer webform nid.'), 'status', FALSE);
  }
  drupal_set_message(t('Configurations saved successfully.'), 'status', FALSE);
}
