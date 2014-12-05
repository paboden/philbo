<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column stacked: 40col-60col'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_4060_stacked.png',
  'theme' => 'panels_twocol_4060_stacked',
  'css' => 'twocol_4060_stacked.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side: 40%'),
    'right' => t('Right side: 60%'),
    'bottom' => t('Bottom')
  ),
);
