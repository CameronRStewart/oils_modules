<?php
/**
 * @file
 * downloads.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function downloads_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-downloads-body'
  $field_instances['node-downloads-body'] = array(
    'bundle' => 'downloads',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description of download',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-downloads-field_download'
  $field_instances['node-downloads-field_download'] = array(
    'bundle' => 'downloads',
    'deleted' => 0,
    'description' => 'Select a file to upload',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_download',
    'label' => 'Downloadable File',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'oils/downloads',
      'file_extensions' => 'txt xls xlsx doc docx pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => array(
          0 => 'auto',
        ),
        'insert_styles' => array(
          0 => 'auto',
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-downloads-field_program'
  $field_instances['node-downloads-field_program'] = array(
    'bundle' => 'downloads',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the program or programs associated with this file.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_program',
    'label' => 'Program(s)',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 33,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description of download');
  t('Downloadable File');
  t('Program(s)');
  t('Select a file to upload');
  t('Select the program or programs associated with this file.');

  return $field_instances;
}
