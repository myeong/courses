<?php
class CoursesMigration extends Migration {
	
  /* Current website's name */
  protected $course_data_path;
	
  public function __construct() {
    parent::__construct();
    
    $this->team = array(
      new MigrateTeamMember('Myeong Lee', 'myeong@umd.edu', t('Developer')),
      );
    $this->issuePattern = 'http://drupal.org/node/:id:';
    $this->description = 'An import of courses from the JSON file.';
    
    $fields = array(
		'code' => t('Course Code'),
		'title' => t('Title'),
    	'description' => t('Description'),    		
    	'grade_method' => t('Grade Method'),    		
    	'credits' => t('Credits'),
    	'details' => t('Course Details'),
		'permreq' => t('Permission Required'),
		//'sections' => t('Sections'),
    );
        
//     $current_site = array();
//     $current_site = explode("/", conf_path());
//     $current_site = explode(".", $current_site[1]);
        
    $this->course_data_path = drupal_realpath(file_default_scheme() . '://') . 
    						  "/courses";
    
    $json_file = $this->course_data_path . "/course_data.json";
    
    /* Creating a directory for JSON file, if not exist */
    if (!file_exists($this->course_data_path)) {
    	if (drupal_mkdir(drupal_realpath(file_default_scheme() . '://') . "/courses/", 0777)){
    		drupal_mkdir($this->course_data_path, 0777);
    		exec("touch " . $json_file);
    	} else {    	
    		print 'Course folder has not been created. Check the permission of your "files" folder. Import denied.';
    		return FALSE;
    	}
    }
    
    $this->course_data_path = $json_file; 
     
    $this->map = new MigrateSQLMap(
    	$this->machineName,
      	array(
        	'id' => array(
          		'type' => 'varchar',
          		'length' => 20,
          		'not null' => TRUE,
        	)
      	),
      MigrateDestinationNode::getKeySchema()
    );
    
    // The source ID here is the one retrieved from each data item in the XML file, and
    // used to identify specific items
    //$this->systemOfRecord = Migration::DESTINATION;

    $this->source = new MigrateSourceList(new MultiListJSON($json_file),
    					new CourseItemJSON($json_file, array()), $fields);   	
	
    $this->destination = new MigrateDestinationNode('course');
        
    $this->addFieldMapping('title', 'code');

    $this->addFieldMapping('field_description', 'description')
    ->callbacks(array($this, 'stripTags'));
    
    $this->addFieldMapping('field_title', 'title');

    $this->addFieldMapping('field_grade_method', 'grade_method');    	

    $this->addFieldMapping('field_credits', 'credits');

    $this->addFieldMapping('field_course_details', 'details')
    ->callbacks(array($this, 'stripTags'));

    $this->addFieldMapping('field_permission_required', 'permreq')
    ->callbacks(array($this, 'permDecode'));   

    $this->addFieldMapping('field_department', 'dept');
    
    $this->addFieldMapping('field_level', 'level')
    	 ->arguments(array('create_term' => TRUE));
    
    $this->addFieldMapping('field_term', 'term')
    	 ->arguments(array('create_term' => TRUE));
    
    //$this->addFieldMapping('field_sections', 'sections');
 
  }
    
  protected function permDecode($value) {
  	if($value) $result = 1;
  	else $result = 0;
  	return $result;
  }
  
  protected function stripTags($value) {
  	$result = strip_tags($value);
  	return $result;
  }
  
  public function prepareRow($row) {
	//print_r($row);	
  }
  
  /* Workaround to deal with field_collection nodes when updating */
  public function prepare($node, stdClass $row) {  	
  	// don't run on initial import only on update
  	if (isset($node->nid)) {
  		// load the original node object
  		$old_node = node_load($node->nid);
  		// add original field collection data to our current node object
  		$node->{'field_sections'} = $old_node->{'field_sections'};
  	}
  }
  
//  targeting all levels (UGrad, Grad) and departments (specified in the python code)
//  crawling Testudo before running migrate code
  public function preImport() {    
  	// options are coming from the course_ui module
  	$term = isset($this->options['term']) ? $this->options['term'] : null;
  	$depts = isset($this->options['department']) ? $this->options['department'] : null;
  	$python_command = null;
  	
  	if (isset($term) && isset($depts)){
  		$python_command = DRUPAL_ROOT ."/". drupal_get_path("module", "migrate_courses") . 
   						'/testudo-crawler/tools/export_course_data.py --term ' . $term . ' -d "' . implode($depts, " ") . 
   						'" --output ' . $this->course_data_path;  		
  	}
  		
   	if ($python_command){
   		$crawl_result = exec($python_command);
   		if ($crawl_result != 1){   			
   			drupal_set_message($message = "[Migrate] Courses for " . implode($depts, " ") . " were not able to be imported!", 
   								$type = 'error');
   			watchdog('migrate_courses', $crawl_result);
   			return FALSE;
   		} else {
   			drupal_set_message($message = "[Migrate] Course " . implode($depts, " ") . " has been seccussfully imported!", 
   								$type = 'status');
   			return 1;
   		}
   	}    
  }

  public function setSystemOfRecordDest(){
  	$this->systemOfRecord = Migration::DESTINATION;  	
  }
}

class MultiListJSON extends MigrateListJSON {

/* 'code' field in JSON would be ID in Drupal */
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    foreach ($data as $item) {
      $ids[] = $item['id'];      
    }
    return $ids;
  }  
}

class CourseItemJSON extends MigrateItemJSON {
  protected $data = array();
  /**
   * Two problems with the default getItem() - it reads and parses the JSON on
   * each call, which we don't want to do for multiple items in the file; and,
   * we need to retrieve a given item from the file according to its 'id' element.
   */
  public function getItem($id) {
    // We cache the parsed JSON at $this->data.
    if (empty($this->data)) {
      $data = $this->loadJSONUrl($this->itemUrl);
      if ($data) {
        // Let's index the array by the ID for easy retrieval.
        foreach ($data as $item) {        	
          $this->data[$item->id] = $item;
        }
      }
      else {
        // Error-handling here....
      }
    }
    // Return the requested item
    if (isset($this->data[$id])) {
      return $this->data[$id];
    }
    else {
      return NULL;
    }
  }
}
