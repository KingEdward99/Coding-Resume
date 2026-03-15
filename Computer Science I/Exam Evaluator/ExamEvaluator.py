#This program evaluates the lowest, the highest and the average score after a set test scores
# Created January 28, 2025
# Author Eddy Koundjou Yem

#Reading the file and extracting the information 
from cgi import test
from gettext import find

#Collecting the student and their grades from the file
def file_reading():
    students = []
    
    with open("Test1scores.txt","r") as exam:
        #Reading in the exam scores
        for line in exam:
            line = line.strip() #removing the newlines
            name, score = line.split(",") #separating the names and grades into tuples
            students.append((name.strip(), int(score.strip())))

    return students

#Showing the professor different options
def menu():
    print("Welcome to the Exam Evaluator.\n")
    print("Press 1 to find the student with the highest  \n")
    print ("Press 2 to find the student with the lowest score. \n")
    print("Press 3 to find the average.\n")

    #Collecting the user's menu options
    menu_selection = int(input("Pick a menu option. \n"))
    return menu_selection 

#function that finds the highest score
def find_highest(students):
    #setting the highest_score to 0 to prepare the comparisons
    highest_student = students[0]

    #comparison algorithm for finding the highest
    for student in students:
        if student[1] > highest_student[1]:
            highest_student = student
    
    #Printing the student and the highest score
    print("The highest scores is: " ,highest_student[1])
    print("Student: ", highest_student[0])

#function that finds the lowest score
def find_lowest(students):
    #Setting the lowest_score to 0 to prepare the comparisons
    lowest_student = students[0]

    #comparison algorithm for find the lowest
    for student in students:
        if student[1] < lowest_student[1]:
            lowest_student = student
    #Printing the student and the lowest score
    print("The lowest score is: ", lowest_student[1])
    print("Student: ", lowest_student[0])

#function that finds the average
def find_average(students):
    #algorithm to finding the average
    total_exam_score = 0
    size = len(students)

    #Going throught the tuple and adding all the scores up
    for name,score in students:
        total_exam_score += score

    #dividing by number of students
    average_exam_score = total_exam_score / size

    print("The average exam scores was: ", average_exam_score)
            
#function that selects the operations
def selection(option, students):
    if option == 1:
        find_highest(students)
    elif option == 2:
        find_lowest(students)
    elif option == 3:
        find_average(students)

#calling the functions
menu_selection = menu()
students = file_reading()
selection(menu_selection,students)