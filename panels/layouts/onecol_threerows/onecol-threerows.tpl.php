<?php

/**
 * @file
 * The one column, three row layout.
 */
?>

<div class="panel-layout one-col-three-rows <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print 'id="' . $css_id . '"'; } ?>>
  <section class="one-col-three-rows-section one-col-three-rows-section-first">
    <?php print $content['row_one']; ?>
  </section>
  <section class="one-col-three-rows-section one-col-three-rows-section-second">
    <?php print $content['row_two']; ?>
  </section>
  <section class="one-col-three-rows-section one-col-three-rows-section-third">
    <?php print $content['row_three']; ?>
  </section>
</div>
