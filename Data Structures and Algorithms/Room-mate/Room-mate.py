"""
    This program allows students to find their perfect roommate
    The program presents the user with potential roommates based on name and major
"""

#Student class to hold the main attributes
class Student:
    name = ""
    major = ""

Student.name = "Eddy"
Student.major = "Computer Science"

#Student Database, using a list for easier traversal and accessibility
studentDatabase = [
    ["Eddy", "Computer Science"],
    ["Jeremiah", "Finance"],
    ["Maya", "Criminal Justice" ]
]

#Displaying the students
print(Student.name + " " + Student.major)

#Displaying the database
print(studentDatabase)