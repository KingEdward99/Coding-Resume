//This project creates an array and finds the largest number 

/*
1. Create an empty array of 5
2. Ask user for input
3. Find the largest numbe r
4. Print array and its largest number
*/
#include <iostream> 
using namespace std; 

int main()
{   
    int size;; 
    int listOfNumbers[size]; 

    //Asking for the size
    cout << "How big is the array " << endl; 

    //Asking for the user input
    cout << "Enter 5 numbers and I will find the largest number" << endl;

    for(int i = 0; i < size; i++)
    {
        cin >> listOfNumbers[i];
    }

    //Printing the list
    cout << "The numbers are : ";
    for(int i = 0; i < size; i++)
    {
        cout << listOfNumbers[i] << " ";
    }

    //Calculating the largest number 
    int largest;
    for(int i=0; i < size; i++)
    {
        if(listOfNumbers[i] > largest)
        {
            largest = listOfNumbers[i];
        }
    }

    cout << endl << "The largest is " << largest; 
    
    return 0; 
}