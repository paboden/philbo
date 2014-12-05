<?php

/**
 * @file
 * Views functions.
 */

/**
 * Implements hook_views_post_render().
 */
function philbo_views_post_render(&$view, &$output, &$cache) {

}

/**
 * Implements hook_preprocess_views_view().
 */
function philbo_preprocess_views_view(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $view = $vars['view'];
  $view_name = $view->name;

}

/**
 * Display a single views grouping.
 */
function philbo_views_view_grouping($vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $view = $vars['view'];
  $title = $vars['title'];
  $content = $vars['content'];
  $label_classes = $vars['title_attributes_array']['class'];
  $content_classes = $vars['content_attributes_array']['class'];
  $group_classes = $vars['group_attributes_array']['class'];

  $output = '<' . $vars['group_wrapper'] . ' class="' . $group_classes . '">';
  $output .= '<' . $vars['label_wrapper'] . ' class="' . $label_classes . '">' . $title . '</' . $vars['label_wrapper'] . '>';
  $output .= '<' . $vars['content_wrapper'] . ' class="' . $content_classes . '">' . $content . '</' . $vars['content_wrapper'] . '>' ;
  $output .= '</' . $vars['group_wrapper'] . '>';

  return $output;
}

/**
 * Process a single grouping within a view.
 */
function philbo_preprocess_views_view_grouping(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $view = $vars['view'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $group_classes = &$vars['group_attributes']['class'];

  //
  // Grouping wrapper.
  $vars['group_items_wrapper_element'] = 'div';
  $group_wrapper_element = &$vars['group_wrapper_element'];
  $group_classes[] = 'view-grouping';

  //
  // Group Label wrapper.
  $vars['label_wrapper_element'] = 'div';
  $group_label_wrapper_element = &$vars['group_label_wrapper_element'];
  $title_classes[] = 'view-grouping-label';

  //
  // Group content wrapper.
  $vars['group_content_wrapper_element'] = 'div';
  $group_content_wrapper_element = &$vars['group_content_wrapper_element'];
  $content_classes[] = 'view-grouping-content';

  $vars['content'] = $vars['view']->style_plugin->render_grouping_sets($vars['rows'], $vars['grouping_level']);

  switch ($view) {
    case '':
    break;
  }
}



