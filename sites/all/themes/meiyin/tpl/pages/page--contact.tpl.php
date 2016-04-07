<?php

/**
 * @file
 * Meiyin's default theme implementation to display contact page.
 */
?>

<?php if($layoutWidth == 'boxedlayout'): ?>
	<section class="allwrapper boxed">
<?php else: ?>
	<section class="allwrapper">
<?php endif; ?>

	<header>
	<?php if($page['header_top_left'] || $page['header_top_right']): ?>
		<?php if($layoutWidth == 'boxedlayout'):?>
			<section class="headertopwrap boxed">
		<?php else: ?>
			<section class="headertopwrap">
		<?php endif; ?>
			<div class="headertop">
				<div class="row">
					<?php if($page['header_top_left']): ?>
						<?php print render($page['header_top_left']); ?>
					<?php endif; ?>
					<?php if($page['header_top_right']): ?>
						<?php print render($page['header_top_right']); ?>
					<?php endif; ?>
					</div><!-- /.row -->
				</div><!-- /.headertop -->
			</section><!-- /.headertopwrap -->
		<?php endif; ?>
		<section class="headerwrap">
			<div class="header span12">
				<?php if ($logo): ?>
					<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
						<picture>
							<!--[if IE 9]><video style="display: none;"><![endif]-->
							<source srcset="<?php print ($GLOBALS['base_url'] . '/' . drupal_get_path('theme', 'meiyin') . '/logo.png'); ?> 1x, <?php print ($GLOBALS['base_url'] . '/' . drupal_get_path('theme', 'meiyin') . '/logo@2x.png'); ?> 2x" media="(min-width: 0px)">
							<!--[if IE 9]></video><![endif]-->
							<img src="<?php print ($GLOBALS['base_url'] . '/' . drupal_get_path('theme', 'meiyin') . '/logo.png'); ?>" alt="<?php print t('Home'); ?>">
						</picture>
					</a>
				<?php endif; ?>

				<?php if ($site_name || $site_slogan): ?>
				<div id="name-and-slogan">
					<?php if ($site_name): ?>
					<?php if ($title): ?>
					<div id="site-name">
						<strong> <a href="<?php print $front_page; ?>"
							title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?>
							</span> </a>
						</strong>
					</div>
					<?php else: /* Use h1 when the content title is empty */ ?>
					<h1 id="site-name">
						<a href="<?php print $front_page; ?>"
							title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?>
						</span> </a>
					</h1>
					<?php endif; ?>
					<?php endif; ?>

					<?php if ($site_slogan): ?>
					<div id="site-slogan">
						<?php print $site_slogan; ?>
					</div>
					<?php endif; ?>
				</div><!-- /#name-and-slogan -->
				<?php endif; ?>

				<?php if ($main_menu || $secondary_menu): ?>
				<nav class="mainmenu">
					<div id="mainmenu" class="menu ddsmoothmenu">
						<?php $menu_name = variable_get('menu_main_links_source', 'main-menu'); $tree = menu_tree($menu_name); print drupal_render($tree); ?>
						<?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
					</div>
					<div class="headersearch">
						<?php print $search_form; ?>
					</div>
				</nav><!-- /#navigation -->
				
				<div class="row mobilemenu">
					<div class="icon-menu"><i class="fa fa-bars"></i></div>
					<form id="responsive-menu" action="#" method="post" accept-charset="UTF-8">
						<select></select>
					</form>
				</div>
				<?php endif; ?>
			</div>
		</section>
	</header>

	<?php if(!drupal_is_front_page()): ?>
		<?php if($layoutWidth == 'boxedlayout'): ?>
			<section class="pagetitlewrap boxed">
		<?php else: ?>
			<section class="pagetitlewrap">
		<?php endif; ?>
			<div class="row pagetitle">
				<?php print render($title_prefix); ?>
				<?php if ($title): ?>
				<h1 class="title" id="page-title"><?php print $title; ?></h1>
				<?php endif; ?>
				<?php print render($title_suffix); ?>
				<?php if ($breadcrumb): ?>
					<?php print $breadcrumb; ?>
				<?php endif; ?>
			</div>
			<div class="clearfix"></div>
		</section>
	<?php endif; ?>

	<section id="firstcontentcontainer" class="container">
	
		<section id="map" class="map" data-lat="<?php print theme_get_setting('latitude'); ?>" data-lon="<?php print theme_get_setting('longitude'); ?>"> </section>
			
		<?php if ($page['prescript_first'] || $page['prescript_second'] || $page['prescript_third'] || $page['prescript_fourth']): ?>
			<section id="prescript" class="container">
				<div class="row">
					<?php if ($page['prescript_first']): ?>
						<?php print render($page['prescript_first']); ?>
					<?php endif; ?>
					<?php if ($page['prescript_second']): ?>
						<?php print render($page['prescript_second']); ?>
					<?php endif; ?>
					<?php if ($page['prescript_third']): ?>
						<?php print render($page['prescript_third']); ?>
					<?php endif; ?>
					<?php if ($page['prescript_fourth']): ?>
						<?php print render($page['prescript_fourth']); ?>
					<?php endif; ?>
				</div><!-- /.row -->
			</section><!-- /#prescript -->
		<?php endif; ?>
	
		<div class="row-fluid">
			<?php if ($page['sidebar_first']): ?>
				<?php print render($page['sidebar_first']); ?>
			<?php endif; ?>

			<?php print render($page['content']); ?>

			<?php if ($page['sidebar_second']): ?>
				<?php print render($page['sidebar_second']); ?>
			<?php endif; ?>
		</div><!-- /.row-fluid -->
		
		<?php if ($page['postscript_first'] || $page['postscript_second'] || $page['postscript_third'] || $page['postscript_fourth']): ?>
			<section id="postscript" class="container">
				<div class="row">
					<?php if ($page['postscript_first']): ?>
					<?php print render($page['postscript_first']); ?>
					<?php endif; ?>
					<?php if ($page['postscript_second']): ?>
					<?php print render($page['postscript_second']); ?>
					<?php endif; ?>
					<?php if ($page['postscript_third']): ?>
					<?php print render($page['postscript_third']); ?>
					<?php endif; ?>
					<?php if ($page['postscript_fourth']): ?>
					<?php print render($page['postscript_fourth']); ?>
					<?php endif; ?>
				</div><!-- /.row -->
			</section><!-- /#postscript -->
		<?php endif; ?>
	</section><!-- /#main -->
