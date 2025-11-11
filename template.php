<?php

/**
 * @file
 * Include template and preprocess function files.
 */
$files = file_scan_directory(drupal_get_path('theme', 'philbo'). '/inc', '/\.inc/');
foreach($files as $file) {
  /** @noinspection PhpIncludeInspection */
  require_once $file->uri;
}

/**
 * Helper function to build out a complete block from the render array().
 */
function build_block($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);

  return $block_rendered;
}

/**
 * Helper function to render image content.
 */
function format_picture($node, $field_name, $delta, $picture_group) {
  $image = get_field($node, $field_name);
  $formatter = array(
    'type' => 'picture',
    'settings' => array(
      'picture_group' => $picture_group,
    ),
  );

  return field_view_value('node', $node, $field_name, $image[$delta], $formatter);
}

/**
 * Helper function to render image content.
 */
function format_image($node, $field_name, $delta, $image_style_name) {
  $image = get_field($node, $field_name);
  $formatter = array(
    'type' => 'picture',
    'settings' => array(
      'image_style' => $image_style_name,
    ),
  );

  return field_view_value('node', $node, $field_name, $image[$delta], $formatter);
}

/**
 * Hack alert!
 * Sometimes the node has a language identifier on the field, sometimes it does
 * not.  This is a bug somewhere in this site's code, but I don't know where
 * the bug exists.
 */
function get_field($node, $field_name) {

  if (isset($node->{$field_name}[0])) {
    return $node->{$field_name};
  }
  else {
    return field_get_items('node', $node, $field_name, '');
  }
}

/**
 * Helper function to render a field with a formatter or other options.
 * Set specific field display settings like summary/text length or image
 * style here. Useful for overriding the field display output and not
 * allowing a site maintainer to accidentally change it in the UI.
 */
function render_field($item, $field, $bundle, $view_mode) {

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

/**
 * Adds helper variables derived from variables defined during preprocessing.
 *
 * @see theme()
 * @see template_preprocess()
 */
function philbo_process(&$variables, $hook) {

  // Flatten out inner classes.
  if (isset($variables['inner_classes_array'])) {
    $variables['inner_classes'] = implode(' ', $variables['inner_classes_array']);
  }

  if (isset($variables['row_classes'])) {
    $variables['row_classes'] = implode(' ', $variables['row_classes']);
  }

//  if (isset($variables['item_attributes_array'])) {
//    $variables['item_attributes'] = drupal_render($variables['item_attributes_array']);
//  }
}