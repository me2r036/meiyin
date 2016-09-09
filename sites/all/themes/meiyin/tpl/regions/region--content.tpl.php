<?php

/**
 * @file
 * Meiyin's default theme implementation to display a content region.
 */
?>

<?php if ($content): ?>
  <div class="<?php print $classes; ?>">
    <?php if ($tabs): ?>
    <div class="tabs clearfix">
      <?php print render($tabs); ?>
    </div>
    <?php endif; ?>
  
    <?php print $messages; ?>
  
    <a id="main-content"></a>
  
    <?php print render($page['help']); ?>
    <?php if ($action_links): ?>
    <ul class="action-links">
      <?php print render($action_links); ?>
    </ul>
    <?php endif; ?>
  
    <?php print $content; ?>
  </div>
<?php endif; ?>
