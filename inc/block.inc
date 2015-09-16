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
  $block_id = $vars['block']->module . '--' . $vars['block']->delta;
  $module = $vars['block']->module;
  //
  // Custom block wrapper html element.
  $vars['use_block_wrapper'] = TRUE;
  $use_block_wrapper = &$vars['use_block_wrapper'];
  $vars['block_wrapper_element'] = 'div';
  $block_wrapper_element = &$vars['wrapper_element'];
  //
  // Use a title wrapper
  $vars['display_title'] = TRUE;
  $display_title = &$vars['display_title'];
  $vars['use_title_wrapper'] = TRUE;
  $use_title_wrapper = &$vars['use_title_wrapper'];
  $vars['title_wrapper_element'] = 'h2';
  $title_wrapper_element = &$vars['title_wrapper_element'];
  $title = &$vars['block']->subject;
  //
  // Use a content wrapper
  $vars['use_content_wrapper'] = TRUE;
  $use_content_wrapper = &$vars['use_content_wrapper'];
  $vars['content_wrapper_element'] = 'div';
  $content_wrapper_element = &$vars['content_wrapper_element'];
  //
  // Control block classes.
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $subject = &$vars['block']->subject;
  $content = &$vars['content'];
  //
  // Set global classes for all blocks
  $title_classes[] = 'block-title';
  $content_classes[] = 'block-content';

  //
  // Alter blocks based on their ID (module--delta).
  switch ($block_id) {
    case 'system--main-menu':
      $use_block_wrapper = TRUE; // wrap the whole block with a container
      $block_wrapper_element = 'div'; // wrap the whole block with this element
      $classes[] = 'system-main'; // add this class to the existing classes in the block wrapper
      break;
    case 'user--login' :
      $display_title = TRUE; // always display title no matter what
      $use_title_wrapper = TRUE; // wrap the title in a container
      $title = t('Login to admin your site'); // Set a custom title/subject
      $title_wrapper_element = 'h4'; // wrap the title with this element
      $title_classes[] = ''; // add this class to the existing classes for the title/subject
      break;
    case 'system--powered-by' :
      $use_content_wrapper = TRUE; // wrap the content with a container
      $content_wrapper_element = 'div'; // wrap the content wrapper with this element
      $content_classes[] = ''; // add this class to the existing classes for the content
      break;
  }
}

/**
 * Implements hook_block_info_alter().
 */
function philbo_block_info_alter(&$blocks, $theme, $code_blocks) {
  // This hook function should be implemented in a module before the theme. But
  // if a change to a blocks output is more theme level then system level, then
  // this is ok. Example would be if you need to alter a block no matter what
  // theme is in use, then use a module function and not this one.
}

/**
 * Implements hook_block_view_alter().
 */
function philbo_block_view_alter(&$data, $block) {
  // This hook function should be implemented in a module before the theme. But
  // if a change to a blocks output is more theme level then system level, then
  // this is ok. Example would be if you need to alter a block no matter what
  // theme is in use, then use a module function and not this one.
}

/**
 * Implements hook_block_view_MODULE_DELTA_alter().
 */
function philbo_block_view_MODULE_DELTA_alter(&$data, $block) {
  // This hook function should be implemented in a module before the theme. But
  // if a change to a blocks output is more theme level then system level, then
  // this is ok. Example would be if you need to alter a block no matter what
  // theme is in use, then use a module function and not this one.
}
