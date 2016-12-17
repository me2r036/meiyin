<?php

/**
 * @file
 * Meiyin's default implementation to display a webform node.
 */

$path = "node/".$node->nid;
$options = array('absolute' => TRUE);
$url = url($path, $options);
?>

<div id="node-<?php print $node->nid; ?>" class="webform singlepost nodate <?php print $classes; ?> clearfix" <?php print $attributes; ?>>
  <?php if(current_path() != $path): ?>
    <h2><a href="<?php print $url; ?>"><?php print $node->title; ?></a></h2>
  <?php endif; ?>

  <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): 
    // Print the page view counter ?>
    <div id="viewcounter"><span class="icon_wrap"><i class="fa fa-eye"></i><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></span></div>
  <?php endif; ?>

  <?php if(!empty($content['field_description'])): ?>
    <div class="field-items webform-description">
      <h4><?php print $node->field_description[LANGUAGE_NONE][0]['value']; ?></h4>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['body'])): ?>
    <div class="field-items webform-body">
      <?php print render($content['body']); ?>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['field_image'])): ?>
    <div class="webform-background-wrapper" style="background:url(<?php print file_create_url($node->field_image[LANGUAGE_NONE][0]['uri']); ?>) no-repeat;">
  <?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_description']);
    hide($content['body']);
    hide($content['field_image']);
    print render($content);
  ?>

  <?php if(!empty($content['field_image'])): ?>
    </div> 
  <?php endif; ?>

  <?php if($node->nid == '47'): ?>
    <!-- Baidu Share -->
    <div class="bdsharebuttonbox">
      <h6>分享到：</h6>
      <a href="#" class="bds_weixin" data-cmd="weixin"></a>
      <a href="#" class="bds_tsina" data-cmd="tsina"></a>
      <a href="#" class="bds_tqq" data-cmd="tqq"></a>
      <a href="#" class="bds_sqq" data-cmd="sqq"></a>
      <a href="#" class="bds_qzone" data-cmd="qzone"></a>
      <a href="#" class="bds_more" data-cmd="more"></a>
    </div>
  <?php endif; ?>
</div>
