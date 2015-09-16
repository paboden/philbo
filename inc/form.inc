<?php

/**
 * @file
 * Form template functions.
 */

/**
 * Implements hook_preprocess_form_element().
 */
function philbo_preprocess_form_element(&$vars) {

}

/**
 * Implements theme_form_element().
 */
function philbo_form_element($variables) {
  $element = &$variables['element'];

  //
  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  //
  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  //
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element ['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }

  //
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  //
  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span>' : '';
  $suffix = isset($element['#field_suffix']) ? '<span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element ['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Implements hook_element_info_alter.
 */
function philbo_element_info_alter(&$type) {
  //
  // Remove the size and cols attribute from form elements.
  // we want css to control these.
  if (isset($type['textfield'])) {
    $type['textfield']['#size'] = NULL;
  }
  if (isset($type['textarea'])) {
    $type['textarea']['#size'] = NULL;
    $type['textarea']['#rows'] = NULL;
    $type['textarea']['#cols'] = NULL;
  }
  if (isset($type['password'])) {
    $type['password']['#size'] = NULL;
  }
  if (isset($type['machine_name'])) {
    $type['machine_name']['#size'] = NULL;
  }
  if (isset($type['managed_file'])) {
    $type['managed_file']['#size'] = NULL;
  }
  if (isset($type['file'])) {
    $type['file']['#size'] = NULL;
  }
  if (isset($type['email'])) {
    $type['email']['#size'] = NULL;
  }
  if (isset($type['telephone'])) {
    $type['telephone']['#size'] = NULL;
  }
}