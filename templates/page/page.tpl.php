<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
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
 * - $subtitle: The page subtitle, for use in the actual HTML content.
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
 * - $page['menu_top']: Top navigation, country/language selector and search form.
 * - $page['menu']: Main menu and logo.
 * - $page['header_callout']: Main slideshow and header callouts specific to each page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['content']: Main content for the page.
 * - $page['content_bottom']: Additional region for content.
 * - $page['footer_top']: Items for the footer top region.
 * - $page['footer_menu_one']: Items for the footer menu one region.
 * - $page['footer_menu_two']: Items for the footer menu two region.
 * - $page['footer_menu_three']: Items for the footer menu three region.
 * - $page['footer_menu_four']: Items for the footer menu four region.
 * - $page['footer_menu_five']: Items for the footer menu five region.
 * - $page['footer_menu_six']: Items for the footer menu six region.
 * - $page['footer_menu_seven']: Items for the footer menu seven region.
 * - $page['footer_bottom']: Items for the footer bottom region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<?php if ($messages): ?>
<div id="messages">
  <div class="container">
    <?php print $messages; ?>
  </div>
</div>
<?php endif; ?>

<?php if ($tabs['#primary']): ?>
<div id="tabs">
  <div class="container">
    <?php print render($tabs);?>
  </div>
</div>
<?php endif; ?>

<header>
  <div id="header">
    <?php if ($logo): ?>
    <div class="logo-wrapper">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
    </div>
    <?php endif; ?>

    <?php if ($page['header']): ?>
      <?php print render($page['header']); ?>
    <?php endif; ?>
  </div>
</header>

<nav>
  <div id="menu">
    <?php if ($page['menu']): ?>
      <?php print render($page['menu']); ?>
    <?php endif; ?>
  </div>
</nav>

<?php if (isset($breadcrumb)): ?>
<div id="breadcrumb">
  <div class="container">
    <?php print $breadcrumb; ?>
  </div>
</div>
<?php endif; ?>

<section>
  <div id="content">

    <?php if (($title) && (!isset($node))): ?>
    <div class="title-wrapper">
    <?php print render($title_prefix); ?>
      <h1 id="page-title"><?php print $title; ?></h1>
    <?php print render($title_suffix); ?>
    </div>
    <?php endif; ?>

    <?php print render($page['content']); ?>

    <?php if ($feed_icons): ?><?php print $feed_icons; ?><?php endif; ?>

    <?php if ($page['sidebar_first']): ?>
      <?php print render($page['sidebar_first']); ?>
    <?php endif; ?>

    <?php if ($page['sidebar_second']): ?>
      <?php print render($page['sidebar_second']); ?>
    <?php endif; ?>

  </div>
</section>

<?php if ($page['footer']): ?>
<footer>
  <?php print render($page['footer']); ?>
</footer>
<?php endif; ?>