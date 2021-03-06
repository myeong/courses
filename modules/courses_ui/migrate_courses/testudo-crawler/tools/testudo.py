#!/usr/bin/env python
# encoding: utf-8
"""
testudo_crawl.py

Created by Brady Law on 2011-01-16.
Copyright (c) 2011 Unknown. All rights reserved.

Modified by Myeong Lee on 2013-06-06.
Since there were big changes in Testudo site, this work had to be revised. 
"""

import re
import urllib
import logging

logger = logging.getLogger('testudo_crawler')
logger.setLevel(logging.DEBUG)
ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)
formatter = logging.Formatter("%(asctime)s - %(name)s - %(levelname)s - %(message)s")
ch.setFormatter(formatter)
logger.addHandler(ch)

class crawler:
    base_url = 'https://ntst.umd.edu/soc/search'

    """ Testudo Regular Expressions:
    Cheatsheet:
        (?P<var>...)    Variable named "var".
        .               Any char except \n.
        [\s\S]          Any char.
        *               Match as much as possible
        *?              Match as little as possible.
    """

    """ Simple Course Pattern:
        Grabs only the course code in an effort to be as simple as possible. This is used
        for testing that the full pattern (course_pattern) is correct.
    """
    simple_course_columns = ['code']
    simple_course_pattern = re.compile(r"""
            <div\sclass="course-id">\s*
            (?P<code>.*)<\/div>\s*
            """, re.IGNORECASE | re.VERBOSE)

    """ Full Course Pattern:
        Grabs all course data, and passes on section data if found for further parsing.
    """
    course_columns = [
            'code',             # ex. CMSC131
            'title',            # ex. Introduction to Computer Programming via the Web
            'permreq',          # ex. PermReq
            'credits',          # ex. 3 credits
            'grade_method',     # ex. REG/P-F/AUD
            'details',          # ex. Corequisite: MATH140 and permission of department...
            'description',      # ex. Introduction to programming and computer science...   
            #'section_data',         
            ]
    course_pattern = re.compile(r"""
            <div\sclass="course-id">\s*
            (?P<code>.*)<\/div>\s*            
            (<div\sclass="perm-req-message">(?P<permreq>.*?)<\/div>\s*)?
            <\/div>\s*    
            <div\sclass="course-info-container[\w\W\s]+?
            <div\s[\w\W\s]+?
            <div\s[\w\W\s]+?
            <div\s[\w\W\s]+?
            <span\sclass="course-title">(?P<title>[\s\S]*?)<\/span>\s*     
            <\/div>\s*
            <div\s[\w\W\s]+?
            <a\shref[\w\W\s]+?
            <input\s[\w\W\s]+?
            <input\s[\w\W\s]+?
            <img\s[\w\W\s]+?
            <\/a>\s*
            <\/div>\s*
            <\/div>\s*
            <div\s[\w\W\s]+?
            <div\s[\w\W\s]+?
            <div>\s*
            <span\s[\w\W\s]+?<\/span>\s*   
            <span\sclass="course-min-credits">(?P<credits>[\d])<\/span>\s*?
            (?:-\s*?<span\sclass="course-max-credits">[\d]<\/span>\s*?)?
            <\/div>\s*?
            <\/div>\s*?
            <div\s[\w\W\s]+?
            <div>\s*?
            <span\s[\w\W\s]+?
            <span\s[\w\W\s]+? 
            <abbr\stitle="Regular[\s\S]*?<span>(?P<grade_method>[\s\S]*?)<\/span><\/abbr>\s*?
            <\/span>\s*
            <\/div>\s*
            <\/div>\s*
            <div\s[\w\W\s]+?
            <div>\s*
            (?:<span\s[\w\W\s]+?<\/span>\s*?
            <a\shref[\w\W\s]+?)?
            <\/div>\s*
            <\/div>\s*
            <div\s[\w\W\s]+?
            <div>\s*
            (?:<span\s[\w\W\s]+?
            <span\s[\w\W\s]+?
            <a\shref[\w\W\s]+?</a></span>)?\s*
            <\/div>\s*?
            <\/div>\s*?
            <\/div>\s*?
            <\/div>\s*?
            (<div\sclass="approved-course-texts-container">\s*?         
            (<div\sclass="row">\s*?
            <div\s[\w\W\s]+?
            <div\sclass="approved-course-text">(?P<details>[\s\S]*?)\s*<\/div>\s*?
            <\/div>\s*?
            <\/div>)?\s*?
            (<div\sclass="row">\s*?
            <div\s[\w\W\s]+?
            <div\sclass="approved-course-text">(?P<description>[\s\S]*?)\s*<\/div>\s*
            <\/div>\s*
            <\/div>)?\s*
            <\/div>             
            )?\s*
            <div\sclass="course-texts-container">\s*
            (<div\sclass="row">\s*?
            <div\s[\w\W\s]+?
            <div\s[\w\W\s]+?<\/div>\s*?
            <\/div>\s*?
            <\/div>\s*?)?
            <\/div>\s+
            (<div\sclass="toggle-sections-link-container">[\w\W\s]+?
            <fieldset\sclass="sections-fieldset\ssections-displayed">
            (?P<section_data>[\s\S]*?)
            <\/fieldset>)?                        
            """, re.IGNORECASE | re.VERBOSE)

    """ Section Pattern:
        Scrapes data for each course section.
    """
    section_columns = [
            'section',
            #'class_time_data',
            #'course_id',
            'teacher',
            #'seats',
            #'open',
            #'waitlist',
            ]
            # 'class_time_data'
    section_pattern = re.compile(r"""
            <span\sclass="section-id">\s*?
            (?P<section>[\w]{4})\s*?
            <\/span>\s*?
            (
            <span\sclass="footnote-marker">[*]<\/span>\s*?
            )?
            <\/div>\s*?
            <div\s[\w\W\s]+?
            <span\sclass="section-instructors">\s*?            
            <span\sclass="section-instructor">(?P<teacher>[\s\S]+?)<\/span>
            [\s\S]*?     
            <div\sclass="class-days-container">
            (?P<class_time_data>[\s\S]*?)            
            <\/div>\s*?            
            (
            <div\sclass="two\scolumns">\s*?
            <span\sclass="class-type">Discussion<\/span>\s*?
            <\/div>\s*?
            )?
            <\/div>\s*?
            <\/div>\s*?
            <\/div>       
            """, re.IGNORECASE | re.VERBOSE)

    """ Class time pattern:
        Scrapes time and location data for each time the section meets.
    """
    class_time_columns = [
            'days',
            'start_time',
            'end_time',
            'building',
            'room',
            # 'type'
            ]
    class_time_pattern = re.compile(r"""
            <span\sclass="section-days">(?P<days>[MWFTuh]+?)<\/span>\s*           
            <span\sclass="class-start-time">(?P<start_time>\d{1,2}:\d{2}[apm]{2})<\/span>[\s\S]*?
            <span\sclass="class-end-time">(?P<end_time>\d{1,2}:\d{2}[apm]{2})<\/span>\s*?
            <\/div>\s*?
            <div\s[\w\W\s]+?
            <span\sclass="class-building">[\s\S]*?
            <span\sclass="building-code">(?P<building>\w+?)<\/span><\/a>\s*?
            <span\sclass="class-room">(?P<room>\w+?)<\/span>\s*?<\/span>
            """, re.IGNORECASE | re.VERBOSE)


    def __init__(self, term, verbose=False):
        self.term = term
        if verbose:
            logger.setLevel(logging.INFO)
        else:
            logger.setLevel(logging.WARNING)
        self.verbose = verbose   
        self.section_seq = 0     

    """
    Returns a list of dictionaries representing all departments.
    ex. {
    'code' : 'AASP',
    'title' : 'African American Studies'
    }
    """
    def get_departments(self):
        response = self.fetch_departments_page()
        pattern = re.compile('<a href=soc.*>(.*)</a>(.*)<br>', re.I)
        departments = list()
        for match in pattern.finditer(response):
            departments.append(dict(code=match.group(1).strip(), title=match.group(2).strip()))

        if self.verbose:
            logger.info('%d departments found.' % len(departments))

        return departments

    """
    Returns a list of dictionaries representing all courses.
    Args:
        dept - Department to retrieve courses for.
        simple - For testing, use the simpler RegEx search to grab only the course titles.
    """
    def get_courses(self, dept, level, simple=False):
        if self.verbose:
            logger.info('Downloading %s...' % (dept))

        response = self.fetch_courses_page(dept=dept, level=level)
        
        pattern = self.course_pattern if not simple else self.simple_course_pattern
        columns = self.course_columns if not simple else self.simple_course_columns        
        courses = list()
        
        for m in pattern.finditer(response):            
            course_raw_data = m.groupdict()
            course = dict()
            for col in columns:
                course[col] = clean_and_trim(course_raw_data[col])
                 
            # Parse the course data
            course['id'] = encode(self.term) + course['code'] 
            course['sections'] = self.parse_section_data(course_raw_data['section_data'],course['id']) \
                if 'section_data' in course_raw_data else None
            course['level'] = get_level(level=level)
            course['term'] = get_term(term=self.term)  
            course['dept'] = get_department(dept=dept)
            courses.append(course)

        if self.verbose:
            logger.info('%d courses downloaded for %s.' % (len(courses), dept))

        return courses

    def parse_section_data(self, section_data, code):
        if not section_data:
            return None

        sections = list()
        for s in self.section_pattern.finditer(section_data):
            class_times = list()
            new_section = dict()
            raw_section_data = s.groupdict()
                        
            # Parse the class time data
            new_section['course_code'] = code           
            if s.group('class_time_data'):
                for ct in self.class_time_pattern.finditer(s.group('class_time_data')):
                    class_times.append(ct.groupdict())
                    

            for col in self.section_columns:
                new_section[col] = re.sub('<[^>]*>', '', clean_and_trim(raw_section_data[col]))

            new_section['class_times'] = class_times
            new_section['section_id'] = code + new_section['section']            
            sections.append(new_section)            
            
        logger.info('  %d sections downloaded' % (len(sections)))
            
        return sections

    def fetch_departments_page(self, level):
        return self.fetch_courses_page(dept='DEPT', level=level)

    def fetch_courses_page(self, dept, level):
        #level = 'UGRAD'
        #level = 'GRAD'
        params = urllib.urlencode({ 'courseId' : dept, 'termId' : self.term, 'courseLevelFilter' : level, '_classDays' : 'on' })
        f = urllib.urlopen(self.base_url + '?%s' % params)
        response = f.read()
        f.close()
        return response

    def get_all_courses(self, simple=False):
        departments = self.get_departments()
        all_courses = list()

        d_count = len(departments)
        d_pos = 0

        for d in departments:
            d_pos += 1
            logger.info('Dept %d/%d' % (d_pos, d_count))
            all_courses.extend(self.get_courses(dept=d['code'], simple=simple))

        if self.verbose:
            logger.info('Done! %d courses found for %d departments.' % (len(all_courses), len(departments)))

        return all_courses

