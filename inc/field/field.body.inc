<?php

/**
 * @file
 * Field template functions.
 */

/**
 * Implements hook_preprocess_field().
 *
 * Field: body
 */
function philbo_preprocess_field__body(&$vars) {
  $vars['label_hidden'] = TRUE;
  $vars['classes_array'] = array();
  $vars['classes_array'][] = 'field';
  $vars['classes_array'][] = 'field-body';
}

/**
 * Implements hook_preprocess_field().
 *
 * Field: body - Type: article
 */
function philbo_preprocess_field__body__article(&$vars) {
  $vars['label_hidden'] = FALSE;
}

/**
 * Implements hook_preprocess_field().
 *
 * Field: body - Type: article - Mode: teaser
 */
function philbo_preprocess_field__body__article__full(&$vars) {
  $vars['label_hidden'] = FALSE;
  $vars['label_wrapper_element'] = 'h2';
  $vars['label'] = t('My Body FULL');
}

/**
 * Implements hook_preprocess_field().
 *
 * Field: body - Type: article - Mode: teaser
 */
function philbo_preprocess_field__body__article__teaser(&$vars) {
  $vars['label_hidden'] = FALSE;
  $vars['label_wrapper_element'] = 'h2';
  $vars['label'] = t('My Body Teaser');
}