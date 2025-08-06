//This project is a juice store that sells juice to customers
// Name: Eddy Koundjou Yem
#include <iostream>
#include <iomanip> 
using namespace std; 

//Creating a class called BulldogJuice
class BulldogJuice {
 public:
    //items and prices
    double waterPrice = 1.00;
    double orppleJuicePrice = 2.00;
    double orangeJuicePrice = 2.00;
    double appleJuicePrice = 2.00;

    //functions
    void menu(); 
    void collectOrder(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water);
    double orderProcessing(int orangeJuice, int appleJuice, int orppleJuice, int water, double waterPrice, double appleJuicePrice, double orangeJuicePrice);
    void customerPaying(double& totalCost);
};

int main() {
    //Creating an object of the BulldogJuice class
    BulldogJuice JuiceStore; 

    //menu items and prices 
    int orangeJuice = 0;
    int appleJuice = 0;
    int orppleJuice = 0;
    int water = 0; 
    double waterPrice = 1.00;
    double appleJuicePrice = 2.00;
    double orangeJuicePrice = 2.00;
    
    //calling the functions
    JuiceStore.menu(); 
    JuiceStore.collectOrder(orangeJuice, appleJuice, orppleJuice, water);

    double totalCost = JuiceStore.orderProcessing(orangeJuice, appleJuice, orppleJuice, water, waterPrice, appleJuicePrice, orangeJuicePrice);
    JuiceStore.customerPaying(totalCost); 
    return 0; 
}

//Presenting the menu to the customer
void BulldogJuice::menu(){
    cout << "Welcome to the Bulldog Juice Store." << endl;
    cout << "Here's our menu:" << endl; 
    cout << " Orange Juice: $" << fixed << setprecision(2) << orangeJuicePrice << endl;
    cout << " Apple Juice: $" <<  appleJuicePrice << endl;
    cout << " Orpple Juice: $" << orppleJuicePrice << endl;
    cout << " Water: $" << waterPrice << endl << endl; 
}

//Collecting the order from the customer
void BulldogJuice::collectOrder(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water) {
    //collecting the order from the customer
    cout << "Please enter the quantity for each item: " << endl;
    cout << "Apple Juice:  " << endl; 
    cin >> appleJuice;
    cout << "Orange Juice: " << endl; 
    cin >> orangeJuice; 
    cout << "Orpple Juice: " << endl;
    cin >> orppleJuice; 
    cout << "Water: " << endl;
    cin >> water; 
}

//Processing the customer's order
double BulldogJuice::orderProcessing(int orangeJuice, int appleJuice, int orppleJuice, int water, double waterPrice, 
double appleJuicePrice, double orangeJuicePrice){
    double tax = 0.06; 

    double totalOrangeCost = orangeJuice *orangeJuicePrice;
    double totalAppleCost = appleJuice * appleJuicePrice; 
    double totalWaterCost = water * waterPrice; 

    long double cost = (totalOrangeCost+totalAppleCost+totalWaterCost);
    double totalCost = cost + (0.06 * cost); 
    cout << "The total cost of your order is: $" << totalCost << endl;

    return totalCost; 
} 

void BulldogJuice::customerPaying(double& totalCost) {
    double payment = 0.0;

    while (true) {
        cout << "Enter payment amount: $";
        cin  >> payment;

        if (payment >= totalCost) {
            double change = payment - totalCost;
            cout << fixed << setprecision(2);
            if (change > 0.005)
                cout << "Your change is: $" << change << "\n";
            else
                cout << "Exact payment received. Thank you!\n";
            break;
        }

        cout << fixed << setprecision(2);
        cout << "Insufficient payment. You still owe $"
             << (totalCost - payment) << ".\n";

        cout << "Options:\n"
             << "  1) Add more to current payment\n"
             << "  2) Re-enter a completely new payment amount\n"
             << "Select 1 or 2: ";
        int choice;
        cin  >> choice;

        if (choice == 1) {
            double more = 0.0;
            cout << "Enter additional amount: $";
            cin  >> more;
            payment += more;
            // loop continues to check if payment >= totalCost
        }
        else if (choice == 2) {
            // restart the loop to enter fresh payment
            continue;
        }
        else {
            cout << "Invalid option. Let's try entering your payment again.\n";
        }
    }
}