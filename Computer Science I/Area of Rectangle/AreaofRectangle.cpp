/*
Name: Eddy Koundjou Yem 
Program Description: This program calculates the area of a rectangle
Date: April 15, 2024
*/

#include <iostream>
using namespace std;

int main()

{  
    //Declaring variables
    int length = 0;
    int width = 0;

    //Prompting user for the variables
    cout << "Enter the length" << endl;
    cin >> length;
    cout << "Enter the width" << endl;
    cin >> width;

    
    //area of a rectangle 
    int area = length * width; 
 
    cout << "The area is: " << area << endl; 
}