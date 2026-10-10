"""
    This program allows students to find their perfect roommate
    The program presents the user with potential roommates based on name and major
"""
import random 
#Student class to hold the main attributes
class Student:

    def __init__(self, name, major, classification,id):
        """
        Creating the self instance
        """
        self.name = name
        self.major = major
        self.classificaiton = classification
        self.id = id
    
    def accountCreation():
        """
        Creating an account and inserting it into the database
        """

        #Having the user enter their info
        print("Welcome to the CMRC Room-mate. We will help you find the ideal roommate.")
        name = input("Please enter your first name: ")
        major = input("Please enter your major: ")
        classification = input("Please enter your classification: ")
        id = random.randint(1,2000)

        #Making sure the classification is the correct one
        proper_classification = ["Freshman", "Sophomore", "Junior", "Senior"]

        while classification not in proper_classification:
            raise ValueError (
            f"{classification} is not a valid choice. \n "
            "Please pick either Freshman, Sophomore, Junior, or Senior"
        )

        newAccount = [name, major, classification,id]

        studentDatabase.append(newAccount)
   
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

#Student Database, using a list for easier traversal and accessibility
studentDatabase = [
    ["Eddy", "Computer Science", "Senior", 1267],
    ["Jeremiah", "Finance", "Freshman", 4356],
    ["Maya", "Criminal Justice", "Sophomore", 8790]
]

#Creating an object
newStudent = Student("","","",0000)

#Calling the account creation
Student.accountCreation()

#Displaying the database
print(studentDatabase)