<?php

	require_once dirname(__FILE__) . '/includes/meiyin.inc';

	/**
	 * Implements hook_css_alter().
	 */
	function meiyin_css_alter(&$css) {
		unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
		unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
		drupal_add_css(drupal_get_path('theme', 'meiyin') . '/css/admin.css');
	 	if (isset($css[drupal_get_path('module', 'views_isotope') . '/views_isotope.css'])) {
 			unset($css[drupal_get_path('module', 'views_isotope') . '/views_isotope.css']);
 		}
 		
 		global $language;
 			
 		if($language->direction == LANGUAGE_RTL) {
 			unset($css[drupal_get_path('theme', 'meiyin') . '/css/bootstrap-responsive.min.css']);
 			unset($css[drupal_get_path('theme', 'meiyin') . '/css/bootstrap.min.css']);
 			unset($css[drupal_get_path('theme', 'meiyin') . '/css/meiyin.css']);
 		}
	}
	
  /**
   * Implements hook_js_alter().
   */
  function meiyin_js_alter(&$javascript) {
    // Unset old version of jQuery on non-administration pages
    if (!path_is_admin(current_path())) {
      unset($javascript['misc/jquery.js']);
    }

    global $language;

    if($language->direction == LANGUAGE_RTL) {
      unset($javascript[drupal_get_path('theme', 'meiyin') . '/js/screen.js']);
      drupal_add_js(drupal_get_path('theme', 'meiyin') . '/js/screen-rtl.js');
    }
  }

	function meiyin_menu_local_tasks(&$vars) {
		$output = '';
	
		if (!empty($vars['primary'])) {
			$vars['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
			$vars['primary']['#prefix'] .= '<ul class="nav nav-tabs primary">';
			$vars['primary']['#suffix'] = '</ul>';
			$output .= drupal_render($vars['primary']);
		}
	
		return $output;
	}
	
  function meiyin_menu_link(&$vars) {
    $element = &$vars['element'];
    $sub_menu = '';

    if($element['#href'] == '<front>' && drupal_is_front_page()) {
      $element['#attributes']['class'][] = 'active';
		}
    
    if($element['#href'] == current_path()) {
      $element['#attributes']['class'][] = 'active';
    }
	
    if($element['#below']) {
      $sub_menu = drupal_render($element['#below']);
    }

    $output = l($element['#title'], $element['#href'], $element['#localized_options']);

    //Add icon to the 'Home' menu link.
    if($element['#title'] == 'Home') {
      $output = str_replace("Home", '<span class="icon_wrap"><i class="fa fa-home"></i>Home</span>', $output);
    }

    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
  }
	
  function meiyin_menu_tree(&$vars) {
    return '<ul>' . $vars['tree'] . '</ul>';
  }
	
	/**
	 * Implements theme_breadcrumb().
	 */
	function meiyin_breadcrumb(&$vars) {
		$breadcrumb = &$vars['breadcrumb'];
	
		if (!empty($breadcrumb)) {
			// Provide a navigational heading to give context for breadcrumb links to
			// screen-reader users. Make the heading invisible with .element-invisible.
			$output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
			$output .= '<div class="breadcrumbwrap">' . implode('&nbsp; &nbsp; / &nbsp; &nbsp;', $breadcrumb) . '&nbsp; &nbsp; / &nbsp; &nbsp;'. drupal_get_title() .'</div>';
			return $output;
		}
	}
	
  /**
   * Implements hook_form_alter().
   */
  function meiyin_form_alter(&$form, &$form_state, $form_id) {
    $form['actions']['submit']['#attributes']['class'][] = 'btn btn-primary';
    if($form_id == 'search_form' && (arg(0) !== 'search')) {
      $form['basic']['submit'] = array('#attributes' => array('class' => array('element-invisible')));
      $form['basic']['keys'] = array(
        '#type' => 'textfield', 
        '#title' => t('Enter your keywords'), 
        '#title_display' => 'invisible', 
        '#attributes' => array('placeholder' => array(t('Search'))) // Add placeholder to the search form 
      );
      //$form['basic']['keys']['#attributes'] = array('placeholder' => t('Search'));
    }

    if($form_id == 'contact_site_form') {
      $form['actions'] = array(
        'submit' => array(
          '#markup' => '<div class="form-actions form-wrapper" id="edit-actions">
                          <button type="submit" class="btn btn-primary form-submit"><span class="icon_wrap"><i class="fa fa-send"></i>发送消息</span></button>
                        </div>'
        )
      );
      //drupal_set_message(print_r($form));
    }

  }

  /**
   * Implements hook_preprocess_html().
   */
  function meiyin_preprocess_html(&$vars) {
    if(theme_get_setting('layoutcolor') !== 'green') {
      $skin = drupal_get_path('theme', 'meiyin') . '/css/' . theme_get_setting('layoutColor') . '.css';
      drupal_add_css($skin, array('group' => CSS_THEME, 'every_page' => TRUE));
    }

    // Load fontawesome from cdn, fallback with globle js.
    drupal_add_css('//cdn.bootcss.com/font-awesome/4.3.0/css/font-awesome.min.css', 
                          array('type' => 'external', 'group' => CSS_THEME, 'every_page' => TRUE));

   // $vars['jquery'] = '<script type="text/javascript" src="http://cdn.bootcss.com/jquery/1.11.2/jquery.min.js"></script>';
   // $vars['migrate'] = '<script type="text/javascript" src="http://cdn.bootcss.com/jquery-migrate/1.2.1/jquery-migrate.min.js"></script>';

    // Add jquery-migrate with fallback if the cdn unavailable
    drupal_add_js('//cdn.bootcss.com/jquery-migrate/1.2.1/jquery-migrate.min.js', array('type' => 'external', 'group' => JS_LIBRARY, 'weight' => -16));
    $data = 'window.jQuery || document.write("<script src=\'' . base_path() . drupal_get_path('theme', 'meiyin') . '/js/jquery-migrate.min.js\'>\x3C/script>")';
    drupal_add_js($data, array('type' => 'inline', 'group' => JS_LIBRARY, 'weight' => -15.999999999));

    $vars['classes_array'][] = 'colored';
    (theme_get_setting('layoutWidth') == 'boxedlayout') ? $vars['classes_array'][] = 'boxedlayout' : $vars['classes_array'][] = 'fullwidthlayout';

    if(theme_get_setting('backgroundImage') !== 'no-background') {
      $vars['classes_array'][] = theme_get_setting('backgroundImage');
    }

    if(theme_get_setting('backgroundImage') == 'custom') {
      $image = 'body.custom {background-image: url('.file_create_url(file_load(theme_get_setting('backgroundCustom'))->uri).');}';
      drupal_add_css($image, array('type' => 'inline', 'every_page' => TRUE));
    }

    if(theme_get_setting('backgroundColor') != NULL) {
      $color = 'body { background-color: #'.theme_get_setting('backgroundColor').' !important; }';
      drupal_add_css($color, array('type' => 'inline', 'every_page' => TRUE));
    }

    if(theme_get_setting('sticky-header') == 1) {
      $vars['classes_array'][] = 'sticky-header';
    }
  }

	/**
	 * Implements hook_preprocess_page().
	 */
	function meiyin_preprocess_page(&$vars) {
		$theme = meiyin_get_theme();
		$theme->page = &$vars;
		$search_form = drupal_get_form('search_form');
		$sidebar_left = 12 - theme_get_setting('sidebar_first_grid');
		$sidebar_right = 12 - theme_get_setting('sidebar_second_grid');
		$sidebar_both = 12 - (theme_get_setting('sidebar_first_grid') + theme_get_setting('sidebar_second_grid'));
		$vars['search_form'] = (arg(0) == 'search') ? '' : drupal_render($search_form);
		$vars['layoutWidth'] = theme_get_setting('layoutWidth');
		if (!empty($vars['page']['sidebar_first']) && !empty($vars['page']['sidebar_second'])) {
			$vars['content_settings'] = 'span' . $sidebar_both;
		}
		else if (!empty($vars['page']['sidebar_first']) && empty($vars['page']['sidebar_second'])) {
			$vars['content_settings'] = 'span' . $sidebar_left;
		}
		else if (empty($vars['page']['sidebar_first']) && !empty($vars['page']['sidebar_second'])) {
			$vars['content_settings'] = 'span' . $sidebar_right;
		} else {
			$vars['content_settings'] = (theme_get_setting('content_grid') !== '0') ? 'span'. theme_get_setting('content_grid') : 'span12';
		}
		
		if (drupal_is_front_page()) { 
			unset($vars['page']['content']['system_main']);
			drupal_add_js(drupal_get_path('theme', 'meiyin') . '/js/TweenMax.min.js');
		}
	}

  /**
   * Implements hook_preprocess_node().
  */
  function meiyin_preprocess_node(&$vars) {
    // Load the currently logged in user
    global $user; 
    $roles = $user->roles;
    // Hide the link statistics if current user is not admin or editor.
    if(module_exists('statistics')) {
      if(!in_array("editor", array_values($roles)) && !in_array("administrator", array_values($roles))) {
        unset($vars['content']['links']['statistics']['#links']['statistics_counter']);
      } else {
        $vars['content']['links']['statistics']['#links']['statistics_counter']['title'] = 
          substr_replace($vars['content']['links']['statistics']['#links']['statistics_counter']['title'], "", -6, 6);
      }
    }
  }

  /* To check if the current user has a single role or any of multiple roles, a great way is to do:
  // can be used in access callback too
  function user_has_role($roles) {
    //checks if user has role/roles
    return !!count(array_intersect(is_array($roles)? $roles : array($roles), array_values($GLOBALS['user']->roles)));
  };

  if (user_has_role(array('moderator', 'administrator'))) {
    // $user is admin or moderator
  } else if(user_has_role('tester')){
    // $user is tester
  } else{
    // $user is not admin and not moderator
  }
  */

	function meiyin_preprocess_region(&$vars) {		
		$theme = meiyin_get_theme();
		$span = theme_get_setting($vars['region'] . '_grid');
		$css = theme_get_setting($vars['region'] . '_css');
		$vars['classes_array'] = array('region');
		$vars['classes_array'][] = drupal_html_id($vars['region']);
		
		switch ($vars['region']) {
			case 'content': 
				$vars['classes_array'][] = $theme->page['content_settings'];
			break;
			case 'header':
				if(theme_get_setting('parallax-toggle') == 1) { $vars['classes_array'][] = 'parallax'; }
				if ($span != '0') { $vars['classes_array'][] = 'span'.$span; }
			break;
	 		default: if ($span != '0') { $vars['classes_array'][] = 'span'.$span; } break;
		}
		
		if (($css != 'none')) { $vars['classes_array'][] = $css; } else { die; }
		
	}

	
	function meiyin_process_region(&$vars) {
		$theme = meiyin_get_theme();

		$vars['messages'] = $theme->page['messages'];
		$vars['breadcrumb'] = $theme->page['breadcrumb'];
		$vars['title_prefix'] = $theme->page['title_prefix'];
		$vars['title'] = $theme->page['title'];
		$vars['title_suffix'] = $theme->page['title_suffix'];
		$vars['tabs'] = $theme->page['tabs'];
		$vars['action_links'] = $theme->page['action_links'];
		$vars['feed_icons'] = $theme->page['feed_icons'];
	}

?>
