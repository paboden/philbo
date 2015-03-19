<?php

/**
 * @file
 * Breadcrumb template functions.
 */

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
    //
    // Remove menu-minipanel references from the breadcrumb links
    foreach ($breadcrumb as $key => $link) {
      while ($start = strpos($link, 'menu-minipanel')) {
        $next_space = strpos($link, ' ', $start);
        $next_quote = strpos($link, '"', $start);
        if (is_numeric($next_space)) {
          $end = $next_quote < $next_space ? $next_quote : $next_space;
        }
        else {
          $end = $next_quote;
        }
        $link = substr_replace($link, '', $start, $end - $start);
        $breadcrumb[$key] = $link;
      }
    }

    //
    // Customize your breadcrumb separator text here.
    $breadcrumb_separator_text = '>>';

    //
    // Build out the full separator. This will be placed inbetween each breadcrumb
    // trail item.
    $before = '<span class="breadcrumb--link">';
    $after = '</span>';
    $breadcrumb_separator = '<span class="breadcrumb--separator"> ' . $breadcrumb_separator_text . ' </span>';

    //
    // Build out our full breadcrumb string
    // @TODO: build this into a template using a render array.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= $before . implode($after . $breadcrumb_separator . $before, $breadcrumb) . $after;
    $output .= $breadcrumb_separator . '<span class="active">'. drupal_get_title() .'</span>';

    return $output;
  }
}