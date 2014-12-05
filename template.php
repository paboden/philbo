<?php

/**
 * @file
 * Include template function files.
 */
require_once dirname(__FILE__) . '/inc/block.inc';
require_once dirname(__FILE__) . '/inc/breadcrumb.inc';
require_once dirname(__FILE__) . '/inc/comments.inc';
require_once dirname(__FILE__) . '/inc/css.inc';
require_once dirname(__FILE__) . '/inc/field.inc';
require_once dirname(__FILE__) . '/inc/form.inc';
require_once dirname(__FILE__) . '/inc/html.inc';
require_once dirname(__FILE__) . '/inc/js.inc';
require_once dirname(__FILE__) . '/inc/link.inc';
require_once dirname(__FILE__) . '/inc/maintenance_page.inc';
require_once dirname(__FILE__) . '/inc/menu.inc';
require_once dirname(__FILE__) . '/inc/messages.inc';
require_once dirname(__FILE__) . '/inc/node.inc';
require_once dirname(__FILE__) . '/inc/page.inc';
require_once dirname(__FILE__) . '/inc/pager.inc';
require_once dirname(__FILE__) . '/inc/panels.inc';
require_once dirname(__FILE__) . '/inc/region.inc';
require_once dirname(__FILE__) . '/inc/search.inc';
require_once dirname(__FILE__) . '/inc/taxonomy_term.inc';
require_once dirname(__FILE__) . '/inc/user.inc';
require_once dirname(__FILE__) . '/inc/views.inc';

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
function format_image($node, $field_name, $delta, $picture_group) {
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