<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use _render_field() to output them.
 *   can use render() to print, but _render_field has special settings.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $bundle: The entity to which the field is attached.
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $field_name: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<?php if ($use_field_wrapper): ?><<?php print $field_wrapper_element; ?> class="<?php print $classes; ?>"<?php print $attributes; ?>><?php endif; ?>
  <?php if (!$label_hidden): ?>
    <<?php print $label_wrapper_element ?> <?php print $title_attributes; ?>><span><?php print $label ?></span></<?php print $label_wrapper_element ?>>
  <?php endif; ?>
  <?php if ($use_items_wrapper): ?><<?php print $items_wrapper_element; ?> <?php print $content_attributes; ?>><?php endif; ?>
    <?php foreach ($items as $delta => $item): ?>
      <?php if (($use_row_wrapper) && ($delta == 0)): ?>
        <<?php print $row_wrapper_element; ?> class="<?php print $row_classes; ?>">
      <?php endif; ?>
        <?php if ($use_item_wrapper): ?><<?php print $item_wrapper_element; ?> <?php print $item_attributes[$delta]; ?>><?php endif; ?>
          <?php print render_field($item, $field_name, $bundle, $view_mode); ?>
        <?php if ($use_item_wrapper): ?></<?php print $item_wrapper_element; ?>><?php endif; ?>
      <?php if (($use_row_wrapper) && ((($delta + 1) % $items_per_row) == 0) && (($delta + 1) != $item_count)): ?>
        </<?php print $row_wrapper_element; ?>><<?php print $row_wrapper_element; ?> class="<?php print $row_classes; ?>">
      <?php endif; ?>
      <?php if (($use_row_wrapper) && (($delta + 1) == $item_count)): ?>
        </<?php print $row_wrapper_element; ?>>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php if ($use_items_wrapper): ?></<?php print $items_wrapper_element; ?>><?php endif; ?>
<?php if ($use_field_wrapper): ?></<?php print $field_wrapper_element; ?>><?php endif; ?>