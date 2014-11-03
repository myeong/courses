Courses UI module
-----------------
by Myeong Lee, deeperlee@gmail.com

This module is basically targeting administrators or developers who manage 
University of Maryland's websites and course catalogs in the websites.

This module provides an interface to import course data from Testudo website, the school's course website.


# For developers

## courses_ui/migrate_courses

by Myeong Lee, deeperlee@gmail.com
This module is a standard migrate module for courses, which migrate data from a JSON file to Drupal site.
Since it migrates data to field_collection fields for sections, it has two different migration files.
Courses UI module has a dependency on this module.

## courses_ui/migrate_courses/testudo-crawler

This consists of Python scripts that crawls Testudo sites. It was originally developed by Brady Law (UMD)
in 2011, and modified by Myeong Lee in 2013 since there were a big change in Testudo website. 
Also, it was customized to be used with Drupal's Migrate module.
In this system, the crawler is triggered by migrate_courses module, when migrate scripts are triggered.
But you can use it separately in other modules.