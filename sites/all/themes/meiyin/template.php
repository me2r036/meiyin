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
	
  /**
   * Implements theme_menu_link().
   */
  function meiyin_menu_link(&$vars) {
    $element = &$vars['element'];
    $sub_menu = '';

    if ($element['#href'] == '<front>' && drupal_is_front_page()) {
      $element['#attributes']['class'][] = 'active';
		}
    
    if ($element['#href'] == current_path()) {
      $element['#attributes']['class'][] = 'active';
    }

    // Hide 'refer new customer' menu item on user menu for other users.
    if ($element['#href'] == 'node/115') {
      $allowed_roles = array('coworker', 'coworker advanced', 'administrator');
      if (!array_intersect($allowed_roles, $GLOBALS['user']->roles)) {
        //$element['#attributes']['class'][] = 'hidden';
        return NULL;
      }
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
    // $vars['element'] = $element;
    return theme_menu_link($vars);
    // return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
  }

  function meiyin_menu_tree(&$vars) {
    return '<ul>' . $vars['tree'] . '</ul>';
  }

  function meiyin_menu_tree__user_menu(&$vars) {
    return '<div id="block-system-user-menu" class="block block-system block-menu"><ul><li class="spot default"><a href="#block-system-user-menu" title="美音婚礼™ 我的账户"><i class="fa fa-user"></i></a><ul>' . $vars['tree'] . '</ul></li></ul></div>';
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
    $form['actions']['draft']['#attributes']['class'][] = 'btn btn-primary';
    $form['actions']['submit']['#attributes']['class'][] = 'btn btn-primary';
    $form['actions']['delete']['#attributes']['class'][] = 'btn btn-primary';

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
      $form['actions']['draft']['#value'] = decode_entities('&#xf0c7;') . ' 保存草稿';
      $form['actions']['submit']['#value'] = decode_entities('&#xf1d8;') . ' 提交预约';
    }
  }

  /**
   * Implements hook_form_FORM_ID_alter().
   *
   * Profile2 data can be accessed here (in the later processing), which can not be accessed in wedding_commission module.
   */
  function meiyin_form_user_register_form_alter(&$form, &$form_state, $form_id) {
    if (current_path() == 'user/register') {
      unset($form['profile_personal_data']);
    }
  }

  /**
   * Implements theme_field().
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

    if ($is_mobile) {
      // Change video field display style to "mobile"
      foreach ($vars['items'] as $delta => $item) {
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

      // Remove servies view from front page if the device is mobile
      if (drupal_is_front_page() && $view->name == 'meiyin_services') {
        foreach ($view->result as $result) {
          unset($view->result);
        }
      }
    }

    // Adds table style file
    if ($view->name == 'meiyin_webform_submissions' || $view->name == 'meiyin_my_referrals') {
      drupal_add_css(drupal_get_path('theme', 'meiyin') . '/css/table-style.css');
    }
  }

  /**
   * Implements theme_pager().
   *
   * Returns HTML for a query pager.
   *
   * Menu callbacks that display paged query results should call theme('pager') to
   * retrieve a pager control so that users can view other results. Format a list
   * of nearby pages with additional query results.
   *
   * @param $variables
   *   An associative array containing:
   *   - tags: An array of labels for the controls in the pager.
   *   - element: An optional integer to distinguish between multiple pagers on
   *     one page.
   *   - parameters: An associative array of query string parameters to append to
   *     the pager links.
   *   - quantity: The number of pages in the list.
   *
   * @ingroup themeable
   */
  function meiyin_pager($variables) {
    $tags = $variables['tags'];
    $element = $variables['element'];
    $parameters = $variables['parameters'];
    $quantity = $variables['quantity'];
    global $pager_page_array, $pager_total;

    // Calculate various markers within this pager piece:
    // Middle is used to "center" pages around the current page.
    $pager_middle = ceil($quantity / 2);
    // current is the page we are currently paged to
    $pager_current = $pager_page_array[$element] + 1;
    // first is the first page listed by this pager piece (re quantity)
    $pager_first = $pager_current - $pager_middle + 1;
    // last is the last page listed by this pager piece (re quantity)
    $pager_last = $pager_current + $quantity - $pager_middle;
    // max is the maximum page number
    $pager_max = $pager_total[$element];
    // End of marker calculations.

    // Prepare for generation loop.
    $i = $pager_first;
    if ($pager_last > $pager_max) {
      // Adjust "center" if at end of query.
      $i = $i + ($pager_max - $pager_last);
      $pager_last = $pager_max;
    }
    if ($i <= 0) {
      // Adjust "center" if at start of query.
      $pager_last = $pager_last + (1 - $i);
      $i = 1;
    }
    // End of generation loop preparation.

    $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
    $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
    $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
    $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

    if ($pager_total[$element] > 1) {
      if ($li_first) {
        $items[] = array(
          'class' => array('pager-first'),
          'data' => $li_first,
        );
      }
      if ($li_previous) {
        $items[] = array(
          'class' => array('pager-previous'),
          'data' => $li_previous,
        );
      }

      // When there is more than one page, create the pager list.
      if ($i != $pager_max) {
        // Now generate the actual pager piece.
        for (; $i <= $pager_last && $i <= $pager_max; $i++) {
          if ($i < $pager_current) {
            $items[] = array(
              'class' => array('pager-item'),
              'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
            );
          }
          if ($i == $pager_current) {
            $items[] = array(
              'class' => array('pager-current'),
              'data' => $i,
            );
          }
          if ($i > $pager_current) {
            $items[] = array(
              'class' => array('pager-item'),
              'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
            );
          }
        }
      }
      // End generation.
      if ($li_next) {
        $items[] = array(
          'class' => array('pager-next'),
          'data' => $li_next,
        );
      }
      if ($li_last) {
        $items[] = array(
          'class' => array('pager-last'),
          'data' => $li_last,
        );
      }
      return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
        'items' => $items,
        'attributes' => array('class' => array('pager')),
      ));
    }
  }

  /**
   * Implements theme_form_element().
   *   Moves form discription above input.
   *
   * Returns HTML for a form element.
   *
   * Each form element is wrapped in a DIV container having the following CSS
   * classes:
   * - form-item: Generic for all form elements.
   * - form-type-#type: The internal element #type.
   * - form-item-#name: The internal form element #name (usually derived from the
   *   $form structure and set via form_builder()).
   * - form-disabled: Only set if the form element is #disabled.
   *
   * In addition to the element itself, the DIV contains a label for the element
   * based on the optional #title_display property, and an optional #description.
   *
   * The optional #title_display property can have these values:
   * - before: The label is output before the element. This is the default.
   *   The label includes the #title and the required marker, if #required.
   * - after: The label is output after the element. For example, this is used
   *   for radio and checkbox #type elements as set in system_element_info().
   *   If the #title is empty but the field is #required, the label will
   *   contain only the required marker.
   * - invisible: Labels are critical for screen readers to enable them to
   *   properly navigate through forms but can be visually distracting. This
   *   property hides the label for everyone except screen readers.
   * - attribute: Set the title attribute on the element to create a tooltip
   *   but output no label element. This is supported only for checkboxes
   *   and radios in form_pre_render_conditional_form_element(). It is used
   *   where a visual label is not needed, such as a table of checkboxes where
   *   the row and column provide the context. The tooltip will include the
   *   title and required marker.
   *
   * If the #title property is not set, then the label and any required marker
   * will not be output, regardless of the #title_display or #required values.
   * This can be useful in cases such as the password_confirm element, which
   * creates children elements that have their own labels and required markers,
   * but the parent element should have neither. Use this carefully because a
   * field without an associated label can cause accessibility challenges.
   *
   * @param $variables
   *   An associative array containing:
   *   - element: An associative array containing the properties of the element.
   *     Properties used: #title, #title_display, #description, #id, #required,
   *     #children, #type, #name.
   *
   * @ingroup themeable
   */
  function meiyin_form_element($variables) {
    $element = &$variables['element'];

    // This function is invoked as theme wrapper, but the rendered form element
    // may not necessarily have been processed by form_builder().
    $element += array(
      '#title_display' => 'before',
    );

    // Add element #id for #type 'item'.
    if (isset($element['#markup']) && !empty($element['#id'])) {
      $attributes['id'] = $element['#id'];
    }
    // Add element's #type and #name as class to aid with JS/CSS selectors.
    $attributes['class'] = array('form-item');
    if (!empty($element['#type'])) {
      $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
    }
    if (!empty($element['#name'])) {
      $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
    }
    // Add a class for disabled elements to facilitate cross-browser styling.
    if (!empty($element['#attributes']['disabled'])) {
      $attributes['class'][] = 'form-disabled';
    }
    $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

    // If #title is not set, we don't display any label or required marker.
    if (!isset($element['#title'])) {
      $element['#title_display'] = 'none';
    }
    $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
    $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

    switch ($element['#title_display']) {
      case 'before':
      case 'invisible':
        $output .= ' ' . theme('form_element_label', $variables);

        if (!empty($element['#description'])) {
          $output .= '<div class="description">' . $element['#description'] . "</div>\n";
        }

        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;

      case 'after':
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
        $output .= ' ' . theme('form_element_label', $variables) . "\n";
        break;

      case 'none':
      case 'attribute':
        // Output no label and no required marker, only the children.
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        break;
    }

    $output .= "</div>\n";

    return $output;
  }

  /**
   * Implements template_preprocess_user_profile().
   */
  function meiyin_preprocess_user_profile(&$vars){
    if(isset($vars['user_profile']['Referrals'])) {
      //$vars['user_profile']['Referrals']['#weight'] = 0;
      $vars['user_profile']['Referrals']['#title'] = '隶属专员';
      $vars['user_profile']['Referrals'][0]['#title'] = '推荐链接';
      $vars['user_profile']['Referrals'][0]['#prifix'] = '<span class="referral_link">';
      $vars['user_profile']['Referrals'][0]['#suffix'] = '</span>';
      $vars['user_profile']['Referrals'][1]['#title'] = '';
      $vars['user_profile']['Referrals'][1]['#markup'] = '<a href="/my-referrals">查看我推荐的专员</a>';
    }
  }

  /**
   * Implements template_preprocess_html().
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

    // Add QR codes variables to the page context
      $wechat_data = 'http://weixin.qq.com/r/ld2stDzE8WGOrXjX94iH';
      $vars['qr_code_wechat'] = theme('qr_codes', array('data' => $wechat_data, 'width' => '600', 'height' => '600', 'margin' => '0', 'alt' => '二维码 - 美音婚礼™ 微信客服', 'title' => '二维码 - 美音婚礼™ 微信客服',));

      $vcard_data =
'BEGIN:VCARD
VERSION:3.0
FN:美音婚礼™
URL:http://meiyin.co
EMAIL:info@meiyin.co
TEL;TYPE=WORK:029 8754 7720
TEL;TYPE=CELL:186 8181 6517
ADR;TYPE=work:;秦融酒店1018;科技路1号;西安市;陕西省;710075;;
END:VCARD';
      $vars['qr_code_vcard'] = theme('qr_codes', array('data' => $vcard_data, 'width' => '600', 'height' => '600', 'margin' => '0', 'alt' => '二维码 - 美音婚礼™ 数字名片', 'title' => '二维码 - 美音婚礼™ 数字名片',));

  }

  /**
  * Implements template_preprocess_page().
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
    elseif (!empty($vars['page']['sidebar_first']) && empty($vars['page']['sidebar_second'])) {
      $vars['content_settings'] = 'span' . $sidebar_left;
    }
    elseif (empty($vars['page']['sidebar_first']) && !empty($vars['page']['sidebar_second'])) {
      $vars['content_settings'] = 'span' . $sidebar_right;
    }
    else {
      $vars['content_settings'] = (theme_get_setting('content_grid') !== '0') ? 'span'. theme_get_setting('content_grid') : 'span12';
    }

    if (drupal_is_front_page()) {
      unset($vars['page']['content']['system_main']);
      drupal_add_js(drupal_get_path('theme', 'meiyin') . '/js/TweenMax.min.js');
    }
  }

  /**
   * Implements template_preprocess_node().
  */
  function meiyin_preprocess_node(&$vars) {
    // Load the currently logged in user
    global $user; 
    $roles = $user->roles;
    // Hide the link statistics if current user is not admin or editor.
    if (module_exists('statistics')) {
      if (!in_array("editor", array_values($roles)) && !in_array("administrator", array_values($roles))) {
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
    } elseif (user_has_role('tester')){
      // $user is tester
    } else {
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

      if ($vars['field_dotted_overlay'][LANGUAGE_NONE][0]['value']) {
        $vars['content']['container']['#attributes']['class'] .= ' dot-overlay';
      }
    }

    if ($vars['type'] == 'portfolio') {
      // Generate partner variables used in the theme layer.
      $vars['partner_flower_art'] = _get_partner_involved_picture($vars['field_flower_art']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
      $vars['partner_makeup'] = _get_partner_involved_picture($vars['field_makeup']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
      $vars['partner_photography'] = _get_partner_involved_picture($vars['field_photography']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
      $vars['partner_camera_shooting'] = _get_partner_involved_picture($vars['field_camera_shooting']['0']['entity']->field_image[LANGUAGE_NONE]['0']);
    }

    //Generate paginator variables for Portfolio and Blog Post nodes.
    if ($vars['type'] == 'portfolio' || $vars['type'] == 'blog_post') {
      $node_type = $vars['type'];

      /* Query Portfolio or Blog Post Nodes */
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', $node_type)
            ->propertyCondition('status', TRUE)
            ->propertyOrderBy('created', 'DESC');
      $result = $query->execute();

      /* Generate Paginator */
      $nid = $vars['nid'];
      $last = end($result['node']);
      $first = reset($result['node']);

      switch ($nid) {
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
    if ($vars['type'] == 'portfolio' || $vars['type'] == 'blog_post' || $vars['type'] == 'service' || $vars['node']->nid == '47' || $vars['node']->nid == '31' || $vars['node']->nid == '105'){
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
       if (theme_get_setting('parallax-toggle') == 1) { $vars['classes_array'][] = 'parallax'; }
       if ($span != '0') { $vars['classes_array'][] = 'span'. $span; }
       break;
     default: if ($span != '0') { $vars['classes_array'][] = 'span'. $span; } break;
   }

   if (($css != 'none')) { $vars['classes_array'][] = $css; } else { die; }
 }

  function meiyin_process_region(&$vars) {
    $theme = meiyin_get_theme();

    if ($vars['elements']['#region'] == 'content') {
      $vars['messages'] = $theme->page['messages'];
    }
    $vars['breadcrumb'] = $theme->page['breadcrumb'];
    $vars['title_prefix'] = $theme->page['title_prefix'];
    $vars['title'] = $theme->page['title'];
    $vars['title_suffix'] = $theme->page['title_suffix'];
    $vars['tabs'] = $theme->page['tabs'];
    $vars['action_links'] = $theme->page['action_links'];
    $vars['feed_icons'] = $theme->page['feed_icons'];
  }

  /* Helper function */
  function _get_partner_involved_picture($picture) {
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
