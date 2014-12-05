<?php

/**
 * @file
 * User functions.
 */

function philbo_preprocess_user_profile(&$variables) {
  //
  // Set shortcut variables. Hooray for less typing!
  $account = $variables['elements']['#account'];

  //
  // Helpful $user_profile variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['user_profile'][$key] = $variables['elements'][$key];
  }

  //
  // Preprocess fields.
  field_attach_preprocess('user', $account, $variables['elements'], $variables);
}