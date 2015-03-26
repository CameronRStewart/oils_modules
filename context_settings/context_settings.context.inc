<?php
/**
 * @file
 * context_settings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_settings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about_oils';
  $context->description = 'About OI&LS Section';
  $context->tag = 'special';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/6' => 'node/6',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-5' => array(
          'module' => 'menu_block',
          'delta' => '5',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('About OI&LS Section');
  t('special');
  $export['about_oils'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cs_bachelor_program_blocks';
  $context->description = 'Place blocks on the bachelor program pages in current students.';
  $context->tag = 'current-students';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/63' => 'node/63',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-12' => array(
          'module' => 'menu_block',
          'delta' => '12',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu_block-7' => array(
          'module' => 'menu_block',
          'delta' => '7',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the bachelor program pages in current students.');
  t('current-students');
  $export['cs_bachelor_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cs_certificate_program_blocks';
  $context->description = 'Place blocks on the certificate program pages in current students.';
  $context->tag = 'current-students';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/72' => 'node/72',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-15' => array(
          'module' => 'menu_block',
          'delta' => '15',
          'region' => 'sidebar_first',
          'weight' => '-41',
        ),
        'menu_block-6' => array(
          'module' => 'menu_block',
          'delta' => '6',
          'region' => 'sidebar_first',
          'weight' => '-40',
        ),
        'views-contact_info-block_1' => array(
          'module' => 'views',
          'delta' => 'contact_info-block_1',
          'region' => 'sidebar_second',
          'weight' => '10',
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the certificate program pages in current students.');
  t('current-students');
  $export['cs_certificate_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cs_common_blocks';
  $context->description = 'Add common blocks to program pages in current students section.';
  $context->tag = 'current-students';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/63' => 'node/63',
        'node/68' => 'node/68',
        'node/72' => 'node/72',
        'node/73' => 'node/73',
      ),
    ),
    'path' => array(
      'values' => array(
        'current-students/*' => 'current-students/*',
        '~current-students/*/*' => '~current-students/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'content',
          'weight' => 0,
        ),
        'block-20' => array(
          'module' => 'block',
          'delta' => '20',
          'region' => 'content',
          'weight' => 1,
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add common blocks to program pages in current students section.');
  t('current-students');
  $export['cs_common_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cs_doctoral_program_blocks';
  $context->description = 'Place blocks on the doctoral program pages in current students.';
  $context->tag = 'current-students';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/73' => 'node/73',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-14' => array(
          'module' => 'menu_block',
          'delta' => '14',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu_block-6' => array(
          'module' => 'menu_block',
          'delta' => '6',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the doctoral program pages in current students.');
  t('current-students');
  $export['cs_doctoral_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cs_masters_program_blocks';
  $context->description = 'Place blocks on the masters program pages in current students.';
  $context->tag = 'current-students';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/68' => 'node/68',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-13' => array(
          'module' => 'menu_block',
          'delta' => '13',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu_block-6' => array(
          'module' => 'menu_block',
          'delta' => '6',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'block-41' => array(
          'module' => 'block',
          'delta' => '41',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the masters program pages in current students.');
  t('current-students');
  $export['cs_masters_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cs_section_main_page';
  $context->description = 'Main page for the current student section.';
  $context->tag = 'current-students';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'current-students' => 'current-students',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'current-students-page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main page for the current student section.');
  t('current-students');
  $export['cs_section_main_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cs_sidemenu';
  $context->description = 'Place side menu on pages in the current students sections.';
  $context->tag = 'current-students';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/63' => 'node/63',
        'node/68' => 'node/68',
        'node/72' => 'node/72',
        'node/73' => 'node/73',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-4' => array(
          'module' => 'menu_block',
          'delta' => '4',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place side menu on pages in the current students sections.');
  t('current-students');
  $export['cs_sidemenu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'faculty_profile';
  $context->description = 'Process Faculty Profiles';
  $context->tag = 'special';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'employee' => 'employee',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-16' => array(
          'module' => 'menu_block',
          'delta' => '16',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => array(
      0 => 'main-menu:node/4',
    ),
    'menu' => array(
      0 => 'main-menu:node/4',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Process Faculty Profiles');
  t('special');
  $export['faculty_profile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_bachelor_program_blocks';
  $context->description = 'Place blocks on the bachelor\'s program pages in the academic programs section.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/11' => 'node/11',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-9' => array(
          'module' => 'menu_block',
          'delta' => '9',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-contact_info-block' => array(
          'module' => 'views',
          'delta' => 'contact_info-block',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the bachelor\'s program pages in the academic programs section.');
  t('academic-programs');
  $export['ps_bachelor_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_bachelor_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'academic-programs/bachelors-program' => 'academic-programs/bachelors-program',
        '~academic-programs/bachelors-program/*' => '~academic-programs/bachelors-program/*',
        'academic-programs/bachelor-science' => 'academic-programs/bachelor-science',
        '~academic-programs/bachelor-science/*' => '~academic-programs/bachelor-science/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'highlighted',
          'weight' => '0',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('academic-programs');
  $export['ps_bachelor_program_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_certificate_program_blocks';
  $context->description = 'Place blocks on the certificate program pages in the academic programs area.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/43' => 'node/43',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-8' => array(
          'module' => 'menu_block',
          'delta' => '8',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-contact_info-block_1' => array(
          'module' => 'views',
          'delta' => 'contact_info-block_1',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'block-21' => array(
          'module' => 'block',
          'delta' => '21',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the certificate program pages in the academic programs area.');
  t('academic-programs');
  $export['ps_certificate_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_certificate_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'academic-programs/professional-certificates' => 'academic-programs/professional-certificates',
        '~academic-programs/professional-certificates/*' => '~academic-programs/professional-certificates/*',
        'academic-programs/certificate-program' => 'academic-programs/certificate-program',
        '~academic-programs/certificate-program/*' => '~academic-programs/certificate-program/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-27' => array(
          'module' => 'block',
          'delta' => '27',
          'region' => 'highlighted',
          'weight' => '0',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('academic-programs');
  $export['ps_certificate_program_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_doctoral_program_blocks';
  $context->description = 'Place blocks on the doctoral program pages in prospective students.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/22' => 'node/22',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-11' => array(
          'module' => 'menu_block',
          'delta' => '11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-contact_info-block_3' => array(
          'module' => 'views',
          'delta' => 'contact_info-block_3',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the doctoral program pages in prospective students.');
  t('academic-programs');
  $export['ps_doctoral_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_doctoral_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'academic-programs/doctor-philosophy' => 'academic-programs/doctor-philosophy',
        '~academic-programs/doctor-philosophy/*' => '~academic-programs/doctor-philosophy/*',
        'academic-programs/doctoral-program' => 'academic-programs/doctoral-program',
        '~academic-programs/doctoral-program/*' => '~academic-programs/doctoral-program/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-26' => array(
          'module' => 'block',
          'delta' => '26',
          'region' => 'highlighted',
          'weight' => '0',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('academic-programs');
  $export['ps_doctoral_program_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_masters_program_blocks';
  $context->description = 'Place blocks on the masters program pages in the academic programs section.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/18' => 'node/18',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-10' => array(
          'module' => 'menu_block',
          'delta' => '10',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-contact_info-block' => array(
          'module' => 'views',
          'delta' => 'contact_info-block',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place blocks on the masters program pages in the academic programs section.');
  t('academic-programs');
  $export['ps_masters_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_masters_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'academic-programs/masters-program' => 'academic-programs/masters-program',
        '~academic-programs/masters-program/*' => '~academic-programs/masters-program/*',
        'academic-programs/master-arts' => 'academic-programs/master-arts',
        '~academic-programs/master-arts/*' => '~academic-programs/master-arts/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'highlighted',
          'weight' => '0',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('academic-programs');
  $export['ps_masters_program_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_masters_program_loose_pages';
  $context->description = 'For adding side blocks to loose Master\'s pages in the academic programs section.';
  $context->tag = 'academic-programs';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        1 => 1,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/18',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('For adding side blocks to loose Master\'s pages in the academic programs section.');
  t('academic-programs');
  $export['ps_masters_program_loose_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_section_main_page';
  $context->description = 'Context for the Prospective Student Page';
  $context->tag = 'prospective-students';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'prospective-students' => 'prospective-students',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-15' => array(
          'module' => 'block',
          'delta' => '15',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'prospective-students-page',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the Prospective Student Page');
  t('prospective-students');
  $export['ps_section_main_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_sidemenu';
  $context->description = 'Places the sidebar menu on pages in the prospective student sections.';
  $context->tag = 'prospective-students';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'node/11' => 'node/11',
        'node/18' => 'node/18',
        'node/22' => 'node/22',
        'node/43' => 'node/43',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Places the sidebar menu on pages in the prospective student sections.');
  t('prospective-students');
  $export['ps_sidemenu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = 'Search pages';
  $context->tag = 'special';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '/search/*' => '/search/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => '0',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search pages');
  t('special');
  $export['search'] = $context;

  return $export;
}
