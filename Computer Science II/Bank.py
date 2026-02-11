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
def menu_selection(bank_withdraw, bank_deposit, bank_display_amount):
    print("If you want to see your current balance press 1 \n")
    print("If you want to deposit money, press 2\n")
    print("If you want to withdraw money, press 3 \n")

#default balance for users
user_balance = 1000

#Calling functions
bank_announcement()
user_balance = bank_withdraw(user_balance)