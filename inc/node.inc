<?php

/**
 * @file
 * Node template functions.
 */

/**
 * Implements hook_preprocess_node().
 */
function philbo_preprocess_node(&$vars, $hook) {
  //
  // Set shortcut variables. Hooray for less typing!
  $type = $vars['type'];
  $mode = $vars['view_mode'];
  $node = $vars['node'];
  $type_mode = $type . '__' . $mode;
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  //
  // Template suggestions
  $vars['theme_hook_suggestions'][] = 'node__' . $mode;
  $vars['theme_hook_suggestions'][] = 'node__' . $type . '__' . $mode;

  //
  // Adding classes
  if ($mode == 'full') {
    $classes[] = 'node-full';
  }

  //
  // Node-type-specific preprocess functions
  $function = __FUNCTION__ . '__' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars, $hook);
  }

  //
  // Set title and wrapper.
  $vars['show_title'] = TRUE;
  $show_title = &$vars['show_title'];
  $vars['title_as_link'] = TRUE;
  $title_as_link = &$vars['title_as_link'];
  $vars['title_wrapper'] = 'h2';
  $title_wrapper = &$vars['title_wrapper'];

  //
  // Set node wrapper
  $vars['node_wrapper'] = 'div';
  $node_wrapper = &$vars['node_wrapper'];

  //
  // Show links or comments
  $vars['show_links'] = TRUE;
  $show_links = &$vars['show_links'];
  $vars['show_comments'] = TRUE;
  $show_comments = &$vars['show_comments'];

  switch($type_mode) {
    case 'page__full' :
      $show_links = FALSE;
      break;
    case 'article__teaser' :
      $show_title = TRUE;
      $node_wrapper = 'article';
      $title_wrapper = 'h2';
      $title_as_link = TRUE;
    case 'page__teaser' :
      $show_links = FALSE;
      $node_wrapper = 'article';
      $title_wrapper = 'h2';
      $title_as_link = FALSE;
      break;
  }


}

/**
 * Implements hook_preprocess_node() for "Article".
 */
function philbo_preprocess_node__article(&$vars, $hook) {
  //
  // Set shortcut variables. Hooray for less typing!
  $mode = $vars['view_mode'];
  $node = $vars['node'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  //
  // Theme suggestions for each tag term
  $category = isset($node->field_tags[LANGUAGE_NONE]) ? $node->field_tags[LANGUAGE_NONE] : NULL;
  if ($category) {
    foreach ($category as $delta => $term) {
      $name = $term['taxonomy_term']->name;
      $vars['theme_hook_suggestions'][] = 'node__article__' . $name;
    }
  }

  if ($mode == 'full') {

  }

  if ($mode == 'teaser') {

  }
}

/**
 * Implements hook_preprocess_node() for "Basic Page".
 */
function philbo_preprocess_node__page(&$vars, $hook) {
  //
  // Set shortcut variables. Hooray for less typing!
  $mode = $vars['view_mode'];
  $node = $vars['node'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  if ($mode == 'full') {

  }

  if ($mode == 'teaser') {

  }
}