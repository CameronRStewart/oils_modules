<?php
/**
 * @file
 * videos.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function videos_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videos';
  $context->description = 'Place blocks on video pages';
  $context->tag = 'special';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-18' => array(
          'module' => 'menu_block',
          'delta' => '18',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on video pages');
  t('special');
  $export['videos'] = $context;

  return $export;
}
