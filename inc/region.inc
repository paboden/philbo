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
  $variables['inner_classes'] = array();

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
  $inner_classes = &$variables['inner_classes'];

  //
  // Create default inner region wrapper classes
  $inner_classes[] = 'region-inner';
  $inner_classes[] = 'region-' . drupal_html_class($region) . '-inner';

  //
  // Set our specific cases per region
  switch($region) {
    case 'menu' :
    $region_wrapper_element = 'nav';
    break;
    case 'content' :
    break;
  }

  //
  // Turn region inner classes array into string for printing.
  $inner_classes = implode($inner_classes, ' ');
}