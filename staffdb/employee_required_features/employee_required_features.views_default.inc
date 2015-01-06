<?php
/**
 * @file
 * employee_required_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function employee_required_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'location_selection_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Location Selection List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_location',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_location' => 'field_location',
    'field_room_number' => 'field_room_number',
    'field_phone_number' => 'field_phone_number',
  );
  /* Field: Content: Building/Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Room Number */
  $handler->display->display_options['fields']['field_room_number']['id'] = 'field_room_number';
  $handler->display->display_options['fields']['field_room_number']['table'] = 'field_data_field_room_number';
  $handler->display->display_options['fields']['field_room_number']['field'] = 'field_room_number';
  $handler->display->display_options['fields']['field_room_number']['label'] = '';
  $handler->display->display_options['fields']['field_room_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_room_number']['type'] = 'text_plain';
  /* Field: Content: Phone Number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['label'] = '';
  $handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone_number']['type'] = 'text_plain';
  /* Sort criterion: Content: Building/Location (field_location) */
  $handler->display->display_options['sorts']['field_location_tid']['id'] = 'field_location_tid';
  $handler->display->display_options['sorts']['field_location_tid']['table'] = 'field_data_field_location';
  $handler->display->display_options['sorts']['field_location_tid']['field'] = 'field_location_tid';
  /* Sort criterion: Content: Room Number (field_room_number) */
  $handler->display->display_options['sorts']['field_room_number_value']['id'] = 'field_room_number_value';
  $handler->display->display_options['sorts']['field_room_number_value']['table'] = 'field_data_field_room_number';
  $handler->display->display_options['sorts']['field_room_number_value']['field'] = 'field_room_number_value';
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
    'employee_location' => 'employee_location',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_location' => 'field_location',
    'field_room_number' => 'field_room_number',
    'field_phone_number' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['location_selection_list'] = $view;

  return $export;
}
