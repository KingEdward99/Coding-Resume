#This is a file analyzing script that uses coommon Linux commands to analyze a file
#!/bin/bash

#Defining our domain and output 
DOMAIN="nmap.sh"
OUTPUT="File_analyzed_report.txt"

echo "What do you want to see?"
echo "Choose 1 if you want to see the contents of $DOMAIN"

read menu_choice

if [ "$menu_choice" = 1 ]; then
    echo "Here are the contents of your file"
    cat $DOMAIN

fi