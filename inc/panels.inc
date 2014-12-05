<?php

/**
 * @file
 * Panels template functions.
 */

/**
 * Implements template_preprocess_panels_pane().
 */
function philbo_preprocess_panels_pane(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $pane_id = $vars['pane']->pid;
  $type = $vars['pane']->type;
  $subtype = $vars['pane']->subtype;
  $layout = $vars['display']->layout;
  $content = $vars['content'];
  $theme_hook_suggestions = &$vars['theme_hook_suggestions'];

  //
  // Set a whole mess of possible panel pane tpl suggestions. If you can't
  // find one that works for you, you shouldn't be using panels.....or drupal ;)
  $theme_hook_suggestions[] = 'panels_pane__' . $subtype;
  $theme_hook_suggestions[] = 'panels_pane__' . $pane_id;
  $theme_hook_suggestions[] = 'panels_pane__' . $type . '__' . $pane_id;
  $theme_hook_suggestions[] = 'panels_pane__' . $subtype . '__' . $pane_id;
  $theme_hook_suggestions[] = 'panels_pane__' . $layout;
  $theme_hook_suggestions[] = 'panels_pane__' . $layout . '__' . $type;
  $theme_hook_suggestions[] = 'panels_pane__' . $layout . '__' . $subtype;
  $theme_hook_suggestions[] = 'panels_pane__' . $layout . '__' . $type . '__' . $pane_id;
  $theme_hook_suggestions[] = 'panels_pane__' . $layout . '__' . $subtype . '__' . $pane_id;

}