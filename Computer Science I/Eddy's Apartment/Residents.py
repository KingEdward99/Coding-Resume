#This is an apartment management program. It allows the user to print current residents, add residents, remove residents, and search for residents
#This program explores the usage of dictionaries

#Function that reads the file and enters it into the program 
from os import remove

def file_reading():
    apartments = {}
    
    with open("Residents.txt", "r") as apt:
        #Reading the the residents and apartments
        for line in apt:
            line = line.strip() #removing the newlines
            name, room = line.split(",") #separating the names and rooms into the dictionary
            apartments[name.strip()] = room.strip()
    
    return apartments

#Displays the current residents and their apartment number
def print_residents():
    apartments = file_reading()
    print(apartments)

#Adding residents to the apartment 
def add_residents(apartments):
    #The maximum residents that can be added are eight
    if len(apartments) >= 8:
        print("There apartment list is too full. You cannot add more residents")
    else:
        #Adding the residents and the room number 
        print("Which resident do you want to add in the apartment")
        name = input("Enter resident name: ")
        room = input("Enter the room number: ")

        apartments[name] = room
        save_residents(apartments)
    
    print("The residents and their apartments are: ")
    print(apartments)

#Removing residents from their apartment    
def remove_residents(apartments):
    #Can't remove residnts from an empty apartment 
    if len(apartments) == 0:
        print("The apartments are empty. You cannot remove any more residents")
    else:
        print("Which resident do you want to remove from the apartment")
        name = input("Enter resident name: ")

        #Checking to see if the user actually exists in the apartment
        if name in apartments: 
            apartments.pop(name)
            save_residents(apartments) 
            print(f"{name} has been removed.")
        else:
            print(f"{name} is not in the apartment")
    
    #Printing the current residents of the apartment
    print(f"The residents in the apartment are: ")
    print(apartments)

#Searching for a resident to see where they say 
def search_residents(apartments):
    name = input("Which resident are you looking for")
    if name in apartments:
        print(f"{name} is in room.")
    else:
        print(f"{name} is not in the apartment")
    print()

#Making the changes permanent
def save_residents(apartments):
    with open("Residents.txt," "w") as apt:
        for name,room in apartments.items():
            apt.write(f"{name}, {room}")

#Menu for the user
def menu(apartments):
    print("Welcome to the Eddy's Apartment database")
    print("You can display, remove, add residents that are currently in the apartment")
    print("To display the current residents, press 1")
    print("To add a resident, press 2")
    print("To remove a resident, press 3")
    print("To search for a resident, press 4")
    print("To exit the program, press -1")

    choice = 0
    while choice != -1:
        choice = int(input("Which option do you want to pick"))
        if choice == 1:
            print_residents()
        elif choice == 2:
            add_residents(apartments)
        elif choice == 3: 
            remove_residents(apartments)
        elif choice == 4: 
            search_residents(apartments)
        else:
            print("Invalid option")
        
#Running the program 
apartments = {}
apartments = file_reading()
menu(apartments)