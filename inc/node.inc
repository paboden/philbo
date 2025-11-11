<?php

/**
 * @file
 * Node template functions.
 */

/**
 * Implements hook_preprocess_node() for "Article".
 */
function philbo_preprocess_node__teaser(&$vars, $hook) {

  // Set node wrapper
  $vars['node_wrapper'] = 'article';
}

/**
 * Implements hook_preprocess_node() for "Article".
 */
function philbo_preprocess_node__article(&$vars, $hook) {

  // Theme suggestions for each tag term
  $category = isset($vars['node']->field_tags[LANGUAGE_NONE]) ? $vars['node']->field_tags[LANGUAGE_NONE] : NULL;
  if ($category) {
    foreach ($category as $delta => $term) {
      $vars['theme_hook_suggestions'][] = 'node__article__' . $term['taxonomy_term']->name;
      $vars['theme_hook_suggestions'][] = 'node__article__' . $vars['view_mode'] . '__' . $term['taxonomy_term']->name;
    }
  }
}

/**
 * Implements hook_preprocess_node() for "Article".
 */
function philbo_preprocess_node__article__full(&$vars, $hook) {

  // Force to show links.
  $vars['show_links'] = TRUE;
}

/**
 * Implements hook_preprocess_node() for "Article".
 */
function philbo_preprocess_node__article__teaser(&$vars, $hook) {

  // Force removal of comments on article teasers.
  $vars['show_comments'] = FALSE;
}

/**
 * Implements hook_preprocess_node() for "Basic Page".
 */
function philbo_preprocess_node__page(&$vars, $hook) {

  // Force removal of comments on all page view modes (except overridden).
  $vars['show_comments'] = FALSE;

  // Force to not show links.
  $vars['show_links'] = FALSE;
}

/**
 * Implements hook_preprocess_node() for "Basic Page".
 */
function philbo_preprocess_node__page__full(&$vars, $hook) {

  // Force removal of comments on all page view modes (except overridden).
  $vars['show_comments'] = FALSE;
  
  // Force to not show links.
  $vars['show_links'] = FALSE;
}

/**
 * Implements hook_preprocess_node() for "Basic Page".
 */
function philbo_preprocess_node__page__teaser(&$vars, $hook) {

  // Force to not show links.
  $vars['title_as_link'] = FALSE;

  // Unset the title link.
  $vars['show_links'] = TRUE;
}

/**
 * Implements hook_preprocess_node().
 */
function philbo_preprocess_node(&$vars, $hook) {

  // Template suggestions
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'];
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];

  // Set title and wrapper.
  $vars['show_title'] = TRUE;
  $vars['title_as_link'] = TRUE;
  $vars['title_element'] = 'h2';
  $vars['title_wrapper'] = 'hgroup';

  // Set node wrapper
  $vars['node_wrapper'] = 'article';

  // Set author/submitted/published date wrapper.
  $vars['display_submitted'] = TRUE;
  $vars['submitted_wrapper'] = 'footer';

  // Show links or comments
  $vars['show_links'] = TRUE;
  $vars['show_comments'] = TRUE;

  // Add default classes to wrapper
  $vars['classes_array'][] = NULL;

  // Set start point for title classes
  $vars['title_attributes_array']['id'] = '';
  $vars['title_attributes_array']['class'] = array();

  // Set start point for content wrapper classes
  $vars['content_attributes_array']['class'] = array();

  // Node-type-specific preprocess functions
  // TEMPLATE_preprocess_node__NODE_TYPE
  $function = __FUNCTION__ . '__' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars, $hook);
  }

  // Node-type-specific preprocess functions
  // TEMPLATE_preprocess_node__NODE_TYPE
  $function = __FUNCTION__ . '__' . $vars['view_mode'];
  if (function_exists($function)) {
    $function($vars, $hook);
  }

  // Node-type-specific preprocess functions
  // TEMPLATE_preprocess_node__NODE_TYPE__VIEW_MODE
  $function = __FUNCTION__ . '__' . $vars['node']->type . '__' . $vars['view_mode'];
  if (function_exists($function)) {
    $function($vars, $hook);
  }
}