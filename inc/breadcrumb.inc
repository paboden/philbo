<?php

/**
 * @file
 * Breadcrumb template functions.
 */

/**
 * Implements hook_menu_breadcrumb_alter().
 */
function philbo_menu_breadcrumb_alter(&$active_trail, $item) {

}

/**
 * Implements hook_preprocess_breadcrumb().
 */
function philbo_preprocess_breadcrumb(&$variables) {

}

/**
 * Implements theme_breadcrumb().
 */
function philbo_breadcrumb(&$vars) {
  $breadcrumb = $vars['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Remove menu-minipanel references from the breadcrumb links
    $breadcrumb = philbo_remove_menu_mini_panels_from_breadcrumb($breadcrumb);

    // Customize your breadcrumb separator text here.
    $breadcrumb_separator_text = '>>';

    // Build out the full separator.
    // This will be placed in-between each breadcrumb trail item.
    $before = '<span class="breadcrumb--link">';
    $after = '</span>';
    $breadcrumb_separator = '<span class="breadcrumb--separator"> ' . $breadcrumb_separator_text . ' </span>';

    // Build out our full breadcrumb string
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= $before . implode($after . $breadcrumb_separator . $before, $breadcrumb) . $after;
    $output .= $breadcrumb_separator . '<span class="active">'. drupal_get_title() .'</span>';

    return $output;
  }
}

/**
 * Helper function to remove menu-mini-panels from the breadcrumb output
 * @param $breadcrumb
 * @return mixed
 */
function philbo_remove_menu_mini_panels_from_breadcrumb($breadcrumb) {
  foreach ($breadcrumb as $key => $link) {
    while ($start = strpos($link, 'menu-minipanel')) {
      $next_space = strpos($link, ' ', $start);
      $next_quote = strpos($link, '"', $start);

      if (is_numeric($next_space)) {
        $end = $next_quote < $next_space ? $next_quote : $next_space;
      } else {
        $end = $next_quote;
      }

      $link = substr_replace($link, '', $start, $end - $start);
      $breadcrumb[$key] = $link;
    }
  }

  return $breadcrumb;
}