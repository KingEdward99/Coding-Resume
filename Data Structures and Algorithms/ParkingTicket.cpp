/* 
    This program allows the police to write down parking tickets for cars that are parked illegally.
    The program will ask the user to input the date of the ticket, the time of the ticket,
    the license plate of the number, and this program will generate a ticket number.

    This program will use hash tables to store the ticket information.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// Structure to store ticket information
struct Ticket {
    string date;
    string time;
    string licensePlate;
};

// Global hash table to store tickets (ticket number → Ticket struct)
unordered_map<int, Ticket> ticketDatabase;
int ticketCounter = 1000;  // Starting ticket number

// Function to generate a new ticket number
int generateTicketNumber() {
    return ticketCounter++;
}

// Function to add a ticket
void issueTicket() {
    string date, time, licensePlate;

    cout << "\n--- Issue a New Parking Ticket ---\n";
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;

    cout << "Enter Time (HH:MM): ";
    cin >> time;

    cout << "Enter License Plate Number: ";
    cin >> licensePlate;

    int ticketNumber = generateTicketNumber();

    Ticket newTicket = {date, time, licensePlate};
    ticketDatabase[ticketNumber] = newTicket;

    cout << "\nTicket Issued Successfully!\n";
    cout << "Ticket Number: " << ticketNumber << "\n";
}

// Function to display all issued tickets
void showAllTickets() {
    cout << "\n--- All Issued Tickets ---\n";
    if (ticketDatabase.empty()) {
        cout << "No tickets have been issued yet.\n";
        return;
    }

    for (const auto& pair : ticketDatabase) {
        cout << "Ticket #" << pair.first
             << " | Date: " << pair.second.date
             << " | Time: " << pair.second.time
             << " | License Plate: " << pair.second.licensePlate << "\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n=== Parking Ticket System ===\n";
        cout << "1. Issue a Parking Ticket\n";
        cout << "2. Show All Tickets\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                issueTicket();
                break;
            case 2:
                showAllTickets();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}