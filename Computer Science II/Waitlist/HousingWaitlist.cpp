/*
    This program allows the user to see what position they are in when they enter their information
    in the housing queue.
*/

#include <iostream>
using namespace std;

class Node {
    public:
        string firstName;
        string lastName;
        string email;
        int studentID;
        int phoneNumber;
        Node* next;
        
        //Default constructor
        Node () {
            firstName = "";
            lastName = "";
            email = "";
            studentID = 0;
            phoneNumber = 0; 
            next = nullptr;
        };

        //Parameterized constructor
        Node (string firstName, string lastName, string email, int studentID, int phoneNumber) {
            this->firstName = firstName;
            this->lastName = lastName;
            this->email = email;
            this->studentID = studentID;
            this->phoneNumber = phoneNumber;
            next = nullptr;
        }
};

class HousingWaitlist {
    private:
        Node* head; //pointer to the first student
    
    public:
        //Constructor when the waitlist is created; it is empty for now
        HousingWaitlist() {
            head = nullptr;
        }

        void insertStudentAtEnd(string firstName, string lastName, string email, int studentID, int phoneNumber) {

            //Creating the new student / node
            Node* newStudent = new Node(firstName,lastName,email,studentID,phoneNumber);

            //Checking to see if the linked list is empty
            if (head == nullptr) {
                head = newStudent;
                return;
            }

            //Store the head reference in a temporary variable
            Node* last = head;
            
            //Traverse until you reach the last node
            while(last->next != nullptr) {
                last = last->next;
            }

            //Change the next pointer of the last node to the next new node
            last->next = newStudent;
        }

        //Printing the linked list
        void printWaitList() {
            int position = 1;
            Node* current = head;
            while(current != nullptr) {
                cout << position++ << " ";
                cout << current->firstName;
                if(current->next != nullptr) {
                    cout << " -> ";
                }

                current = current->next;
            }

        cout << endl;
    }

    string menu () {
        string firstName, lastName, email;
        int studentID, phoneNumber; 
        cout << "Welcome to the Alex Haley Housing Waitlist." << endl;
        cout << "Please enter your first name, last name, email, student ID, phone number. " << endl;
        cout << " First Name: " << endl;
        cin >> firstName; 
        cout << " Last Name: " << endl; 
        cin >> lastName;
        cout << "Email: " << endl;
        cin >> email;
        cout << "Student ID: " << endl; 
        cin >> studentID;
        cout << "Phone Number: " << endl;
        cin >> phoneNumber;

        return firstName;
    }

};

int main () {
    //Creating the waitlist object
    HousingWaitlist list;

    //Inserting students in the list
    list.insertStudentAtEnd("Wendell", "Russell", "wendellrussell@gmail.com", 1976, 2024046719);
    list.insertStudentAtEnd("Cleveland", "Dennard", "clevelanddennard@gmail.com", 1977, 2024047791);
    list.insertStudentAtEnd("Lisle", "Carter", "lislecarter@gmail.com",1982,2024042891);

    list.menu();

    list.printWaitList();

    return 0;
}
