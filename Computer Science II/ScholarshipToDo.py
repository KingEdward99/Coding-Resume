"""
   This program prvoides the necessary steps to apply to 
   MHEC, TMCF, and UNCF scholarships

   This program uses classes and functions to ensure that the
   user can apply to them.
"""

#Scholarship class with its functions
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

#Creating a MHEC Scholarship object and adding tasks
MHEC = Scholarship("MD Scholarship ", "June 01, 2026", "Open")
MHEC.add_task("Fill out your FAFSA")
MHEC.add_task("Create MDCAPS account")
print(MHEC)

#Creating a TMCF Scholarship object and adding tasks
TMCF = Scholarship("Thurgood Marshall College Fund ", "May 23, 2026", "Open")
TMCF.add_task("Create TMCF Account")
TMCF.add_task("Create video essay")
print(TMCF)

#Creating a UNCF Scholarship object and adding tasks
UNCF = Scholarship("United Negro College Fund ", "July 01, 2026", "Closed")
UNCF.add_task("Ask Professors for a recommendation letter")
print(UNCF)