<?php

// THIS IS NOT FUNCTIONING YET. ITS ON THE TODO LIST.

/**
 * Implements hook_form_system_theme_settings_alter() function.
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function philbo_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  // Create the form using Forms API
  $form['breadcrumb'] = array(
    '#type' => 'fieldset',
    '#title' => t('Breadcrumb settings'),
    '#weight' => -1000,
  );
  $form['breadcrumb']['philbo_breadcrumb'] = array(
    '#type' => 'select',
    '#title' => t('Display breadcrumb'),
    '#default_value' => theme_get_setting('philbo_breadcrumb'),
    '#options' => array(
      'yes' => t('Yes'),
      'admin' => t('Only in admin section'),
      'no' => t('No'),
    ),
  );
  $form['breadcrumb']['breadcrumb_options'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        ':input[name="philbo_breadcrumb"]' => array('value' => 'no'),
      ),
    ),
  );
  $form['breadcrumb']['breadcrumb_options']['philbo_breadcrumb_separator'] = array(
    '#type' => 'textfield',
    '#title' => t('Breadcrumb separator'),
    '#description' => t('Text only. Don’t forget to include spaces.'),
    '#default_value' => theme_get_setting('philbo_breadcrumb_separator'),
    '#size' => 5,
    '#maxlength' => 10,
  );
  $form['breadcrumb']['breadcrumb_options']['philbo_breadcrumb_home'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show home page link in breadcrumb'),
    '#default_value' => theme_get_setting('philbo_breadcrumb_home'),
  );
  $form['breadcrumb']['breadcrumb_options']['philbo_breadcrumb_trailing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Append a separator to the end of the breadcrumb'),
    '#default_value' => theme_get_setting('philbo_breadcrumb_trailing'),
    '#description' => t('Useful when the breadcrumb is placed just before the title.'),
    '#states' => array(
      'disabled' => array(
        ':input[name="philbo_breadcrumb_title"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['breadcrumb']['breadcrumb_options']['philbo_breadcrumb_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Append the content title to the end of the breadcrumb'),
    '#default_value' => theme_get_setting('philbo_breadcrumb_title'),
    '#description' => t('Useful when the breadcrumb is not placed just before the title.'),
  );

  $form['support'] = array(
    '#type' => 'fieldset',
    '#title' => t('Accessibility and support settings'),
    '#weight' => -999,
  );

  $form['support']['philbo_skip_link_anchor'] = array(
    '#type' => 'textfield',
    '#title' => t('Anchor ID for the “skip link”'),
    '#default_value' => theme_get_setting('philbo_skip_link_anchor'),
    '#field_prefix' => '#',
    '#description' => t('Specify the HTML ID of the element that the accessible-but-hidden “skip link” should link to. Note: that element should have the <code>tabindex="-1"</code> attribute to prevent an accessibility bug in webkit browsers. (<a href="!link">Read more about skip links</a>.)', array('!link' => 'https://drupal.org/node/467976')),
  );

  $form['support']['philbo_skip_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text for the “skip link”'),
    '#default_value' => theme_get_setting('philbo_skip_link_text'),
    '#description' => t('For example: <em>Jump to navigation</em>, <em>Skip to content</em>'),
  );

  $form['default'] = array(
    '#type' => 'fieldset',
    '#title' => t('Core Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight'=> 0,
  );

  $form['default']['theme_settings'] = $form['theme_settings'];
  $form['default']['logo'] = $form['logo'];
  $form['default']['favicon'] = $form['favicon'];
  unset($form['theme_settings']);
  unset($form['logo']);
  unset($form['favicon']);

}
