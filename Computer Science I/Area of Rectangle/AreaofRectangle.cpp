/*
Name: Eddy Koundjou Yem 
Program Description: This program calculates the perimter and the area of a rectangle
Date: April 15, 2024
*/

#include <iostream>
using namespace std;

int main()

{  
    int length = 0;
    int width = 0;

    cout << "Enter the length" << endl;
    cin >> length;
    cout << "Enter the width" << endl;
    cin >> width;

    
    //perimeter of a rectangle 
    int perimeter = 2 * (length + width);

    int area = length * width; 

    cout << "The perimeter is: " << perimeter << endl; 
    cout << "The area is: " << area << endl; 
}