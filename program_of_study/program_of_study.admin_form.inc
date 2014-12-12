<?php
function program_of_study_admin_form($form, &$form_state) {
  $form = array();
  // Because we have many fields with the same values, we have to set
  // #tree to be able to access them.
  $form['#tree'] = TRUE;
  $form['pos_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enter Program of Studies URLs and Titles.'),
    '#prefix' => '<div id="pos-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  //Used to keep track of each group
  $groupID = 0;

  $result = db_query('SELECT * FROM program_of_study');
  $form_state['num_existing'] = $result->rowCount();

  foreach ($result as $row) {
    $form['pos_fieldset']['pos_group'][$groupID] = array(
      '#type' => 'fieldset',
      '#title' => t('Program of Study #!num', array('!num' => $groupID + 1)),
      '#prefix' => '<div class="pos-fieldset-group-wrapper">',
      '#suffix' => '</div>',
    );
    //Display message if any
    if (!empty($row->msg)) {
      $form['pos_fieldset']['pos_group'][$groupID]['message'] = array(
        '#markup' => '<span style="color:dodgerblue"><b>Status: </b>' . $row->msg . '</span>',
      );
    }
    if (!empty($row->updated)) {
      $form['pos_fieldset']['pos_group'][$groupID]['message'] = array(
        '#markup' => '<span style="color:dodgerblue">Last updated: ' . format_date($row->updated, 'custom', 'l, m/j/y - g:ia') . '</span>',
      );
    }
    $form['pos_fieldset']['pos_group'][$groupID]['posid'] = array(
      '#type' => 'hidden',
      '#value' => $row->id,
    );
    $form['pos_fieldset']['pos_group'][$groupID]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('The title of the page (eg. Doctoral Program of Study)'),
      '#required' => TRUE,
      '#default_value' => $row->title,
    );
    $form['pos_fieldset']['pos_group'][$groupID]['url'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('The URL to grab the program of study from. Currently only supports degrees.unm.edu'),
      '#required' => TRUE,
      '#default_value' => $row->url,
    );
    $groupID++;
  }

  //Build the fieldset with the proper number of entries. We'll use
  // $form_state['num_new'] to determine the number of new textfields to build.
  if (empty($form_state['num_new'])) {
    if ($result->rowCount() > 0) {
      $form_state['num_new'] = 0;
    }
    else {
      $form_state['num_new'] = 1;
    }
  }

  for ($i = 0; $i < $form_state['num_new']; $i++) {
    $form['pos_fieldset']['pos_group'][$groupID] = array(
      '#type' => 'fieldset',
      '#title' => t('Program of Study #!num', array('!num' => $groupID + 1)),
      '#prefix' => '<div class="pos-fieldset-group-wrapper">',
      '#suffix' => '</div>',
    );
    $form['pos_fieldset']['pos_group'][$groupID]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('The title of the page (eg. Doctoral Program of Study)'),
      '#required' => TRUE,
    );
    $form['pos_fieldset']['pos_group'][$groupID]['url'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('The URL to grab the program of study from. Currently only supports degrees.unm.edu'),
      '#required' => TRUE,
    );
    $groupID++;
  }
  $form['pos_fieldset']['add_pos'] = array(
    '#type' => 'submit',
    '#value' => t('Add another'),
    '#submit' => array('program_of_study_admin_form_add'),
    '#ajax' => array(
      'callback' => 'program_of_study_admin_form_callback',
      'wrapper' => 'pos-fieldset-wrapper',
    ),
  );
  if ($form_state['num_new'] > 1 || ($form_state['num_new'] > 0 && $result->rowCount() > 0)) {
    $form['pos_fieldset']['remove_pos'] = array(
      '#type' => 'submit',
      '#value' => t('Remove one'),
      '#submit' => array('program_of_study_admin_form_remove'),
      '#ajax' => array(
        'callback' => 'program_of_study_admin_form_callback',
        'wrapper' => 'pos-fieldset-wrapper',
      ),
      '#limit_validation_errors' => array(),
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );

  return $form;
}

/**
 * Callback for both ajax-enabled buttons.
 *
 * Selects and returns the fieldset with the titles/urls in it.
 */
function program_of_study_admin_form_callback($form, $form_state) {
  return $form['pos_fieldset'];
}

/**
 * Submit handler for the "add-another" button.
 *
 * Increments the max counter and causes a rebuild.
 */
function program_of_study_admin_form_add($form, &$form_state) {
  $form_state['num_new']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "remove one" button.
 *
 * Decrements the max counter and causes a form rebuild.
 */
function program_of_study_admin_form_remove($form, &$form_state) {
  if ($form_state['num_new'] > 0) {
    $form_state['num_new']--;
  }
  $form_state['rebuild'] = TRUE;
}

function program_of_study_admin_form_validate($form, &$form_state) {
  foreach ($form_state['values']['pos_fieldset']['pos_group'] as $key => $group) {
    if (!strstr($group['url'], 'http')) {
      form_set_error("pos_fieldset][pos_group][{$key}][url", 'Please enter a valid URL.');
    }
  }
}

/**
 * @param $form
 * @param $form_state
 * @throws Exception
 */
function program_of_study_admin_form_submit($form, &$form_state) {
  foreach ($form_state['values']['pos_fieldset']['pos_group'] as $group) {
    if (isset($group['posid'])) {
      db_update('program_of_study')
        ->fields(array(
          'title' => $group['title'],
          'url' => $group['url'],
        ))
        ->condition('id', $group['posid'])
        ->execute();
    }
    else {
      db_insert('program_of_study')
        ->fields(array(
          'title' => $group['title'],
          'url' => $group['url'],
          'msg' => t('Awaiting page creation.'),
        ))
        ->execute();
    }
  }
  drupal_set_message('Changes saved.');
  //Create/update pages
  get_program_of_study();
}