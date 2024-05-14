//A program that can calculate the federal tax for a single person based on their income. C++ pg 502 
/*
  Write a program that can be used to calculate the federal tax. The tax is calculated as follows: For single people, the standard exemption is $4,000; for married people, the standard exemption is $7,000. A person can also put up to 6% of his or her gross income in a pension plan. The tax rates are as follows: If the taxable income is:
• Between $0 and $15,000, the tax rate is 15%.
• Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable
income over $15,000.
• Over $40,000, the tax is $8,460 plus 35% of the taxable income over
$40,000.
Prompt the user to enter the following information:
• Marital status
• If the marital status is ‘‘married,’’ ask for the number of children under
the age of 14
• Gross salary (If the marital status is ‘‘married’’ and both spouses have income, enter the combined salary.)
• Percentage of gross income contributed to a pension fund
Your program must consist of at least the following functions:
a. Function getData: This function asks the user to enter the relevant data.
b. Function taxAmount: This function computes and returns the tax owed.
To calculate the taxable income, subtract the sum of the standard exemption, the amount contributed to a pension plan, and the personal exemption, which is $1,500 per person. (Note that if a married couple has two children under the age of 14, then the personal exemption is $1,500 * 4 = $6,000.)
*/
#include <iostream>
using namespace std;

class FederalTax {
  public:
    void getData(); // Getting basic info from the user
    void taxAmount(); // Calculating the tax amount
    double taxableIncome(); // The taxable income of the user
};

int main() {

  FederalTax userAccount; // Creating an object of the FederalTax class

  userAccount.getData(); // Getting the data from the user

  return 0;   
}

void FederalTax::getData() {
   double incomeFirstSpouse = 0;
   double incomeSecondSpouse = 0;
   double marriedIncome = 0; 
   int pensionPercentage = 0;  
   int maritalStatus = 0; 
   int childrenUnder14 = 0;  
   int personalExemptionMultiplier = 0; 
   int standardExemption = 0;
  
  //Determing marital status
   cout << "What is your marital status? (1 for single, 2 for married): " << endl;
   cin >> maritalStatus;

   cout << "How many children under 14 do you have? " << endl;
   cin >> childrenUnder14;

   if (maritalStatus == 2) { //If the user is married
    cout << "What is the income of the first spouse? " << endl;
    cin >> incomeFirstSpouse;

    cout << "What is the income of the second spouse? " << endl;
    cin >> incomeSecondSpouse;

    double marriedIncome = incomeFirstSpouse + incomeSecondSpouse; //Calculating the combined income of the married couple
    personalExemptionMultiplier = 2 + childrenUnder14; //Calculating the personal exemption based on the number of children
    int standardExemption = 7000;
   }
   else { //If the user is single
    cout << "What is your income? " << endl;
    cin >> incomeFirstSpouse;
    personalExemptionMultiplier = 1 + childrenUnder14; //Calculating the personal exemption based on the number of children
    int standardExemption = 4000;
   }
  
   //Determinng how much the user wants to contribute to their pension fund
    cout << "How much of your gross income would you like to contribute to your pension fund? Remember that you can only contirbute up to 6%." << endl;
    cin >> pensionPercentage;

    double actualPensionFund = pensionPercentage/100; //Converting the percentage to a decimal

   cout << "The combined salary is: " << marriedIncome << endl;
   cout << "The number of children are " << childrenUnder14 << endl;
   cout << "The standard exemption is: " << standardExemption << endl;


}

void FederalTax::taxAmount() {
  //Tax rates 
 double taxRate = 0;
 int taxableIncome = 0;
 int tax = 0;

 cout << "What is your taxable income? " << endl;
 cin >> taxableIncome;

 if(taxableIncome < 15000) {
   taxRate = 0.15;
 }
 else if(taxableIncome > 15000 && taxableIncome < 40000) {
   taxRate = 0.25;
   tax = 2250 + (taxableIncome - 15000) * taxRate;
 }
 else {
   taxRate = 0.35;
   tax = 8460 + (taxableIncome - 40000) * taxRate;
 }


  
}

double FederalTax::taxableIncome() {
  double taxableIncome=0;

}