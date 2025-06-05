# Password strength tool

'''
This application determines how strong your password is 

Steps
1. User enters their password 
2. Function calculates the strength 
3. Program outputs the strength 
'''


#user enters their password


def userPassword():
    password = input("Enter your password and I will determine its strength: ")
    return password

# calculates the strength of the password 
def passwordStrength(password):
    strengthCounter = 0
    
    if password.length() <= 5:
        strengthCounter = 1
    else:
        strengthCounter = 2
    
    return strengthCounter


#outputs the strength of the password 
def strengthResult(strengthCounter):
    if strengthCounter <= 5:
        passwordStrength = "weak"
    
    return passwordStrength

user_input = userPassword()
print(user_input)
