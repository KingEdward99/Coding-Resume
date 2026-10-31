# Design Specification: CMRC Room-mate Matching System

 

## 1. Introduction
    This document describes the technical design and architecture for the CMRC Room-mate Matching System.
    It details *how* the system will be implemented to meet the requirements outlined in the SRS document

## 2. System Architecture
    The system will be designed using an Object-Oriented approach in Python. 
    The architecture is centered around two primary classes, which separates the data model from the application logic
    
    ** ’Student’ Class: ** A data class that encapsulates all information and validation rules for a single student profile.
    
    ** ’Matcher’ Class: ** A service class that contains the core business logic, manages the collection of all student profiles, and performs the matching calculation

## 3. Class & Data Model Design

### 3.1. Class Diagram
Student
- name: string
- major: string
- classification: string
- id: int
+ init(..)
+ get_id(): int
 
Matcher
- all_students: list <Student>
+ create_student_account()
+ find_best_matches(..)
+ calculate_match_level(…)

### 3.2 Data Structures

**Student Storage:** All ‘Student’ objects will be stored in a Python list within the ‘Matcher’ class
The list id will be student’s unique ID. This allows for highly efficient ‘O(n)’ time complexity when looking up a student by their ID.


## 4. Algorithm Design
    Function calculate_match_level(student1, student2):
    //initialize a score for this specific pair
    
    SET match_points TO 0
    // Compare majors
    
    IF student1.major is equal to student2.major THEN INCREMENT match_points by 1 END IF
    // Compare classification
    
    IF student1.classification is equal to student2.classification
    THEN INCREMENT match_points by 1
    END IF
    
    //Detemrine the match level based on the final score
    IF match_points is equal to 2
    THEN RETURN “High”