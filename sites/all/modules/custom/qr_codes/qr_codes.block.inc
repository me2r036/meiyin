<?php

/**
 * @file
 * QR Codes
 *
 * @author
 */

/**
 * Callback for block configure form
 */
function _qr_codes_block_configure_form($delta = '') {
  $form = array();
  $form['qr_codes'] = array(
    '#type' => 'fieldset',
    '#title' => t('QR Codes Node Block'),
    '#collapsible' => FALSE,
  );

  $form['qr_codes']['qr_codes_block_caption'] = array(
    '#type' => 'textfield',
    '#title' => t('Caption'),
    '#description' => t('Will display above the QR Code'),
    '#default_value' => variable_get('qr_codes_block_caption', t('This page URL')),
  );

  $form['qr_codes']['qr_codes_width_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the size of the QR code image'),
    '#default_value' => variable_get('qr_codes_width_height', '480'),
  );

  $form['qr_codes']['qr_codes_block_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the text to embed in your barcode'),
    '#default_value' => variable_get('qr_codes_block_data', ''),
  );

  $form['qr_codes']['qr_codes_image_alt'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the alt attribute of the QR code image'),
    '#default_value' => variable_get('qr_codes_image_alt', 'QR Code'),
  );

  $form['qr_codes']['qr_codes_image_title'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the title attribute of the QR code image'),
    '#default_value' => variable_get('qr_codes_image_title', 'QR Code'),
  );

  if (module_exists('token')) {
    $form['qr_codes']['qr_codes_block_data']['#description'] = t('Available token replacement patterns are listed below and will be applied on node or user pages.');
    $form['qr_codes']['qr_codes_block_data']['#element_validate'][] = 'token_element_validate';

    $form['qr_codes']['qr_codes_block_token_tree'] = array(
      '#type' => 'fieldset',
      '#title' => t('Replacement patterns'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => theme('token_tree', array('token_types' => array('all'))),
      );
    }

  if(module_exists('image')){
    $form['qr_codes']['qr_codes_block_image_style'] = array(
      '#type' => 'select',
      '#title' => t('Select an Image style'),
      '#multiple' => FALSE,
      '#description' => t('If selected, this image style will be applied to the barcode image.'),
      '#options' => image_style_options(),
      '#default_value' => variable_get('qr_codes_block_image_style', NULL),
    );
  }

  return $form;
}

/**
 * Callback to handle save of block configure options
 */
function _qr_codes_block_configure_save($delta, $edit) {
  variable_set('qr_codes_block_caption', $edit['qr_codes_block_caption']);
  variable_set('qr_codes_width_height', $edit['qr_codes_width_height']);
  variable_set('qr_codes_block_data', $edit['qr_codes_block_data']);
  variable_set('qr_codes_block_image_style', $edit['qr_codes_block_image_style']);
  variable_set('qr_codes_image_alt', $edit['qr_codes_image_alt']);
  variable_set('qr_codes_image_title', $edit['qr_codes_image_title']);
}

/**
 * Callback to handle view of qr_codes block
 */
function _qr_codes_block_view($delta) {
  $text = variable_get('qr_codes_block_data', '');
  $style = variable_get('qr_codes_block_image_style', '');
  $width = variable_get('qr_codes_width_height', '600');

  $alt = variable_get('qr_codes_image_alt', 'QR Code');
  $title = variable_get('qr_codes_image_title', 'QR Code');

  // Use token replacement if available for nodes and users
  $data = array();
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $data['node'] = node_load(arg(1));
  }
  elseif (arg(0) == 'user' && is_numeric(arg(1))) {
    $data['user'] = user_load(arg(1));
  }
  $text = token_replace($text, $data);
  $alt = t('QR Code') . ' - ' . token_replace($alt, $data);
  $title = t('QR Code') . ' - ' . token_replace($title, $data);

  $block['subject'] = t('QR Codes');
  $block['content'] = '<div class="qr-code-container"><div class="qr-code-caption">'. variable_get('qr_codes_block_caption') . '</div><div class="qr-code-image">' . theme('qr_codes', array('data' => $text, 'width' => $width, 'height' => $width, 'margin' => 0, 'image_style' => $style, array('alt' => $alt, 'title' => $title,))) . '</div></div>';

  return $block;
}
