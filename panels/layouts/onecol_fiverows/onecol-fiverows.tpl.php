<?php

/**
 * @file
 * The one column, five row layout.
 */
?>

<div class="panel-layout one-col-five-rows <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print 'id="' . $css_id . '"'; } ?>>
  <section class="one-col-five-rows-section one-col-five-rows-section-first">
    <?php print $content['row_one']; ?>
  </section>
  <section class="one-col-five-rows-section one-col-five-rows-section-second">
    <?php print $content['row_two']; ?>
  </section>
  <section class="one-col-five-rows-section one-col-five-rows-section-third">
    <?php print $content['row_three']; ?>
  </section>
  <section class="one-col-five-rows-section one-col-five-rows-section-fourth">
    <?php print $content['row_four']; ?>
  </section>
  <section class="one-col-five-rows-section one-col-five-rows-section-fifth">
    <?php print $content['row_five']; ?>
  </section>
</div>
