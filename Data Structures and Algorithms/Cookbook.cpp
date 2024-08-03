/*
    Simple program that demonstrates the use of header files
    User gets recommended recipes based on the time of the day 
*/

/*
    Outline on how to the program works 

    User is asked to enter the time of the day
    User is then given a recipe based on the time of the day

    Author: Eddy Koundjou Yem 
    Date: 08/03/2024
*/

#include <iostream>
#include "Cookbook.h"
using namespace std;


int main() {
    int time; // time of the day
    cout << "Enter the time of the day in 24 hour format: ";
    cin >> time;
    getRecipe(time);
}
