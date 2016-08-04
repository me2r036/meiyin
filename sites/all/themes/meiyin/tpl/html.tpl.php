<?php

/**
 * @file
 * Meiyin's default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */

?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<!--西安婚庆 西安婚庆公司 西安婚礼策划 西安婚庆网 婚庆网站
                         _         _                     
       ____ ___   ___   (_)__  __ (_)____     _____ ____ 
      / __ `__ \ / _ \ / // / / // // __ \   / ___// __ \
     / / / / / //  __// // /_/ // // / / /_ / /__ / /_/ /
    /_/ /_/ /_/ \___//_/ \__, //_//_/ /_/(_)\___/ \____/ 
                        /____/                           
    =====================================================
                                    美音婚礼 | meiyin.co - tell the differences
                                    Technical support: http://meiyin.co/contact
-->
<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php if(theme_get_setting('responsive') == 1): ?>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php endif; ?>
<!-- 美音婚礼 | meiyin.co
  <?php if(theme_get_setting('iphoneRegularIcon') != NULL): ?>
  <link rel="apple-touch-icon" href="<?php print file_create_url(file_load(theme_get_setting('iphoneRegularIcon'))->uri); ?>">
  <?php endif; ?>
  <?php if(theme_get_setting('ipadRegularIcon') != NULL): ?>
  <link rel="apple-touch-icon" sizes="72x72" href="<?php print file_create_url(file_load(theme_get_setting('ipadRegularIcon'))->uri); ?>">
  <?php endif; ?>
  <?php if(theme_get_setting('appleRetinaIcon') != NULL): ?>
  <link rel="apple-touch-icon" sizes="114x114" href="<?php print file_create_url(file_load(theme_get_setting('appleRetinaIcon'))->uri); ?>">
  <?php endif; ?> tell the differences, from here -->
  <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-57x57.png"/>
  <link rel="apple-touch-icon" sizes="60x60" href="/apple-touch-icon-60x60.png"/>
  <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-72x72.png"/>
  <link rel="apple-touch-icon" sizes="76x76" href="/apple-touch-icon-76x76.png"/>
  <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114x114.png"/>
  <link rel="apple-touch-icon" sizes="120x120" href="/apple-touch-icon-120x120.png"/>
  <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144x144.png"/>
  <link rel="apple-touch-icon" sizes="152x152" href="/apple-touch-icon-152x152.png"/>
  <link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon-180x180.png"/>
  <link rel="icon" type="image/png" href="/favicon-32x32.png" sizes="32x32"/>
  <link rel="icon" type="image/png" href="/favicon-194x194.png" sizes="194x194"/>
  <link rel="icon" type="image/png" href="/favicon-96x96.png" sizes="96x96"/>
  <link rel="icon" type="image/png" href="/android-chrome-192x192.png" sizes="192x192"/>
  <link rel="icon" type="image/png" href="/favicon-16x16.png" sizes="16x16"/>
  <link rel="manifest" href="/manifest.json"/>
  <link rel="mask-icon" href="/safari-pinned-tab.svg" color="#ff5165"/>
  <meta name="apple-mobile-web-app-title" content="美音婚礼"/>
  <meta name="application-name" content="美音婚礼"/>
  <meta name="msapplication-TileColor" content="#b91d47"/>
  <meta name="msapplication-TileImage" content="/mstile-144x144.png"/>
  <meta name="theme-color" content="#ffffff"/>
  <?php print $styles; ?>
  <?php print $scripts; ?>
    <!--[if lt IE 9]>
      <link rel="stylesheet" href="<?php print drupal_get_path('theme', 'meiyin') . '/css/ie8.css'; ?>" type="text/css" media="all" />
      <script src="<?php print drupal_get_path('theme', 'meiyin') . '/js/html5shiv.min.js'; ?>"</script>
    <![endif]--> 
  
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <!-- Add QR codes layers -->
  <div id="meiyin-wechat-qr-code" style="display:none">
    <div class="qr-code-caption">扫一扫添加 <span class="highlight">美音婚礼™ 官方客服</span></div>
    <div class="qr-code-image-contact"><?php print $qr_code_wechat; ?></div>
  </div>
  <div id="meiyin-vcard-qr-code" style="display:none">
    <div class="qr-code-caption">扫一扫快速添加 <span class="highlight">美音婚礼™ 到手机联系人</span></div>
    <div class="qr-code-image-contact"><?php print $qr_code_vcard; ?></div>
  </div>
</body>
</html>
