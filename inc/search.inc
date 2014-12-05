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
  $node = $vars['item'];
  $type = node_type_get_name($node);
  $vars['type'] = $type;

  //
  // Get created date information
  $created_date = $vars['item']->created;
  $vars['created_date'] = $created_date;

  //
  // Build node/%nid url for linking title or readmore buttons
  $nid = $vars['item']->nid;
  $url = url('node/'.$nid);
  $vars['url'] = $url;
}