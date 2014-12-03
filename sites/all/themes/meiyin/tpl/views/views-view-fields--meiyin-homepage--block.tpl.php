<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
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
?>

<?php foreach ($fields as $id => $field): ?>
  <?php if($id == 'field_fancybox'): ?>
  	<div class="mediaholder">
	  	<img src="<?php print image_style_url('isotope_portfolio_400x225', $row->field_field_image[0]['raw']['uri']); ?>" />
	  	<div class="cover"></div>
	  	<?php if(!empty($row->field_field_fancybox[0]['raw']['value'])): ?>
			<a title="<?php print $row->node_title; ?>" href="<?php print file_create_url($row->field_field_image[0]['raw']['uri']); ?>" class="fancybox">
				<div class="show icon-search notalone"></div>
			</a>
			<a href="<?php $options = array('absolute' => TRUE); print url('node/' . $row->nid, $options);?>">
				<div class="link icon-plus notalone"></div>
			</a>
		<?php else: ?>
		<a href="<?php $options = array('absolute' => TRUE); print url('node/' . $row->nid, $options);?>">
			<div class="link icon-plus"></div>
		</a>
		<?php endif; ?>
  	</div>
  <?php endif;?>
	
  <?php if($id != 'field_fancybox' && $id != 'field_image'): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>
    <?php print $field->content; ?>
  <?php print $field->wrapper_suffix; ?>
  <?php endif; ?>
<?php endforeach; ?>