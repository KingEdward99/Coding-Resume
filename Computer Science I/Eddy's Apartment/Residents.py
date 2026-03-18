#This program reads a file that contains residents and their apartment numbers
#It translates that information into a text file

"""
four methods
1. print current residents
2. add residents
3. remove residents
4. search residents
"""


def file_reading():
    apartments = {}
    
    with open("Residents.txt", "r") as apt:
        #Reading the the residents and apartments
        for line in apt:
            line = line.strip() #removing the newlines
            name, room = line.split(",") #separating the names and rooms into the dictionary
            apartments[name.strip()] = room.strip()
    
    return apartments

def print_residents():
    apartments = file_reading()
    print(apartments)

def add_residents(apartments):
    #The maximum residents are eight
    if len(apartments) >= 8:
        print("There apartment list is too full. You cannot add more residents")
    else:
        #Adding the residents and the room number 
        print("Which resident do you want to add in the apartment")
        name = input("Enter resident name: ")
        room = input("Enter the room number: ")

        apartments[name] = room
    
def remove_residents(apartments):
    if len(apartments) == 0:
        print("The apartmets are empty. You cannot remove any more residents")
    else:
        print("Which resident do you want to remove from the apartment")
        name = input("Enter resident name: ")

        if name in apartments: 
            apartments.pop(name)
            print(f"{name} has been removed.")
        else:
            print(f"{name} is not in the apartment")

"""
def search_residents():
    print()
"""

print_residents()