"""
    This program allows students to find their perfect roommate
    The program presents the user with potential roommates based on name and major
"""

#Student class to hold the main attributes
class Student:
    name = ""
    major = ""
    classification = ""

    proper_classification = ["Freshman", "Sophomore", "Junior", "Senior"]

    if classification not in proper_classification:
        raise ValueError (
            f"{classification} is not a valid choice. \n "
            "Please pick either Freshman, Sophomore, Junior, or Senior"
        )
    
    def matching_level():
        """
            Calculates the matching level between two students 
            Returns 'High', 'Medium' or 'Low'
        """
        student1_major = ""
        student2_major = ""
        student1_classification = ""
        student2_classification = ""
        match = 0

        if student1_major == student2_major:
            match += 1
        
        if student1_classification == student2_classification:
            match += 1
        
        if match == 2:
            return "High"
        elif match == 1:
            return "Medium"
        else:
            return "Low"

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

#Having the user enter their info
print("Welcome to the CMRC Room-mate. We will help you find the ideal roommate.")
name = input("Please enter your first name: ")
major = input("Please enter your major: ")
classification = input("Please enter your classification: ")