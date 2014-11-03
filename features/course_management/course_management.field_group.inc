<?php
/**
 * @file
 * course_management.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function course_management_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tags|node|course|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '12',
    'children' => array(
      0 => 'field_department',
      1 => 'field_level',
      2 => 'field_term',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tags',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_tags|node|course|form'] = $field_group;

  return $export;
}
