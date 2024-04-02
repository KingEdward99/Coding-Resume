//This project is a juice store that sells juice to customers
// Name: Eddy Koundjou Yem
// 
#include <iostream>
using namespace std; 

//functions we need
class BulldogJuice {

 public:
    void collectOrder(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water);
    void menu(); 
 private:
    double waterPrice = 1.00; 
    double orppleJuicePrice, orangeJuicePrice, appleJuicePrice = 2.00;
 //double calculatingPrice(int orangeJuice, int appleJuice, int orppleJuice, int water); 
};

int main() {
    //menu items
    BulldogJuice JuiceStore; 

    int orangeJuice, appleJuice, orppleJuice, water; 

    JuiceStore.menu(); 
    JuiceStore.collectOrder(orangeJuice, appleJuice, orppleJuice, water);
    return 0; 
}

void BulldogJuice::menu(){
    cout << "Welcome to the Bulldog Juice Store." << endl;
    cout << "The following is our menu." << endl; 
    cout << " Orange Juice: $2.00" << endl;
    cout << " Apple Juice: $2.00" << endl;
    cout << " Orpple Juice: $2.00" << endl;
    cout << " Water: $1.00" << endl; 
}

void BulldogJuice::collectOrder(int& orangeJuice, int& appleJuice, int& orppleJuice, int& water) {
    cout << "What would you like to order today?" << endl;
    cout << "How much water do you want?" << endl;
    cin >> water;
    cout << "How much apple juice do you want? " << endl; 
    cin >> appleJuice;
    cout << "How much orange juice do you want?" << endl; 
    cin >> orangeJuice; 
    cout << "How much orpple juice do you want?" << endl;
    cin >> orppleJuice; 
    cout << "How much water do you want?" << endl;
    cin >> water; 
}

/*
double orderProcessing(int orangeJuice, int appleJuice, int orppleJuice, int water, double waterPrice, double appleJuicePrice, double orangeJuicePrice){
    double tax = 0.06; 
    double totalCost = 0.00;

    double totalOrangeCost = orangeJuice *orangeJuicePrice;
    double totalAppleCost = appleJuice * appleJuicePrice; 
    double totalWaterCost = water * waterPrice; 

    double cost = (totalOrangeCost+totalAppleCost+totalWaterCost);
    totalCost = cost + (0.06 * cost); 

    return totalCost; 
} 
*/

/*
double calculatingPrice(int orangeJuice, int appleJuice, int orppleJuice, int water ){

return 1; 
};
*/
void Tester() {
    cout << "Testing"; 
}