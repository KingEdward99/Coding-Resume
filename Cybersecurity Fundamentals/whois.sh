#Using whois on a website

#!/bin/bash

#Defining our domain and output
DOMAIN="scanme.nmap.org"
OUTPUT="whois_results.txt"

#Starting the whois
echo "Using whois for $OUTPUT"
whois "$DOMAIN" >> "$OUTPUT"

echo "Scanning is done and save on $OUTPUT"