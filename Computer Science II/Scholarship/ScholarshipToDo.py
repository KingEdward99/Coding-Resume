"""
   This program prvoides the necessary steps to apply to 
   MHEC, TMCF, and UNCF scholarships

   This program uses classes and functions to ensure that the
   user can apply to them.
"""

#Scholarship class with its functions
from asyncio import tasks
from ctypes import sizeof


class Scholarship:
    #Initializing function
    def __init__(self, title, deadline, status):
        self.title = title
        self.deadline = deadline
        self.status = status
        self.actions = []
    
    #Presenting the status of the scholarship
    def __str__(self):
        return (
            f"\n--- {self.title} ({self.status}) ---"
            f"\n--- Deadline: {self.deadline} --- "
            f"\nTo Do: {self.actions}"
        )

    #Adds the task to the scholarship list
    def add_task(self, action):
        self.actions.append(action)
        print(f"{action} has been added.")
    
    #removing the tasks from the scholarship list
    def remove_task(self, action):
        if action in self.actions:
            self.actions.remove(action)
            print(f"{action} has been done. ")
        else:
            print(f"{action} is not in the list.")
    
    #Looking for a specific task in the list
    def find_task(self):
        #Asking the user for input and storing in a variable
        search_action = input("Enter the name of the task.")

        if search_action in self.actions:
            print(f"{search_action} is in your opened tasks.")
        else:
            print(f"{search_action} is not in your opened tasks.")
    
    #Displaying the info for each scholarship
    def display_info(self):
        print(self)
    
    #Displaying the scholarship menu
    def scholarship_menu():
        print("Welcome to the Bulldog Scholarship Menu.\n")
        print("Your default scholarships are:\n")
        print("Thurgood Marshall College Fund \n")
        print("United Negro College Fund \n")
        print("Maryland Higher Education Commission\n")
        print("Each scholarship has different tasks for you to do")
        print("To display your scholarships, press 1")
        print("To add a scholarships, press 2")
        print("To edit a specific scholarship, press 3")

        user_choice = 0

        user_choice = int(input("What option do you want to pick?"))
        
        return user_choice
    
    def add_scholarship():
        #Creating a new scholarship object 
        new_scholarship = Scholarship("","","") 

        #Adding the necessary info for scholarship
        new_scholarship.title = input("What is the name of the scholarship?")
        new_scholarship.deadline = input("Enter the deadline in Month, Day, Year. e.g June 1, 2019")
        new_scholarship.status = input("Enter open if the scholarship is still open. Enter closed if it is not")

        #Adding tasks to the scholarship
        print("Add up to four tasks for your new scholarship")

        for i in range(4):
            task = input(f"task {i+1}: ")
            new_scholarship.actions.append(task)
            if task.strip() == "":
                break
        
        print (new_scholarship)

        return new_scholarship

#Inheritance code
class BowieState(Scholarship):
    pass

#Printing Scholarship menu
BowieState = Scholarship
user_option = Scholarship.scholarship_menu()

#Creating a MHEC Scholarship object and adding tasks
MHEC = Scholarship("MD Scholarship ", "June 01, 2026", "Open")
MHEC.actions.append("Fill out the form")


#Creating a TMCF Scholarship object and adding tasks
TMCF = Scholarship("Thurgood Marshall College Fund ", "May 23, 2026", "Open")
TMCF.actions.append("Fill out the form")
TMCF.actions.append("Complete your video essay")


#Creating a UNCF Scholarship object and adding tasks
UNCF = Scholarship("United Negro College Fund ", "July 01, 2026", "Closed")
UNCF.actions.append("Fill out the form.")
UNCF.actions.append("Finish your written essay.")
UNCF.actions.append("Submit your recommendation letter.")

if user_option == 1:
    print(MHEC)
    print(TMCF)
    print(UNCF)
elif user_option == 2:
    Scholarship.add_scholarship()
elif user_option == 3:
    print("You have the following scholarships you can edit: ", MHEC.title, TMCF.title, UNCF.title)
    edit_option = int(input("Enter the scholarship you want to edit: "))
    if edit_option == 1:
        add_or_remove = int(input("Press 1 to add a task. Press 2 to remove: "))
        if add_or_remove == 1:
            user_add_task = input("What task do you want to add?")
            MHEC.actions.append(user_add_task)
            print(MHEC)
        elif add_or_remove == 2:
            for tasks in MHEC.actions:
                print(tasks, MHEC.actions)
            user_remove_task = int(input("Select the action you want to remove: "))
            MHEC.actions.pop(user_remove_task)
            print(MHEC)