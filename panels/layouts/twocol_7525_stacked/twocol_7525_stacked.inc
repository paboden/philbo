<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column stacked: 75col-25col'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_7525_stacked.png',
  'theme' => 'panels_twocol_7525_stacked',
  'css' => 'twocol_7525_stacked.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side: 75%'),
    'right' => t('Right side: 25%'),
    'bottom' => t('Bottom')
  ),
);
