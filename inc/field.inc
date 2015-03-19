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
  $vars['field_name'] = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $vars['bundle'] = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $vars['view_mode'] = $vars['element']['#view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $row_classes = &$vars['row_classes'];
  $item_classes = array();
  $base_class = $field;
  $field_bundle = $field . '__' . $bundle;
  $field_bundle_mode = $field . '__' . $bundle . '__' . $mode;

  //
  // Remove "field-" from $base_class and set field classes
  $base_class = drupal_html_class($base_class);
  if (strpos($base_class, 'field-') === 0) {
    $base_class = substr($base_class, 6);
  }

  //
  // Field (outer) wrapper.
  $vars['use_field_wrapper'] = TRUE;
  $use_field_wrapper = &$vars['use_field_wrapper'];
  $vars['field_wrapper_element'] = 'div';
  $field_wrapper_element = &$vars['field_wrapper_element'];
  $classes = array();
  $classes[] = 'field';
  $classes[] = $base_class;

  //
  // Label wrapper and base class settings.
  $vars['label_hidden'] = FALSE;
  $label_hidden = &$vars['label_hidden'];
  $label = &$vars['label'];
  $vars['label_wrapper_element'] = 'div';
  $label_wrapper_element = &$vars['label_wrapper_element'];
  $title_classes[] = 'label';
  $title_classes[] = $base_class . '-label';
  $title_classes[] = drupal_html_class($bundle) . '-' . $base_class . '-label';

  //
  // Items wrapper and base class settings.
  $vars['use_items_wrapper'] = FALSE;
  $use_items_wrapper = &$vars['use_items_wrapper'];
  $vars['items_wrapper_element'] = 'div';
  $items_wrapper_element = &$vars['items_wrapper_element'];
  $content_classes[] = $base_class . '-items';

  //
  // Item per Row wrapper and base class settings.
  $vars['use_row_wrapper'] = FALSE;
  $use_row_wrapper = &$vars['use_row_wrapper'];
  $vars['items_per_row'] = 1;
  $items_per_row = &$vars['items_per_row'];
  $vars['row_wrapper_element'] = 'div';
  $row_wrapper_element = &$vars['row_wrapper_element'];
  $vars['item_count'] = count($vars['items']);
  $row_classes = 'field-row ' . $base_class . '-row';
  $vars['row_classes'] = $row_classes;

  //
  // Individual item wrapper and base class settings.
  $vars['use_item_wrapper'] = TRUE;
  $use_item_wrapper = &$vars['use_item_wrapper'];
  $vars['item_wrapper_element'] = 'div';
  $item_wrapper_element = &$vars['item_wrapper_element'];
  // @TODO get item classes rendering
  //$item_classes[] = $base_class . '-item';
  //$item_classes[] = drupal_html_class($bundle) . '-' . $base_class;
  //$item_classes[] = drupal_html_class($bundle) . '-' . drupal_html_class($mode) . '-' . $base_class;
  foreach ($vars['items'] as $delta => $item) {
    $vars['item_attributes_array'][$delta]['class'] = $delta % 2 ? 'item-' . ($delta + 1) . ' even' : 'item-' . ($delta + 1) . ' odd';
  }

  //
  // BELOW IS WHERE WE APPLY OUR SETTINGS TO EACH FIELD

  //
  // Set our custom settings per field.
  // This can be overridden by field_bundle and field_bundle_mode switch case.
  switch ($field) {
    case 'body':
      $label_hidden = TRUE;
      break;
  }

  //
  // Set our custom settings per field and the content type it is used in.
  // This can override the field switch case.
  // This can be overridden by field_bundle_mode switch case.
  switch ($field_bundle) {
    case 'body__article':
      $label_hidden = FALSE;
      $label_wrapper_element = 'h3';
      $label = t('My Body');
      break;
  }

  //
  // Set our custom settings per field, the content type it is used in, and
  // the view mode that it is displayed in. This can override the previous
  // switch cases.
  switch ($field_bundle_mode) {
    case 'body__article__teaser':
      $label_hidden = FALSE;
      $label_wrapper_element = 'h2';
      $label = t('My Body Teaser');
      break;

    case 'field_image__article__full':
      $label_hidden = FALSE;
      $label_wrapper_element = 'h2';
      $label = t('Article Images');
      $use_field_wrapper = FALSE;
      $use_items_wrapper = FALSE;
      $use_row_wrapper = TRUE;
      $items_per_row = 2;
      $row_wrapper_element = 'div';
      $use_item_wrapper = FALSE;
      break;

    case 'field_image__article__teaser':
      $label_hidden = FALSE;
      $label_wrapper_element = 'h3';
      break;

    case 'field_tags__article__full':
      $label_hidden = FALSE;
      $label_wrapper_element = 'h2';
      $use_row_wrapper = TRUE;
      $items_per_row = 3;
      $row_wrapper_element = 'div';
      break;

    case 'field_tags__article__teaser':
      $label_hidden = TRUE;
      break;
  }

}

/**
 * Helper function to render a field with a formatter or other options.
 */
function render_field($item, $field, $bundle, $view_mode) {
  //
  // Set specific field display settings like summary/text length or image style here
  // Useful for overriding the field display output and not allowing a site maintainer
  // to accidently change it in the UI.
  switch ($field) {
    case 'FIELD_NAME':
      $content = 'DO SOMETHING TO THE FIELD ITEM OUTPUT HERE, LIKE SET IMAGE STYLE FOR AN IMAGE';
      break;

    default:
      $content = drupal_render($item);
      break;
  }

  return $content;
}