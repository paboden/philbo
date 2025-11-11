<?php

/**
 * @file
 * Block template functions.
 */

/**
 * Implements hook_preprocess_block().
 * 
 * System main menu block
 */
function philbo_preprocess_block__system__main(&$vars) {

  // Wrap the whole block with a container.
  $vars['use_block_wrapper'] = TRUE;

  // Wrap the whole block with this element.
  $vars['block_wrapper_element'] = 'div';
  
  // Add a class to the existing classes in the block wrapper
  $vars['classes_array'][] = 'system-main';
}

/**
 * Implements hook_preprocess_block().
 *
 * User login block
 */
function philbo_preprocess_block__user__login(&$vars) {

  // Always display title no matter what.
  $vars['display_title'] = TRUE;

  // Wrap the title in a container
  $vars['use_title_wrapper'] = TRUE;

  // Set a custom title/subject
  $vars['title'] = t('Login to admin your site');

  // Wrap the title with this element.
  $vars['title_wrapper_element'] = 'h4';

  // Add this class to the existing classes for the title/subject
  $vars['title_classes'][] = '';
}

/**
 * Implements hook_preprocess_block().
 *
 * System "Powered by Drupal" block
 */
function philbo_preprocess_block__system__powered_by(&$vars) {

  // wrap the content with a container
  $vars['use_content_wrapper'] = TRUE;

  // wrap the content wrapper with this element
  $vars['content_wrapper_element'] = 'div';

  // add this class to the existing classes for the content
  $vars['content_classes'][] = '';
}

/**
 * Implements hook_preprocess_block().
 *
 * User login block
 */
function philbo_preprocess_block__region__header(&$vars) {

  // Always hide title no matter what.
  $vars['display_title'] = FALSE;
}

/**
 * Implements hook_preprocess_block().
 */
function philbo_preprocess_block(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $module = $vars['block']->module;
  $delta = $vars['block']->delta;
  $region = $vars['block']->region;

  // Custom block wrapper html element. defaults to TRUE and div as the wrapper.
  $vars['use_block_wrapper'] = TRUE;
  $vars['block_wrapper_element'] = 'div';

  // Control the display of the title.
  // Defaults to TRUE with an h2 as the wrapper.
  $vars['display_title'] = TRUE;
  $vars['use_title_wrapper'] = TRUE;
  $vars['title_wrapper_element'] = 'h2';
  $vars['title'] = $vars['block']->subject;

  // Control the content output.
  // Defaults to TRUE with a div as the wrapper.
  $vars['use_content_wrapper'] = TRUE;
  $vars['content_wrapper_element'] = 'div';

  // Control and set block classes. default is set for title and content.
  $vars['classes_array'] = array();
  $vars['title_attributes_array']['class'][] = 'block-title';
  $vars['content_attributes_array']['class'][] = 'block-content';

  // Block-module specific preprocess functions
  // THEME_preprocess_block__MODULE(&$vars)
  $function = __FUNCTION__ . '__' . $module;
  if (function_exists($function)) {
    $function($vars);
  }

  // Block-module-delta specific preprocess functions
  // THEME_preprocess_block__MODULE__DELTA(&$vars)
  $function = __FUNCTION__ . '__' . $module . '__' . str_replace('-','_' , $delta);
  if (function_exists($function)) {
    $function($vars);
  }

  // Block-module-delta specific preprocess functions
  // THEME_preprocess_block__region__REGION_NAME(&$vars)
  $function = __FUNCTION__ . '__region__' . $region;
  if (function_exists($function)) {
    $function($vars);
  }

  // Block-module-delta specific preprocess functions
  // THEME_preprocess_block__MODULE__region__REGION_NAME(&$vars)
  $function = __FUNCTION__ . '__' . $module . '__region__' . $region;
  if (function_exists($function)) {
    $function($vars);
  }
}