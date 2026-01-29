# This program explores sets using different basketball players on the 2025 - 2026 Lakers NBA roster
# It explores cardinality, union, Cartesian product and a little bit of combinatorics
#Created by Eddy Koundjou Yem

#Operations

#union between two sets / player positions
def union(first_position, second_position, third_position):
    #Displaying the different unions we can display and asking for their input
    print("Which combination of positions do you want to see?")
    print("1: guards and forwards\n")
    print("2: guards and centers\n")
    print("3: forwards and centers\n")
    union_choice = int(input())

    #choice decision
    if union_choice == 1:
        print(first_position + second_position)
    elif union_choice == 2:
        print(first_position + third_position)
    elif union_choice == 3:
        print(second_position + third_position)
    else:
        print("Invalid option selected")

#user choosing which positions what they want to see
def choice(first_position, second_position, third_position):
    users_first_choice = int(input("Choose 1 for guard, Choose 2 for forwards, and 3 for centers\n"))
    
    if users_first_choice == 1:
        print(first_position)
    elif users_first_choice == 2:
        print(second_position)
    elif users_first_choice == 3:
        print(third_position)
    else:
        print("Invalid option")
    
#Rosters set divided into guards, forwards and centers
guards = ["Gabe Vincent", "Luka Doncic", "Bronny James"]
forwards = ["Lebron James", "Jarred Vanderbilt", "Dalton Knecht"]
centers = ["Jaxson Hayes", "Deandre Ayton"]

#choice(guards, forwards, centers)
union(guards, forwards, centers)

