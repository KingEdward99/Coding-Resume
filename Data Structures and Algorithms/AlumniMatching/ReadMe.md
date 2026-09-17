Attempting to create Abstract Data Types with Alumni Matching Program (C++)

Purpose: Helping students match with alumni from their institution based on whether they are computer science, nursing, or business administration major. 

Program Tasks
- Determin whether a new user is an alumni or a student
- Determine the major
- Create a correct match between alumni and student (e.g computer science student with software engineering)

**ADT Student**
Model:
- represents students at the university 

Attributes:
- student name
- student email
- student major 

Operations:
- getInfo() - gets the name, email, and major
- matchwithAlumni - matches them with an alumni based on major

Behavior:
- stores the student data to match them with alumni 

Constraints
- data must be all in strings 

**ADT Alumni**
Model: 
- Represents the alumni from the school

Attributes: 
- alumni name
- alumni career
- alumni major

Operations
- getInfo() - gets the name, career, and major
- matchwithStudent - matches them with a student based on major 

Behavior:
- stores the alumni data to match them with students

Constraints
- data must be in all strings 

**ADT Matching System**
Model:
- algorithm that matches the students and alumni

Attributes
- student data
- alumni data


operations
- getStudentsInfo() - collects multiple students information
- getAlumniInfo() - collects multiple alumni information
- match() - matches students and alumni 

Behavior
- matches the students and alumni

Constraints
- Matching is strictly based on major