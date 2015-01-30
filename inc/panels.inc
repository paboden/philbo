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
  $vars['classes_array'] = NULL;
  $classes = &$vars['classes_array'];
  $vars['title_attributes_array']['class'] = NULL;
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $theme_hook_suggestions = &$vars['theme_hook_suggestions'];

  //
  // Add global classes to all blocks.
  $classes[] = 'panel-pane';
  $classes[] = 'panel-' . drupal_html_class($type);
  $title_classes[] = 'pane-title';
  $content_classes[] = 'pane-content';

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