<?php
/**
 * @file
 * videos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function videos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'oils_videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OILS Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest Videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['style_options']['wrapper_class'] = 'latest-videos';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: MediaFront Player */
  $handler->display->display_options['header']['mediafront_player']['id'] = 'mediafront_player';
  $handler->display->display_options['header']['mediafront_player']['table'] = 'views';
  $handler->display->display_options['header']['mediafront_player']['field'] = 'mediafront_player';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Media File */
  $handler->display->display_options['fields']['field_media_file']['id'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['table'] = 'field_data_field_media_file';
  $handler->display->display_options['fields']['field_media_file']['field'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['label'] = '';
  $handler->display->display_options['fields']['field_media_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_file']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_file']['settings'] = array(
    'file_view_mode' => 'media_small',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'video' => 'video',
  );

  /* Display: Latest Videos */
  $handler = $view->new_display('block', 'Latest Videos', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['style_options']['wrapper_class'] = 'latest-videos';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Media File */
  $handler->display->display_options['fields']['field_media_file']['id'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['table'] = 'field_data_field_media_file';
  $handler->display->display_options['fields']['field_media_file']['field'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['label'] = '';
  $handler->display->display_options['fields']['field_media_file']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_file']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_media_file']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_media_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_file']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_file']['settings'] = array(
    'file_view_mode' => 'media_link',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '33';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;

  /* Display: Video Gallery */
  $handler = $view->new_display('page', 'Video Gallery', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Video Gallery';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: MediaFront Player */
  $handler->display->display_options['header']['mediafront_player']['id'] = 'mediafront_player';
  $handler->display->display_options['header']['mediafront_player']['table'] = 'views';
  $handler->display->display_options['header']['mediafront_player']['field'] = 'mediafront_player';
  $handler->display->display_options['header']['mediafront_player']['mediafront_preset'] = 'default';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media File */
  $handler->display->display_options['fields']['field_media_file']['id'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['table'] = 'field_data_field_media_file';
  $handler->display->display_options['fields']['field_media_file']['field'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['label'] = '';
  $handler->display->display_options['fields']['field_media_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_file']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_file']['settings'] = array(
    'file_view_mode' => 'media_small',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['path'] = 'videos';
  $export['oils_videos'] = $view;

  return $export;
}
