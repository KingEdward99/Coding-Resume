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
#include <string>
using namespace std;

/*
Scratch work

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;

    protected:
    int count; // store the number of nodes in the list
    nodeType<Type> *first; // pointer to the first node of the list
    nodeType<Type> *last; // pointer to the last node of the list
};

class linkedListIterator {
    linkedListIterator();
    //default constructor
    //Postcondition: current = NULL;

    linkedListIterator(nodeType<Type> *ptr);
    //constructor with a parameter
    //Postcondition: current = ptr;

    Type operator*();
    //Function to overload the dereferencing operator *
    //Postcondition: Returns the info contained in the node

    linkedListIterator<Type> operator++();
    //Overload the pre-increment operator
    //Postcondition: The iterator is advanced to the next node

    bool operator==(const linkedListIterator<Type>& right) const;
    //Overload the equality operator
    //Postcondition: Returns true if this iterator is equal to the iterator specified by right, otherwise it returns false

    bool operator!=(const linkedListIterator<Type>& right) const;
    //Overload the not equal to operator
    //Postcondition: Returns true if this iterator is not equal to the iterator specified by right, otherwise it returns false

    private:
    nodeType<Type> *current; //pointer to point to the current node in the linked list


    //Function Definitions
    template <class Type>
    linkedListIterator<Type>::linkedListIterator() {
        current = NULL;
    }

    template <class Type>
    linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) {
        current = ptr;
    }

    template <class Type>
    Type linkedListIterator<Type>::operator*() {
        return current->info;
    }

    template <class Type>
    linkedListIterator<Type> linkedListIterator<Type>::operator++() {
        current = current->link;
        return *this;
    }

    template <class Type>
    bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const {
        return (current == right.current);
    }

    template <class Type>
    bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const {
        return (current != right.current);
    }

    //basic properties of the linked list
    template <class Type>
    class linkedListType {
        public:
        const linkedListType<Type>& operator=(const linkedListType<Type>&);
        //Overload the assignment operator
        void initializeList();
        //Initialize the list to an empty state
        //Postcondition: first = NULL, last = NULL, count = 0;
        bool isEmptyList() const;
        //Function to determine whether the list is empty
        //Postcondition: Returns true if the list is empty, otherwise it returns false
        void print() const;
        //Function to output the data contained in each node
        //Postcondition: none
        int length() const;
        //Function to return the number of nodes in the list
        //Postcondition: The value of count is returned
        void destroyList();
        //Function to delete all the nodes from the list
        //Postcondition: first = NULL, last = NULL, count = 0;
        Type front() const;
        //Function to return the first element of the list
        //Precondition: The list must exist and must not be empty
        //Postcondition: If the list is empty, the program terminates; otherwise, the first element of the list is returned
        Type back() const;
        //Function to return the last element of the list
        //Precondition: The list must exist and must not be empty
        //Postcondition: If the list is empty, the program terminates; otherwise, the last element of the list is returned
        virtual bool search(const Type& searchItem) const = 0;
        //Function to determine whether searchItem is in the list
        //Postcondition: Returns true if searchItem is in the list, otherwise it returns false
        virtual void insertFirst(const Type& newItem) = 0;
        //Function to insert newItem at the beginning of the list
        //Postcondition: first points to the new list, newItem is inserted at the beginning of the list, last points to the last node in the list, and count is incremented by 1
        virtual void insertLast(const Type& newItem) = 0;
        //Function to insert newItem at the end of the list
        //Postcondition: first points to the new list, newItem is inserted at the end of the list, last points to the last node in the list, and count is incremented by 1
        virtual void deleteNode(const Type& deleteItem) = 0;
        //Function to delete deleteItem from the list
        //Postcondition: If found, the node containing deleteItem is deleted from the list; first points to the first node of the new list, last points to the last node of the new list, and count is decremented by 1
        linkedListIterator<Type> begin();
        //Function to return an iterator at the begining of the linked list
        //Postcondition: Returns an iterator such that current is set to first
        linkedListIterator<Type> end();
        //Function to return an iterator one element past the last element of the linked list
        //Postcondition: Returns an iterator such that current is set to NULL
        linkedListType();
        //default constructor
        //Initializes the list to an empty state
        //Postcondition: first = NULL, last = NULL, count = 0;
        linkedListType(const linkedListType<Type>& otherList);
        //copy constructor
        ~linkedListType();
        //destructor
        //Deletes all the nodes from the list
        //Postcondition: The list object is destroyed
        protected:
        int count; // store the number of nodes in the list
        nodeType<Type> *first; // pointer to the first node of the list
        nodeType<Type> *last; // pointer to the last node of the list
        private:
        void copyList(const linkedListType<Type>& otherList);
        //Function to make a copy of otherList
        //Postcondition: A copy of otherList is created and assigned to this list
        };

        //Function Definitions
        template <class Type>
        bool linkedListType<Type>::isEmptyList() const {
            return (first == NULL);
        }

        
    }
}

280 - 353
280 - 290

*/

