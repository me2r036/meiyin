<?php
/**
 * @file
 * themetastic_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function themetastic_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog';
  $context->description = 'A collection of contexts for blog pages';
  $context->tag = 'themetastic - templates';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog_post' => 'blog_post',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'blog-small-sidebar' => 'blog-small-sidebar',
        'blog' => 'blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-themetastic_blog-block_1' => array(
          'module' => 'views',
          'delta' => 'themetastic_blog-block_1',
          'region' => 'content',
          'weight' => '10',
        ),
        'views-themetastic_blog-block_3' => array(
          'module' => 'views',
          'delta' => 'themetastic_blog-block_3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-e08b212f7cb647be029e63d747c4df6f' => array(
          'module' => 'views',
          'delta' => 'e08b212f7cb647be029e63d747c4df6f',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-themetastic_taxonomy-block_1' => array(
          'module' => 'views',
          'delta' => 'themetastic_taxonomy-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-themetastic_blog-block_4' => array(
          'module' => 'views',
          'delta' => 'themetastic_blog-block_4',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-themetastic_blog-block_2' => array(
          'module' => 'views',
          'delta' => 'themetastic_blog-block_2',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-themetastic_taxonomy-block_tags' => array(
          'module' => 'views',
          'delta' => 'themetastic_taxonomy-block_tags',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
    'menu' => 'blog',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A collection of contexts for blog pages');
  t('themetastic - templates');
  $export['blog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact';
  $context->description = 'Contexts for ThemeTastic contact page';
  $context->tag = 'themetastic - templates';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'prescript_first',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'contact',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contexts for ThemeTastic contact page');
  t('themetastic - templates');
  $export['contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portfolio';
  $context->description = 'Contexts for ThemeTastic portfolio nodes';
  $context->tag = 'themetastic - templates';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'portfolio' => 'portfolio',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-4b2e07c6a14798a320f0499ce7483714' => array(
          'module' => 'views',
          'delta' => '4b2e07c6a14798a320f0499ce7483714',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
    'menu' => 'portfolio-5col',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contexts for ThemeTastic portfolio nodes');
  t('themetastic - templates');
  $export['portfolio'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portfolio-sidebar';
  $context->description = 'Contexts for ThemeTastic portfolio nodes/views featuring a right sidebar';
  $context->tag = 'themetastic - templates';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/11' => 'node/11',
        'portfolio-sidebar' => 'portfolio-sidebar',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-themetastic_blog-block_3' => array(
          'module' => 'views',
          'delta' => 'themetastic_blog-block_3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-e08b212f7cb647be029e63d747c4df6f' => array(
          'module' => 'views',
          'delta' => 'e08b212f7cb647be029e63d747c4df6f',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-themetastic_taxonomy-block_1' => array(
          'module' => 'views',
          'delta' => 'themetastic_taxonomy-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-themetastic_blog-block_4' => array(
          'module' => 'views',
          'delta' => 'themetastic_blog-block_4',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-themetastic_blog-block_2' => array(
          'module' => 'views',
          'delta' => 'themetastic_blog-block_2',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-themetastic_taxonomy-block_tags' => array(
          'module' => 'views',
          'delta' => 'themetastic_taxonomy-block_tags',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
    'menu' => 'portfolio-5col',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contexts for ThemeTastic portfolio nodes/views featuring a right sidebar');
  t('themetastic - templates');
  $export['portfolio-sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'services';
  $context->description = 'Contexts for service nodes and views used with the ThemeTastic theme';
  $context->tag = 'themetastic - templates';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'services' => 'services',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'services' => 'services',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-themetastic_services-block_1' => array(
          'module' => 'views',
          'delta' => 'themetastic_services-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-463a00dd691c9b3f7aec5e0adb3b3009' => array(
          'module' => 'views',
          'delta' => '463a00dd691c9b3f7aec5e0adb3b3009',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contexts for service nodes and views used with the ThemeTastic theme');
  t('themetastic - templates');
  $export['services'] = $context;

  return $export;
}
