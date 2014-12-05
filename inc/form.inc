<?php

/**
 * @file
 * Form template functions.
 */

/**
 * Implements hook_form_alter().
 */
function philbo_form_alter(&$form, &$form_state, $form_id) {

}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function philbo_form_FORM_ID_alter(&$form, &$form_state, $form_id) {

}

/**
 * Implements hook_element_info_alter.
 */
function philbo_element_info_alter(&$type) {
  //
  // Remove the size and cols attribute from form elements.
  // we want css to control these.
  $type['textfield']['#size'] = NULL;
  $type['textarea']['#cols'] = NULL;
  $type['password']['#size'] = NULL;
  $type['machine_name']['#size'] = NULL;
  $type['managed_file']['#size'] = NULL;
  $type['file']['#size'] = NULL;
  if (isset($type['email'])) {
    $type['email']['#size'] = NULL;
  }
  if (isset($type['telephone'])) {
    $type['telephone']['#size'] = NULL;
  }
}