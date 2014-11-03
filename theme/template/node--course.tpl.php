<div<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <div>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </div>   
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <div class="submitted"><?php print $date; ?> -- <?php print $name; ?></div>
  <?php endif; ?>  
  
  <div<?php print $content_attributes; ?>>
  
   <script>
   /* jQuery scrips for link to user profiles and syllabi in Course page */   
   		jQuery(function(){
   	  		userIds = jQuery(".node-course .field-collection-item-field-sections .content");

			/* Creating syllabus and user profile links for imported user profiles */
			userIds.each(function(){
				/* If there are both user id that comes from Testudo and that is entered manually, ignore the automatical one*/
				if (jQuery(this).children('.field-name-field-user-id').length != 0  
						&& jQuery(this).children('.field-name-field-user-id-manual').length != 0){
					jQuery(this).children('.field-name-field-user-id').remove();
					return;
				} 
				userId = jQuery(this).children('.field-name-field-user-id').find('div.field-item');
				if(userId.length == 0) return;
				userIdText = userId.text();
				userFullName = jQuery(this).children(".field-name-field-teacher").find('div.field-item');
				userId.find('a').text(userFullName.text());				
				userFullName.parent().html(userId.html());	
				userId.find('a').remove(); 	 		
			});

			userIdManual = jQuery(".node-course .field-name-field-user-id-manual");   	

			/* Updating manually set user reference in the view */
			userIdManual.each(function(){
				uid = jQuery(this).find('div.field-item');
				uidText = uid.text();
				uidFullName = jQuery(this).prev(".field-name-field-teacher").find('div.field-item');
				uid.find('a').text(uidFullName.text());				
				uidFullName.parent().html(uid.html());	
				uid.find('a').remove();
				
			});			
   	  				
   		});  
  </script>

    <?php
      
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      
      // hide other fields if there's no contents
      if (isset($content['field_course_details'])){
     	 if ($content['field_course_details'][0]['#markup']  == ''){
      		hide($content['field_course_details']);
      	 }
      }
      if ($content['field_description'][0]['#markup'] == ''){
      	hide($content['field_description']);
      }      
      
      if (isset($title)){
      	print "<div class='course-title'>" . $title . " - </div>";
      }      
      $term_str = isset($content['field_term'][0]['#markup']) ? $content['field_term'][0]['#markup'] : '';
      
      $term = '';
      $year = substr($term_str, -4);
      $semester = strtok($term_str, " ");
      if ($semester == "Spring"){ 
      	$term = $year . '01';      	
      } elseif ($semester == "Summer"){
      	$term = $year . '05';      	
      } elseif ($semester == "Fall"){
	  	$term = $year . '08';      	
      } elseif ($semester == "Winter"){
      	$term = $year . '12';
      }    
      $dept = substr($title, 0, 4);	  
      
      print '<div id="testudo-icon"><a href="https://ntst.umd.edu/soc/search?courseId=' . $dept .
      		'&termId='. $term .'" target="_blank"> 
      		<img src="/' . drupal_get_path("module", "courses_ui") . '/img/testudo.png" /></a><br>';
      print 'Check times and seat availability on Testudo</div>';
      
      print render($content);
      
    ?>
  </div>
  
  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <div class="links node-links clearfix"><?php print render($content['links']); ?></div>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</div>