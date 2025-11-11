<?php

/**
 * @file
 * Field template functions.
 */

/**
 * Implements hook_preprocess_field().
 *
 * Field: field_image - Type: article - Mode: full
 */
function philbo_preprocess_field__field_image__article__full(&$vars) {
  $vars['label_hidden'] = TRUE;
  $vars['use_item_wrapper'] = FALSE;
  $vars['use_items_wrapper'] = FALSE;
}

/**
 * Implements hook_preprocess_field().
 *
 * Field: field_image - Type: article - Mode: teaser
 */
function philbo_preprocess_field__field_image__article__teaser(&$vars) {
  $vars['label_hidden'] = TRUE;
}