# This program enables users to buy wings from The Pub at Bowie State

#Presenting the menu to the customer
def menu():
    print("Welcome to The Pub")
    print("We have chicken wings for $1 per wings")
    print("The wing flavors are: barbecue, zing, and lemon pepper")
    print("Our cornbread is $2")
    print("Our drink options are Sprite, Coca-Cola, and water")

#The options
def foodprice():
    wings = 1.00
    cornbread = 2.00
    drink = 1.00

#Collecting the user's order
def userOrder():
    userOrder = input("What do you want to order?")

    wings_quantity = int(input("How many wings do you want?"))
    wings_flavor = input("What flavor do you want?")

    cornbread = int(input("How much cornbread do you want"))

    drink_flavor = input("Which drink do you want?")
    drink_quantity = input(int("How many drinks do you want?"))

def orderProcessing(wings_quantity, cornbread, drink_quantity):
    wings_total_price = 1.00 * wings_quantity
    cornbread_total_price = 2.00 * cornbread
    drink_total_price = 1.00 * drink_quantity

#Collecting user payment 
def paymentcollection():
    total_cost = 5.0
    user_payment = 0.0

    while user_payment < total_cost:
        print("Your total cost is $: ", total_cost)
        user_payment = float(input("How much are you willing to pay?"))

        if user_payment < total_cost:
            print("Insufficent funds")
        else:
            user_change = user_payment - total_cost
            print("Your change is $", user_change)

#Presenting the menu
#menu()

#Collecting the user order
#userOrder()

paymentcollection()



