# This program enables users to buy wings from The Pub at Bowie State

#Presenting the menu to the customer
def menu():
    print("Welcome to The Pub")
    print("We have chicken wings for $1 per wing")
    print("The wing flavors are: BBQ, Zeng, and Lemon Pepper")
    print("Our cornbread is $2")
    print("Our drink options are Sprite, Coca-Cola, and water")

#The options
def foodPrice():
    wingsPrice = 1.00
    cornbreadPrice = 2.00
    drinkPrice = 1.00

    return wingsPrice, cornbreadPrice, drinkPrice

#Collecting the user's order
def userOrder():
    #Giving the user options on what they want to order
    print("If you want some wings press 1")
    print("If you want some cornbread, press 2")
    print("If you want some drinks, press 3")
    userOrder = int(input("What do you want to order?"))

    #Initializing the food options
    wingsQuantity = 0
    wingsFlavor = ""
    cornbreadQuantity = 0
    drinkQuantity = 0
    drinkFlavor = ""

    userOrderDone = 1

    #Going through the options
    while (userOrderDone == 1):
        #User ordering wings
        if userOrder == 1:
            wingsQuantity += int(input("How many wings do you want?"))

            print("If you want BBQ, press 1")
            print("If you want Lemon Pepper, press 2")
            print("If you want Zeng, press 3")

            wingsFlavor = int(input("Which flavor of wings do you want?"))
            if wingsFlavor == 1:
                wingsFlavor = "BBQ"
            elif wingsFlavor == 2:
                wingsFlavor = "Lemon Pepper"
            elif wingsFlavor == 3:
                wingsFlavor= "Zeng"
            
            print("Number of wings you ordered: ",wingsQuantity )
            print("The flavor of the  wings: ", wingsFlavor)
        
        #User ordering cornbread
        elif userOrder == 2:
            cornbreadQuantity += int(input("How much cornbread do you want"))
            print("You ordered", cornbreadQuantity, "cornbread.")
        
        #User ordering drinks
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
                
            print("You ordered ", drinkQuantity, drinkFlavor)
        
        #In case the user presses the wrong option
        else:
            print("Invalid selection")
        
        #Asking the user if they want anymore food
        print("Do you want anything else? ")
        userOrderDone = int(input("Press 1 for Yes. Press 2 for No"))

        #When the user wants more food
        if userOrderDone == 1:
            print("\nIf you want some wings, press 1")
            print("If you want some corbread, press 2")
            print("If you want some a drink, press 3")
            userOrder = int(input("What do you want to order?"))

    return wingsQuantity, cornbreadQuantity, drinkQuantity

#Doing the math of calculating the food price
def orderProcessing(userOrderFunc, foodPriceFunc):
    #Calling the functions
    wingsQuantity, cornbreadQuantity, drinkQuantity = userOrderFunc()
    wingsPrice, cornbreadPrice, drinkPrice = foodPriceFunc()

    #Calculating the total food ordered
    wingsTotalPrice = wingsQuantity * wingsPrice
    cornbreadTotalPrice = cornbreadPrice * cornbreadQuantity
    drinkTotalPrice = drinkPrice * drinkQuantity
    
    totalOrder = wingsTotalPrice + cornbreadTotalPrice + drinkTotalPrice
    
    #Displaying the total cost to the user
    print("\n Order Summary:")
    print("Wings total: $", wingsTotalPrice)
    print("Cornbread total: $", cornbreadTotalPrice)
    print("Drink total: $", drinkTotalPrice)
    print("Total order: $", totalOrder)

    return totalOrder
   
#Collecting user payment 
def paymentcollection(orderProcessingFunc):
    totalOrder = orderProcessingFunc(userOrder, foodPrice)
    userPayment = 0.0

    #Presenting the total cost and verifying the user pays
    while userPayment < totalOrder:
        print("Your total cost is $: ", totalOrder)
        userPayment = float(input("How much are you willing to pay?"))

        #In case the user pays more and the program needs to return change
        if userPayment < totalOrder:
            print("Insufficent funds")
        else:
            userChange = userPayment - totalOrder
            print("Your change is $", userChange)

#Running the program
menu()
paymentcollection(orderProcessing)