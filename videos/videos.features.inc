<?php
/**
 * @file
 * videos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function videos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function videos_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function videos_image_default_styles() {
  $styles = array();

  // Exported image style: video_thumbnail_140.
  $styles['video_thumbnail_140'] = array(
    'label' => 'Video Thumbnail 140',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 140,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: video_thumbnail_220.
  $styles['video_thumbnail_220'] = array(
    'label' => 'Video Thumbnail 220',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_mediafront_default_presets().
 */
function videos_mediafront_default_presets() {
  $items = array(
    'default' => array(
      'name' => 'default',
      'description' => 'A Default Preset',
      'player' => 'osmplayer',
      'connect' => array(
        'iscontroller' => array(),
        'isplaylist' => array(),
      ),
      'settings' => array(
        'debug' => 0,
        'disptime' => 0,
        'duration' => 0,
        'volume' => 80,
        'wmode' => 'transparent',
        'preload' => TRUE,
        'autoplay' => 0,
        'autoload' => 1,
        'scrollMode' => 'auto',
        'scrollSpeed' => 20,
        'showPlaylist' => 1,
        'vertical' => 1,
        'node' => array(),
        'playlist' => '',
        'pageLimit' => 10,
        'preset' => '',
        'autoNext' => 1,
        'shuffle' => 0,
        'loop' => 0,
        'logo' => '/sites/all/modules/contrib/mediafront/players/osmplayer/player/logo.png',
        'swfplayer' => '/sites/all/modules/contrib/mediafront/players/osmplayer/player/minplayer/flash/minplayer.swf',
        'link' => 'http://www.mediafront.org',
        'width' => '100%',
        'height' => '450px',
        'template' => 'default',
        'playlistOnly' => 0,
        'disablePlaylist' => 0,
        'controllerOnly' => 0,
        'volumeVertical' => 1,
        'plugins' => array(
          'timeline_indicator' => 0,
        ),
        'theme' => 'dark-hive',
        'showWhenEmpty' => 1,
        'showController' => 1,
        'prereel' => '',
        'postreel' => '',
        'player_settings__active_tab' => 'edit-player-settings-playlist-settings',
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function videos_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Use this to create a new video.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
