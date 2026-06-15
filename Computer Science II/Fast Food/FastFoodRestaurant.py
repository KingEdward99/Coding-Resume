# This program enables users to buy wings from The Pub at Bowie State

#Presenting the menu to the customer
def menu():
    print("Welcome to The Pub")
    print("We have chicken wings for $1 per wing")
    print("The wing flavors are: BBQ, Zeng, and Lemon Pepper")
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
    wingsQuantity = 0
    wingsFlavor = 0
    printWingsFlavor = ""
    drinkFlavor = ""
    cornbreadQuantity = 0
    drinkQuantity = 0
    userOrderDone = 1
    userCompleteOrder = []

    #Going through the options
    while (userOrderDone == 1):
        if userOrder == 1:
            wingsQuantity += int(input("How many wings do you want?"))

            print("If you want BBQ, press 1")
            print("If you want Lemon Pepper, press 2")
            print("If you want Zeng, press 3")

            wingsFlavor = int(input("Which flavor of wings do you want?"))
            if wingsFlavor == 1:
                printWingsFlavor = "BBQ"
            elif wingsFlavor == 2:
                printWingsFlavor = "Lemon Pepper"
            elif wingsFlavor == 3:
                printWingsFlavor = "Zeng"
            
            print("Number of wings you ordered: ",wingsQuantity )
            print("The flavor of the  wings: ", printWingsFlavor)
        elif userOrder == 2:
            cornbreadQuantity += int(input("How much cornbread do you want"))
            print("You ordered", cornbreadQuantity, "cornbread.")
        elif userOrder == 3:
            drinkQuantity += int(input("How many drinks do you want?"))
            print("Press 1 for Sprite. Press 2 for Coca-Cola. Press 3 for water.")
            userDrinkFlavor = input("Which drink do you want?")
            if userDrinkFlavor == 1:
                drinkFlavor == "Sprite"
            elif userDrinkFlavor == 2:
                drinkFlavor == "Coca-Cola"
            elif userDrinkFlavor == 3:
                drinkFlavor == "water"
                
            print("You ordered", drinkQuantity, drinkFlavor)
        else:
            print("Invalid selection")
        
        print("Do you want anything else? ")
        userOrderDone = int(input("Press 1 for Yes. Press 2 for No"))
    
    return wingsQuantity, cornbreadQuantity, drinkQuantity


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
def paymentcollection(userOrder):
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

orderProcessing(userOrder)

#paymentcollection(orderProcessing)