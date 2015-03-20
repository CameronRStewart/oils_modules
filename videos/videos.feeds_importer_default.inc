<?php
/**
 * @file
 * videos.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function videos_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'youtube_video_importer';
  $feeds_importer->config = array(
    'name' => 'OILS YouTube Video Importer',
    'description' => 'Imports OILS videos from YouTube',
    'fetcher' => array(
      'plugin_key' => 'YouTubeFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'string(media:group/yt:videoid)',
          'xpathparser:1' => 'string(media:group/media:title)',
          'xpathparser:2' => 'string(media:group/media:description)',
          'xpathparser:3' => 'string(link/@href)',
          'xpathparser:6' => 'string(media:group/media:category/@label)',
          'xpathparser:7' => 'string(media:group/media:keywords)',
          'xpathparser:8' => 'published',
          'xpathparser:9' => 'string(media:group/media:thumbnail[1]/@url)',
          'xpathparser:10' => 'string(media:group/media:thumbnail[3]/@url)',
          'xpathparser:11' => 'string(link/@href)',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
        ),
        'context' => '//entry',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_youtube_url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_youtube_category',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          5 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_youtube_keywords',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          6 => array(
            'source' => 'xpathparser:8',
            'target' => 'created',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_youtube_thumb:uri',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_youtube_poster:uri',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_media_file',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'authorize' => 1,
        'skip_hash_check' => 0,
        'bundle' => 'video',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['youtube_video_importer'] = $feeds_importer;

  return $export;
}
