<?php
/**
 * @file
 * employee_required_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function employee_required_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function employee_required_features_node_info() {
  $items = array(
    'employee' => array(
      'name' => t('Employee'),
      'base' => 'node_content',
      'description' => t('Maintains information about employees.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'employee_location' => array(
      'name' => t('Employee Location'),
      'base' => 'node_content',
      'description' => t('The physical location of the employee.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
