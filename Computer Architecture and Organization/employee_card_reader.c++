/*
    This program simulates a keypad verification system.
    Employees enter their pin and the database verifies if they are an employee or not
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Employee {
    public:
        string firstName;
        string lastName;
        string employeePassword;
        string employeeID;
        static map <string, Employee> employeeDatabase;

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

map <string, Employee> Employee::employeeDatabase;

int main() {
    Employee temp("John", "Doe", "0001", "1000");
    temp.menu();
    return 0;

    /*
    engineer1.firstName = "Elijah";
    engineer1.lastName = "McCoy";
    engineer1.employeeID = 0001;
    engineer1.employeePassword = 3290;

    engineer1.verifyUser();
    */

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

void Employee::setPassword() {
    cout << "Please enter your 4 digit pin: " << endl;
    cin >> employeePassword; 
}

void Employee::verifyUser() {
    string enteredID = 0;
    string enteredPassword = 0; 

    cout << "Please enter your 4 digit employee ID " << endl;
    cin >> enteredID;
    
    cout << "Please enter your 4 digit employee password" << endl;
    cin >> enteredPassword;

    while (enteredID != employeeID || enteredPassword != employeePassword) {
        cout << "The credentials you entered are wrong " << endl;

        cout << "Enter your 4 digit employee ID. " << endl;
        cin >> enteredID;

        cout << "Enter your 4 digit pin." << endl; 
        cin >> enteredPassword;
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