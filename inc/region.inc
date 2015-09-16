<?php

/**
 * @file
 * Region functions.
 */

function philbo_preprocess_region(&$vars) {
  //
  // Create the $content variable that templates expect.
  $vars['content'] = $vars['elements']['#children'];
  $region = $vars['elements']['#region'];

  //
  // Region (outer) wrapper.
  $vars['use_region_wrapper'] = TRUE;
  $use_region_wrapper = &$vars['use_region_wrapper'];
  $vars['region_wrapper_element'] = 'div';
  $region_wrapper_element = &$vars['region_wrapper_element'];

  //
  // Region-inner (inner) wrapper.
  $vars['use_region_inner_wrapper'] = FALSE;
  $use_region_inner_wrapper = &$vars['use_region_inner_wrapper'];
  $vars['region_inner_wrapper_element'] = 'div';
  $region_inner_wrapper_element = &$vars['region_inner_wrapper_element'];

  //
  // Reset the classes array to just contain region.
  $vars['classes_array'] = array();
  $classes = &$vars['classes_array'];
  $classes[] = 'region';
  $classes[] = 'region--' . drupal_html_id($region);

  //
  // Set the default inner region wrapper classes to region-inner.
  $vars['inner_classes'] = array();
  $inner_classes = &$vars['inner_classes'];
  $inner_classes[] = 'region-inner';

  //
  // Set our specific cases per region
  switch($region) {
    case 'content' :
      $use_region_wrapper = TRUE; // Set region to use (outer) wrapper
      $region_wrapper_element = 'section'; // wrap region with this element
      $classes = array(); // remove all classes from (outer) wrapper
      $classes[] = 'region--content'; // set new single class
      break;
    case 'sidebar_first' :
      $use_region_inner_wrapper = TRUE; // Set region to use inner wrapper
      $region_inner_wrapper_element = 'section'; // wrap inner region with this element
      break;

  }

  //
  // Turn region outer and inner classes array into string for printing.
  $inner_classes = implode($inner_classes, ' ');
}