def clean_and_trim(string):
    if string:
        return string.replace('\n', ' ').strip()
    else:
        return None

def get_department(dept):    
    return {
        "AASP": "African American Studies",
        "AAST": "Asian American Studies",
        "AMST": "American Studies",        
        "ANTH": "Anthropology",
        "ARAB": "Arabic",
        "ARHU": "Arts and Humanities",
        "ARTH": "Art History & Archaeology",
        "ARTT": "Art Studio",
        "BSGC": "Global Communities",
        "BSOS": "Behavioral and Social Sciences",
        "CHIN": "Chinese",
        "CLAS": "Classics",
        "CMLT": "Comparative Literature",
        "COMM": "Communication",
        "DANC": "Dance",
        "EALL": "East Asian Languages and Literatures",
        "EDCI": "Curriculum and Instruction",        
        "ENGL": "English",
        "FILM": "Film Studies",
        "FMSC": "Family Science",
        "FOLA": "Foreign Language",
        "FREN": "French",
        "GERM": "Germanic Studies",
        "GREK": "Classics",        
        "HDCC": "Digital Cultures and Creativity",
        "HEBR": "Hebrew",
        "HESP": "Hearing and Speech Sciences",
        "HHUM": "Honors Humanities",
        "HISP": "Historic Preservation",
        "HIST": "History",        
        "HLTH": "Health",
        "HONR": "Honors",
        "ISRL": "Israel Studies",
        "ITAL": "Italian",
        "JAPN": "Japanese",
        "JWST": "Jewish Studies",
        "KORA": "Korean",
        "LASC": "Latin American Studies Center",
        "LATN": "Classics",
        "LGBT": "Lesbian Gay Bisexual Transgender Studies",
        "LING": "Linguistics",
        "MUSC": "School of Music",
        "PERS": "Persian",
        "PHIL": "Philosophy",
        "PORT": "Spanish and Portuguese",
        "RUSS": "Russian",
        "SLAA": "Second Language Acquisition",
        "SLLC": "School of Languages, Literatures and Cultures",
        "SPAN": "Spanish and Portuguese",
        "TDPS": "School of Theatre, Dance, and Performance Studies",
        "THET": "School of Theatre, Dance, and Performance Studies",    #theatre        
        "WMST": "Women's Studies",             
    }.get(dept, '')   
    
def get_level(level):
    return {
        "UGRAD": "Undergraduate",
        "GRAD": "Graduate"    
    }[level]

def get_term(term):
    year = term[:4]
    month = term[-2:]
    if month == "01":
        return "Spring " + year
    elif month == "05": 
        return "Summer " + year
    elif month == "08":
        return "Fall " + year
    elif month == "12":
        return "Winter " + str(int(year)+1)    
    else:
        return None

#encoding Source ID to shorten the length (should be under 10)
def encode(term):  
    year = term[-4:-2]  
    month = term[-2:]
    if month == "01":
        return "P" + year
    elif month == "05": 
        return "S" + year
    elif month == "08":
        return "F" + year
    elif month == "12":
        return "W" + year    
    else:
        return None