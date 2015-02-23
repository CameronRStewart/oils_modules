<?php
/**
 * @file
 * employee_updater_role.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function employee_updater_role_user_default_roles() {
  $roles = array();

  // Exported role: employee updater.
  $roles['employee updater'] = array(
    'name' => 'employee updater',
    'weight' => 2,
  );

  return $roles;
}
