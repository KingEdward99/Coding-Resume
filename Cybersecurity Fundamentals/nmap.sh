#Using whois on a website

#!/bin/bash

#Defining our domain and output
DOMAIN="scanme.nmap.org"
OUTPUT="nmap_results.txt"

#Starting the scan
echo "---Starting Scan ---" > $OUTPUT


echo "Host availability for $DOMAIN >> $OUTPUT"

#nmap command for detemrining host availability
nmap -sn $DOMAIN >> $OUTPUT



#Scanning the top 100 most common ports with their service version and operating system
echo "Top 100 most common ports for $DOMAIN >> $OUTPUT"
nmap -top-ports 100 -sV -O $DOMAIN >> $OUTPUT

#Utilizing the nmap script engine (NSE) to find interesting directories or headers on the web server port 80 or 443"
echo "Running NSE Discovery Scripts >> $OUTPUT"
echo "Some interesting files: >> $OUTPUT"

nmap -sC -p 80, 443 $DOMAIN >> $OUTPUT

echo "Script is done. Everything is in $OUTPUT"