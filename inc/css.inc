<?php

/**
 * @file
 * CSS functions.
 */

/**
 * Implements hook_css_alter().
 */
function philbo_css_alter(&$css) {

  /**
   * Remove unnecessary css from being added to the output.
   *
   */

  // No base styles
  unset($css['modules/system/system.base.css']);

  // No styles from primary tabs
  unset($css['modules/system/system.menus.css']);

  // No styles from messages
  unset($css['modules/system/system.messages.css']);

  // No styles from system theme
  unset($css['modules/system/system.theme.css']);

  // No styles from aggregator
  unset($css['modules/aggregator/aggregator.css']);

  // No styles from book
  unset($css['modules/book/book.css']);

  // No styles from comment
  unset($css['modules/comment/comment.css']);

  // No styles from contextual
  unset($css['modules/contextual/contextual.css']);

  // No styles from poll
  unset($css['modules/poll/poll.css']);

  // No styles from node
  unset($css['modules/node/node.css']);

  // No styles from search
  unset($css['modules/search/search.css']);

  // No styles from user
  unset($css['modules/user/user.css']);

  // No styles from forum
  unset($css['modules/forum/forum.css']);

  // No styles for filter
  unset($css['modules/filter/filter.css']);

  // No styles from field
  unset($css['modules/field/theme/field.css']);

  // No styles from comment
  unset($css['modules/taxonomy/taxonomy.css']);

  // No styles from shortcuts if admin menu component is turned off
  if (module_exists('ctools')) {
    unset($css[drupal_get_path('module', 'ctools') . '/css/ctools.css']);
  }

  // No styles from shortcuts if admin menu component is turned off
  if (module_exists('panels')) {
    unset($css[drupal_get_path('module', 'panels') . '/css/panels.css']);
  }

  // No styles from views
  if (module_exists('views')) {
    unset($css[drupal_get_path('module', 'views') . '/css/views.css']);
  }

  // No styles from nice_menus
  if (module_exists('nice_menus')) {
    unset($css[drupal_get_path('module', 'nice_menus') . '/css/nice_menus_default.css']);
  }

  // No styles from field_group horizontal tabs
  if (module_exists('field_group')) {
    unset($css[drupal_get_path('module', 'field_group') . '/horizontal-tabs/horizontal-tabs.css']);
  }

  // No styles from dates
  if (module_exists('date')) {
    unset($css[drupal_get_path('module', 'date') . '/date_api/date.css']);
  }

  /**
   * Switch existing css with new css files provided by this theme.
   *
   */

  // Path to the theme's CSS directory.
  $dir = drupal_get_path('theme', 'philbo') . '/css';

  // Swap out block.css with the block.admin.css.
  $block = drupal_get_path('module', 'block');
  if (isset($css[$block . '/block.css'])) {
    $css[$block . '/block.css']['data'] = $dir . '/block/block.admin.css';
  }

  // Swap out color.css with the color.admin.css.
  $color = drupal_get_path('module', 'color');
  if (isset($css[$color . '/color.css'])) {
    $css[$color . '/color.css']['data'] = $dir . '/color/color.admin.css';
  }
  if (isset($css[$color . '/color-rtl.css'])) {
    $css[$color . '/color-rtl.css']['data'] = $dir . '/color/color.admin-rtl.css';
  }

  /**
   * No styles from jquery.ui
   * Note: need to do this way even though jquery_update replaces the paths
   *
   */

  unset($css['misc/ui/jquery.ui.core.css']);
  unset($css['misc/ui/jquery.ui.theme.css']);
  unset($css['misc/ui/jquery.ui.tabs.css']);
}