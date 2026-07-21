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
            this->next = nullptr;
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

};
