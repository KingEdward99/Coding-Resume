#This is a file analyzing script that uses common Linux commands to analyze a file
#!/bin/bash

#Defining our domain and output 
DOMAIN="nmap.sh"

#Presenting the options to our user
echo "What do you want to see?"
echo "Choose 1 if you want to see the contents of $DOMAIN"
echo "Choose 2 if you want to see a page by page version of $DOMAIN. Note: Make sure to press :q to exit"
echo "Choose 3 if you want to see the bottom of $DOMAIN"
echo "Choose 4 if you want to see the top of $DOMAIN"
echo "Choose 0 if you want to exit the program."
read menu_choice

#Using a while loop so the porgrma does not end until the user wants to 
while [ "$menu_choice" -gt 0 ]; 
do
    #Reading the file
    if [ "$menu_choice" = 1 ]; then
        echo "Here are the contents of your file"
        cat $DOMAIN
    fi

    #Reading the file in page mode
    if [ "$menu_choice" = 2 ]; then
        echo "Here is a page by page version of $DOMAIN"
        less $DOMAIN
    fi

    #Reading the last 5 lines of the file
    if [ "$menu_choice" = 3 ]; then
        echo "Here is the bottom of $DOMAIN"
        tail -n 5 $DOMAIN
    fi

    #Reading the the first 5 lines of the file
    if [ "$menu_choice" = 4 ]; then
        echo "Here is the top of $DOMAIN"
        head -n 5 $DOMAIN
    fi

    #Exiting the program
    if [ "$menu_choice" = 0 ]; then
        echo "Exiting the program..."
        exit
    fi

    #Allowing the user to pick another option
    echo ""
    echo "What other options do you want to explore."
    read menu_choice
done