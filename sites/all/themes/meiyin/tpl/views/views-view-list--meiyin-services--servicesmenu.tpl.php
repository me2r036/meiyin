<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
$rows_array = $view->style_plugin->rendered_fields;
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
<!-- Responsive menu item -->
    <?php foreach ($rows_array as $id => $row_array): ?>
      <?php if ('/' . request_path() == drupal_get_normal_path($row_array['path'])): ?>
        <?php $classes_array[$id] = 'active'; ?>
      <?php endif; ?>
      <li class="<?php print $classes_array[$id]; ?>">
        <a href= "<?php print $row_array['path']; ?>" target="_self" class="service-menu">
          <div class="serviceicon-menu">
            <div class="<?php print $row_array['field_icon']; ?>"></div>
          </div>
          <h2><?php print $row_array['title']; ?></h2>
          <h5><?php print $row_array['field_subtitle']; ?></h5>
        </a>
      </li>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>
