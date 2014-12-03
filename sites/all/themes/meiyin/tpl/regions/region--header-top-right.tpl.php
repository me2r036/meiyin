<?php

/**
 * @file
 * Default theme implementation to display a region.
 */
?>

<?php if ($content): ?>
	<div class="<?php print $classes; ?>">
		<div class="headerrightwrap">
			<div class="headerrightinner">
				<?php print $content; ?>
			</div>
		</div>
		<div class="clear"></div>
	</div>
<?php endif; ?>