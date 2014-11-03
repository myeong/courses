<?php
class SectionsMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->team = array(
      new MigrateTeamMember('Myeong Lee', 'myeong@umd.edu', t('Developer')),
      );
    $this->issuePattern = 'http://drupal.org/node/:id:';
    $this->description = 'An import of sections from the JSON file.';
    
    $this->dependencies = array('Courses');
    
    // There isn't a consistent way to automatically identify appropriate "fields"
    // from an XML feed, so we pass an explicit list of source fields
    $fields = array(
    	'section_id' => t('Unique Section ID'), // needed only for migrate
    	'course_code' => t('Course code to match data'),// needed only for migrate
		'section' => t('Section ID'),
    	'teacher' => t('Teacher'),
    );
    
    $current_site = array();
    $current_site = explode("/", conf_path());
    $current_site = explode(".", $current_site[1]);
    $json_file = drupal_realpath(file_default_scheme() . '://') . "/courses/" . $current_site[0] . "/course_data.json";     

    $this->map = new MigrateSQLMap(
    	$this->machineName,
      	array(
        	'section_id' => array(
          		'type' => 'varchar',          	
          		'not null' => TRUE,
      			'length' => 20,
        	)
      	),
      MigrateDestinationFieldCollection::getKeySchema()
    );
    
    //$this->systemOfRecord = Migration::DESTINATION;
    
    $this->source = new MigrateSourceList(new SectionMultiListJSON($json_file), new SectionItemJSON($json_file, array()), $fields);    	

    $this->destination = new MigrateDestinationFieldCollection('field_sections', array('host_entity_type' => 'node'));
    
    $this->addFieldMapping('host_entity_id', 'course_code')->sourceMigration('Courses');
      
    $this->addFieldMapping('field_section_id', 'section');
    $this->addFieldMapping('field_teacher', 'teacher');
    $this->addFieldMapping('field_user_id', 'teacher')->callbacks(array($this, 'matchUser'));

  }
  
  public function prepareRow($row) {
  }
    
  public function matchUser($value){
  	
  	$result = NULL;
  	$names = explode(" ", $value);
  	$firstname = $names[0];
  	$lastname = $names[sizeof($names)-1];  	
  	  	
  	$input = $firstname . "%" . $lastname;

  	/* Direct querying to DB for enhancing performance */
  	$query_result = db_select('field_data_field_longname', 'f')
		  			 ->fields('f', array("entity_id"))
		  			 ->condition('field_longname_value', $input, 'LIKE')
		  			 ->execute();
  	while ($row = $query_result->fetchAssoc()){
  		$result = $row["entity_id"];  	
  		break;
  	}  	
/*
 *  Constructing an array to match user's full name and username. Reserved for future use.
 *   
  	$users = entity_load('user');
  	$result = NULL;
  	
  	$names = array();
  	foreach ($users as $user){
  		$name = field_get_items('user', $user, 'field_longname');
  	
  		if ($name){
  			if ($name[0]["value"] == $value){
  				$result = $user->uid;
  				break;
  			}
  		} else {
  			continue;
  		}
  	
  	}
  */  	
  		
  	return $result;
  	
  }
  public function setSystemOfRecordDest(){
  	$this->systemOfRecord = Migration::DESTINATION;
  }
  
}

class SectionMultiListJSON extends MigrateListJSON {

/* 'code' field in JSON would be ID in Drupal */
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    $i = 0;
    foreach ($data as $item) {
      foreach($item['sections'] as $section_item){
      	$ids[$i] = $section_item['section_id'];
      	$i++;
      }      
    }
    return $ids;
  }  
  
  public function computeCount() {
      $count = 0;
    if (empty($this->httpOptions)) {
      $json = file_get_contents($this->listUrl);
    }
    else {
      $response = drupal_http_request($this->listUrl, $this->httpOptions);
      $json = $response->data;
    }
    if ($json) {
      $data = drupal_json_decode($json);
      if ($data) {      
      	foreach($data as $item){      		
        	$count += count($item['sections']);         	
      	}
      }
    }
    return $count;
  }  
}

class SectionItemJSON extends MigrateItemJSON {
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
          if(is_array($item->sections)){
         	 foreach($item->sections as $section_item){          	  
            	$this->data[$section_item->section_id] = $section_item;            
          	 }
          }
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