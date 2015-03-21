<?php

/**
 * @file
 * Preprocess template functions.
 */

/**
 * Implements hook_preprocess_link().
 */
function philbo_preprocess_link(&$vars) {

}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function philbo_preprocess_maintenance_page(&$vars, $hook) {

  //
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  philbo_preprocess_html($vars, $hook);
  philbo_preprocess_page($vars, $hook);

  //
  // This preprocessor will also be used if the db is inactive. To ensure your
  // theme is used, add the following line to your settings.php file:
  // $conf['maintenance_theme'] = 'temp';
  // Also, check $vars['db_is_active'] before doing any db queries.
  $css_options = array(
    'group' => CSS_THEME,
    'every_page' => TRUE,
    'weight' => 9999,
    'preprocess' => FALSE,
  );
  drupal_add_css(path_to_theme() . '/css/maintenance.css', $css_options);

  //
  // By default, site_name is set to Drupal if no db connection is available
  // or during site installation. Setting site_name to an empty string makes
  // the site and update pages look cleaner.
  // @see template_preprocess_maintenance_page
  if (!$vars['db_is_active']) {
    $vars['site_name'] = '';
  }
  drupal_add_css(drupal_get_path('theme', 'bartik') . '/css/maintenance-page.css');
}
