<?php

/**
 * @file
 * Field template functions.
 */

/**
 * Implements hook_preprocess_field().
 */
function philbo_preprocess_field(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $field = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $row_classes = &$vars['row_attributes']['class'];
  $item_classes = array();
  $base_class = $field;
  $field_bundle = $field . '__' . $bundle;
  $field_bundle_mode = $field . '__' . $bundle . '__' . $mode;

  //
  // Field (outer) wrapper.
  $vars['use_field_wrapper'] = TRUE;
  $use_field_wrapper = &$vars['use_field_wrapper'];
  $vars['field_wrapper_element'] = 'div';
  $field_wrapper_element = &$vars['field_wrapper_element'];

  //
  // Items wrapper.
  $vars['use_items_wrapper'] = FALSE;
  $use_items_wrapper = &$vars['use_items_wrapper'];
  $vars['items_wrapper_element'] = 'div';
  $items_wrapper_element = &$vars['items_wrapper_element'];

  //
  // Item Row wrapper.
  $vars['use_row_wrapper'] = FALSE;
  $use_row_wrapper = &$vars['use_row_wrapper'];
  $vars['items_per_row'] = 1;
  $items_per_row = &$vars['items_per_row'];
  $vars['row_wrapper_element'] = 'div';
  $row_wrapper_element = &$vars['row_wrapper_element'];

  //
  // Individual item wrapper.
  $vars['use_item_wrapper'] = TRUE;
  $use_item_wrapper = &$vars['use_item_wrapper'];
  $vars['item_wrapper_element'] = 'div';
  $item_wrapper_element = &$vars['item_wrapper_element'];

  //
  // Label wrapper.
  $vars['label_hidden'] = FALSE;
  $label_hidden = &$vars['label_hidden'];
  $label = &$vars['label'];
  $vars['label_wrapper_element'] = 'div';
  $label_wrapper_element = &$vars['label_wrapper_element'];
  $title_classes[] = 'label';

  //
  // Set our custom settings per field and the content type it is used in.
  switch ($field_bundle_mode) {
    //
    // This field would have no field wrapper, its label would be
    // an H2, it would have 2 individual items inside of a row
    // div element. Its label content would also be altered.
    // It would also have a new variable for use in
    // field--NAME-OF-FIELD.tpl.php
    // Example (field_image__article__full)
    case 'NAME_OF_FIELD__CONTENT_TYPE_BUNDLE_NAME__VIEW_MODE':
    $label_hidden = TRUE;
    $label_wrapper_element = 'h2';
    $use_field_wrapper = FALSE;
    $use_items_wrapper = FALSE;
    $use_row_wrapper = TRUE;
    $use_item_wrapper = FALSE;
    $items_per_row = 2;
    $row_wrapper_element = 'div';
    $label = t('Products');
    $vars['label_anchor'] = drupal_html_class($vars['items'][0]['#markup']);
    break;

    case 'field_image__article__full':
    $label_hidden = FALSE;
    $label = t('Article image');
    $label_wrapper_element = 'h2';
    break;

    case 'field_image__article__teaser':
    $label_hidden = FALSE;
    $label = t('Image');
    $label_wrapper_element = 'h3';
    break;

    case 'field_tags__article__full':
    $label_hidden = FALSE;
    $label_wrapper_element = 'h2';
    break;

    case 'field_tags__article__teaser':
    $label_hidden = TRUE;
    break;
  }

  //
  // Remove "field-" from $base_class and set field classes
  $base_class = drupal_html_class($base_class);
  if (strpos($base_class, 'field-') === 0) {
    $base_class = substr($base_class, 6);
  }

  //
  // Add some default classes to the field wrapper
  $classes = array();
  $classes[] = 'field';
  $classes[] = $base_class;

  //
  // Add some default classes to the field label
  $title_classes[] = $base_class . '-label';
  $title_classes[] = drupal_html_class($bundle) . '__' . $base_class . '-label';

  //
  // Add some default classes to the items wrapper
  $content_classes[] = $base_class . '-items';

  //
  // Add some default classes to the item
  $item_classes[] = $base_class . '-item';
  $item_classes[] = drupal_html_class($bundle) . '__' . $base_class;
  $item_classes[] = drupal_html_class($bundle) . '--' . drupal_html_class($mode) . '__' . $base_class;
  foreach ($vars['items'] as $delta => $item) {
    $item_classes[] = $delta % 2 ? 'odd' : 'even';
    $vars['item_attributes_array'][$delta]['class'] = $item_classes;
  }

  //
  // @TODO Row classes setup needs more work. Need to set up or allow
  // First, last, and row number classes for each row.
  $row_classes = 'field-row ' . $base_class . '-row ' . 'items-per-row-' . $items_per_row;
  $vars['row_attributes']['class'] = $row_classes;
}

