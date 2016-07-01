<?php

/**
 * @file
 * Meiyin's default theme implementation to display a blog-post node.
 */

  /* Query Blog Post Nodes */
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'blog_post')
        ->propertyOrderBy('created', 'DESC');
  $result = $query->execute();

  /* Generate Paginator */
  $nid = $node->nid;
  $last = end($result['node']);
  $first = reset($result['node']);

  switch($nid) {
    case $first->nid:
      $prev = $last->nid;
      $next = next($result['node'])->nid;
      break;
    case $last->nid:
      end($result['node']);
      $prev = prev($result['node'])->nid;
      $next = $first->nid;
      break;
    default:
      while(list($key, ) = each($result['node'])){
        if($key == $nid){
          $next = current($result['node'])->nid;
          prev($result['node']);
          $prev = prev($result['node'])->nid;
          break;
        }
      }
  }

  $path = "node/".$node->nid;
  $options = array('absolute' => TRUE);
  $url = url($path, $options);
?>

<div id="node-<?php print $node->nid; ?>" class="blogpost singlepost nodate <?php print $classes; ?> clearfix" <?php print $attributes; ?>>

  <?php if(current_path() != $path): ?>
    <h2><a href="<?php print $url; ?>"><?php print $node->title; ?></a></h2>
  <?php endif; ?>
  
  <?php if(!empty($node->field_template[LANGUAGE_NONE][0]['value'])): ?>

    <?php switch($node->field_template[LANGUAGE_NONE][0]['value']): case 'image': ?>
      <?php if(!empty($content['field_image'])): ?>
        <div class="postmedia"><?php print render($content['field_image']); ?></div>
      <?php endif; ?>

      <?php break; case 'video': ?>
        <?php if(!empty($content['field_video'])): ?>
          <div class="postmedia">
            <div class="scalevid">
              <?php print render($content['field_video']); ?>
            </div>
          </div>
        <?php endif; ?>

      <?php break; case 'slider': ?>
        <?php if(!empty($content['field_slider_block'])): ?>
          <div class="postmedia-slide">
            <?php print render($content['field_slider_block']); ?>
          </div>
        <?php endif;?>
      <?php break; endswitch; ?>

  <?php else: ?>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  <?php endif; ?>

  <!-- Blog post info starts here -->
  <div class="postinfo">
    <?php if ($display_submitted): ?>
      <div class="time"><?php print format_date($created, 'custom', 'Y年Md日'); ?></div>
    <?php endif; ?>

    <div class="categories"><span>in</span><?php print render($content['field_categories']); ?></div>
    <div class="comments"><?php print $comment_count; $comment_count < 2 ? print ' comment' : print 'comments';?></div>    
    <?php if(!empty($content['field_tags'])): ?>
      <div class="tags"><span>of</span> <?php print render($content['field_tags']); ?></div>
    <?php endif; ?>

    <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
      <div id="viewcounter"><span class="icon_wrap"><i class="fa fa-eye"></i><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></span></div>
    <?php endif; ?>
  </div>

  <div class="posttext">
    <?php print $node->body[LANGUAGE_NONE][0]['safe_value']; ?>
  </div>

  <div class="projectnavwrapper">
    <div id="projectnavwrap">
      <div class="projectnav previousproject" data-rel="tooltip" data-original-title="<?php print(t("Previous Blog")); ?>">
        <a href="<?php print url('node/' . $prev, array('absolute' => TRUE)); ?>" rel="prev" rev="next"></a>
      </div>
      <div class="projectnav nextproject" data-rel="tooltip" data-original-title="<?php print (t("Next Blog")); ?>">
        <a href="<?php print url('node/' . $next, array('absolute' => TRUE)); ?>" rel="next" rev="prev"></a>
      </div>
    </div>
    <div class="bdsharebuttonbox">
      <h6>分享到：</h6>
      <a href="#" class="bds_weixin" data-cmd="weixin"></a>
      <a href="#" class="bds_tsina" data-cmd="tsina"></a>
      <a href="#" class="bds_tqq" data-cmd="tqq"></a>
      <a href="#" class="bds_sqq" data-cmd="sqq"></a>
      <a href="#" class="bds_qzone" data-cmd="qzone"></a>
      <a href="#" class="bds_more" data-cmd="more"></a>
    </div>
  </div>
</div>
