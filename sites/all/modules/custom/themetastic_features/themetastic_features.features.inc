<?php
/**
 * @file
 * themetastic_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function themetastic_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function themetastic_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function themetastic_features_image_default_styles() {
  $styles = array();

  // Exported image style: isotope_portfolio_400x225.
  $styles['isotope_portfolio_400x225'] = array(
    'name' => 'isotope_portfolio_400x225',
    'label' => 'Isotope Portfolio (400x225)',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 225,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: portfolio_fullwidth.
  $styles['portfolio_fullwidth'] = array(
    'name' => 'portfolio_fullwidth',
    'label' => 'Portfolio Fullwidth',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1170,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: portfolio_thumbnail__60x60_.
  $styles['portfolio_thumbnail__60x60_'] = array(
    'name' => 'portfolio_thumbnail__60x60_',
    'label' => 'Portfolio Thumbnail (60x60)',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function themetastic_features_node_info() {
  $items = array(
    'blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('Use the <em>blog post</em> content type to manage blog nodes with the ThemeTastic theme.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('Use the <em>portfolio</em> content type to manage portfolio nodes with the ThemeTastic theme.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'services' => array(
      'name' => t('Services'),
      'base' => 'node_content',
      'description' => t('Use the <em>services</em> content type to manage service nodes with the ThemeTastic theme.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
