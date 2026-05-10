#Using nslookup on a website
#Created 05/10/2026

#!/bin/bash

#Defining out domain and output
DOMAIN=""
OUTPUT="NSLOOKUP_results.txt"

#Running the commands
echo "nslookup results for $DOMAIN" > "$OUTPUT"
nslookup "$DOMAIN" >> "$OUTPUT"

#Script has finished running 
echo "Done. Results were saved to $OUTPUT"