/*
    This program allows the user to add, delete, show and search a student records

    Student recrods include the following information:
    - Student Name
    - Student ID
    - Student GPA
    - Student Major

    The program will use linked lists to store the student information
*/
#include <iostream>
using namespace std;

//Functions for our program
class nodeType {
    public:
        string info; // store the first name
        nodeType *link; // pointer to the next node
};

class StudentRecord {
    public:
        void createRecords(); //initialize the records
        void transversingRecords(); // transversing the records
        void addRecord(); // add a record
       void deleteRecord(); // delete a recor
       void printRecords(); // print the records
};

int main () {
    //Creating a Data Structures and Algorithms (DSA) object
    StudentRecord DSA;

    DSA.createRecords();


    //Creating a linked list
    nodeType *first, *last, *newNode; 
    int num; 

    //Declare the first and last pointers null
    first = NULL;
    last = NULL;

    //Reading and storing the numbers for our list 
    cin >> num;
    newNode = new nodeType;
    newNode->info = num;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        last->link = newNode;
        last = newNode;
    }
}

void StudentRecord::createRecords() { 
    cout << " Add the first name of the students to the record system " << endl;
    nodeType *first, *last, *newNode;
    string firstName;
    cin >> firstName ;
    first = NULL; 
    while(firstName !=  "Done") {
        newNode = new nodeType;
        newNode->info = firstName;
        newNode->link = NULL;
        if (first == NULL) {
            first = newNode;
            last = newNode;
        } else {
            last->link = newNode;
            last = newNode;
        }
        cin >> firstName;
    }
}

void StudentRecord::transversingRecords() {
    nodeType *current; // pointer to traverse the list
    //current = head;  set current to point to the first node
    while (current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
}

void addRecord() {
    nodeType *head, *current, *p, *q, *newNode;  // pointer to the first node
    string firstName; 
    current = head; 
    cout << "What name do you want to enter? " << endl;
    cin >> firstName;
    while(current != NULL) {
        current = current->link;
        newNode = new nodeType;
        newNode->info = firstName;
        newNode->link = p -> link;
        p -> link = newNode;
    }
}

void deleteRecord() {

}

