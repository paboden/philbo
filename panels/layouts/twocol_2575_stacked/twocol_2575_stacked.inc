<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column stacked: 25col-75col'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_2575_stacked.png',
  'theme' => 'panels_twocol_2575_stacked',
  'css' => 'twocol_2575_stacked.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side: 25%'),
    'right' => t('Right side: 75%'),
    'bottom' => t('Bottom')
  ),
);
