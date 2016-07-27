<?php

/**
 * @file
 * Meiyin's default theme implementation to display a portfolio node.
 */

?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> blogpost singlepost clearfix"<?php print $attributes; ?>>
  <?php if(current_path() != $path): ?>
    <h2 style="padding-left: 0px;"><a href="<?php print $url; ?>"><?php print $node->title; ?></a></h2>
  <?php endif; ?>
  <div class="post">
    <div class="post-body">

      <?php switch($node->field_template[LANGUAGE_NONE][0]['value']): case 'image': ?>
        <div class="postmedia">
          <?php print render($content['field_image']); ?>
        </div>
        <?php break; case 'video': ?>
          <div class="postmedia">
            <div class="scalevid">
              <?php print render($content['field_video']); ?>
            </div>
          </div>
        <?php break; case 'slider': ?>
          <?php if(!empty($content['field_slider_block'])): ?>
            <div class="postmedia-slide"><?php print render($content['field_slider_block']); ?></div>
          <?php endif;?>
        <?php break; default: ?>
      <?php break; endswitch; ?>

      <!-- Portfolio info starts here -->
      <div class="postinfo">
        <?php if ($display_submitted): ?>
          <div class="author">by <?php print $node->name; ?></div>
        <?php endif; ?>

        <?php if(!empty($content['field_portfolio_tags'])): ?>
          <div class="tags"><span>in</span><?php print render($content['field_portfolio_tags']); ?></div>
        <?php endif; ?>
        <?php if(!empty($content['field_tags'])): ?>
          <div class="tags"><span>of</span><?php print render($content['field_tags']); ?></div>
        <?php endif; ?>
        <?php if(!empty($content['links']['statistics']['#links']['statistics_counter'])): // Print the page view counter ?>
          <div id="viewcounter"><span class="icon_wrap"><i class="fa fa-eye"></i><?php print $content['links']['statistics']['#links']['statistics_counter']['title']; ?></span></div>
        <?php endif; ?>
      </div>

      <div class="posttext">
        <div class="one_half">
          <div class="contenttable">
            <table>
              <tbody>
                <tr><td class="partner-subject"><h5>Flower Art / 花艺:</h5></td><td><?php print $node->field_flower_art[LANGUAGE_NONE][0]['entity']->title; ?></td></tr>
                <tr><td class="partner-subject"><h5>Makeup / 跟妆:</h5></td><td><?php print $node->field_makeup[LANGUAGE_NONE][0]['entity']->title; ?></td></tr>
                <tr><td class="partner-subject"><h5>Photography / 摄影:</h5></td><td><?php print $node->field_photography[LANGUAGE_NONE][0]['entity']->title; ?></td></tr>
                <tr><td class="partner-subject"><h5>Camera Shooting / 摄像:</h5></td><td><?php print $node->field_camera_shooting[LANGUAGE_NONE][0]['entity']->title; ?></td></tr>
              </tbody>
            </table>
          </div>
        </div>

        <!-- Show involved parners' logo -->
        <div class="contenttable-logo one_half lastcolumn">
          <table>
            <tbody>
              <tr>
                <td><?php print $partner_flower_art; ?></td>
                <td><?php print $partner_makeup; ?></td>
                <td><?php print $partner_photography; ?></td>
                <td><?php print $partner_camera_shooting; ?></td>
              </tr>
            </tbody>
          </table>
        </div>

        <?php if(!empty($content['body'])): ?>
          <?php print render($content['body']); ?>
        <?php endif; ?>
        <?php if(!empty($content['field_company_info'])): ?>
          <?php print render($content['field_company_info']); ?>
        <?php endif; ?>
      </div>

      <!-- Add fancybox gallery to the portfolio page, regardless of the template is image, video or slider. -->
      <div id="gallerywrap">
        <div id="gallery">
          <div class="thumbholder">
            <a class="fancybox" href="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-wide_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-normal_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-normal_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-narrow_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-narrow_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-tablet_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-tablet_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-mobile_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-href-mobile_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" data-fancybox-group="gallery<?php print $node->nid; ?>" title="<?php print $title; ?>">
              <picture>
                <!--[if IE 9]><video style="display: none;"><![endif]-->
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_wide_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 1x" media="(min-width: 1200px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_normal_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_normal_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 980px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_narrow_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_narrow_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 768px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_tablet_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_tablet_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 480px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_mobile_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_mobile_2x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 0px)">
                <!--[if IE 9]></video><![endif]-->
                <img src="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_wide_1x', $node->field_image[LANGUAGE_NONE][0]['uri']); ?>" name="gallery-cover" />
              </picture>
              <div class="thumboverlay"></div>
            </a>
          </div>
          <?php if (!empty($node->field_gallery)): ?>
            <?php $i = 0; $holder_class = 'thumbholder'; ?>
            <?php foreach ($node->field_gallery[LANGUAGE_NONE] as $imageInfo): ?>
              <?php if ( $i > 6): ?>
                <?php $holder_class = 'thumbholder hide'; ?>
              <?php endif; ?>
              <div class="<?php print $holder_class; ?>">
                <a class="fancybox" href="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $imageInfo['uri']); ?>" data-href-wide_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_wide_1x', $imageInfo['uri']); ?>" data-href-normal_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_1x', $imageInfo['uri']); ?>" data-href-normal_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_normal_2x', $imageInfo['uri']); ?>" data-href-narrow_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_1x', $imageInfo['uri']); ?>" data-href-narrow_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_narrow_2x', $imageInfo['uri']); ?>" data-href-tablet_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_1x', $imageInfo['uri']); ?>" data-href-tablet_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_tablet_2x', $imageInfo['uri']); ?>" data-href-mobile_1x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_1x', $imageInfo['uri']); ?>" data-href-mobile_2x="<?php print image_style_url('portfolio_markedwhite_breakpoints_theme_meiyin_mobile_2x', $imageInfo['uri']); ?>" data-fancybox-group="gallery<?php print $node->nid; ?>" title="<?php print $title; ?>">
                  <picture>
                    <!--[if IE 9]><video style="display: none;"><![endif]-->
                    <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_wide_1x', $imageInfo['uri']); ?> 1x" media="(min-width: 1200px)">
                    <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_normal_1x', $imageInfo['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_normal_2x', $imageInfo['uri']); ?> 2x" media="(min-width: 980px)">
                    <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_narrow_1x', $imageInfo['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_narrow_2x', $imageInfo['uri']); ?> 2x" media="(min-width: 768px)">
                    <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_tablet_1x', $imageInfo['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_tablet_2x', $imageInfo['uri']); ?> 2x" media="(min-width: 480px)">
                    <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_mobile_1x', $imageInfo['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_mobile_2x', $imageInfo['uri']); ?> 2x" media="(min-width: 0px)">
                    <!--[if IE 9]></video><![endif]-->
                    <img src="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_wide_1x', $imageInfo['uri']); ?>" />
                  </picture>
                  <div class="thumboverlay"></div>
                </a>
              </div>
              <?php $i++; ?>
            <?php endforeach ?>
          <?php endif ?>
          <div class="thumbholder hide">
            <a class="fancybox" href="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_wide_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-wide_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_wide_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-normal_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_normal_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-normal_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_normal_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-narrow_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_narrow_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-narrow_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_narrow_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-tablet_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_tablet_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-tablet_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_tablet_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-mobile_1x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_mobile_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-href-mobile_2x="<?php print image_style_url('portfolio_breakpoints_theme_meiyin_mobile_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" data-fancybox-group="gallery<?php print $node->nid; ?>" title="<?php print $title; ?>">
              <picture>
                <!--[if IE 9]><video style="display: none;"><![endif]-->
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_wide_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 1x" media="(min-width: 1200px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_normal_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_normal_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 980px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_narrow_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_narrow_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 768px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_tablet_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_tablet_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 480px)">
                <source srcset="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_mobile_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 1x, <?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_mobile_2x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?> 2x" media="(min-width: 0px)">
                <!--[if IE 9]></video><![endif]-->
                <img src="<?php print image_style_url('portfolio_gallery_thumbnail_breakpoints_theme_meiyin_wide_1x', $node->field_back_cover[LANGUAGE_NONE][0]['uri']); ?>" />
              </picture>
              <div class="thumboverlay"></div>
            </a>
          </div>
        </div>
      </div>

      <?php if(current_path() == $path): ?>
        <div class="projectnavwrapper">
          <div id="projectnavwrap">
            <?php if(!empty($content['field_project_link'])): ?>
              <a href="<?php print $content['field_project_link']['#items'][0]['safe_value']; ?>" target="_blank" class="btn btn-primary btn-normal launchbtn">
                <span class="icon_wrap"><i class="fa fa-camera"></i><?php print (t("Launch Project")); ?></span>
              </a>
            <?php endif; ?>
            <div class="projectnav previousproject" data-rel="tooltip" data-original-title="<?php print(t("Previous Project")); ?>">
              <a href="<?php print url('node/' . $prev, array('absolute' => TRUE)); ?>" rel="prev" rev="next"></a>
            </div>
            <div class="projectnav nextproject" data-rel="tooltip" data-original-title="<?php print (t("Next Project")); ?>">
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
      <?php endif; ?>
      <div class="divider"></div>
    </div>
  </div>
</div>
