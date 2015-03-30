<?php
/**
 * @file
 * course_info_content_types.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function course_info_content_types_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__course_sections';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Course Sections',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'course_sections',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'OILS %node:title - %node:field_course_title';
  $display->uuid = '0521511a-1eac-4812-b8d4-a7a5c9025425';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-df6dfb75-3c02-43ac-867a-b7616122f9e0';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'df6dfb75-3c02-43ac-867a-b7616122f9e0';
    $display->content['new-df6dfb75-3c02-43ac-867a-b7616122f9e0'] = $pane;
    $display->panels['center'][0] = 'new-df6dfb75-3c02-43ac-867a-b7616122f9e0';
    $pane = new stdClass();
    $pane->pid = 'new-bc27488d-9af5-454a-9eb9-e71472d4a6cf';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-course_sections-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bc27488d-9af5-454a-9eb9-e71472d4a6cf';
    $display->content['new-bc27488d-9af5-454a-9eb9-e71472d4a6cf'] = $pane;
    $display->panels['center'][1] = 'new-bc27488d-9af5-454a-9eb9-e71472d4a6cf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bc27488d-9af5-454a-9eb9-e71472d4a6cf';
  $handler->conf['display'] = $display;
  $export['node_view__course_sections'] = $handler;

  return $export;
}
