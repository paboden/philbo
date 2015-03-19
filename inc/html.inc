<?php

/**
 * @file
 * HTML template functions.
 */

/**
 * Implements hook_preprocess_html()
 */
function philbo_preprocess_html(&$vars) {
  //
  // For each region that has content, add a class of 'REGION-active' to the body,
  // This is helpful for knowing if a sidebar or footer region has content
  // for triggering some javascript or refining our css for different layouts
  // For each region that has no content, add a class of 'REGION-inactive'.
  global $theme;
  $regions = system_region_list($theme);
  foreach ($regions as $region => $region_name) {
    if (!empty($vars['page'][$region])) {
      $region = drupal_html_class($region);
      $vars['classes_array'][] = $region . '-active';
    }
    else {
      $region = drupal_html_class($region);
      $vars['classes_array'][] = $region . '-inactive';
    }

  }

  //
  // We want to add classes to the body based on succession of url
  // This is how we make section based css body classes
  // Example: news/blog/recent would build "section-news news news-blog news-blog-recent"
  global $base_path;
  list(,$path) = explode($base_path, $_SERVER['REQUEST_URI'], 2);
  list($path,) = explode('?', $path, 2);
  $path = rtrim($path, '/');

  //
  // Construct the id name from the path, replacing slashes with dashes.
  list($body_class,) = explode('/', $path, 2);
  if (!empty($body_class)) {
    $body_class = 'section-'. $body_class;
    $vars['classes_array'][] = $body_class;
  }

  //
  // Construct classes if its a page-manager panels page
  if (function_exists('page_manager_get_current_page')) {
    $page = page_manager_get_current_page();
    if ($page) {
      $vars['classes_array'][] = 'page-manager';
      $vars['classes_array'][] = 'page-manager-' . $page['name'];
      if (isset($page['handler']->conf['display']->layout)) {
        $vars['classes_array'][] = 'page-manager-layout-' . $page['handler']->conf['display']->layout;
      }
    }
  }

  //
  // Viewport!
  $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'initial-scale=1.0',
    ),
  );
  drupal_add_html_head($viewport, 'viewport');

  //
  // Force IE to use most up-to-date render engine.
  $xua = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=edge',
    ),
  );
  drupal_add_html_head($xua, 'x-ua-compatible');

  //
  // Initializes attributes which are specific to the html and body elements.
  $vars['html_attributes_array'] = array();
  $vars['rdf_attributes_array'] = array();
  $vars['body_attributes_array'] = array();

  //
  // HTML element attributes.
  $vars['html_attributes_array']['lang'] = $GLOBALS['language']->language;
  $vars['html_attributes_array']['dir'] = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

  //
  // Update RDF Namespacing
  if (module_exists('rdf')) {
    //
    // Adds RDF namespace prefix bindings in the form of an RDFa 1.1 prefix
    // attribute inside the html element.
    $prefixes = array();
    foreach (rdf_get_namespaces() as $prefix => $uri) {
      $vars['rdf_attributes_array']['prefix'][] = $prefix . ': ' . $uri . "\n";
    }
  }

  //
  // Flatten out html_attributes and body_attributes.
  $vars['html_attributes'] = drupal_attributes($vars['html_attributes_array']);
  $vars['rdf_attributes'] = drupal_attributes($vars['rdf_attributes_array']);
  $vars['body_attributes'] = drupal_attributes($vars['body_attributes_array']);
}

/**
  * Implements hook_process_html_tag
  */
function philbo_process_html_tag(&$vars) {
  $element = &$vars['element'];

  //
  // Remove type="..." and CDATA prefix/suffix.
  unset($element['#attributes']['type'], $element['#value_prefix'], $element['#value_suffix']);

  //
  // Remove media="all" but leave others unaffected.
  if (isset($element['#attributes']['media']) && $element['#attributes']['media'] === 'all') {
    unset($element['#attributes']['media']);
  }
}