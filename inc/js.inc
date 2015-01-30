<?php

/**
 * @file
 * JS functions.
 */

/**
 * Implements hook_js_alter().
 */
function philbo_js_alter(&$javascript) {
  //
  // Remove unneccesary js from being added to the output.

  //
  // No jquery from core. we add our own later
  if (isset($javascript['misc/jquery.js'])) {
    unset($javascript['misc/jquery.js']);
  }

  //
  // No jquery from core. we add our own later
  if (isset($javascript['misc/jquery.once.js'])) {
    unset($javascript['misc/jquery.once.js']);
  }

  //
  // No jquery from core. we add our own later
  if (isset($javascript['misc/form.js'])) {
    unset($javascript['misc/form.js']);
  }

  //
  // No jquery from core. we add our own later
  if (isset($javascript['misc/textarea.js'])) {
    unset($javascript['misc/textarea.js']);
  }

  //
  // No jquery from core. we add our own later
  if (isset($javascript['modules/filter/filter.js'])) {
    unset($javascript['modules/filter/filter.js']);
  }

  //
  // No jquery from core. we add our own later
  if (isset($javascript['modules/contextual/contextual.js'])) {
    unset($javascript['modules/contextual/contextual.js']);
  }

  //
  // No js from nice_menus
  if (isset($javascript['sites/all/modules/contrib/nice_menus/css/nice_menus_default.js'])) {
    unset($javascript['sites/all/modules/contrib/nice_menus/css/nice_menus_default.js']);
  }

}
