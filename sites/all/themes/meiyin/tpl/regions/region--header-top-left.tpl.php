<?php

/**
 * @file
 * Meiyin's customised theme implementation to display a header-top-left region.
 */
?>

<?php if ($content): ?>
  <div class="<?php print $classes; ?>">
    <div class="headerleftwrap">
      <div class="headerleftinner">
        <?php print $content; ?>
      </div>
    </div>
    <div class="clear"></div>
  </div>
<?php endif; ?>