<?php

/**
 * @file
 * Page template functions.
 */

/**
 * Implements hook_preprocess_page().
 */
function philbo_preprocess_page__panel__PANEL_NAME(&$vars) {

}

/**
 * Implements hook_preprocess_page().
 */
function philbo_preprocess_page__views__VIEW_NAME(&$vars) {

}

/**
 * Implements hook_preprocess_page().
 */
function philbo_preprocess_page__node__NODE_TYPE_NAME(&$vars) {

}

/**
 * Implements hook_preprocess_page().
 */
function philbo_preprocess_page(&$vars) {

  // If this page is a panel page...
  $vars['is_panel'] = FALSE;
  if (module_exists('panels') && module_exists('page_manager')) {
    $panel = page_manager_get_current_page();
    if ($panel) {
      $vars['is_panel'] = TRUE;

      // Create page.tpl suggestions based on content type (along with node id)
      $vars['theme_hook_suggestions'][] = 'page__panel';
      $vars['theme_hook_suggestions'][] = 'page__panel__' . $panel['subtask']['name'];

      // Create preprocess function suggestions based on panel page name
      // THEME_preprocess_page__PANEL_SUBTASK_DISPLAY_NAME__panel_page
      $function = __FUNCTION__ . '__panel__' . $panel['subtask']['name'];
      if (function_exists($function)) {
        $function($vars);
      }
    }
  }

  // If this page is a view page...
  $vars['is_view'] = FALSE;
  if (module_exists('views')) {
    $view = views_get_page_view();
    if ($view) {
      $vars['is_view'] = TRUE;

      // Create page.tpl suggestions based on view name
      $vars['theme_hook_suggestions'][] = 'page__views';
      $vars['theme_hook_suggestions'][] = 'page__views__' . $view->name;

      // Create preprocess function suggestions based on view name
      // THEME_preprocess_page__VIEW_NAME_views_page
      $function = __FUNCTION__ . '__views__' . $view->name;
      if (function_exists($function)) {
        $function($vars);
      }
    }
  }

  // If this page is a node page...
  $vars['is_node'] = FALSE;
  if (isset($vars['node'])) {
    $node = $vars['node'];
    $vars['is_node'] = TRUE;

    // Create page.tpl suggestions based on content type (along with node id)
    $vars['theme_hook_suggestions'][] = 'page__node__' . $node->type;
    $vars['theme_hook_suggestions'][] = 'page__node__' . $node->type . '__' . $node->nid;

    //
    // Node-type-specific preprocess functions
    $function = __FUNCTION__ . '__node__' . $node->type;
    if (function_exists($function)) {
      $function($vars);
    }
  }
}