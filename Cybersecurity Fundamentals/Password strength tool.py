# Password strength tool

'''
This application determines how strong your password is 

Steps
1. User enters their password 
2. Function calculates the strength 
3. Program outputs the strength 
'''


#function where user enters their password
def userPassword():
    password = input("Enter your password and I will determine its strength: ")
    return password

# calculates the strength of the password 
def passwordStrength(password):
    strengthCounter = 0
    
    if len(password) <= 5:
        strengthCounter = 1
    else:
        strengthCounter = 2
    
    return strengthCounter


#outputs the strength of the password 
def strengthResult(strengthCounter):
    if strengthCounter <= 5:
        passwordStrength = "weak"
    else:
        passwordStrength = "Strong"
    return passwordStrength

#User enters their password 
user_input = userPassword()
tough = passwordStrength(user_input)

#Outputting the result 
print("Your password is:", user_input)
print("Your password strength score is:", tough)
print(" which means it is ", strengthResult(tough))