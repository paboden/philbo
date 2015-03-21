<?php

/**
 * @file
 * Region functions.
 */

function philbo_preprocess_region(&$variables) {
  //
  // Create the $content variable that templates expect.
  $variables['content'] = $variables['elements']['#children'];
  $region = $variables['elements']['#region'];

  //
  // Reset the classes array to just contain region.
  $variables['classes_array'] = array();
  $classes = &$variables['classes_array'];
  $classes[] = 'region';

  //
  // Set the default inner region wrapper classes to region-inner.
  $variables['inner_classes'] = array();
  $inner_classes = &$variables['inner_classes'];
  $inner_classes[] = 'region-inner';

  //
  // Region (outer) wrapper.
  $variables['id'] = 'region-' . drupal_html_id($region);
  $variables['region_wrapper_element'] = 'div';
  $region_wrapper_element = &$variables['region_wrapper_element'];

  //
  // Region-inner (inner) wrapper.
  $variables['use_region_inner_wrapper'] = FALSE;
  $use_region_inner_wrapper = &$variables['use_region_inner_wrapper'];
  $variables['region_inner_wrapper_element'] = 'div';
  $region_inner_wrapper_element = &$variables['region_inner_wrapper_element'];

  //
  // Set our specific cases per region
  switch($region) {
    case 'content' :
    $region_wrapper_element = 'section';
    break;
    case 'sidebar_first' :
    $region_wrapper_element = 'aside';
    break;
    case 'sidebar_second' :
    $region_wrapper_element = 'aside';
    break;
  }

  //
  // Turn region inner classes array into string for printing.
  $inner_classes = implode($inner_classes, ' ');
}