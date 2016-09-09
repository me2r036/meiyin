<?php

/**
 * @file
 * Meiyin's customised theme implementation to display a header-top-right region.
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