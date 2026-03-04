#This program evaluates the lowest, the highest and the average score after a set test scores
# Created January 28, 2025
# Author Eddy Koundjou Yem

#presenting options to the user
from json import load

#Reading the file and extracting the information 
def load_grades(filename):
    students = []
    
    with open(filename,"r") as Exam_scores:
        for line in Exam_scores:
            name, grade = line.split()
            students.append(name, int(grade))
    
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
    for score in students:
        if students[score] > highest_student:
            highest_student = students
    return highest_student

#function that finds the lowest score
def lowest_score(grades):
    #Setting the lowest_score to 0 to prepare the comparisons
    lowest_score = grades[0]

    #comparison algorithm for find the lowest
    for score in grades:
        if score < lowest_score:
            lowest_score = score
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
students = load_grades("Test1scores.txt")

#Learning how to implement file reading in a program
