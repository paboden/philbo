<?php

/**
 * @file
 * Block template functions.
 */

/**
 * Implements hook_preprocess_block().
 */
function philbo_preprocess_block(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $subject = &$vars['block']->subject;
  $content = &$vars['content'];

  //
  // Custom block wrapper html element.
  $vars['wrapper_element'] = 'div';
  $wrapper_element = &$vars['wrapper_element'];

  //
  // Use a title wrapper
  $vars['use_title_wrapper'] = TRUE;
  $use_title_wrapper = &$vars['use_title_wrapper'];
  $vars['title_wrapper_element'] = 'h2';
  $title_wrapper_element = &$vars['title_wrapper_element'];

  //
  // Use a content wrapper
  $vars['use_content_wrapper'] = TRUE;
  $use_content_wrapper = &$vars['use_content_wrapper'];
  $vars['content_wrapper_element'] = 'div';
  $content_wrapper_element = &$vars['content_wrapper_element'];

  //
  // Add global classes to all blocks.
  $classes[] = drupal_html_class($block_id);
  $title_classes[] = 'block-title';
  $content_classes[] = 'block-content';

  //
  // Alter blocks based on their ID (module-delta).
  switch ($block_id) {
    case 'system-main-menu':
      $classes[] = '';
      $title_classes[] = '';
      $content_classes[] = '';
      $wrapper_element = 'div';
      $use_title_wrapper = TRUE;
      $title_wrapper_element = 'h1';
      $use_content_wrapper = TRUE;
      $content_wrapper_element = 'div';
      break;
    case 'system-main':
      $use_title_wrapper = FALSE;
      $subject = '';
  }
}

/**
 * Implements hook_block_info_alter().
 */
function philbo_block_info_alter(&$blocks, $theme, $code_blocks) {

}

/**
 * Implements hook_block_view_alter().
 */
function philbo_block_view_alter(&$data, $block) {

}

/**
 * Implements hook_block_view_MODULE_DELTA_alter().
 */
function philbo_block_view_MODULE_DELTA_alter(&$data, $block) {

}
