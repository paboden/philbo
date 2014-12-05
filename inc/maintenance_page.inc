<?php

/**
 * @file
 * Maintenance page template functions.
 */

/**
 * Implements hook_preprocess_maintenance_page().
 */
function philbo_preprocess_maintenance_page(&$vars, $hook) {

  //
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  philbo_preprocess_html($variables, $hook);
  philbo_preprocess_page($variables, $hook);

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
  if (!$variables['db_is_active']) {
    $variables['site_name'] = '';
  }
  drupal_add_css(drupal_get_path('theme', 'bartik') . '/css/maintenance-page.css');
}

function philbo_process_maintenance_page(&$vars, $hook) {
  //
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  philbo_preprocess_html($vars);

  //
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    //
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    //
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
}