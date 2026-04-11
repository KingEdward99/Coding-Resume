"""
    A Scholarship to do list based on the following scholarships
    MHEC
    TMCF
    UNCF

    Also using classes and functions to make it work 
"""
class Scholarship:
    Title = ""
    Deadline = ""
    Action = ""
    Status = "opened"

Scholarship = MHEC()

MHEC.title = "MD SCholarship"
MHEC.action = "Create MDCAPS Account"
MHEC.deadline = "June 01, 2026"
MHEC.status = "open"

#Finds specific scholarship tasks
def find_task(task_name):
    search = Scholarship()
    search.input = input("Enter the name of the task")

    for i in Scholarship():
        if i == search.input():
            return i
        else:
            print(f"Can't find {Scholarship}")

#Switching the tasks from open to close
def update_task(task_name):
    Scholarship.Action = "close"


