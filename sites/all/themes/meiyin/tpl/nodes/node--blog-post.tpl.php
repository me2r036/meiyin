<?php

/**
 * @file
 * Meiyin's default theme implementation to display a blog-post node.
 */

$path = "node/".$node->nid;
$options = array('absolute' => TRUE);
$url = url($path, $options);
?>

<div id="node-<?php print $node->nid; ?>" class="blogpost singlepost nodate <?php print $classes; ?> clearfix" <?php print $attributes; ?>>
		
	<?php if(current_path() != $path): ?>
		<h2><a href="<?php print $url; ?>"><?php print $node->title; ?></a></h2>
	<?php endif; ?>
			
	<?php if(!empty($node->field_template['und'][0]['value'])): ?>
	
		<?php switch($node->field_template['und'][0]['value']): case 'image': ?>
		
		<?php if(!empty($content['field_image'])): ?>
			<div class="postmedia">
				<?php print render($content['field_image']); ?>
			</div>
		<?php endif; ?>
		
		<?php if ($display_submitted): ?>
			<div class="postinfo">
				<div class="time"><?php print format_date($created, 'custom', 'F jS, Y'); ?></div>
				<div class="author">by <?php print $name; ?></div>
				<?php if(!empty($content['field_categories'])): ?>
					<div class="categories"><span>in</span> <?php print render($content['field_categories']); ?></div>
				<?php endif; ?>
				<div class="comments"><?php print $comment_count; ?> comments</div>
				<?php if(!empty($content['field_tags'])): ?>
					<div class="tags"><span>tagged:</span> <?php print render($content['field_tags']); ?></div>
				<?php endif; ?>
                <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
                  <div id="viewcounter"><span class="icon_wrap"><i class="fa fa-eye"></i><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></span></div>
                <?php endif; ?>
			</div>
		<?php endif; ?>
		
		<div class="posttext">
			<?php print $node->body['und'][0]['safe_value']; ?>
		</div>
	
		<?php break; case 'video': ?>
	
		<?php if(!empty($content['field_video'])): ?>
			<div class="postmedia">
				<div class="scalevid">
					<?php print render($content['field_video']); ?>
				</div>
			</div>
		<?php endif; ?>
		
		<?php if ($display_submitted): ?>
			<div class="postinfo">
				<div class="time"><?php print format_date($created, 'custom', 'F jS, Y'); ?></div>
				<div class="author">by <?php print $name; ?></div>
				<div class="categories"><span>in</span> <?php print render($content['field_categories']); ?></div>
				<div class="comments"><?php print $comment_count; ?> comments</div>
				<?php if(!empty($content['field_tags'])): ?>
					<div class="tags"><span>tagged:</span> <?php print render($content['field_tags']); ?></div>
				<?php endif; ?>
                <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
                  <div id="viewcounter"><span class="icon_wrap"><i class="fa fa-eye"></i><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></span></div>
                <?php endif; ?>
			</div>
		<?php endif; ?>
		
		<div class="posttext">
			<?php print $node->body['und'][0]['safe_value']; ?>
		</div>
	
		<?php break; case 'slider': ?>
		
		<?php if(!empty($content['field_slider_block'])): ?>
			<div class="postmedia-slide">
				<?php print render($content['field_slider_block']); ?>
			</div>
		<?php endif;?>
		
		<?php if ($display_submitted): ?>
			<div class="postinfo">
				<div class="time"><?php print format_date($created, 'custom', 'F jS, Y'); ?></div>
				<div class="author">by <?php print $name; ?></div>
				<div class="categories"><span>in</span> <?php print render($content['field_categories']); ?></div>
				<div class="comments"><?php print $comment_count; ?> comments</div>
				<?php if(!empty($content['field_tags'])): ?>
					<div class="tags"><span>tagged:</span> <?php print render($content['field_tags']); ?></div>
				<?php endif; ?>
                <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
                  <div id="viewcounter"><span class="icon_wrap"><i class="fa fa-eye"></i><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></span></div>
                <?php endif; ?>
			</div>
		<?php endif; ?>
		
		<div class="posttext">
			<?php print $node->body['und'][0]['safe_value']; ?>
		</div>
	
		<?php break; endswitch; ?>
		
	<?php else: ?>

		<!-- Default Settings -->
		<?php if ($display_submitted): ?>
			<div class="postinfo">
				<div class="time"><?php print format_date($created, 'custom', 'F jS, Y'); ?></div>
				<div class="author">by <?php print $name; ?></div>
				<div class="categories"><span>in</span> <?php print render($content['field_categories']); ?></div>
				<div class="comments"><?php print $comment_count; ?> comments</div>
				<?php if(!empty($content['field_tags'])): ?>
					<div class="tags"><span>tagged:</span> <?php print render($content['field_tags']); ?></div>
				<?php endif; ?>
                <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
                  <div id="viewcounter"><span class="icon_wrap"><i class="fa fa-eye"></i><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></span></div>
                <?php endif; ?>
			</div>
		<?php endif; ?>
	
		<?php
		// We hide the comments and links now so that we can render them later.
			hide($content['comments']);
			hide($content['links']);
			print render($content);
		?>

	<?php endif; ?>
	
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
