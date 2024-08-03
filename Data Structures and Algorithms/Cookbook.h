// Purpose: Header file for Cookbook.cpp
/*
    Author: Eddy Koundjou Yem
    Date: 08/03/2024
*/
#include "iostream"
using namespace std;

//Function to get recipe based on the time of the day
void getRecipe(int time) {
    string breakfast = "Pancakes";
    string lunch = "Sandwich";
    string dinner = "Spaghetti";
    if (time >= 0 && time < 12) {
        cout << "You should have " << breakfast << " for breakfast" << endl;
    } else if (time >= 12 && time < 18) {
        cout << "You should have " << lunch << " for lunch" << endl;
    } else {
        cout << "You should have " << dinner << " for dinner" << endl;
    }
}