/**
 * Overrides theme_field().
 * Remove the hard coded classes so we can add them in preprocess functions.
 */
function philbo_field($vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $field = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $items_per_row = $vars['items_per_row'];
  $item_count = count($vars['items']);

  $output = '';

  //
  // Render the label, if it's not hidden.
  if (!$vars['label_hidden']) {
    $output .= '<' . $vars['label_wrapper_element'] . ' ' . $vars['title_attributes'] . '><span>' . $vars['label'] . '</span></' . $vars['label_wrapper_element'] . '>';
  }
  if ($vars['use_items_wrapper']) {
    $output .= '<'. $vars['items_wrapper_element'] . ' ' . $vars['content_attributes'] . '>';
  }
  foreach ($vars['items'] as $delta => $item) {
    //
    // Render the individual item, including item row wrappers.
    // Start first row
    if (($vars['use_row_wrapper']) && ($delta == 0)) {
      $output .= '<'. $vars['row_wrapper_element'] . ' class="' . $vars['row_attributes']['class'] . '" >';
    }
    //
    // Wrap individual item
    if ($vars['use_item_wrapper']) {
      $output .= '<' . $vars['item_wrapper_element'] . ' ' . $vars['item_attributes'][$delta] . '>';
    }
    $output .= _field_render_content($item, $field, $bundle, $mode);
    if ($vars['use_item_wrapper']) {
      $output .= '</' . $vars['item_wrapper_element'] . '>';
    }
    //
    // Create row divider
    if ($vars['use_row_wrapper'] && ((($delta + 1) % $items_per_row) == 0) && (($delta + 1) != $item_count)) {
      $output .= '</'. $vars['row_wrapper_element'] . '><'. $vars['row_wrapper_element'] . ' class="' . $vars['row_attributes']['class'] . '" >';
    }
    //
    // End last row
    if (($vars['use_row_wrapper']) && (($delta + 1) == $item_count)) {
      $output .= '</'. $vars['row_wrapper_element'] . '>';
    }
  }
  if ($vars['use_items_wrapper']) {
    $output .= '</' . $vars['items_wrapper_element'] . '>';
  }
  // Render the top-level DIV.
  if ($vars['use_field_wrapper']) {
    $output = '<' . $vars['item_wrapper_element'] . ' class="' . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . '</' . $vars['item_wrapper_element'] . '>';
  }

  return $output;
}

/**
 * Implements theme_field__field_type().
 */
function philbo_field__FIELD_NAME($vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $field = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $items_per_row = $vars['items_per_row'];
  $item_count = count($vars['items']);

  $output = '';

  //
  // Render the label, if it's not hidden.
  if (!$vars['label_hidden']) {
    $output .= '<h3 class="field-label">' . $vars['label'] . ': </h3>';
  }

  //
  // Render the items.
  $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
  foreach ($vars['items'] as $delta => $item) {
    $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $vars['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
  }
  $output .= '</ul>';

  //
  // Render the top-level DIV.
  $output = '<div class="' . $vars['classes'] . (!in_array('clearfix', $vars['classes_array']) ? ' clearfix' : '') . '"' . $vars['attributes'] .'>' . $output . '</div>';

  return $output;
}

/**
 * Helper function to render content.
 */
function _field_render_content($item, $field, $bundle, $view_mode) {
  //
  // Set specific field display settings like summary/text length or image style here
  // Useful for overriding the field display output and not allowing a site maintainer
  // to accidently change it in the UI.
  if ($field == 'FIELD_NAME') {
    $content = 'DO SOMETHING TO THE FIELD ITEM OUTPUT HERE, LIKE SET IMAGE STYLE FOR AN IMAGE';
  }
  // else render as mother nature intended.
  else {
    $content = drupal_render($item);
  }

  return $content;
}