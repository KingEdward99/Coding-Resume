/*
    This program allows the user to see what position they are in when they enter their information
    in the housing queue. This program uses linked listss
*/

#include <iostream>
using namespace std;

//Creating a node class for the linked list
class Node {
    //information that the nodes will hold
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

//Class that holds the function of creating the housing waitlist
class HousingWaitlist {
    private:
        Node* head; //pointer to the first student
    
    public:
        //Constructor when the waitlist is created; it is empty for now
        HousingWaitlist() {
            head = nullptr;
        }

        //Inserting the students at the end of the waitlist
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
    //Introduces the options to the user
    void menu() {
        int userChoice;
        cout << "Welcome to the Haley Student Housing Waitlist." << endl;
        cout << "If you want to view the current waitlist, press 1." << endl;
        cout << "If you want to enter your name into the waitlist, press 2." << endl;

        //User select what choice they want 
        cin >> userChoice;

        //User displays the queue
        if(userChoice == 1) {
            printWaitList();
        }
        //User enters their name and sees their position in the queue 
        else if (userChoice == 2) {
            enterWaitlist();
        }
    }

    //Process of the user entering their information in the queue
    string enterWaitlist () {
        string firstName, lastName, email;
        int studentID, phoneNumber; 
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

        //After the student enters their information in the queue, it displays their information 
        insertStudentAtEnd(firstName, lastName, email, studentID, phoneNumber);
        printWaitList();
        
        return firstName;
    }

};

int main () {
    //Creating the waitlist object
    HousingWaitlist list;

    //Inserting students in the list and this is our default waitlist
    list.insertStudentAtEnd("Wendell", "Russell", "wendellrussell@gmail.com", 1976, 2024046719);
    list.insertStudentAtEnd("Cleveland", "Dennard", "clevelanddennard@gmail.com", 1977, 2024047791);
    list.insertStudentAtEnd("Lisle", "Carter", "lislecarter@gmail.com",1982,2024042891);

    //Running the program
    list.menu();

    return 0;
}
