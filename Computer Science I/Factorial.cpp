/*
    Name: Eddy Koundjou Yem

    This project finds the factorial of any integer number

*/
#include <iostream>
using namespace std; 

//functions needed
int factorialCalculate(int userNumber); // calculates the factorial 

int main()
{
    int userNumber = 0; 
    cout << " Enter a number and I will calculate its factorial" << endl; 
    cin >> userNumber; 
    cout << "You entered " << userNumber << endl; 

    cout << "The factorial is " << factorialCalculate(userNumber) << endl; 
    
    return 0; 
}

//factorial algorithm 
int factorialCalculate(int userNumber)
{
    int factorialNumber = 1;
    if (userNumber == 0)
        return 1;
    else
        for(int i = 1; i <= userNumber; i++ )
        {
            factorialNumber  *= i; 
        };
    return factorialNumber; 
}