<?php

/**
 * @file
 * Default theme implementation to display a node.
 */

  /* Query Portfolio Nodes */
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'portfolio');
  $result = $query->execute();

  /* Generate Paginator */
  $nid = $node->nid;
  $first = reset($result['node']);
  $last = end($result['node']);

  switch($nid) {
    case $first->nid: $prev = $last->nid; $next = $nid + 1;	break;
    case $last->nid: $prev = $nid - 1; $next = $first->nid;	break;
    default: $prev = $nid - 1; $next = $nid + 1; break;
  }

  $path = "node/".$node->nid; 
  $options = array('absolute' => TRUE); 
  $url = url($path, $options);
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> blogpost singlepost clearfix"<?php print $attributes; ?>>
  <?php if(current_path() != $path): ?>
    <h2 style="padding-left: 0px;"><a href="<?php print $url; ?>"><?php print $node->title; ?></a></h2>
  <?php endif; ?>
  <div class="post">
    <div class="post-body">

      <?php switch($node->field_template['und'][0]['value']): case 'image': ?>
        <div class="postmedia">
          <img src="<?php print image_style_url('portfolio_fullwidth_1170x468', $node->field_image['und'][0]['uri']); ?>" />
        </div>
        <?php if ($display_submitted): ?>
          <div class="postinfo">
            <div class="author">by <?php print $node->name; ?></div>
            <?php if(!empty($content['field_portfolio_tags'])): ?>
              <div class="categories"><span>in</span> <?php print render($content['field_portfolio_tags']); ?></div>
            <?php endif; ?>
            <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
               <div id="viewcounter"><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></div>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <div class="posttext">
          <?php if(!empty($node->field_project_info['und'][0]['value'])): ?>
            <div class="one_half"><?php print $node->field_project_info['und'][0]['value']; ?></div>
          <?php endif; ?>
          <?php if(!empty($node->body['und'][0]['safe_value'])): ?>
            <?php print $node->body['und'][0]['safe_value']; ?>
          <?php endif; ?>
        </div>
        
        <?php // Add gallelry to the portfolio page ?>
        <div id="gallerywrap">
          <div id="gallery">
            <div class="thumbholder">
              <a class="fancybox" href="<?php print file_create_url($node->field_image['und'][0]['uri']); ?>" data-fancybox-group="gallery<?php print $node->nid; ?>" title="<?php print $title; ?>">
                <img src="<?php print image_style_url('thumbnail', $node->field_image['und'][0]['uri']); ?>" />
                <div class="thumboverlay" style="display: none"></div>
              </a>
            </div>
            <?php if(!empty($node->field_gallery)): ?>
              <?php foreach ($node->field_gallery['und'] as $imageInfo): ?>
                <div class="thumbholder">
                  <a class="fancybox" href="<?php print file_create_url($imageInfo['uri']); ?>" data-fancybox-group="gallery<?php print $node->nid; ?>" title="<?php print $title; ?>">
                    <img src="<?php print image_style_url('thumbnail', $imageInfo['uri']); ?>" />
                    <div class="thumboverlay" style="display: none"></div>
                  </a>
                </div>
              <?php endforeach ?>
            <?php endif ?>
          </div>
        </div>

      <?php break; case 'video': ?>
        <div class="postmedia">
          <div class="scalevid">
            <div class="fluid-width-video-wrapper "style="padding-top: 56.25%;">
              <?php print $node->field_video['und'][0]['safe_value']; ?>
            </div>
          </div>
        </div>
        <?php if ($display_submitted): ?>
          <div class="postinfo">
            <div class="author">by <?php print $node->name; ?></div>
            <?php if(!empty($content['field_portfolio_tags'])): ?>
              <div class="categories"><span>in</span> <?php print render($content['field_portfolio_tags']); ?></div>
            <?php endif; ?>
            <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
               <div id="viewcounter"><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></div>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <div class="posttext">
          <?php if(!empty($node->field_project_info['und'][0]['value'])): ?>
            <div class="one_half"><?php print $node->field_project_info['und'][0]['value']; ?></div>
          <?php endif; ?>
          <?php if(!empty($node->body['und'][0]['safe_value'])): ?>
            <?php print $node->body['und'][0]['safe_value']; ?>
          <?php endif; ?>
        </div>

      <?php break; case 'slider': ?>
        <?php if(!empty($content['field_slider_block'])): ?>
          <div class="postmedia-slide"><?php print render($content['field_slider_block']); ?></div>
        <?php endif;?>
        <?php if ($display_submitted): ?>
          <div class="postinfo">
            <div class="author">by <?php print $node->name; ?></div>
            <?php if(!empty($content['field_portfolio_tags'])): ?>
              <div class="categories"><span>in</span> <?php print render($content['field_portfolio_tags']); ?></div>
            <?php endif; ?>
            <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
               <div id="viewcounter"><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></div>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <div class="posttext">
          <?php if(!empty($node->field_project_info['und'][0]['value'])): ?>
            <div class="one_half"><?php print $node->field_project_info['und'][0]['value']; ?></div>
          <?php endif; ?>
          <?php if(!empty($node->body['und'][0]['safe_value'])): ?>
            <?php print $node->body['und'][0]['safe_value']; ?>
          <?php endif; ?>
        </div>

      <?php break; default: ?>
        <?php if ($display_submitted): ?>
          <div class="postinfo">
            <div class="author">by <?php print $node->name; ?></div>
            <?php if(!empty($content['field_portfolio_tags'])): ?>
              <div class="categories"><span>in</span> <?php print render($content['field_portfolio_tags']); ?></div>
            <?php endif; ?>
            <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
               <div id="viewcounter"><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <div class="content"<?php print $content_attributes; ?>>
          <?php
            // We hide the comments and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
            print render($content);
          ?>
        </div>
        <?php print render($content['links']); ?>
        <?php print render($content['comments']); ?>
      <?php break; endswitch; ?>

      <?php if(current_path() == $path): ?>
        <div class="projectnavwrapper">
          <div id="projectnavwrap">
            <?php if(!empty($content['field_project_link'])): ?>
              <a href="<?php print $content['field_project_link']['#items'][0]['safe_value']; ?>" target="_blank" class="btn btn-primary btn-normal launchbtn"><?php print (t("Launch Project")); ?></a>
            <?php endif; ?>
            <div class="projectnav previousproject" data-rel="tooltip" data-original-title="<?php print(t("Previous Project")); ?>">
              <a href="<?php print url('node/' . $prev, array('absolute' => TRUE)); ?>" rel="prev" rev="next"></a>
            </div>
            <div class="projectnav nextproject" data-rel="tooltip" data-original-title="<?php print (t("Next Project")); ?>">
              <a href="<?php print url('node/' . $next, array('absolute' => TRUE)); ?>" rel="next" rev="prev"></a>
            </div>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>