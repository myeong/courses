<?php
/**
 * @file
 * course_management.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function course_management_user_default_roles() {
  $roles = array();

  // Exported role: course admin.
  $roles['course admin'] = array(
    'name' => 'course admin',
    'weight' => '4',
  );

  return $roles;
}
