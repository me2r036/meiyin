<?php

/**
 * @file
 * Meiyin's default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="row-fluid">
<?php foreach ($rows as $id => $row): ?>
	<?php if(($id % 3 == 0) && $id > 0): ?>
		<?php print ('</div><div class="row-fluid top-divider">'); ?>
	<?php endif; ?>
    <?php print $row; ?>
<?php endforeach; ?>
</div>
