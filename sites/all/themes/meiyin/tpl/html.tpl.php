<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 */

?>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>

<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php if(theme_get_setting('responsive') == 1): ?>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php endif; ?>
  <?php if(theme_get_setting('iphoneRegularIcon') != NULL): ?>
  <link rel="apple-touch-icon" href="<?php print file_create_url(file_load(theme_get_setting('iphoneRegularIcon'))->uri); ?>">
  <?php endif; ?>
  <?php if(theme_get_setting('ipadRegularIcon') != NULL): ?>
  <link rel="apple-touch-icon" sizes="72x72" href="<?php print file_create_url(file_load(theme_get_setting('ipadRegularIcon'))->uri); ?>">
  <?php endif; ?>
  <?php if(theme_get_setting('appleRetinaIcon') != NULL): ?>
  <link rel="apple-touch-icon" sizes="114x114" href="<?php print file_create_url(file_load(theme_get_setting('appleRetinaIcon'))->uri); ?>">
  <?php endif; ?>
  <?php print $styles; ?>
  <?php print $skin; ?>
  <?php print $jquery; ?>
  <?php print $migrate; ?>
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
</body>
</html>