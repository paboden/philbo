<?php

/**
 * @file
 * Search template functions.
 */

/**
 * Implements template_preprocess_search_results().
 */
function philbo_preprocess_search_results(&$vars) {

}

/**
 * Implements template_preprocess_search_result().
 */
function philbo_preprocess_search_result(&$vars) {
  //
  // Get node type information
  $node = isset($vars['item']) ? $vars['item'] : null;
  $type = isset($node) ? node_type_get_name($node) : null;
  $vars['type'] = $type;

  //
  // Get created date information
  $created_date = isset($vars['item']) ? $vars['item']->created : null;
  $vars['created_date'] = $created_date;

  //
  // Build node/%nid url for linking title or readmore buttons
  $nid = isset($vars['item']) ? $vars['item']->nid : null;
  $url = isset($nid) ? url('node/' . $nid) : null;
  $vars['url'] = $url;
}