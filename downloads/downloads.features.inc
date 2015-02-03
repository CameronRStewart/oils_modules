<?php
/**
 * @file
 * downloads.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function downloads_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function downloads_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function downloads_node_info() {
  $items = array(
    'downloads' => array(
      'name' => t('Download'),
      'base' => 'node_content',
      'description' => t('Use <em>download</em> for managing downloadable files.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Files uploaded to the site using this form will be managed as downloads. Downloads can be linked to on any page on the site using normal content editing tools and will also be available on a <a href="/downloads">single page that lists all available files</a> filterable by program.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
