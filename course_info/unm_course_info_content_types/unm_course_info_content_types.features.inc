<?php
/**
 * @file
 * unm_course_info_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unm_course_info_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function unm_course_info_content_types_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('This is an individual course being offered in a subject, by a department'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Each Course has a Title, a Number, a Catalog Description, and one or more Sections.'),
    ),
    'department' => array(
      'name' => t('Department'),
      'base' => 'node_content',
      'description' => t('This is a department within a college'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Each department has a required department code and name.'),
    ),
    'meeting_time' => array(
      'name' => t('Meeting Time'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
      'description' => t('Each Department teaches one or more Subjects.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Each subject has a required Code and Name field'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
