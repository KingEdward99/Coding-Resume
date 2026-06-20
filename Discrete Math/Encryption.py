#This code creates an encryption and decryption algorithm for messages below 20 characters

#Menu presenting the options to the user
def menu():
    print("Welcome to Caesar Cipher encryption and decryption program \n")
    print("To encrypt your message, press 1.\n")
    print("To decrypt your message, press 2.\n")
    
    menu_choice = int(input("Select a menu choice: "))

    return menu_choice

#Encryption function
def encrypt():
    #The message gets into a list so each character can be encrypted
    message = (input("What message do you want me to encrypt?"))
    encrypt_message = ""

    for char in message:
        encrypt_message += chr(ord(char) + 5)
    
    print("Encrypted message: ", encrypt_message)
    return encrypt_message

#def decrypt(message):
 #   print(message)

user_choice = menu()
if user_choice == 1:
    encrypt()
else:
    print("Wrong choice")