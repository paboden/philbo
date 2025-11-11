<?php

/**
 * @file
 * Region functions.
 */

/**
 * Implements hook_preprocess_region().
 *
 * Content region
 */
function philbo_preprocess_region__content(&$vars) {

  // Enable region to use (outer) wrapper
  $vars['use_region_wrapper'] = TRUE;

  // Wrap this region with this element
  $vars['region_wrapper_element'] = 'section';

  // Reset/remove all classes in the wrapper and just set region--name.
  $vars['classes_array'] = array();
  $vars['classes_array'][] = 'region--content';
}

/**
 * Implements hook_preprocess_region().
 *
 * Sidebar_first region
 */
function philbo_preprocess_region__sidebar_first(&$vars) {

  // Wrap this region with this element
  $vars['region_wrapper_element'] = 'section';

  // Set region to use inner wrapper
  $vars['use_region_inner_wrapper'] = FALSE;

  // Reset/remove all classes in the wrapper and just set region--name.
  $vars['classes_array'] = array();
  $vars['classes_array'][] = 'region--sidebar-first';
}

/**
 * Implements hook_preprocess_region().
 *
 * Sidebar_first region
 */
function philbo_preprocess_region__sidebar_second(&$vars) {

  // Wrap this region with this element
  $vars['region_wrapper_element'] = 'section';

  // Set region to use inner wrapper
  $vars['use_region_inner_wrapper'] = FALSE;

  // Reset/remove all classes in the wrapper and just set region--name.
  $vars['classes_array'] = array();
  $vars['classes_array'][] = 'region--sidebar-second';
}

/**
 * Implements hook_preprocess_region().
 */
function philbo_preprocess_region(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $region = $vars['elements']['#region'];

  // Create the $content variable that templates expect.
  $vars['content'] = $vars['elements']['#children'];

  // Enable or disable region (outer) wrapper.
  // Defaults to TRUE with 'div' as the wrapping element.
  $vars['use_region_wrapper'] = TRUE;
  $vars['region_wrapper_element'] = 'div';

  // Enable or disable region-inner (inner) wrapper.
  // Defaults to TRUE with 'div' as the wrapping element.
  $vars['use_region_inner_wrapper'] = FALSE;
  $vars['region_inner_wrapper_element'] = 'div';

  // Reset the classes array.
  // Set new classes of the region and region--name.
  $vars['classes_array'] = array();
  $vars['classes_array'][] = 'region';
  $vars['classes_array'][] = 'region--' . drupal_html_id($region);

  // Set the default inner region wrapper classes to region-inner.
  $vars['inner_classes_array'] = array();
  $vars['inner_classes_array'][] = 'region-inner';

  // Block-module specific preprocess functions
  // THEME_preprocess_region__REGION-NAME(&$vars)
  $function = __FUNCTION__ . '__' . $region;
  if (function_exists($function)) {
    $function($vars);
  }
}