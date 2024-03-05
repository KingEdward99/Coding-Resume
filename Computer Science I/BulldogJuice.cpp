//This project is a juice store that sells juice to customers
// Name: eddy Koundjou Yem
// 
#include <iostream>
using namespace std; 
//functions we need
void collectOrder(); 

void menu(); 

int main (){
    //menu items
    return 0; 
}

void menu(){
    int orangeJuice, appleJuice, orppleJuice, water;
    double waterPrice = 1.00; 
    double orangeJuicePrice, appleJuicePrice = 2.00; 

}

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

void collectOrder() {
    cout << "What would you like to order today?" << endl;
}