//Functions for our program
class nodeType {
    public: 
        string info; // store the first name
        nodeType *link; // pointer to the next node

};     

class StudentRecord {
    private:
        nodeType *first, *last; // pointers to the first and last nodes
    public:
        StudentRecord () {
            first = NULL;
            last = NULL;
        }
        void createRecords(string& name); //initialize the records
        void transversingRecords(); // transversing the records
        void addRecord(); // add a record
        void deleteRecord(); // delete a record
        void printRecords(); // print the records
        bool searchRecord(); // search for a record
};

int main () {

    StudentRecord Students; // create a student record object
    string name;
    int choice = 0;
    //Introducing different program options 
    cout << "Welcome to the Student Record Program" << endl;
    cout << "Please select an option from the following: " << endl;
    cout << "1. Add a student record" << endl;
    cout << "2. Delete a student record" << endl;
    cout << "3. Search for a student record" << endl;
    cout << "4. Print all student records" << endl;
    cout << "5. Exit the program" << endl;
    cin >> choice; // get the user's choice

    while (choice != 5) {
        if (choice == 1)
        {
            cout << "Enter the name of the student: " << endl;
            cout << "Enter 'done' when you are finished entering names" << endl;
            cin >> name;

            while(name != "done") {
                Students.createRecords(name);
                cin >> name;
            }

            cout << endl;
            cout << "The student names are: " << endl;
            Students.printRecords();
        }
        else if (choice == 2)
        {
            Students.deleteRecord();
        }
        else if (choice == 3)
        {
            Students.searchRecord();
        }
        else if (choice == 4)
        {
            Students.printRecords();
        }
        else if (choice == 5)
        {
            cout << "Exiting the program" << endl;
        }
    cout << "What else do you want to do ?" << endl;
    cin >> choice;
    }
    
}

void StudentRecord::createRecords(string& name) { 
    nodeType *current; // pointer to create a new node
    nodeType *trailCurrent; // pointer to trail the current node
    nodeType *newNode; // pointer to create a new node
    

    bool found; // boolean to check if the name is found

    newNode = new nodeType; // create a new node
    newNode -> info = name; // set the info of the new node
    newNode -> link = NULL; // set the link of the new node to NULL

    if(first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        current = first; 
        found = false; 

        while (current != NULL && !found) {
            if (current->info >= name) {
                found = true;
            } else {
                trailCurrent = current;
                current = current->link;
            }
        }
        
        if(current == first) {
            newNode->link = first;
            first = newNode;
        } 
        else {
            trailCurrent->link = newNode;
            newNode->link = current;
            if(current == NULL) {
                last = newNode;
            }
        }
    }
}

void StudentRecord::printRecords() {
    nodeType *current = first; // pointer to traverse the list
    while(current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl; 
}

void StudentRecord::transversingRecords() {
    nodeType *current; // pointer to traverse the list
    //current = head;  set current to point to the first node
    while (current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
}

void StudentRecord::deleteRecord() {
    nodeType *current, *trailCurrent, *first, *last; // pointers to delete a node
    bool found; 
    string name; 
    

    if (first == NULL) {
        cout << "Cannot delete from an empty list" << endl;
    }
    else 
    {
        current = first;
        found = false;

        while(current  != NULL && !found) {
            if (current->info == name) {
                found = true;
            } else {
                trailCurrent = current;
                current = current->link;
            }
        }
        if(current == NULL ) {
            cout << "The name to be deleted is not in the list" << endl;
        }
        else if (current -> info == name) {
            if (first == current) {
                first = first->link;
                if (first == NULL) {
                    last = NULL;
                }
                delete current;
            } else {
                trailCurrent->link = current->link;
                if (current == last) {
                    last = trailCurrent;
                }
                delete current;
            }
            
        }
        else {
                cout << "The name to be deleted is not in the list" << endl;
        }

    }
}

bool StudentRecord::searchRecord() {
    nodeType *current; // pointer to traverse the list
    nodeType *first, *last;
    bool found; 
    string name; 
    cout << "Enter the name you want to search for: " << endl;
    cin >> name;
    if (first == NULL) {
        cout << "Cannot search an empty list" << endl;
    }
    else 
    {
        current = first;
        found = false;

        while(current  != NULL && !found) {
            if (current->info == name) {
                found = true;
            } else {
                current = current->link;
            }
        }
        if (found) {
            cout << "The name is in the list" << endl;
        } else {
            cout << "The name is not in the list" << endl;
        }
    }
    return found;
}