<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column stacked: 60col-40col'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_6040_stacked.png',
  'theme' => 'panels_twocol_6040_stacked',
  'css' => 'twocol_6040_stacked.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side: 60%'),
    'right' => t('Right side: 40%'),
    'bottom' => t('Bottom')
  ),
);
