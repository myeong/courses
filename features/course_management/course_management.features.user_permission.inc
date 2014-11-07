<?php
/**
 * @file
 * course_management.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function course_management_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
      2 => 'hist admin',
      3 => 'hist editor',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: administer course.
  $permissions['administer course'] = array(
    'name' => 'administer course',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'courses_ui',
  );

  // Exported permission: administer field collections.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
      2 => 'hist admin',
      3 => 'hist editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: create course content.
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create field_course_details.
  $permissions['create field_course_details'] = array(
    'name' => 'create field_course_details',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_credits.
  $permissions['create field_credits'] = array(
    'name' => 'create field_credits',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_description.
  $permissions['create field_description'] = array(
    'name' => 'create field_description',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_grade_method.
  $permissions['create field_grade_method'] = array(
    'name' => 'create field_grade_method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_level.
  $permissions['create field_level'] = array(
    'name' => 'create field_level',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_permission_required.
  $permissions['create field_permission_required'] = array(
    'name' => 'create field_permission_required',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_section_id.
  $permissions['create field_section_id'] = array(
    'name' => 'create field_section_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_sections.
  $permissions['create field_sections'] = array(
    'name' => 'create field_sections',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_syllabus_file.
  $permissions['create field_syllabus_file'] = array(
    'name' => 'create field_syllabus_file',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_teacher.
  $permissions['create field_teacher'] = array(
    'name' => 'create field_teacher',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_term.
  $permissions['create field_term'] = array(
    'name' => 'create field_term',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_title.
  $permissions['create field_title'] = array(
    'name' => 'create field_title',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_id.
  $permissions['create field_user_id'] = array(
    'name' => 'create field_user_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_id_manual.
  $permissions['create field_user_id_manual'] = array(
    'name' => 'create field_user_id_manual',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: delete any course content.
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own course content.
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(
      0 => 'course admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 15.
  $permissions['delete terms in 15'] = array(
    'name' => 'delete terms in 15',
    'roles' => array(
      0 => 'course admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 16.
  $permissions['delete terms in 16'] = array(
    'name' => 'delete terms in 16',
    'roles' => array(
      0 => 'course admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 17.
  $permissions['delete terms in 17'] = array(
    'name' => 'delete terms in 17',
    'roles' => array(
      0 => 'course admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any course content.
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_course_details.
  $permissions['edit field_course_details'] = array(
    'name' => 'edit field_course_details',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_credits.
  $permissions['edit field_credits'] = array(
    'name' => 'edit field_credits',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_description.
  $permissions['edit field_description'] = array(
    'name' => 'edit field_description',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_grade_method.
  $permissions['edit field_grade_method'] = array(
    'name' => 'edit field_grade_method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_level.
  $permissions['edit field_level'] = array(
    'name' => 'edit field_level',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_permission_required.
  $permissions['edit field_permission_required'] = array(
    'name' => 'edit field_permission_required',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_section_id.
  $permissions['edit field_section_id'] = array(
    'name' => 'edit field_section_id',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_sections.
  $permissions['edit field_sections'] = array(
    'name' => 'edit field_sections',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_syllabus_file.
  $permissions['edit field_syllabus_file'] = array(
    'name' => 'edit field_syllabus_file',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_teacher.
  $permissions['edit field_teacher'] = array(
    'name' => 'edit field_teacher',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_term.
  $permissions['edit field_term'] = array(
    'name' => 'edit field_term',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_title.
  $permissions['edit field_title'] = array(
    'name' => 'edit field_title',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_id.
  $permissions['edit field_user_id'] = array(
    'name' => 'edit field_user_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_id_manual.
  $permissions['edit field_user_id_manual'] = array(
    'name' => 'edit field_user_id_manual',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own course content.
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_course_details.
  $permissions['edit own field_course_details'] = array(
    'name' => 'edit own field_course_details',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_credits.
  $permissions['edit own field_credits'] = array(
    'name' => 'edit own field_credits',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_description.
  $permissions['edit own field_description'] = array(
    'name' => 'edit own field_description',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_grade_method.
  $permissions['edit own field_grade_method'] = array(
    'name' => 'edit own field_grade_method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_level.
  $permissions['edit own field_level'] = array(
    'name' => 'edit own field_level',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_permission_required.
  $permissions['edit own field_permission_required'] = array(
    'name' => 'edit own field_permission_required',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_section_id.
  $permissions['edit own field_section_id'] = array(
    'name' => 'edit own field_section_id',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_sections.
  $permissions['edit own field_sections'] = array(
    'name' => 'edit own field_sections',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_syllabus_file.
  $permissions['edit own field_syllabus_file'] = array(
    'name' => 'edit own field_syllabus_file',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_teacher.
  $permissions['edit own field_teacher'] = array(
    'name' => 'edit own field_teacher',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_term.
  $permissions['edit own field_term'] = array(
    'name' => 'edit own field_term',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_title.
  $permissions['edit own field_title'] = array(
    'name' => 'edit own field_title',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_id.
  $permissions['edit own field_user_id'] = array(
    'name' => 'edit own field_user_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_id_manual.
  $permissions['edit own field_user_id_manual'] = array(
    'name' => 'edit own field_user_id_manual',
    'roles' => array(
      0 => 'administrator',
      1 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit terms in 15.
  $permissions['edit terms in 15'] = array(
    'name' => 'edit terms in 15',
    'roles' => array(
      0 => 'course admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 16.
  $permissions['edit terms in 16'] = array(
    'name' => 'edit terms in 16',
    'roles' => array(
      0 => 'course admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 17.
  $permissions['edit terms in 17'] = array(
    'name' => 'edit terms in 17',
    'roles' => array(
      0 => 'course admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: publish any course content.
  $permissions['publish any course content'] = array(
    'name' => 'publish any course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish editable course content.
  $permissions['publish editable course content'] = array(
    'name' => 'publish editable course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish own course content.
  $permissions['publish own course content'] = array(
    'name' => 'publish own course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish any course content.
  $permissions['unpublish any course content'] = array(
    'name' => 'unpublish any course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish editable course content.
  $permissions['unpublish editable course content'] = array(
    'name' => 'unpublish editable course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish own course content.
  $permissions['unpublish own course content'] = array(
    'name' => 'unpublish own course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: view field_course_details.
  $permissions['view field_course_details'] = array(
    'name' => 'view field_course_details',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_credits.
  $permissions['view field_credits'] = array(
    'name' => 'view field_credits',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_description.
  $permissions['view field_description'] = array(
    'name' => 'view field_description',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_grade_method.
  $permissions['view field_grade_method'] = array(
    'name' => 'view field_grade_method',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_level.
  $permissions['view field_level'] = array(
    'name' => 'view field_level',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_permission_required.
  $permissions['view field_permission_required'] = array(
    'name' => 'view field_permission_required',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_section_id.
  $permissions['view field_section_id'] = array(
    'name' => 'view field_section_id',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_sections.
  $permissions['view field_sections'] = array(
    'name' => 'view field_sections',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_syllabus_file.
  $permissions['view field_syllabus_file'] = array(
    'name' => 'view field_syllabus_file',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_teacher.
  $permissions['view field_teacher'] = array(
    'name' => 'view field_teacher',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_term.
  $permissions['view field_term'] = array(
    'name' => 'view field_term',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_title.
  $permissions['view field_title'] = array(
    'name' => 'view field_title',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_id.
  $permissions['view field_user_id'] = array(
    'name' => 'view field_user_id',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_id_manual.
  $permissions['view field_user_id_manual'] = array(
    'name' => 'view field_user_id_manual',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_course_details.
  $permissions['view own field_course_details'] = array(
    'name' => 'view own field_course_details',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_credits.
  $permissions['view own field_credits'] = array(
    'name' => 'view own field_credits',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_description.
  $permissions['view own field_description'] = array(
    'name' => 'view own field_description',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_grade_method.
  $permissions['view own field_grade_method'] = array(
    'name' => 'view own field_grade_method',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_level.
  $permissions['view own field_level'] = array(
    'name' => 'view own field_level',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_permission_required.
  $permissions['view own field_permission_required'] = array(
    'name' => 'view own field_permission_required',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_section_id.
  $permissions['view own field_section_id'] = array(
    'name' => 'view own field_section_id',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_sections.
  $permissions['view own field_sections'] = array(
    'name' => 'view own field_sections',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_syllabus_file.
  $permissions['view own field_syllabus_file'] = array(
    'name' => 'view own field_syllabus_file',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_teacher.
  $permissions['view own field_teacher'] = array(
    'name' => 'view own field_teacher',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_term.
  $permissions['view own field_term'] = array(
    'name' => 'view own field_term',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_title.
  $permissions['view own field_title'] = array(
    'name' => 'view own field_title',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_id.
  $permissions['view own field_user_id'] = array(
    'name' => 'view own field_user_id',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_id_manual.
  $permissions['view own field_user_id_manual'] = array(
    'name' => 'view own field_user_id_manual',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'course admin',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
