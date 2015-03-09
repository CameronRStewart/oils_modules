<?php
function course_info_admin_form($form, &$form_state) {
    $form = array();

    $form['unm_data_college_code'] = array(
        '#type' => 'fieldset',
        '#title' => t('Enter UNM assigned letter code for this college.'),
    );

    $form['unm_data_url'] = array(
        '#type' => 'fieldset',
        '#title' => t('Enter URL to course information XML file.'),
    );

    $results = db_query('SELECT * FROM courses_info_admin_extras');

    // There should only ever be one result
    $count = $results->rowCount();
    if ($count > 1) {
        //Display message and take the first URL
        $form['unm_data_url']['message'] = array(
            '#markup' => '<span style="color:dodgerblue">There should only ever be one URL for this file, check your results.  There may be a problem.</span>',
        );
        //$result = $result[0];
    }


    if(isset($results) && !empty($results) && $count > 0) {
        foreach($results as $result) {
            if (!isset($result->url)  || empty($result->url)) {
                $result->url = "http://datastore.unm.edu/schedules/current.xml";
            }

            if (!isset($result->college_code) || empty($result->college_code)) {
                $result->college_code = 'Enter College Code';
            }
            $form['unm_data_college_code']['code'] = array(
                '#type' => 'textfield',
                '#title' => t('College Code'),
                '#description' => t('The code for your college in the UNM Open Data file'),
                '#required' => TRUE,
                '#default_value' => $result->college_code,
            );
            $form['unm_data_url']['url'] = array(
                '#type' => 'textfield',
                '#title' => t('URL'),
                '#description' => t('The URL to grab the UNM Open Data file'),
                '#required' => TRUE,
                '#default_value' => $result->url,
            );
        }
    } else {
        $college_code = 'Enter College Code';
        $form['unm_data_college_code']['code'] = array(
            '#type' => 'textfield',
            '#title' => t('College Code'),
            '#description' => t('The code for your college in the UNM Open Data file'),
            '#required' => TRUE,
            '#default_value' =>  $college_code,
        );
        $url = "http://datastore.unm.edu/schedules/current.xml";
        $form['unm_data_url']['url'] = array(
            '#type' => 'textfield',
            '#title' => t('URL'),
            '#description' => t('The URL to grab the UNM Open Data file'),
            '#required' => TRUE,
            '#default_value' => $url,

        );
    }



    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
        '#submit' => array('course_info_admin_form_submit'),
    );

    $form['reload'] = array(
        '#type' => 'submit',
        '#value' => t('Load XML'),
        '#submit' => array('course_info_admin_form_reload_submit'),
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
    $saved_college_code = $form_state['values']['code'];
    $exists = db_query('SELECT * FROM courses_info_admin_extras')->fetchField();

    if(!$exists) {
        db_insert('courses_info_admin_extras')
            ->fields(array(
                'url' => $saved_url,
                'college_code' => $saved_college_code,
            ))
            ->execute();
    }
    else {
        db_update('courses_info_admin_extras')
            ->fields(array(
                'url' => $saved_url,
                'college_code' => $saved_college_code,
            ))
            ->condition('id', 1)
            ->execute();
    }

    drupal_set_message('Changes saved.');

}

function course_info_admin_form_reload_submit($form, &$form_state) {
    //Grab UNM Course info file and parse into DB.
    $msg = load_course_info_from_web();

    drupal_set_message($msg);
}

