<?php
/**
 * @file
 * course_management.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function course_management_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_title' => 'field_title',
    'field_sections' => 'field_sections',
    'field_sections_1' => 'field_sections_1',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sections' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sections_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['operator'] = 'and';
  $handler->display->display_options['filters']['tid_2']['group'] = 1;
  $handler->display->display_options['filters']['tid_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['operator_id'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['label'] = 'Term/Year';
  $handler->display->display_options['filters']['tid_2']['expose']['operator'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['identifier'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
    4 => 0,
    7 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['tid_2']['group_info']['label'] = 'Has taxonomy term';
  $handler->display->display_options['filters']['tid_2']['group_info']['identifier'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['tid_2']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'term';
  $handler->display->display_options['filters']['tid_2']['hierarchy'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['operator'] = 'and';
  $handler->display->display_options['filters']['tid_1']['group'] = 1;
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Course Level';
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
    4 => 0,
    7 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'level';
  $handler->display->display_options['filters']['tid_1']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_term' => 'field_term',
    'field_title' => 'field_title',
    'field_sections' => 'field_sections',
    'field_sections_1' => 'field_sections_1',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sections' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sections_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'The Classics department offers courses with three different prefixes.  Course numbers with the CLAS prefix are taught in English; those with the GREK prefix are language courses in either ancient or modern Greek; and those with the LATN prefix are language courses in Latin.  The course listings will be updated each semester. For more detailed descriptions of the courses, follow the link for the course brochure.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Course Code */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Course Code';
  $handler->display->display_options['fields']['title']['label'] = 'Course';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['label'] = 'Semester';
  $handler->display->display_options['fields']['field_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  /* Field: Content: Sections */
  $handler->display->display_options['fields']['field_sections']['id'] = 'field_sections';
  $handler->display->display_options['fields']['field_sections']['table'] = 'field_data_field_sections';
  $handler->display->display_options['fields']['field_sections']['field'] = 'field_sections';
  $handler->display->display_options['fields']['field_sections']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_sections']['delta_offset'] = '0';
  /* Field: Content: Sections */
  $handler->display->display_options['fields']['field_sections_1']['id'] = 'field_sections_1';
  $handler->display->display_options['fields']['field_sections_1']['table'] = 'field_data_field_sections';
  $handler->display->display_options['fields']['field_sections_1']['field'] = 'field_sections';
  $handler->display->display_options['fields']['field_sections_1']['label'] = 'Instructor(s)';
  $handler->display->display_options['fields']['field_sections_1']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_sections_1']['settings'] = array(
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_sections_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sections_1']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['group'] = 1;
  $handler->display->display_options['filters']['tid_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['operator_id'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['label'] = 'Term/Year';
  $handler->display->display_options['filters']['tid_2']['expose']['operator'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['identifier'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['tid_2']['group_info']['label'] = 'Has taxonomy term';
  $handler->display->display_options['filters']['tid_2']['group_info']['identifier'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['tid_2']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'term';
  $handler->display->display_options['filters']['tid_2']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid_2']['error_message'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['operator'] = 'and';
  $handler->display->display_options['filters']['tid_1']['group'] = 1;
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Course Level';
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
    4 => 0,
    7 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'level';
  $handler->display->display_options['filters']['tid_1']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'undergraduate/courses';
  $handler->display->display_options['menu']['title'] = 'Courses';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Course References */
  $handler = $view->new_display('references', 'Course References', 'references_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'references_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_term']['id'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['table'] = 'field_data_field_term';
  $handler->display->display_options['fields']['field_term']['field'] = 'field_term';
  $handler->display->display_options['fields']['field_term']['label'] = '';
  $handler->display->display_options['fields']['field_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Course Code */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Course Code';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['label'] = '';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;

  /* Display: Syllabus */
  $handler = $view->new_display('page', 'Syllabus', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Syllabus';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No syllabus available';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No syllabus is available for this faculty.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Course ID */
  $handler->display->display_options['fields']['field_course_id']['id'] = 'field_course_id';
  $handler->display->display_options['fields']['field_course_id']['table'] = 'field_data_field_course_id';
  $handler->display->display_options['fields']['field_course_id']['field'] = 'field_course_id';
  /* Field: Content: Instructor */
  $handler->display->display_options['fields']['field_instructor']['id'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['fields']['field_instructor']['field'] = 'field_instructor';
  $handler->display->display_options['fields']['field_instructor']['alter']['text'] = '[field_instructor-name]';
  $handler->display->display_options['fields']['field_instructor']['type'] = 'user_reference_plain';
  $handler->display->display_options['fields']['field_instructor']['settings'] = array(
    'user_reference_view_mode' => 'full',
  );
  /* Field: Content: Syllabus File */
  $handler->display->display_options['fields']['field_syllabus_file']['id'] = 'field_syllabus_file';
  $handler->display->display_options['fields']['field_syllabus_file']['table'] = 'field_data_field_syllabus_file';
  $handler->display->display_options['fields']['field_syllabus_file']['field'] = 'field_syllabus_file';
  $handler->display->display_options['fields']['field_syllabus_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Instructor (field_instructor) */
  $handler->display->display_options['arguments']['field_instructor_uid']['id'] = 'field_instructor_uid';
  $handler->display->display_options['arguments']['field_instructor_uid']['table'] = 'field_data_field_instructor';
  $handler->display->display_options['arguments']['field_instructor_uid']['field'] = 'field_instructor_uid';
  $handler->display->display_options['arguments']['field_instructor_uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_instructor_uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_instructor_uid']['title'] = 'Syllabus of %1';
  $handler->display->display_options['arguments']['field_instructor_uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_instructor_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_instructor_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_instructor_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_instructor_uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_instructor_uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['field_instructor_uid']['validate_options']['type'] = 'name';
  $handler->display->display_options['arguments']['field_instructor_uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'syllabus' => 'syllabus',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'syllabus/%';
  $export['courses'] = $view;

  return $export;
}
