/*
    This program allows the user to see what position they are in when they enter their information
    in the housing queue.
*/

#include <iostream>
using namespace std;

class Node {
    public:
        string name;
        Node* next;
        
        //Default constructor
        Node () {
            name = "";
            next = nullptr;
        };

        //Parameterized constructor
        Node (string name) {
            this->name = name;
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

        void insertStudentAtEnd(string name) {

            //Creating the new student / node
            Node* newStudent = new Node(name);

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
            Node* current = head;
            while(current != nullptr) {
                cout << current->name;
                if(current->next != nullptr) {
                    cout << " -> ";
                }

                current = current->next;
            }

        cout << endl;
    }
};

int main () {
    //Creating the waitlist object
    HousingWaitlist list;

    list.insertStudentAtEnd("Dasean");
    list.insertStudentAtEnd("Jeremy");

    list.printWaitList();

    return 0;
}
