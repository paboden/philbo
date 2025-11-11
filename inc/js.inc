<?php

/**
 * @file
 * JS functions.
 */

/**
 * Implements hook_js_alter().
 */
function philbo_js_alter(&$javascript) {

  /**
   * Remove unnecessary js from being added to the output.
   */

  // No jquery from core. we add our own later
  unset($javascript['misc/jquery.js']);

  // No jquery from core. we add our own later
  unset($javascript['http://code.jquery.com/jquery-1.7.1.min.js']);

  // No jquery from core. we add our own later
  unset($javascript['misc/jquery.once.js']);

  // No jquery from core. we add our own later
  unset($javascript['misc/form.js']);

  // No jquery from core. we add our own later
  unset($javascript['misc/textarea.js']);

  // No jquery from core. we add our own later
  unset($javascript['modules/filter/filter.js']);

  // No jquery from core. we add our own later
  unset($javascript['modules/contextual/contextual.js']);

  // No js from nice_menus
  if (module_exists('nice_menus')) {
    unset($javascript[drupal_get_path('module', 'nice_menus') . '/css/nice_menus_default.js']);
  }
}
