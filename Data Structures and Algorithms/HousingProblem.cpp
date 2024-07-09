//Creating a Housing Portal using queues
//Users can add their problems withing the hosuing portal and a fixer will remove the problem.

// Break down of low level how it works plus story board
/*
    1. User adds a problem to the housing portal
    2. The problem is added to the queue
    3. The fixer removes the problem from the queue
    4. The fixer fixes the problem
    5. The fixer removes the problem from the queue
*/

//Designing a Queue template class
#include <iostream>
using namespace std;
template <class Type>
class queueADT {
    public:
        virtual bool isEmptyQueue() const = 0;
        //Function to determine whether the queue is empty
        //Postcondition: Returns true if the queue is empty, otherwise returns false
        // otherwise returns false

        virtual bool isFullQueue() const = 0;
        //Function to determine whether the queue is full
        //Postcondition: Returns true if the queue is full, otherwise returns false
        // otherwise returns false

        virtual void initializeQueue() = 0;
        //Function to initialize the queue to an empty state
        //Postcondition: The queue is empty

        virtual Type front() const = 0;
        //Function to return the first element of the queue
        //Precondition: The queue exists and is not empty
        //Postcondition: If the queue is empty, the program terminates; otherwise, 
        //the first element of the queue is returned

        virtual Type back() const = 0;
        //Function to return the last element of the queue
        //Precondition: The queue exists and is not empty
        //Postcondition: If the queue is empty, the program terminates; otherwise,
        //the last element of the queue is returned

        virtual void addQueue(const Type& queueElement) = 0;
        //Function to add queueElement to the queue
        //Precondition: The queue exists and is not full
        //Postcondition: The queue is changed and queueElement is added to the queue

        virtual void deleteQueue() = 0;
        //Function to remove the first element of the queue
        //Precondition: The queue exists and is not empty
        //Postcondition: The queue is changed and the first element is removed from the queue


};

void customerProblem();

int main () {
    int userChoice;
    cout << "Welcome to the Housing Portal" << endl;
    cout << "If you are customer press 1, if you are a fixer press 2" << endl;
    cin >> userChoice;
    
    if(userChoice == 1) {
        customerProblem();
    }
    
    return 0;
}

void customerProblem() {
    int areaProblem; //This is the area of the problem (e.g. kitchen, bathroom, living room)
    string detailedProblem; //This is the detailed problem the customer is facing
    cout << "Please enter the area of the problem" << endl;
    cout << " 1. Kitchen\n 2. Bathroom\n 3. Bedroom\n 4. Living Room " << endl;
    cin >> areaProblem;

    cout << "What seems to be the problem?" << endl;
    cin >> detailedProblem;

    cout << "Thank You for your submission, a fixer will be with you shortly" << endl;

}