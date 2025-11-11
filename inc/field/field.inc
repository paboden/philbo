<?php

/**
 * @file
 * Field template functions.
 */

/**
 * Implements hook_preprocess_field().
 */
function philbo_preprocess_field(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $field_name = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];

  $vars['field_name'] = $vars['element']['#field_name'];
  $vars['bundle'] = $vars['element']['#bundle'];
  $vars['view_mode'] = $vars['element']['#view_mode'];

  $field_base_class = drupal_html_class($field_name);

  // Field (outer) wrapper.
  $vars['use_field_wrapper'] = TRUE;
  $vars['field_wrapper_element'] = 'div';
  $vars['classes_array'] = array();
  $vars['classes_array'][] = 'field';
  $vars['classes_array'][] = $field_base_class;

  // Label wrapper and base class settings.
  $vars['label_hidden'] = FALSE;
  $vars['label_wrapper_element'] = 'div';
  $vars['title_attributes_array']['class'][] = 'label';
  $vars['title_attributes_array']['class'][] = $field_base_class . '-label';
  $vars['title_attributes_array']['class'][] = drupal_html_class($bundle) . '-' . $field_base_class . '-label';

  // Items wrapper and base class settings.
  $vars['use_items_wrapper'] = FALSE;
  $vars['items_wrapper_element'] = 'div';
  $vars['content_attributes_array']['class'][] = $field_base_class . '-items';

  // Item per Row wrapper and base class settings.
  $vars['use_row_wrapper'] = FALSE;
  $vars['items_per_row'] = 1;
  $vars['row_wrapper_element'] = 'div';
  $vars['item_count'] = count($vars['items']);
  $vars['row_classes'] = array();

  // Individual item wrapper and base class settings.
  $vars['use_item_wrapper'] = FALSE;
  $vars['item_wrapper_element'] = 'div';

  foreach ($vars['items'] as $delta => $item) {
    $vars['item_attributes_array'][$delta]['class'] = $delta % 2 ? 'item-' . ($delta + 1) . ' even' : 'item-' . ($delta + 1) . ' odd';
  }

  // Block-module specific preprocess functions
  // THEME_preprocess_field__FIELD_NAME(&$vars)
  $function = __FUNCTION__ . '__' . $field_name;
  if (function_exists($function)) {
    $function($vars);
  }

  // Block-module-delta specific preprocess functions
  // THEME_preprocess_field__FIELD_NAME__CONTENT_TYPE(&$vars)
  $function = __FUNCTION__ . '__' . $field_name . '__' . $bundle;
  if (function_exists($function)) {
    $function($vars);
  }

  // Field-module specific preprocess functions
  // THEME_preprocess_field__FIELD_NAME__CONTENT_TYPE__VIEW_MODE(&$vars)
  $function = __FUNCTION__ . '__' . $field_name . '__' . $bundle . '__' . $mode;
  if (function_exists($function)) {
    $function($vars);
  }
}