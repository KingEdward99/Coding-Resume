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
        int employeePassword;
        int employeeID;
        map <int, int> employeeAccount;

        void setPassword();
        void verifyUser();
};

int main() {
    Employee engineer1;
    engineer1.firstName = "Elijah";
    engineer1.lastName = "McCoy";
    engineer1.employeeID = 0001;
    engineer1.employeePassword = 3290;

    engineer1.verifyUser();
}

void Employee::setPassword() {
    cout << "Please enter your 4 digit pin: " << endl;
    cin >> employeePassword; 
}

void Employee::verifyUser() {
    int enteredID = 0;
    int enteredPassword = 0; 

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