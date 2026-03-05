#This program evaluates the lowest, the highest and the average score after a set test scores
# Created January 28, 2025
# Author Eddy Koundjou Yem

#Reading the file and extracting the information 
from gettext import find


def file_reading():
    students = []
    
    with open("Test1scores.txt","r") as exam:
        #Reading in the exam scores
        for line in exam:
            line = line.strip() #removing the newlines
            name, score = line.split(",") #separating grades into names and grades
            students.append(name.strip(), int(score.strip()))

    return students


def menu():
    print("Welcome to the Exam Evaluator.\n")
    print("Press 1 to find the student with the highest  \n")
    print ("Press 2 to find the student with the lowest score. \n")
    print("Press 3 to find the average.\n")

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
    print("The highest scores is: " ,highest_student[1])
    print("Student: ", highest_student[0])

#function that finds the lowest score
def lowest_score(grades):
    #Setting the lowest_score to 0 to prepare the comparisons
    lowest_score = grades[0]

    #comparison algorithm for find the lowest
    for score in grades:
        if score < lowest_score:
            lowest_score = score
    return lowest_score

def find_lowest(students):
    lowest_score = students[0]

    for score in students:
        if students[score] < lowest_score:
            lowest_score = students[score]
    
    return lowest_score
            

#function that finds the average
def average_score(grades):
    #algorithm to finding the average

    size = len(grades)

    total_sum = 0

    for score in grades:
        total_sum += score
    
    average = total_sum / size

    return average

#function that selects the operations
def selection(option, grades):
    if option == 1:
        highest_grade = highest_score(grades)
        print("The highest score is: ", highest_grade)
    elif option == 2:
        lowest_grade = lowest_score(grades)
        print("The lowest score is: ", lowest_grade)
    elif option == 3:
        average_grade = average_score(grades)
        print("The average score is: ", average_grade)
    else:
        print("Invalid option selected.")

#set amount of grades
#grades = [80, 95, 62, 78, 83]

#option = menu()
#selection(option, grades)

#calling the first changed function
students = file_reading()
find_highest(students)

#Learning how to implement file reading in a program
