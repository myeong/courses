Course Management Module: Importing Courses data from UMD Testudo into Drupal website
===========================
Created by Myeong Lee (University of Maryland)
-----------------------------

### Introduction
Course Management module, a custom Drupal module, was developed for UMD websites (that were developed with Drupal). The motivation was from university members’ demands for presenting up-to-date courses in their department websites. So, I developed the module as a developer (GA) at ARHU Web and Application Services. The module basically crawls Testudo websites’ courses data and migrates them into Drupal database (as a Content Type called “Course”). This module can help administrators and users have up-to-data courses information which is automatically imported from the UMD Testudo site. 
Specifically, this module consists of 3 components: Python scripts, Drupal Migrate classes, and a custom Drupal module called “Courses UI.” The Python scripts were originally developed by a student from Computer Science department, but was old and not compatible with Drupal website. I modified and wrote some more codes, so that it can crawl the current version of Testudo site and provide Drupal-compatible formats of courses data. Then, the Migrate module was created to import the courses data into Drupal database system. Courses UI module provides a UI for administrators to import Courses manually, and basically used at the stage of setting up the courses pages. These 3 components are essential in importing courses data to Drupal system. Beside this module, in order for the data to be shown in an actual website, there should be some more configurations in the View, Content Type, and Template files.
Distributed File Structure
In the repository, there are 3 folders: features, modules, and theme.

- "modules" folder contains "courses ui" module, which is a core part of this project. Explained in the next section.
- "features" folder has "course_management" folder, which is a Drupal feature. This contains a content type, a view, and other minor configurations to help developers easily set up courses page. These are separated as a feature because this is about presenting the data, not about migrating the data.
- "theme" folder has "css" folder: it has a css file, and its contents can be copied to any css files that you are working with (normally, goes in "global.css" file).
	- "template" folder: it has two template files. Copy them to template folder that is under "theme" folder. These are overriding Course page (content type) and Course Listing page (View).

### courses_ui Module Structure
##### Courses UI module consists of 3 components
- Courses UI: this is a module that provides a basic UI for users to import courses data from Testudo. Also, dealing with a cron job.
- Migrate Courses: this is a module that overrides Migrate module, so that it migrates courses data from a JSON file to Drupal DB (Course Content Type). Automatically triggered by Courses UI module.
- Testudo-Crawler: this is a Python code that crawls the Testudo website. Automatically triggered by Migrate Courses module. Originally developed by Brady Law in 2011, and revised by Myeong Lee in 2013. 

##### File structure
- [Folder] courses_ui : the module folder
	- courses_ui.info
	- courses_ui.install  – automatically create taxonomy vocabularies that are needed for course migration (Course Code, Level, Term)
	- courses_ui.module – UI for course administrator, a cron job (per semester), and manual import functionality are implemented here.
	- LICENSE.txt
	- README.txt
	- [Folder] img – contains "testudo" icon
	- [Folder] migrate_courses – overridden "Migrate" class that import courses data from a JSON file to Drupal DB.
		- migrate_courses.info
		- migrate_courses.migrate.inc
		- migrate_courses.module – a cron job (everyday) implemented
		- [Folder] migrations
			- courses.inc – actual Migrate class that migrates "courses" data. Also, creating an empty JSON file under files folder.
			- sections.inc – actual Migrate class that migrates "sections" data (field_collection entity)
	- [Folder] testudo-crawler – Python scrips that crawls course information from Testudo website, and make a JSON file as an output.
		- [Folder] src – for testing, ignore it
		- [Folder] test  – for testing, ignore it
		- [Folder] tools
			- __init__.py
			- export_course_data.py – provide an interface with several options to use these scripts, and make a JSON file.
			- testudo.py – regular expressions and data organizing logic are implemented when crawling the Testudo site.
			- testudo.pyc

### JSON file
Stored at "files/courses/[site_name]/" directory in Drupal.
Supports multi-site configurations: each multisite can has its own JSON file, while the courses module is shared by all the site.