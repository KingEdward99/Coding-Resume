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

#User finding the quantity / cardinality of each position
def size(first_position, second_position, third_position):
    print("Which position do you want to see the quantity of?")
    print("Select 1 for guards")
    print("Select 2 for forwards")
    print("Select 3 for centers")
    user_size_choice = int(input()) 

    if user_size_choice == 1:
        print("The quantity of the point guards are: " ,len(first_position))
    elif user_size_choice == 2:
        print("The quantity of the forwards are: ", len(second_position))
    elif user_size_choice == 3:
        print("The quantity of the centers are: ", len(third_position))
    else:
        print("Invalid choice")

#Explores different duo / combinatrics of the three positions
def duos(first_position, second_position, third_position):
    print("Which two positions do you want to see in a duo")
    print("Select 1 for guards and forwards")
    print("Select 2 for guards and centers")
    print("Select 3 for forwards and centers")
    user_size_choice = int(input())

    if user_size_choice == 1:
        for primary in first_position:
            for secondary in second_position:
                print(primary + " & " + secondary)
    if user_size_choice == 2:
        for primary in first_position:
            for tertiary in third_position:
                print(primary + " & " + tertiary)
    if user_size_choice == 3:
        for secondary in second_position:
            for tertiary in third_position:
                print(secondary + " & " + tertiary)

    
#Rosters set divided into guards, forwards and centers
guards = ["Gabe Vincent", "Luka Doncic", "Bronny James"]
forwards = ["Lebron James", "Jarred Vanderbilt", "Dalton Knecht"]
centers = ["Jaxson Hayes", "Deandre Ayton"]

print("Welcome to the Lakers positions data: \n")
print("We have a list of various positions, potential combinations, quantity at each position, and duo explorations\n")
print("Select 1 for a list of players at certain position\n")
print("Select 2 for combinations of different positions\n")
print("Select 3 for the quantity of players at each position\n")
print("Select 4 for potential duo combinations\n")

menu_choice = int(input())

if menu_choice == 1:
    choice(guards, forwards, centers)
elif menu_choice == 2:
    union(guards, forwards, centers)
elif menu_choice == 3:
    size(guards, forwards, centers)
elif menu_choice == 4:
    duos(guards, forwards, centers)
else:
    print("Invalid option")