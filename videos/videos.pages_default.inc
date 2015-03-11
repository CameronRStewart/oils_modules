<?php
/**
 * @file
 * videos.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function videos_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__video';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Video',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'video',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'video',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'video' => 'video',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '313a2d2d-acca-4ce0-8707-43e60d967097';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0b19b29f-1106-40a5-9ff0-eee001135e85';
    $pane->panel = 'left';
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
    $pane->uuid = '0b19b29f-1106-40a5-9ff0-eee001135e85';
    $display->content['new-0b19b29f-1106-40a5-9ff0-eee001135e85'] = $pane;
    $display->panels['left'][0] = 'new-0b19b29f-1106-40a5-9ff0-eee001135e85';
    $pane = new stdClass();
    $pane->pid = 'new-3d9c80dc-6c3d-4a84-afe7-2006cf510bbd';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-oils_videos-block';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3d9c80dc-6c3d-4a84-afe7-2006cf510bbd';
    $display->content['new-3d9c80dc-6c3d-4a84-afe7-2006cf510bbd'] = $pane;
    $display->panels['right'][0] = 'new-3d9c80dc-6c3d-4a84-afe7-2006cf510bbd';
    $pane = new stdClass();
    $pane->pid = 'new-68d72751-4a5d-4ab7-b447-300cd59871d8';
    $pane->panel = 'top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_media_file';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_rendered',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'media_large',
        'preset' => 'default',
      ),
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
    $pane->uuid = '68d72751-4a5d-4ab7-b447-300cd59871d8';
    $display->content['new-68d72751-4a5d-4ab7-b447-300cd59871d8'] = $pane;
    $display->panels['top'][0] = 'new-68d72751-4a5d-4ab7-b447-300cd59871d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-68d72751-4a5d-4ab7-b447-300cd59871d8';
  $handler->conf['display'] = $display;
  $export['node_view__video'] = $handler;

  return $export;
}
