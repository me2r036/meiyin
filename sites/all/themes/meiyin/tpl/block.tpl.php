<?php

/**
 * @file
 * Meiyin's default implementation to display a block.
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <div class="blocktitle">
    <div class="title">
      <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
    </div>
  </div>
<?php endif;?>
  <?php print render($title_suffix); ?>

  <?php print $content ?>
</div>
