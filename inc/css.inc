<?php

/**
 * @file
 * CSS functions.
 */

/**
 * Implements hook_css_alter().
 */
function philbo_css_alter(&$css) {
  //
  // Remove unneccesary css from being added to the output.
  // No base styles
  if (isset($css['modules/system/system.base.css'])) {
    unset($css['modules/system/system.base.css']);
  }

  //
  // No styles from primary tabs
  if (isset($css['modules/system/system.menus.css'])) {
    unset($css['modules/system/system.menus.css']);
  }

  //
  // No styles from messages
  if (isset($css['modules/system/system.messages.css'])) {
    unset($css['modules/system/system.messages.css']);
  }

  //
  // No styles from system theme
  if (isset($css['modules/system/system.theme.css'])) {
    unset($css['modules/system/system.theme.css']);
  }

  //
  // No styles from aggregator
  if (isset($css['modules/aggregator/aggregator.css'])) {
    unset($css['modules/aggregator/aggregator.css']);
  }

  //
  // No styles from book
  if (isset($css['modules/book/book.css'])) {
    unset($css['modules/book/book.css']);
  }

  //
  // No styles from comment
  if (isset($css['modules/comment/comment.css'])) {
    unset($css['modules/comment/comment.css']);
  }

  //
  // No styles from poll
  if (isset($css['modules/poll/poll.css'])) {
    unset($css['modules/poll/poll.css']);
  }

  //
  // No styles from node
  if (isset($css['modules/node/node.css'])) {
    unset($css['modules/node/node.css']);
  }

  //
  // No styles from node
  if (isset($css['modules/search/search.css'])) {
    unset($css['modules/search/search.css']);
  }

  //
  // No styles from user
  if (isset($css['modules/user/user.css'])) {
    unset($css['modules/user/user.css']);
  }

  //
  // No styles from forum
  if (isset($css['modules/forum/forum.css'])) {
    unset($css['modules/forum/forum.css']);
  }

  //
  // No styles for filter
  if (isset($css['modules/filter/filter.css'])) {
    unset($css['modules/filter/filter.css']);
  }

  //
  // No styles from field
  if (isset($css['modules/field/theme/field.css'])) {
    unset($css['modules/field/theme/field.css']);
  }

  //
  // No styles from shortcuts if admin menu component is turned off
  if (module_exists('admin_menu')) {
    $components = variable_get('admin_menu_components', array());
    if (($components['shortcut.links'] != 1) && (isset($css['modules/shortcut/shortcut.css']))) {
      unset($css['modules/shortcut/shortcut.css']);
    }
  }

  //
  // No styles from nice_menus
  $nice_menus = drupal_get_path('module', 'nice_menus');
  if (isset($css[$nice_menus . '/css/nice_menus_default.css'])) {
    unset($css[$nice_menus . '/css/nice_menus_default.css']);
  }

  //
  // No styles from field_group horizontal tabs
  $field_group = drupal_get_path('module', 'field_group');
  if (isset($css[$field_group . '/horizontal-tabs/horizontal-tabs.css'])) {
    unset($css[$field_group . '/horizontal-tabs/horizontal-tabs.css']);
  }

  //
  // No styles from views
  $views = drupal_get_path('module', 'views');
  if (isset($css[$views . '/css/views.css'])) {
    unset($css[$views . '/css/views.css']);
  }

  //
  // No styles from dates
  $date = drupal_get_path('module', 'date');
  if (isset($css[$date . '/date_api/date.css'])) {
    unset($css[$date . '/date_api/date.css']);
  }

  //
  // Switch existing css with new css files provided by this theme.
  // Path to the theme's CSS directory.
  $dir = drupal_get_path('theme', 'philbo') . '/css';

  //
  // Swap out block.css with the block.admin.css.
  $block = drupal_get_path('module', 'block');
  if (isset($css[$block . '/block.css'])) {
    $css[$block . '/block.css']['data'] = $dir . '/block/block.admin.css';
  }

  //
  // Swap out color.css with the color.admin.css.
  $color = drupal_get_path('module', 'color');
  if (isset($css[$color . '/color.css'])) {
    $css[$color . '/color.css']['data'] = $dir . '/color/color.admin.css';
  }
  if (isset($css[$color . '/color-rtl.css'])) {
    $css[$color . '/color-rtl.css']['data'] = $dir . '/color/color.admin-rtl.css';
  }

  //
  // No styles from jquery.ui
  // Note: need to do this way even though jquery_update replaces the paths
  unset($css['misc/ui/jquery.ui.core.css']);
  unset($css['misc/ui/jquery.ui.theme.css']);
  unset($css['misc/ui/jquery.ui.tabs.css']);

}