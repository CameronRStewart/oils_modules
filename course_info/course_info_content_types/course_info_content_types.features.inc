<?php
/**
 * @file
 * course_info_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function course_info_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function course_info_content_types_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('This is a specific course offered by this department'),
      'has_title' => '1',
      'title_label' => t('Number'),
      'help' => '',
    ),
    'department' => array(
      'name' => t('Department'),
      'base' => 'node_content',
      'description' => t('This is a department within a college'),
      'has_title' => '1',
      'title_label' => t('Code'),
      'help' => '',
    ),
    'section' => array(
      'name' => t('Section'),
      'base' => 'node_content',
      'description' => t('For each Course, there may be one or more sections available at different times, or with different people.'),
      'has_title' => '1',
      'title_label' => t('CRN'),
      'help' => '',
    ),
    'subject' => array(
      'name' => t('Subject'),
      'base' => 'node_content',
      'description' => t('This is a subject of study within a department'),
      'has_title' => '1',
      'title_label' => t('Code'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
