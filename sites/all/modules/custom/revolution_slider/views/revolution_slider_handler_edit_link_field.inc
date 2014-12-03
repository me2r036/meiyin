<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class revolution_slider_handler_edit_link_field extends revolution_slider_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy revolution_slider to check access against
    $dummy_revolution_slider = (object) array('type' => $type);
    if (!revolution_slider_access('edit', $dummy_revolution_slider)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $revolution_slider_id = $values->{$this->aliases['revolution_slider_id']};
    
    return l($text, 'admin/content/revolution_slider/slide/' . $revolution_slider_id . '/edit');
  }
}
