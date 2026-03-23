#Calculator that figures out the combination and permutation

#C(n,r) = n!/(r!*(n-r)!)
#P(n,r) = n!/(n-r)!

from math import perm
#Combination calculator
#C(n,r) = n!/(r!*(n-r)!)
def combination():
    #Combination function
    #Asking for the input 
    n = int(input("Enter n (total items):"))
    r = int(input("Enter r (items to arrange)"))
    
    #Top Half
    top_factorial = 1
    for i in range(1, n+1):
        top_factorial *= i


    #Bottom Left Half
    BL_factorial = 1
    for i in range(1,r+1):
        BL_factorial *= i

    #Bottom Right Half
    BR_factorial = 1
    s = n-r

    for i in range(1,s+1):
        BR_factorial *= i

    combination = top_factorial/(BL_factorial*BR_factorial)
    
    print("Combination is ",combination)
    print(f"C({n}, {r}) = {combination}") 

#Permutation Calculator
#P(n,r) = n!/(n-r)!
def permutation():
    #Permutation function: P(n,r) = n! / (n-r)!
    n = int(input("Enter n (total items): "))
    r = int(input("Enter r (items to arrange): "))

    #Calculate n!
    top_factorial = 1
    for i in range(1, n+1):
        top_factorial *= i

    #Calculate (n - r)!
    bottom_factorial = 1
    for i in range(1, (n-r)+1):
        bottom_factorial *= i

    perm = top_factorial / bottom_factorial
    
    print(f"P({n}, {r}) = {perm}")  

def menu():
    print("Welcome to the permutation-combination calculator")

    print("Remember in a permutation, order does matter")
    print("In a combination, order does not matter")
    print("Press 1 for combination")
    print("Press 2 for permutation")

    choice = int(input("Does your problem require a permutation or combination"))
    return choice

choice = menu()
if choice == 1:
    combination()
else:
    permutation()