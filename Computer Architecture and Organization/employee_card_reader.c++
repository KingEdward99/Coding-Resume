/*
    This program simulates a keypad verification system.
    Employees enter their pin and the database verifies if they are an employee or not
    Employees can be entered into the database
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Employee {
    //variables for the program
    public:
        string firstName;
        string lastName;
        string employeePassword;
        string employeeID;
        static map <string, Employee> employeeDatabase; //using hashmaps for rapid search within the system

        //Default constructor
        Employee() : firstName(""), lastName(""), employeeID(""), employeePassword("") {}

        //Constructor
        Employee(string fName, string lName, string ID, string Password)
        : firstName(fName), lastName(lName), employeeID(ID), employeePassword(Password) {}

        //methods
        void setPassword();
        void verifyUser();
        void createUser();
        void menu();
};

//Initializing the employee database
map <string, Employee> Employee::employeeDatabase;

int main() {
    Employee temp("John", "Doe", "0001", "1000");
    temp.menu();
    return 0;

}

void Employee::menu() {
    int userOption = 0;
    
    while (true){
        cout << "Welcome to employee account management system. " << endl;
        cout << "To create your account, press 1. " << endl;
        cout << "Press 2 to exit. " << endl;
        cin >> userOption;

        if (userOption == 1) {
            createUser();
        }
        else if (userOption == 2) {
            cout << "Exiting the program..." << endl;
            exit(0); 
        }
        else {
            cout << "Invalid input!" << endl; 
        }

    }
}

void Employee::verifyUser() {
    string enteredID, enteredPassword;

    cout << "Please enter your 4 digit employee ID " << endl;
    cin >> enteredID;
    
    cout << "Please enter your 4 digit employee password" << endl;
    cin >> enteredPassword;

    if(employeeDatabase.count(enteredID) == 0) {
        cout << "User not found." << endl;
        return;
    }

    cout << "Access Granted " << endl;
}

void Employee::createUser() {
   string tempfirst, tempLast, tempID, tempPin;

   cout << "You are at the create user section " << endl;

   cout << "Enter your first name: " << endl;
   cin >> tempfirst;

   cout << "Enter your last name: " << endl;
   cin >> tempLast;
   
   cout << "Enter a 4 digit userID " << endl;
   tempID = "";
   while(tempID.length() != 4) {
    cin >> tempID;
   }
   
   cout << "Enter a 4 digit PIN" << endl;
   tempPin = "";
   while(tempPin.length() != 4) {
    cin >> tempPin;
   }
   
   Employee newAccount(tempfirst, tempLast, tempID, tempPin);
   Employee::employeeDatabase[tempID] = newAccount; 

}

//The Cache Layer which simulates the M1-SRAM

struct CacheLine {
    Employee profile;

    int lastAccessTime; // timestamp for LRU

};

class CacheController {
    private:
        vector <CacheLine> sramCache; //M1 Cache that holds 3 employees information
        const size_t CACHE_MAX_SIZE = 3;
        int systemClock = 0;
    
    public:
        //Implementation of the LRU which checks the cache first, then the employee database
        bool verifyUser(string inputID, string inputPIN) {
            systemClock++;

            cout << "\n [DOOR] User " << inputID << "swiped at keypad." << endl;

            for(int i = 0; i < sramCache.size(); i++) {
                if (sramCache[i].profile.employeeID == inputID  && sramCache[i].profile.employeePassword == inputPIN) {
                    cout << "[CACHE HIT] User found in SRAM cache." << endl;
                    sramCache[i].lastAccessTime = systemClock;
                    return true;
                }
            }

        }
};