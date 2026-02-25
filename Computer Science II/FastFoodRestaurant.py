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
    #Giving the user options on what they want to order
    print("If you want some wings press 1")
    print("If you want some cornbread, press 2")
    print("If you want some drinks, press 3")
    userOrder = int(input("What do you want to order?"))

    #Initializing the food options
    wings_quantity = 0
    user_flavor = ""
    cornbread = 0
    drink_quantity = 0

    #Going through the options
    if userOrder == 1:
        wings_quantity = int(input("How many wings do you want?"))

        print("If you want bbq, press 1")
        print("If you want Lemon Pepper, press 2")
        print("If you want Zeng, press 3")

        wings_flavor = int(input("What flavor do you want?"))
        
        if wings_flavor == 1:
            user_flavor = "barbecue"
        elif wings_flavor == 2:
            user_flavor = "Lemon Pepper"
        elif wings_flavor == 3:
            user_flavor = "Zheng"
        else: 
            user_flavor = "Unknown Flavor"
        
        print("Number of wings you ordered: ",wings_quantity )
        print("The flavor of the  wings: ", user_flavor)

    elif userOrder == 2:
         cornbread = int(input("How much cornbread do you want"))
         print("You ordered", cornbread, "cornbread.")
    elif userOrder == 3:
        drink_quantity = int(input("How many drinks do you want?"))
        drink_flavor = input("Which drink do you want?")
        print("You ordered", drink_quantity, drink_flavor)
    else:
        print("Invalid selection")
    return wings_quantity, cornbread, drink_quantity


def orderProcessing(userOrder):
    wings_quantity, cornbread, drink_quantity = userOrder()

    wings_total_price = 1.00 * wings_quantity
    cornbread_total_price = 2.00 * cornbread
    drink_total_price = 1.00 * drink_quantity

    total_order = wings_total_price + cornbread_total_price + drink_total_price
    
    print("\n Order Summary:")
    print("Wings total: $", wings_total_price)
    print("Cornbread total: $", cornbread_total_price)
    print("Drink total: $", drink_total_price)
    print("Total order: $", total_order)

    return total_order


    
#Collecting user payment 
def paymentcollection():
    total_cost = 0.0
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
menu()

#Collecting the user order
#userOrder()

#paymentcollection()

orderProcessing(userOrder)