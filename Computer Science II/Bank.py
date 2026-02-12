#Creating a banking application where users can see their balance, withdraw money, and deposit money

#presenting the balance
def bank_announcement():
    print("Welcome to Eddy's bank.")
    print("You have the option to see your balance, withdraw some money, and deposit some money.\n")


#Withdrawing money
def bank_withdraw(user_balance):
    print("How much money do you want to withdraw?")
    user_withdraw_amount = int(input("Enter amount: "))

    print("You are withdrawing: ", user_withdraw_amount)

    if(user_withdraw_amount > user_balance):
        print("Insufficent funds.")
        return user_balance
    else:
        new_balance = user_balance - user_withdraw_amount
        print("You are withdrawing: ", user_withdraw_amount)
        print("You now have: ", new_balance)
        return new_balance

#depositing money
def bank_deposit(user_balance):
    print("How much money do you want to deposit?")
    user_deposit_amount = int(input("Enter amount: "))

    print("You are depositing: ", user_deposit_amount)

    new_balance = user_balance + user_deposit_amount
    return new_balance

#Displaying current money balance
def bank_display_amount(user_balance):
    print("Your current balance is: ", user_balance)

#Menu selection
def menu_selection(user_balance):
   

    menu_selection = -1
    while menu_selection != 0:
         print("If you want to see your current balance press 1 \n")
         print("If you want to deposit money, press 2\n")
         print("If you want to withdraw money, press 3 \n")
         print("If you want to exit the program, press 0")
         
         menu_selection = int(input("What do you want to see?"))
         
         if menu_selection == 1:
            bank_display_amount(user_balance)
         elif menu_selection == 2:
            user_balance = bank_deposit(user_balance)
         elif menu_selection == 3:
             user_balance = bank_withdraw(user_balance)
         elif menu_selection == 0:
            print("Thank you for using Eddy's Bank")
         else:
             print("Wrong input")
    
    return user_balance

#default balance for users
user_balance = 1000

#Calling functions
bank_announcement()

#Calling the menu
user_balance = menu_selection(user_balance)