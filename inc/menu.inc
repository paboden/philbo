<?php

/**
 * @file
 * Menu template functions.
 */

/**
 * Implements hook_preprocess_menu_link().
 */
function philbo_preprocess_menu_link(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $menu = $vars['element']['#original_link']['menu_name'];
  $mlid = $vars['element']['#original_link']['mlid'];
  $item_classes = &$vars['element']['#attributes']['class'];
  $link_classes = &$vars['element']['#localized_options']['attributes']['class'];

  //
  // Add global classes to all menu links
  $item_classes[] = 'nav-item';
  $link_classes[] = 'nav-link';

  //
  // Items wrapper.
  $vars['use_menu_items_wrapper'] = FALSE;
  $use_menu_items_wrapper = &$vars['use_menu_items_wrapper'];
  $vars['menu_items_wrapper_element'] = 'li';
  $menu_items_wrapper_element = &$vars['menu_items_wrapper_element'];

  switch($menu) {
    case 'main_menu':
    $use_menu_items_wrapper = TRUE;
    $menu_items_wrapper_element = 'li';
    $link_classes = 'main-menu-link';
    break;
  }

}

/**
 * Implements theme_menu_link().
 */
function philbo_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  $output = '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

  return $output;
}

/**
 * Implements hook_preprocess_menu_tree().
 */
function philbo_preprocess_menu_tree(&$vars) {
  //
  // Set shortcut variables. Hooray for less typing!
  $menu = '';
  $menu_classes = array();
  $localized_classes = array();

  //
  // Add global classes to all menu links
  $menu_classes[] = 'nav';
  $menu_classes[] = 'menu-nav';

  //
  // Settings for menu wrapper.
  $vars['use_menu_wrapper'] = TRUE;
  $use_menu_wrapper = &$vars['use_menu_wrapper'];
  $vars['menu_wrapper_element'] = 'ul';
  $menu_wrapper_element = &$vars['menu_wrapper_element'];

  switch($menu) {
    case 'main_menu':
    $use_menu_wrapper = TRUE;
    $menu_wrapper_element = 'ul';
    $menu_classes[] = 'nav-inline';
    $localized_classes[] = 'nav-inline';
    break;
  }
}

/**
 * Implements theme_menu_tree().
 */
function philbo_menu_tree(&$vars) {
  if ($vars['use_menu_wrapper']) {
    $menu_tree = '<' . $vars['menu_wrapper_element'] . ' class="nav nav-inline">' . $vars['tree'] . '</' . $vars['menu_wrapper_element'] . '>';
  }
  else {
    $menu_tree = '<ul class="nav menu-nav">' . $vars['tree'] . '</ul>';
  }

  return $menu_tree;
}

/**
 * Implements theme_menu_tree() for the main menu.
 */
function philbo_menu_tree__MENU_NAME(&$vars) {

}

