<?php

	require_once dirname(__FILE__) . '/includes/meiyin.inc';

	/**
	 * Implements hook_css_alter().
	 */
	function meiyin_css_alter(&$css) {
		unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
		unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
 		
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
      //krumo($javascript);
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
	
    //if($element['#below']) {
    //  $sub_menu = drupal_render($element['#below']);
    //}
    //$output = l($element['#title'], $element['#href'], $element['#localized_options']);

    //Add icon to the 'Home' menu link.
    //if($element['#title'] == 'Home') {
    //  $output = str_replace('Home', '<span class="icon_wrap"><i class="fa fa-home"></i>' . t('Home') . '</span>', $output);
    //  $output = str_replace('Home', ' ' . t('Home'), $output);
    //  drupal_set_message(print "<pre>");
    //  drupal_set_message(print_r($element));
    //  drupal_set_message(print "</pre>");
    //}
    //if ($element['#title'] == 'Contact') {
    //  $output = str_replace('Contact', ' ' . t('Contact'), $output);
    //}

    //return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

    /**
     * Implements theme_menu_link().
     *
     * This code adds an icon <I> tag for use with icon fonts when a menu item
     * contains a CSS class that starts with "icon-". You may add CSS classes to
     * your menu items through the Drupal admin UI with the menu_attributes contrib
     * module.
     *
     * Originally written by lacliniquemtl.
     * Refactored by jwilson3 > mroji28 > driesdelaey.
     * @see http://drupal.org/node/1689728
     */
    $exclusion = array(
      'fa-lg','fa-2x','fa-3x','fa-4x','fa-5x',
      'fa-fw',
      'fa-ul', 'fa-li',
      'fa-border',
      'fa-spin',
      'fa-rotate-90', 'fa-rotate-180','fa-rotate-270','fa-flip-horizontal','fa-flip-vertical',
      'fa-stack', 'fa-stack-1x', 'fa-stack-2x',
      'fa-inverse'
    );

    if (isset($element['#original_link']['options']['attributes']['class'])) {
      foreach ($element['#original_link']['options']['attributes']['class'] as $key => $class) {
        if (substr($class, 0, 3) == 'fa-' && !in_array($class, $exclusion)) {

        // We're injecting custom HTML into the link text, so if the original
        // link text was not set to allow HTML (the usual case for menu items),
        // we MUST do our own filtering of the original text with check_plain(),
        // then specify that the link text has HTML content.

          if (!isset($element['#original_link']['options']['html']) || empty($element['#original_link']['options']['html'])) {
            $element['#title'] = check_plain($element['#title']);
            $element['#localized_options']['html'] = TRUE;
          }

          // Add the default-FontAwesome-prefix so we don't need to add it manually in the menu attributes
            // My approach still need to specify fa fa-icon in the menu attributes. by me2 on 14/11/2015
          $class = 'fa ' . $class;

          // Create additional HTML markup for the link's icon element and wrap
          // the link text in a SPAN element, to easily turn it on or off via CSS.
          $element['#title'] = '<i class="' . $class . '"></i><span>' . t($element['#title']) . '</span>';

          // Finally, remove the icon class from link options, so it is not printed twice.
          unset($element['#localized_options']['attributes']['class']);

          // kpr($element); // For debugging.

        }
      }
    }
    // Save our modifications, and call core theme_menu_link().
    $var['element'] = $element;
    return theme_menu_link($var);
    // return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
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
			$output .= '<div class="breadcrumbwrap"><i class="fa fa-location-arrow"></i>' . implode('&nbsp; &nbsp; / &nbsp; &nbsp;', $breadcrumb) . '&nbsp; &nbsp; / &nbsp; &nbsp;'. drupal_get_title() .'</div>';
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
      $form['#submit'][] = 'input_search_submit'; 
    }

    if($form_id == 'contact_site_form') {
      $form['actions']['submit']['#value'] = decode_entities('&#xf1d8;') . ' 发送消息';
      //$form['actions'] = array(
      //  'submit' => array(
      //    '#markup' => '<div class="form-actions form-wrapper" id="edit-actions">
      //                    <button type="submit" class="btn btn-primary form-submit"><span class="icon_wrap"><i class="fa fa-send"></i>发送消息</span></button>
      //                  </div>',
          // '#type' => 'markup',
          // '#prefix' => '<div class ...',
          // '#suffix' => '</div>',
      //  )
      //);
    }

    if ($form_id == 'webform_client_form_47') {
      $form['actions']['submit']['#value'] = decode_entities('&#xf1d8;') . ' 提交预约';
    }

  }

  /**
   * Implements hook_field().
   */
  function meiyin_field__video_embed_field(&$vars) {
    $output ='';

    // Render the label, if it's not hidden.
    if (!$vars['label_hidden']) {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
    }

    // Modify video display style to "mobile" if the current display device is mobile or tablet.
    $detect = mobile_detect_get_object();
    $is_mobile = $detect->isMobile();

    foreach ($vars['items'] as $delta => $item) {
      // Change video field display style to "mobile"
      if ($is_mobile) {
        $item[0]['#style'] = 'mobile';
      }
      $output .= drupal_render($item);
    }

    return $output;
  }

  /**
   * Implements hook_views_pre_render().
   */
  function meiyin_views_pre_render(&$view) {
    $detect = mobile_detect_get_object();
    $is_mobile = $detect->isMobile();

    if ($is_mobile) {
      if ($view->name == 'meiyin_blog' || $view->name == 'meiyin_portfolio') {
        foreach ($view->result as $result) {
          if( $result->field_field_video != NULL ) {
            $result->field_field_video[0]['rendered'][0]['#style'] = 'mobile';
          }
        }
      }
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

    // Load fontawesome from cdn, fallback within globle js.
    drupal_add_css('//cdn.bootcss.com/font-awesome/4.5.0/css/font-awesome.min.css', 
                          array('type' => 'external', 'group' => CSS_THEME, 'every_page' => TRUE));

   // $vars['jquery'] = '<script type="text/javascript" src="http://cdn.bootcss.com/jquery/1.11.2/jquery.min.js"></script>';
   // $vars['migrate'] = '<script type="text/javascript" src="http://cdn.bootcss.com/jquery-migrate/1.2.1/jquery-migrate.min.js"></script>';

    // Add jquery-migrate with fallback if the cdn unavailable
    drupal_add_js('//cdn.bootcss.com/jquery-migrate/1.2.1/jquery-migrate.min.js', array('type' => 'external', 'group' => JS_LIBRARY, 'weight' => -16));
    $data = 'jQuery.migrateWarnings || document.write("<script src=\'' . base_path() . drupal_get_path('theme', 'meiyin') . '/js/jquery-migrate.min.js\'>\x3C/script>")';
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
    if (module_exists('statistics')) {
      if(!in_array("editor", array_values($roles)) && !in_array("administrator", array_values($roles))) {
        unset($vars['content']['links']['statistics']['#links']['statistics_counter']);
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
    }*/

    // Add rounded class to the container of field_image; add dotted overlay effect if is set.
    if ($vars['type'] == 'service') {
      $vars['content']['container'] = array(
        '#type' => 'container',
        '#attributes' => array('class' => 'service-banner rounded'),
      );
      $vars['content']['container']['field_image'] = $vars['content']['field_image'];
      unset($vars['content']['field_image']);

      if($vars['field_dotted_overlay'][LANGUAGE_NONE][0]['value']) {
        $vars['content']['container']['#attributes']['class'] .= ' dot-overlay';
      }
    }

    if ($vars['type'] == 'portfolio') {
      // Generate partner variables used in the theme layer.
      $vars['partner_flower_art'] = get_partner_involved_picture($vars['field_flower_art']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
      $vars['partner_makeup'] = get_partner_involved_picture($vars['field_makeup']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
      $vars['partner_photography'] = get_partner_involved_picture($vars['field_photography']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
      $vars['partner_camera_shooting'] = get_partner_involved_picture($vars['field_camera_shooting']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
    }

    //Generate paginator variables for Portfolio and Blog Post nodes.
    if($vars['type'] == 'portfolio' || $vars['type'] == 'blog_post') {
      $node_type = $vars['type'];

      /* Query Portfolio or Blog Post Nodes */
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', $node_type)
            ->propertyOrderBy('created', 'DESC');
      $result = $query->execute();

      /* Generate Paginator */
      $nid = $vars['nid'];
      $last = end($result['node']);
      $first = reset($result['node']);

      switch($nid) {
        case $first->nid:
        $prev = $last->nid;
        $next = next($result['node'])->nid;
        break;
        case $last->nid:
        end($result['node']);
        $prev = prev($result['node'])->nid;
        $next = $first->nid;
        break;
        default:
        while(list($key, ) = each($result['node'])){
          if($key == $nid){
            $next = current($result['node'])->nid;
            prev($result['node']);
            $prev = prev($result['node'])->nid;
            break;
          }
        }
      }

      $path = "node/".$nid;
      $options = array('absolute' => TRUE);
      $url = url($path, $options);

      // Generate variables used in the theme layer.
      $vars['prev'] = $prev;
      $vars['next'] = $next;
      $vars['path'] = $path;
      $vars['url'] = $url;
    }

    // Baidu share script added here
    if ($vars['type'] == 'portfolio' || $vars['type'] == 'blog_post' || $vars['type'] == 'webform' || $vars['type'] == 'service' || $vars['node']->nid == '31'){
      $data = 'window._bd_share_config={"common":{"bdSnsKey":{},"bdText":"","bdMini":"2","bdPic":"","bdStyle":"1"},
              "share":{"bdSize":"24"},
              "image":{"viewList":["weixin","tsina","tqq","sqq","qzone"],"viewText":"分享到：","viewPos":"top","viewSize":"16"},
              "selectShare":{"bdContainerClass":null,"bdSelectMiniList":["weixin","tsina","tqq","sqq","qzone"]}};
              with(document)0[(getElementsByTagName(\'head\')[0]||body).appendChild(createElement(\'script\'))
              .src=\'http://bdimg.share.baidu.com/static/api/js/share.js?v=89860593.js?cdnversion=\'+~(-new Date()/36e5)];';
      drupal_add_js($data, array('type' => 'inline', 'group' => JS_THEME));
    }

  }

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

  /* Helper function */
  function get_partner_involved_picture($picture) {
    $fallback_image_style = 'partner_involved_breakpoints_theme_meiyin_wide_1x';
    $picture_mapping = picture_mapping_load('resp_partner_involved');
    $breakpoints = picture_get_mapping_breakpoints($picture_mapping, $fallback_image_style);
    $image_render_array = array(
      '#theme' => 'picture',
      '#uri' => $picture['uri'],
      '#breakpoints' => $breakpoints,
      '#style-name' => $$fallback_image_style,
      '#alt' => isset($picture['alt']) ? $picture['alt'] : '',
      '#timestamp' => $picture['timestamp'],
    );
    return render($image_render_array);
  }
