//This project is a juice store that sells juice to customers
// Name: Eddy Koundjou Yem
#include <iostream>
using namespace std; 

//Creating a class called BulldogJuice
class BulldogJuice {
 public:
    //items and prices
    double waterPrice = 1.00;
    double orppleJuicePrice, orangeJuicePrice, appleJuicePrice = 2.00;

    //functions
    void collectOrder(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water);
    void menu(); 
    double orderProcessing(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water, double& waterPrice, double& appleJuicePrice, double& orangeJuicePrice);
};

int main() {
    //Creating an object of the BulldogJuice class
    BulldogJuice JuiceStore; 

    //menu items and prices 
    int orangeJuice, appleJuice, orppleJuice, water; 
    double waterPrice = 1.00;
    double orppleJuicePrice, orangeJuicePrice, appleJuicePrice = 2.00;

    //calling the functions
    JuiceStore.menu(); 
    JuiceStore.collectOrder(orangeJuice, appleJuice, orppleJuice, water);
    JuiceStore.orderProcessing(orangeJuice, appleJuice, orppleJuice, water, waterPrice, appleJuicePrice, orangeJuicePrice);
    return 0; 
}

//Presenting the menu to the customer
void BulldogJuice::menu(){
    cout << "Welcome to the Bulldog Juice Store." << endl;
    cout << "The following is our menu." << endl; 
    cout << " Orange Juice: $2.00" << endl;
    cout << " Apple Juice: $2.00" << endl;
    cout << " Orpple Juice: $2.00" << endl;
    cout << " Water: $1.00" << endl; 
}

//Collecting the order from the customer
void BulldogJuice::collectOrder(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water) {
    //collecting the order from the customer
    cout << "What would you like to order today?" << endl;
    cout << "How much apple juice do you want? " << endl; 
    cin >> appleJuice;
    cout << "How much orange juice do you want?" << endl; 
    cin >> orangeJuice; 
    cout << "How much orpple juice do you want?" << endl;
    cin >> orppleJuice; 
    cout << "How much water do you want?" << endl;
    cin >> water; 
}

//Processing the customer's order
double BulldogJuice::orderProcessing(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water, double& waterPrice, double& appleJuicePrice, double& orangeJuicePrice){
    double tax = 0.06; 
    double totalCost = 0.00;

    double totalOrangeCost = orangeJuice *orangeJuicePrice;
    double totalAppleCost = appleJuice * appleJuicePrice; 
    double totalWaterCost = water * waterPrice; 

    long double cost = (totalOrangeCost+totalAppleCost+totalWaterCost);
    totalCost = cost + (0.06 * cost); 
    cout << "The total cost of your order is: $" << totalCost << endl;

    return totalCost; 
} 