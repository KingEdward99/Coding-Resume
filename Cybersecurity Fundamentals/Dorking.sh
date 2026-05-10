#This is a google dorking script that searches for documents and different positions
#Created: 05/10/2026

#!/bin/bash

#Target Domain
DOMAIN=""

#Seeking the different files and positions
queries=(
    "site:$DOMAIN filetype:pdf"
    "site:$DOMAIN filetype:docx"
    "site:$DOMAIN filetype:xlsx"
    "site:$DOMAIN intitle:'index of'"
    "site:$DOMAIN president"
    "site:$DOMAIN associate"
    "site:$DOMAIN researcher"
    "site:$DOMAIN cyber"
)

#Outputting the results
OUTPUT="OSINT_results.txt"
echo "search results for $DOMAIN" > "$OUTPUT"

#Loop through queries
for query in "${queries[@]}"; do 
    echo "Running query: $query"
    echo -e "\n === $query ===" >> "$OUTPUT"
    
    #URL encode the query
    encoded=$(python3 - << EOF
import urllib.parse
print(urllib.parse.quote("$query"))
EOF
)

    #Perform the search in browser
    curl -s "https://www.google.com/search?q=$encoded" >> "$OUTPUT"
done

echo "Done. Results were saved to $OUTPUT"
