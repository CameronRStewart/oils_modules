<?php
/**
 * @file
 * oils_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oils_content_context_default_contexts() {
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
        'menu_block-8' => array(
          'module' => 'menu_block',
          'delta' => '8',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'menu_block-6' => array(
          'module' => 'menu_block',
          'delta' => '6',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
        'views-contact_info-block_1' => array(
          'module' => 'views',
          'delta' => 'contact_info-block_1',
          'region' => 'sidebar_first',
          'weight' => 2,
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
  $context->name = 'ps_bachelor_program_blocks';
  $context->description = 'Place blocks on the bachelor\'s program pages in academic programs section.';
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
  t('Place blocks on the bachelor\'s program pages in academic programs section.');
  t('academic-programs');
  $export['ps_bachelor_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_bachelor_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'prospective-students';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'prospective-students/bachelors-program' => 'prospective-students/bachelors-program',
        '~prospective-students/bachelors-program/*' => '~prospective-students/bachelors-program/*',
        'prospective-students/bachelor-science' => 'prospective-students/bachelor-science',
        '~prospective-students/bachelor-science/*' => '~prospective-students/bachelor-science/*',
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
          'weight' => 0,
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('prospective-students');
  $export['ps_bachelor_program_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_certificate_program_blocks';
  $context->description = 'Place blocks on the certificate program pages in prospective students.';
  $context->tag = 'prospective-students';
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
        'views-contact_info-block_1' => array(
          'module' => 'views',
          'delta' => 'contact_info-block_1',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'block-21' => array(
          'module' => 'block',
          'delta' => '21',
          'region' => 'sidebar_second',
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
  t('Place blocks on the certificate program pages in prospective students.');
  t('prospective-students');
  $export['ps_certificate_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_certificate_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'prospective-students';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'prospective-students/professional-certificates' => 'prospective-students/professional-certificates',
        '~prospective-students/professional-certificates/*' => '~prospective-students/professional-certificates/*',
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
          'weight' => 0,
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('prospective-students');
  $export['ps_certificate_program_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_doctoral_program_blocks';
  $context->description = 'Place blocks on the doctoral program pages in prospective students.';
  $context->tag = 'prospective-students';
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
        'views-contact_info-block_3' => array(
          'module' => 'views',
          'delta' => 'contact_info-block_3',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
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
  t('Place blocks on the doctoral program pages in prospective students.');
  t('prospective-students');
  $export['ps_doctoral_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_doctoral_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'prospective-students';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'prospective-students/doctor-philosophy' => 'prospective-students/doctor-philosophy',
        '~prospective-students/doctor-philosophy/*' => '~prospective-students/doctor-philosophy/*',
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
          'weight' => 0,
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('prospective-students');
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
  t('Place blocks on the masters program pages in the academic programs section.');
  t('academic-programs');
  $export['ps_masters_program_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_masters_program_homepage';
  $context->description = 'For doing special stuff on the program main page only.';
  $context->tag = 'prospective-students';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'prospective-students/masters-program' => 'prospective-students/masters-program',
        '~prospective-students/masters-program/*' => '~prospective-students/masters-program/*',
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
          'weight' => 0,
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'program-home-page',
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For doing special stuff on the program main page only.');
  t('prospective-students');
  $export['ps_masters_program_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ps_masters_program_loose_pages';
  $context->description = 'For adding side blocks to loose pages.';
  $context->tag = 'prospective-students';
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
  t('For adding side blocks to loose pages.');
  t('prospective-students');
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

  return $export;
}
