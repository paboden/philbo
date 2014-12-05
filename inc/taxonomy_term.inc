<?php

/**
 * @file
 * Taxonomy term template functions.
 */

/**
 * Implements template_preprocess_search_results().
 */
function philbo_preprocess_taxonomy_term(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $vid = $vars['vid'];
  $term_name = $vars['name'];
  $vm_name = $vars['vocabulary_machine_name'];
}