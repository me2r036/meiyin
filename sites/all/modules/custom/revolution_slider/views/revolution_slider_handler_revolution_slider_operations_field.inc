<?php

/**
 * This field handler aggregates operations that can be done on a revolution_slider
 * under a single field providing a more flexible way to present them in a view
 */
class revolution_slider_handler_revolution_slider_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['revolution_slider_id'] = 'revolution_slider_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('revolution_slider', 'admin/content/revolution_slider/slide', array($this->get_value($values, 'revolution_slider_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
