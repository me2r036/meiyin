<?php

/**
 * @file
 * Meiyin's default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['featured']: Items for the featured region.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['triptych_first']: Items for the first triptych.
 * - $page['triptych_middle']: Items for the middle triptych.
 * - $page['triptych_last']: Items for the last triptych.
 * - $page['footer_firstcolumn']: Items for the first footer column.
 * - $page['footer_secondcolumn']: Items for the second footer column.
 * - $page['footer_thirdcolumn']: Items for the third footer column.
 * - $page['footer_fourthcolumn']: Items for the fourth footer column.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 * @see html.tpl.php
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
				<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="logo">
				  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
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
					<div class="icon-menu"></div>
					<form id="responsive-menu" action="#" method="post">
						<select></select>
					</form>
				</div>
				<?php endif; ?>
			</div>
		</section>
	</header>
	
	<?php if ($page['header']): ?>
		<?php print render($page['header']); ?>
	<?php endif; ?>

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
