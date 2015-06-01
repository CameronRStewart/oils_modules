<?php
/**
 * @file
 * videos.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function videos_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-video-playlists.
  $menus['menu-video-playlists'] = array(
    'menu_name' => 'menu-video-playlists',
    'title' => 'Video Playlists',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Video Playlists');


  return $menus;
}
