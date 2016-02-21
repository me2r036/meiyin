<?php

/**
 * @file
 * Meiyin's default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$view->current_display == "feedbacksidebar" ? $sidebar = true : $sidebar = false;
$rows_array = $view->style_plugin->rendered_fields;
?>

<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<div class="row-fluid">
  <div class="span12">
    <div class="carousel slide" id="testimonials">
      <div class="carousel-inner">
      <?php $item_class = "item active"; ?>
      <?php foreach($rows_array as $key=>$row_array) : ?>
        <div class="<?php print $item_class; ?>">
          <div class="padded clearfix">
            <?php if(!$sidebar): ?>
              <div class="span9"><i class="fa fa-quote-left fa-lg"></i><?php print $row_array['field_description']; ?></div>
              <div class="span3">
                <cite>
                  <ul>
                    <li><?php print $row_array['field_image']; ?></li>
                    <li><?php print $row_array['field_customer']; ?></li>
                    <li><?php print $row_array['field_subtitle']; ?></li>
                  </ul>
                </cite>
              </div>
            <?php else: ?>
              <i class="fa fa-quote-left fa-lg"></i><?php print $row_array['field_description']; ?>
              <cite>
                <ul style="margin-top: 15px;">
                  <li><?php print $row_array['field_image']; ?></li>
                  <li><?php print $row_array['field_customer']; ?></li>
                  <li><?php print $row_array['field_subtitle']; ?></li>
                </ul>
              </cite>          
            <?php endif; ?>
          </div>
        </div>
        <?php $item_class = "item"; ?>
      <?php endforeach; ?>
      </div>
      <?php if(count($rows_array) > 1): ?>
        <a class="carousel-control left" href="#testimonials" data-slide="prev">‹</a><a class="carousel-control right" href="#testimonials" data-slide="next">›</a>
      <?php endif; ?>
    </div>
  </div>
</div>