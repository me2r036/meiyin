<?php

/**
 * @file
 * Meiyin's default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

$fancybox = array_key_exists('field_fancybox', $fields);
?>

<?php foreach($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php if($id == 'field_fancybox'): ?>
    <div class="mediaholder">
      <picture>
        <!--[if IE 9]><video style="display: none;"><![endif]-->
        <source srcset="<?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_wide_1x', $row->field_field_image[0]['raw']['uri']); ?> 1x" media="(min-width: 1200px)">
        <source srcset="<?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_normal_1x', $row->field_field_image[0]['raw']['uri']); ?> 1x, <?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_normal_2x', $row->field_field_image[0]['raw']['uri']); ?> 2x" media="(min-width: 980px)">
        <source srcset="<?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_narrow_1x', $row->field_field_image[0]['raw']['uri']); ?> 1x, <?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_narrow_2x', $row->field_field_image[0]['raw']['uri']); ?> 2x" media="(min-width: 768px)">
        <source srcset="<?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_tablet_1x', $row->field_field_image[0]['raw']['uri']); ?> 1x, <?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_tablet_2x', $row->field_field_image[0]['raw']['uri']); ?> 2x" media="(min-width: 480px)">
        <source srcset="<?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_mobile_1x', $row->field_field_image[0]['raw']['uri']); ?> 1x, <?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_mobile_2x', $row->field_field_image[0]['raw']['uri']); ?> 2x" media="(min-width: 0px)">
        <!--[if IE 9]></video><![endif]-->
        <img src="<?php print image_style_url('portfolio_isotope_thumbnail_breakpoints_theme_meiyin_wide_1x', $row->field_field_image[0]['raw']['uri']); ?>" name="gallery-cover" />
      </picture>
      <?php if(!empty($row->field_field_fancybox[0]['raw']['value'])): ?>
        <a class="fancybox" href="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-wide_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-normal_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_1x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-normal_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_2x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-narrow_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_1x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-narrow_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_2x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-tablet_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_1x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-tablet_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_2x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-mobile_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_1x', $row->field_field_image[0]['raw']['uri']); ?>" data-href-mobile_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_2x', $row->field_field_image[0]['raw']['uri']); ?>" data-fancybox-group="gallery<?php print $row->nid; ?>" title="<?php print $row->node_title; ?>">
          <div class="show fa fa-photo fa-lg notalone"></div>
        </a>
        <a href="<?php $options = array('absolute' => TRUE); print url('node/' . $row->nid, $options);?>">
          <div class="link fa fa-link fa-lg notalone"></div>
        </a>

        <!-- Add images in the field_gallery to fancybox -->
        <?php $galleryArray = $row->_field_data[nid][entity]->field_gallery; ?>
        <?php if(!empty($galleryArray)): ?>
          <?php foreach($galleryArray[LANGUAGE_NONE] as $imageInfo): ?>
            <a class="fancybox" href="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $imageInfo['uri']); ?>" data-href-wide_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $imageInfo['uri']); ?>" data-href-normal_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_1x', $imageInfo['uri']); ?>" data-href-normal_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_2x', $imageInfo['uri']); ?>" data-href-narrow_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_1x', $imageInfo['uri']); ?>" data-href-narrow_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_2x', $imageInfo['uri']); ?>" data-href-tablet_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_1x', $imageInfo['uri']); ?>" data-href-tablet_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_2x', $imageInfo['uri']); ?>" data-href-mobile_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_1x', $imageInfo['uri']); ?>" data-href-mobile_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_2x', $imageInfo['uri']); ?>" data-fancybox-group="gallery<?php print $row->nid; ?>" title="<?php print $row->node_title; ?>"></a>
          <?php endforeach; ?>
        <?php endif; ?>
        <a class="fancybox" href="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_wide_1x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-wide_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_wide_1x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-normal_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_normal_1x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-normal_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_normal_2x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-narrow_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_narrow_1x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-narrow_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_narrow_2x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-tablet_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_tablet_1x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-tablet_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_tablet_2x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-mobile_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_mobile_1x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-href-mobile_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_mobile_2x', $row->field_field_back_cover[0]['raw']['uri']); ?>" data-fancybox-group="gallery<?php print $row->nid; ?>" title="<?php print $row->node_title; ?>"></a>

      <?php else: ?>
        <a href="<?php $options = array('absolute' => TRUE); print url('node/' . $row->nid, $options);?>">
          <div class="link fa fa-link fa-lg"></div>
        </a>
      <?php endif; ?>
    </div>
  <?php elseif (($fancybox && $id != 'field_image') || !$fancybox): ?>
    <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>
    <?php print $field->content; ?>
    <?php print $field->wrapper_suffix; ?>
  <?php endif; ?>
<?php endforeach; ?>
