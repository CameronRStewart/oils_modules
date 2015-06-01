<?php

function course_info_drush_command() {
    $items['delete-course-content'] = array(
        'description' => 'Deletes all entities of the type provided.',
        'aliases' => array('dcc'),
        'options' => array(
            'types' => 'Comma seperated list of each content type whose entities you wish to remove.'
        ),
    );

    return $items;
}

function drush_course_info_delete_course_content() {

    $types = drush_get_option('types', '');

    $types = explode(',', $types);

    course_info_delete_all_content($types);

}

function course_info_delete_all_content($type) {

    if(isset($type) && !empty($type)) {
        foreach($type as $t) {
            $query = new EntityFieldQuery;

            $result = $query->entityCondition('entity_type', 'node')
                ->propertyCondition('type', $t)
                ->execute();

            if (isset($result['node']) && count($result['node'])) {
                $node_ids = array_keys($result['node']);

                node_delete_multiple($node_ids);
            }
        }
    }
}