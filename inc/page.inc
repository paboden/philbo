<?php

/**
 * @file
 * Page template functions.
 */

/**
 * Implements hook_preprocess_page().
 */
function philbo_preprocess_page(&$vars) {
  $node = null;
  $classes_array = null;

  if (isset($vars['node'])) {
    $node = $vars['node'];

    //
    // Create page.tpl suggestions based on content type (along with node id)
    $vars['theme_hook_suggestions'][] = 'page__' . $node->type;
    $vars['theme_hook_suggestions'][] = 'page__' . $node->type . '__' . $node->nid;

    //
    // Node-type-specific preprocess functions
    $function = __FUNCTION__ . '__' . $node->type;
    if (function_exists($function)) {
      $function($vars);
    }
  }

  if (isset($vars['classes_array'])) {
    $classes_array = $vars['classes_array'];
  }

  //
  // Determine if the page is rendered using panels.
  $variables['is_panel'] = FALSE;
  if (module_exists('page_manager') && count(page_manager_get_current_page())) {
    $variables['is_panel'] = TRUE;
  }
}

/**
 * Implements hook_preprocess_page().
 */
function philbo_preprocess_page__article(&$vars) {
  $node = $vars['node'];
  $classes_array = $vars['classes_array'];

  //
  // Example:
  // Build out a block for hardcoded placement in the article type template
  // $vars['MY_BLOCK_VARIABLE'] = build_block('MODULE_NAME', 'BLOCK_DELTA');

}

/**
 * Override or insert variables into the page template.
 */
function philbo_process_page(&$variables) {

}
