"""
    This program allows students to find their perfect roommate
    The program presents the user with potential roommates based on name and major
"""

#Student class to hold the main attributes
class Student:
    name = ""
    major = ""
    classification = ""

Student.name = "Eddy"
Student.major = "Computer Science"
Student.classification = "Senior"

#Student Database, using a list for easier traversal and accessibility
studentDatabase = [
    ["Eddy", "Computer Science", "Senior"],
    ["Jeremiah", "Finance", "Freshman"],
    ["Maya", "Criminal Justice", "Sophomore"]
]

#Displaying the students
print(Student.name + " " + Student.major + " " + Student.classification)

#Displaying the database
print(studentDatabase)