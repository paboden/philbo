<?php

/**
 * @file
 * The one column, two row layout.
 */
?>

<div class="panel-layout one-col-two-rows <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print 'id="' . $css_id . '"'; } ?>>
  <section class="one-col-two-rows-section one-col-two-rows-section-first">
    <?php print $content['row_one']; ?>
  </section>
  <section class="one-col-two-rows-section one-col-two-rows-section-second">
    <?php print $content['row_two']; ?>
  </section>
</div>
