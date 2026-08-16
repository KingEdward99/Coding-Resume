
# Cybersecurity Fundamentals — Program Collection

This folder contains beginner-level programming projects written in Python and Java created as part of my **Cybersecurity Fundamentals** coursework. These projects build on the 

---

## Overview of Programs

### **1. Dorking.sh (Bash)**
This script automates **Google Dorking**, a common OSINT technique using in cybersecurity to discover publicly exposed files, directories, and organizational information, The user specifies a target domain, and the script runs a series of predefined search queries, covering document types, directory listings, and role-based keywords, then saves all results to a single output file. 

**Concepts demonstrated:** 
- Google Dorking
- OSINT
- Bash Scripting
- cURL requests
- URL encoding
- Reconnaissance techniques
- Automation in security

---

### **2. Log Analysis (Bash)**
This program provides a simple interface for analyzing a target gile using common Linux utilities. It allows the user to inspect the full contents of a file, view it page-by-page, or quickly examine the top or bottom lines.

**Concepts demonstrated:** 
- Linux log analysis
- Bash scripting
- File inspection utilities
- Incident response triage
- Control flow
- User input handling

---

### **3. Nmap Scan (Bash)**
This program automates a multi-stage reconnaissance scan against a target domain using **Nmap**, one of the most widely used tools in cybersecurity. The script performs host discovery, ARP probing, top-port scanning, service and OS detection, and basic NSE enumerations. All results are savd to single output file, providing a consolidated snapshot of the target's network exposure.

**Concepts demonstrated:** 
- Nmap scanning
- Host discovery
- ARP probing
- Service and OS detection
- NSE scripting
- Network reconnaissance
- Security automation

---

### **4. NS Lookup (Bash)**
The script performs a basic DNS reconnaissance step using the **nslookup** utility. By querying a target domain and saving the results to a text file, the program provides a quick insight into DNS records such as IP addresses, authoritative name servers, and other publicly exposed information. 

**Concepts demonstrated:** 
- DNS lookups
- OSINT
- Bash scripting
- DNS record analysis
- Reconnaissance techniques

### **5. WHOIS Lookup (Bash)**
The script performs a **WHOIS lookup** on a target domain to gather publicly available regsitration and ownership information. WHOIS data often includes details such as registrars, administrative contacts, creation/expiration dates, and name-server information.

**Concepts demonstrated:** 
- WHOIS lookups
- DNS and domain intelligence
- OSINT
- Bash Scripting
- Reconnaissance techniques
---

## Skills Demonstrated
Across these programs, I practiced and strengthened:

- **OSINT Reconnaissance**: gathering publicly exposed information using Google Dorking, WHOIS, NSLOOKUP, and Nmap discovery scans
- **Bash Scripting**: automating reconnaissance  tasks, building menus, handling user input, and chaining Linux utilities
- **Network Scanning:** performing host discovery, ARP probing, top-port scanning, service detection, and NSE enumeration with Nmap
- **DNS and Domain Analysis:** inspecting DNS records, name servers, and domain metadata using NSLOOKUP and WHOIS
- **Linux Log Analysis:** using cat, less, head, and tail to triage files and extract meaningful information
- **Security Automation:** creating repeatable workflows that consolidate reconnaissance results into structured output files 
- **Reconnaisance Methodology:** applying early-phase penetration testing techniques to map assets, identify exposures, and enumerate services
---

## How to Run the Programs
Each program is self‑contained. To run one:

1. Open the file in your preferred IDE or compiler  
2. Compile (if required)  
3. Run the program and follow the on‑screen prompts  

---

## Notes
These projects represent my transition from basic scripting to structured, multistage cybersecurity tooling
They demonstrate my ability to automate reconnaissance workflows, integrate multiple Linux utilities, and apply real-world security methodologies across Bash-based tools. Through OSINT collection, DNS enumeration, log triage, and netwrok scanning, I show practical competence in building tolls that support early-phase scurity analyssis and map exteranl attack surfaces. 