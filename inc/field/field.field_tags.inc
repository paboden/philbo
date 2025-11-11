<?php

/**
 * @file
 * Field template functions.
 */

/**
 * Implements hook_preprocess_field().
 *
 * Field: field_tags - Type: article - Mode: full
 */
function philbo_preprocess_field__field_tags__article__full(&$vars) {
  $vars['label_hidden'] = FALSE;
  $vars['label_wrapper_element'] = 'h2';
  $vars['use_items_wrapper'] = TRUE;
  $vars['items_wrapper_element'] = 'ul';
  $vars['use_item_wrapper'] = TRUE;
  $vars['item_wrapper_element'] = 'li';
}

/**
 * Implements hook_preprocess_field().
 *
 * Field: field_tags - Type: article - Mode: teaser
 */
function philbo_preprocess_field__field_tags__article__teaser(&$vars) {
  $vars['label_hidden'] = TRUE;
  $vars['use_items_wrapper'] = TRUE;
  $vars['items_wrapper_element'] = 'ul';
  $vars['use_item_wrapper'] = TRUE;
  $vars['item_wrapper_element'] = 'li';
}