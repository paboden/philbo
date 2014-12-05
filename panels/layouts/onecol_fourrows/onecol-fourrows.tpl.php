<?php

/**
 * @file
 * The one column, four row layout.
 */
?>

<div class="panel-layout one-col-four-rows <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print 'id="' . $css_id . '"'; } ?>>
  <section class="one-col-four-rows-section one-col-four-rows-section-first">
    <?php print $content['row_one']; ?>
  </section>
  <section class="one-col-four-rows-section one-col-four-rows-section-second">
    <?php print $content['row_two']; ?>
  </section>
  <section class="one-col-four-rows-section one-col-four-rows-section-third">
    <?php print $content['row_three']; ?>
  </section>
  <section class="one-col-four-rows-section one-col-four-rows-section-fourth">
    <?php print $content['row_four']; ?>
  </section>
</div>
