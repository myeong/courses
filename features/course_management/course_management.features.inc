<?php
/**
 * @file
 * course_management.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function course_management_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function course_management_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function course_management_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('Course content type migrated from Testudo'),
      'has_title' => '1',
      'title_label' => t('Course Code'),
      'help' => '',
    ),
    'syllabus' => array(
      'name' => t('Syllabus'),
      'base' => 'node_content',
      'description' => t('Syllabus for Courses'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
