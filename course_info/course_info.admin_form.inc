<?php
function course_info_admin_form($form, &$form_state) {
    $form = array();

    $form['unm_data_url'] = array(
        '#type' => 'fieldset',
        '#title' => t('Enter Program of Studies URLs and Titles.'),
        '#prefix' => '<div id="pos-fieldset-wrapper">',
        '#suffix' => '</div>',
    );

    $results = db_query('SELECT * FROM courses_info_url');

    // There should only ever be one result
    $count = $results->rowCount();
    if ($count > 1) {
        //Display message and take the first URL
        $form['unm_data_url']['message'] = array(
            '#markup' => '<span style="color:dodgerblue">There should only ever be one URL for this file, check your results.  There may be a problem.</span>',
        );
        //$result = $result[0];
    }

    foreach($results as $result) {
        if (!isset($result->url)) {
            $result->url = "Feed Me!";
        }
        $form['unm_data_url']['url'] = array(
            '#type' => 'textfield',
            '#title' => t('URL'),
            '#description' => t('The URL to grab the UNM Open Data file'),
            '#required' => TRUE,
            '#default_value' => $result->url,
        );
    }


    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save Configuration'),
    );

    return $form;
}

function course_info_form_validate($form, &$form_state) {
    $saved_url = $form_state['values']['unm_data_url']['url'];
    if (!strstr($saved_url, 'http')) {
            form_set_error("unm_data_url][url", 'Please enter a valid URL.');
        }


}

/**
 * @param $form
 * @param $form_state
 * @throws Exception
 */
function course_info_admin_form_submit($form, &$form_state) {
    $saved_url = $form_state['values']['url'];
    $exists = db_query('SELECT * FROM courses_info_url')->fetchField();

    if(!$exists) {
        db_insert('courses_info_url')
            ->fields(array(
                'title' => t('UNM Open Data URL'),
                'url' => $saved_url,
            ))
            ->execute();
    }
    else {
        db_update('courses_info_url')
            ->fields(array(
                'title' => t('UNM Open Data URL'),
                'url' => $saved_url,
            ))
            ->condition('id', 1)
            ->execute();
    }

    drupal_set_message('Changes saved.');

    //Grab UNM Course info file and parse into DB.
    //load_course_info_from_web();
}