</section>
<!-- /#page -->

<footer>
	<?php if($layoutWidth == 'boxedlayout'): ?>
		<section class="footerwrap">
	<?php else: ?>
		<section class="footerwrap wide">	
	<?php endif; ?>
		<section class="footer">
			<div class="row">
				<?php if ($page['footer_first']): ?>
					<?php print render($page['footer_first']); ?>
				<?php endif; ?>
				<?php if ($page['footer_second']): ?>
					<?php print render($page['footer_second']); ?>
				<?php endif; ?>
				<?php if ($page['footer_third']): ?>
					<?php print render($page['footer_third']); ?>
				<?php endif; ?>
				<?php if ($page['footer_fourth']): ?>
					<?php print render($page['footer_fourth']); ?>
				<?php endif; ?>
			</div>
		</section>
		<?php if ($page['footer_fifth'] || $page['footer_sixth']): ?>
			<section class="subfooterwrap wide">
					<div class="subfooter">
						<div class="row">
							<?php if($page['footer_fifth']): ?>
								<?php print render($page['footer_fifth']); ?>
							<?php endif; ?>
							<?php if($page['footer_sixth']): ?>
								<?php print render($page['footer_sixth']); ?>
							<?php endif; ?>
						</div>
					</div>
				</section>
		<?php endif; ?>
	</section>
</footer>
<!-- /#footer -->

<script type="text/javascript" src="http://www.google.cn/maps/api/js?v=3&sensor=false"></script>
