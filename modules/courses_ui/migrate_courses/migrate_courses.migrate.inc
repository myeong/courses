<?php
/**
 * Implements hook_migrate_api().
 */
function migrate_courses_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'Courses' => array('class_name' => 'CoursesMigration'),
      'Sections' => array('class_name' => 'SectionsMigration'),
    ),
  );
  return $api;
}

