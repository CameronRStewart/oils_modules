<?php
function program_of_study_remove_form($form, &$form_state) {
  $form = array();
  // Because we have many fields with the same values, we have to set
  // #tree to be able to access them.
  $form['#tree'] = TRUE;

  $result = db_query('SELECT id, title FROM program_of_study')->fetchAllKeyed(0, 1);

  $form['items'] = array(
    '#type' => 'checkboxes',
    '#options' => $result,
    '#title' => t('Select items to remove.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Remove'),
  );

  return $form;
}

function program_of_study_remove_form_submit($form, &$form_state) {
  foreach ($form_state['values']['items'] as $item) {
    if ($item !== 0) {
      remove_program($item);
    }
  }
}

function remove_program($itemID) {
  $result = db_query('SELECT nid FROM program_of_study WHERE id = :id', array(':id' => $itemID))->fetchCol();

  if (isset($result[0]->nid) && !empty($result[0]->nid)) {
    node_delete($result[0]->nid);
  }
  db_delete('program_of_study')
    ->condition('id', $itemID)
    ->execute();
}