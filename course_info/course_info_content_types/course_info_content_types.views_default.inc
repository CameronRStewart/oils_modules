<?php
/**
 * @file
 * course_info_content_types.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function course_info_content_types_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course Listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_course_title' => 'field_course_title',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_course_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Course Title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['label'] = '';
  $handler->display->display_options['fields']['field_course_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'OILS [title] - [field_course_title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
    'course' => 'course',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'course-listing';
  $export['course_listing'] = $view;

  $view = new view();
  $view->name = 'course_sections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course Sections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sections';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_number' => 'field_number',
    'field_credits' => 'field_credits',
    'field_delivery_type' => 'field_delivery_type',
    'field_enrollment' => 'field_enrollment',
    'field_enrollment_max' => 'field_enrollment',
    'field_waitlist' => 'field_waitlist',
    'field_waitlist_max' => 'field_waitlist',
    'field_fees' => 'field_fees',
    'field_instructional_method' => 'field_instructional_method',
    'field_instructor' => 'field_instructor',
    'field_date_range' => 'field_date_range',
    'field_end_date' => 'field_date_range',
    'field_meeting_time' => 'field_meeting_time',
    'field_end_time' => 'field_meeting_time',
    'field_building_name' => 'field_building_name',
    'field_room_number' => 'field_building_name',
    'field_building_code' => 'field_building_name',
    'field_status' => 'field_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_credits' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_delivery_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_enrollment' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '/',
      'empty_column' => 0,
    ),
    'field_enrollment_max' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_waitlist' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '/',
      'empty_column' => 0,
    ),
    'field_waitlist_max' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fees' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_instructional_method' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_instructor' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_range' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ' to ',
      'empty_column' => 0,
    ),
    'field_end_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_meeting_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
    'field_end_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_building_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'field_room_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_building_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_section_node']['id'] = 'reverse_field_section_node';
  $handler->display->display_options['relationships']['reverse_field_section_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_section_node']['field'] = 'reverse_field_section_node';
  $handler->display->display_options['relationships']['reverse_field_section_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'CRN';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Number */
  $handler->display->display_options['fields']['field_number']['id'] = 'field_number';
  $handler->display->display_options['fields']['field_number']['table'] = 'field_data_field_number';
  $handler->display->display_options['fields']['field_number']['field'] = 'field_number';
  $handler->display->display_options['fields']['field_number']['label'] = 'Section';
  /* Field: Content: Credits */
  $handler->display->display_options['fields']['field_credits']['id'] = 'field_credits';
  $handler->display->display_options['fields']['field_credits']['table'] = 'field_data_field_credits';
  $handler->display->display_options['fields']['field_credits']['field'] = 'field_credits';
  /* Field: Content: Delivery Type */
  $handler->display->display_options['fields']['field_delivery_type']['id'] = 'field_delivery_type';
  $handler->display->display_options['fields']['field_delivery_type']['table'] = 'field_data_field_delivery_type';
  $handler->display->display_options['fields']['field_delivery_type']['field'] = 'field_delivery_type';
  /* Field: Content: Enrollment */
  $handler->display->display_options['fields']['field_enrollment']['id'] = 'field_enrollment';
  $handler->display->display_options['fields']['field_enrollment']['table'] = 'field_data_field_enrollment';
  $handler->display->display_options['fields']['field_enrollment']['field'] = 'field_enrollment';
  /* Field: Content: Enrollment Max */
  $handler->display->display_options['fields']['field_enrollment_max']['id'] = 'field_enrollment_max';
  $handler->display->display_options['fields']['field_enrollment_max']['table'] = 'field_data_field_enrollment_max';
  $handler->display->display_options['fields']['field_enrollment_max']['field'] = 'field_enrollment_max';
  $handler->display->display_options['fields']['field_enrollment_max']['alter']['text'] = '/[field_enrollment_max]';
  $handler->display->display_options['fields']['field_enrollment_max']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Waitlist */
  $handler->display->display_options['fields']['field_waitlist']['id'] = 'field_waitlist';
  $handler->display->display_options['fields']['field_waitlist']['table'] = 'field_data_field_waitlist';
  $handler->display->display_options['fields']['field_waitlist']['field'] = 'field_waitlist';
  $handler->display->display_options['fields']['field_waitlist']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_waitlist']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Waitlist Max */
  $handler->display->display_options['fields']['field_waitlist_max']['id'] = 'field_waitlist_max';
  $handler->display->display_options['fields']['field_waitlist_max']['table'] = 'field_data_field_waitlist_max';
  $handler->display->display_options['fields']['field_waitlist_max']['field'] = 'field_waitlist_max';
  $handler->display->display_options['fields']['field_waitlist_max']['alter']['text'] = '/[field_waitlist_max]';
  $handler->display->display_options['fields']['field_waitlist_max']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_waitlist_max']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Fees */
  $handler->display->display_options['fields']['field_fees']['id'] = 'field_fees';
  $handler->display->display_options['fields']['field_fees']['table'] = 'field_data_field_fees';
  $handler->display->display_options['fields']['field_fees']['field'] = 'field_fees';
  /* Field: Content: Instructional Method */
  $handler->display->display_options['fields']['field_instructional_method']['id'] = 'field_instructional_method';
  $handler->display->display_options['fields']['field_instructional_method']['table'] = 'field_data_field_instructional_method';
  $handler->display->display_options['fields']['field_instructional_method']['field'] = 'field_instructional_method';
  /* Field: Content: Instructor */
  $handler->display->display_options['fields']['field_instructor']['id'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['fields']['field_instructor']['field'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_instructor']['delta_offset'] = '0';
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_date_range']['id'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['table'] = 'field_data_field_date_range';
  $handler->display->display_options['fields']['field_date_range']['field'] = 'field_date_range';
  $handler->display->display_options['fields']['field_date_range']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date_range']['alter']['text'] = '[field_date_range] to [field_end_date]';
  /* Field: Content: End Date */
  $handler->display->display_options['fields']['field_end_date']['id'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['fields']['field_end_date']['field'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['alter']['text'] = ' to [field_end_date]';
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_meeting_time']['id'] = 'field_meeting_time';
  $handler->display->display_options['fields']['field_meeting_time']['table'] = 'field_data_field_meeting_time';
  $handler->display->display_options['fields']['field_meeting_time']['field'] = 'field_meeting_time';
  $handler->display->display_options['fields']['field_meeting_time']['label'] = 'Time';
  $handler->display->display_options['fields']['field_meeting_time']['alter']['text'] = '[field_meeting_time] - [field_end_time]';
  $handler->display->display_options['fields']['field_meeting_time']['hide_empty'] = TRUE;
  /* Field: Content: End Time */
  $handler->display->display_options['fields']['field_end_time']['id'] = 'field_end_time';
  $handler->display->display_options['fields']['field_end_time']['table'] = 'field_data_field_end_time';
  $handler->display->display_options['fields']['field_end_time']['field'] = 'field_end_time';
  $handler->display->display_options['fields']['field_end_time']['alter']['text'] = ' - [field_end_time]';
  $handler->display->display_options['fields']['field_end_time']['hide_empty'] = TRUE;
  /* Field: Content: Building Name */
  $handler->display->display_options['fields']['field_building_name']['id'] = 'field_building_name';
  $handler->display->display_options['fields']['field_building_name']['table'] = 'field_data_field_building_name';
  $handler->display->display_options['fields']['field_building_name']['field'] = 'field_building_name';
  /* Field: Content: Room Number */
  $handler->display->display_options['fields']['field_room_number']['id'] = 'field_room_number';
  $handler->display->display_options['fields']['field_room_number']['table'] = 'field_data_field_room_number';
  $handler->display->display_options['fields']['field_room_number']['field'] = 'field_room_number';
  /* Field: Content: Building Code */
  $handler->display->display_options['fields']['field_building_code']['id'] = 'field_building_code';
  $handler->display->display_options['fields']['field_building_code']['table'] = 'field_data_field_building_code';
  $handler->display->display_options['fields']['field_building_code']['field'] = 'field_building_code';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['exclude'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_section_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'section' => 'section',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['course_sections'] = $view;

  $view = new view();
  $view->name = 'faculty_classes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Faculty Classes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Classes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_course_title' => 'field_course_title',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_section_target_id']['id'] = 'field_section_target_id';
  $handler->display->display_options['relationships']['field_section_target_id']['table'] = 'field_data_field_section';
  $handler->display->display_options['relationships']['field_section_target_id']['field'] = 'field_section_target_id';
  $handler->display->display_options['relationships']['field_section_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_instructor_target_id']['id'] = 'field_instructor_target_id';
  $handler->display->display_options['relationships']['field_instructor_target_id']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['relationships']['field_instructor_target_id']['field'] = 'field_instructor_target_id';
  $handler->display->display_options['relationships']['field_instructor_target_id']['relationship'] = 'field_section_target_id';
  $handler->display->display_options['relationships']['field_instructor_target_id']['required'] = TRUE;
  /* Field: Content: Course Title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['label'] = '';
  $handler->display->display_options['fields']['field_course_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_title']['element_label_colon'] = FALSE;
  /* Field: Course Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Course Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'OILS [title] [field_course_title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_instructor_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'course' => 'course',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['faculty_classes'] = $view;

  return $export;
}
