<?php
/**
 * @file
 * downloads.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function downloads_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'downloadable_forms';
  $view->description = 'Collection of files available for download.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Downloadable Forms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Downloadable Forms';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'title',
    'field_download' => 'field_download',
    'changed' => 'changed',
    'field_program' => 'field_program',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_download' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_program' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No downloads were found for the selected program.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title/Description';
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'em';
  /* Field: Content: Downloadable File */
  $handler->display->display_options['fields']['field_download']['id'] = 'field_download';
  $handler->display->display_options['fields']['field_download']['table'] = 'field_data_field_download';
  $handler->display->display_options['fields']['field_download']['field'] = 'field_download';
  $handler->display->display_options['fields']['field_download']['label'] = 'Download';
  $handler->display->display_options['fields']['field_download']['click_sort_column'] = 'fid';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'F j, Y, g:i a';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['timezone'] = 'America/Denver';
  /* Field: Content: Program(s) */
  $handler->display->display_options['fields']['field_program']['id'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['table'] = 'field_data_field_program';
  $handler->display->display_options['fields']['field_program']['field'] = 'field_program';
  $handler->display->display_options['fields']['field_program']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_program']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_program']['separator'] = '<br/>';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'downloads' => 'downloads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Program(s) (field_program) */
  $handler->display->display_options['filters']['field_program_tid']['id'] = 'field_program_tid';
  $handler->display->display_options['filters']['field_program_tid']['table'] = 'field_data_field_program';
  $handler->display->display_options['filters']['field_program_tid']['field'] = 'field_program_tid';
  $handler->display->display_options['filters']['field_program_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_tid']['expose']['operator_id'] = 'field_program_tid_op';
  $handler->display->display_options['filters']['field_program_tid']['expose']['label'] = 'Program';
  $handler->display->display_options['filters']['field_program_tid']['expose']['description'] = 'Select a program to filter the list.';
  $handler->display->display_options['filters']['field_program_tid']['expose']['operator'] = 'field_program_tid_op';
  $handler->display->display_options['filters']['field_program_tid']['expose']['identifier'] = 'field_program_tid';
  $handler->display->display_options['filters']['field_program_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_program_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_tid']['vocabulary'] = 'program';

  /* Display: Downloads page */
  $handler = $view->new_display('page', 'Downloads page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'downloads';
  $export['downloadable_forms'] = $view;

  return $export;
}
