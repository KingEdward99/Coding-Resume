#This code creates an encryption and decryption algorithm for messages

#Menu presenting the options to the user
def menu():
    print("Welcome to Caesar Cipher encryption and decryption program \n")
    print("To encrypt your message, press 1.\n")
    print("To decrypt your message, press 2.\n")
    
    menu_choice = int(input("Select a menu choice: "))

    return menu_choice

#Encryption function
def encrypt():
    message = input("What message do you want me to encrypt?")
    encrypt_message = ""

    for char in message:
        encrypt_message += chr(ord(char) + 5)
    
    print("Encrypted message: ", encrypt_message)
    return encrypt_message

#Decryption function
def decrypt():
    message = input("What message do you want me to decrypt?")
    decrypt_message = ""

    for char in message:
        decrypt_message += chr(ord(char) - 5)

    print("Decrypted message: ", decrypt_message)
    return decrypt_message

user_choice = menu()
if user_choice == 1:
    encrypt()
elif user_choice == 2:
    decrypt()
else:
    print("Wrong choice")