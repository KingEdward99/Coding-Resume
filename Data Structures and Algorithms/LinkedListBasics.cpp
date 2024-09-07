/*
    This program goes through basic linked list commands such as:
    - Inserting a node at the beginning of the list
    - Inserting a node at the end of the list
    - Deleting a node from the beginning of the list
    - Deleting a node from the end of the list
    - Displaying the list
*/

using namespace std;
#include <iostream>
class Nodetype {
    public: 
        int data;
        Nodetype* next;

        Nodetype(int val) {
            data = val;
            next = nullptr;
        }
};

class LinkedListBasics { 
    private:
        Nodetype* head;
    
    public:
        LinkedListBasics () {
            head = nullptr;
        }
    // function to create a linked list by adding nodes
    void insert(int val)
    {
        Nodetype* newNode = new Nodetype(val);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Nodetype* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // function to print the linked list
    void print() {
        Nodetype* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListBasics list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.print();
    return 0;
}
