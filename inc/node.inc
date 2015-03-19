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
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  //
  // Template suggestions
  $vars['theme_hook_suggestions'][] = 'node__' . $type . '__' . $mode;
  // Adding classes
  $classes[] = drupal_html_class($type);
  $classes[] = drupal_html_class($type) . '--' . drupal_html_class($mode);

  //
  // Node-type-specific preprocess functions
  $function = __FUNCTION__ . '__' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars, $hook);
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
    //
    // Create a variable that can be printed on any related article template.
    if (module_exists('views')) {
      $vars['view_embed_variable'] = views_embed_view('VIEW_NAME', 'DISPLAY_NAME');
    }
  }

  if ($mode == 'teaser') {
    //
    // Create a custom "read more" link variable for use on any artile template.
    $vars['read_more'] = l(t('Read more'), 'node/' . $node->nid, array('attributes' => array('class' => array('read-more-link'))));
  }

  if ($mode == 'search_results') {

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

  if ($mode == 'search_results') {

  }
}