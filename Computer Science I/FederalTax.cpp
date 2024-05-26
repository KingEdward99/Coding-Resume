//A program that can calculate the federal tax for a single person based on their income. C++ pg 502 
/*
  Write a program that can be used to calculate the federal tax. The tax is calculated as follows: For single people, the standard exemption is $4,000; for married people, the standard exemption is $7,000. 
  A person can also put up to 6% of his or her gross income in a pension plan. The tax rates are as follows: If the taxable income is:
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
    int maritalStatus;
    double grossSalary;
    double marriedIncome;
    double taxableIncome; 
    void getData(int &maritalStatus, double &grossSalary, double &marriedIncome, double& taxableIncome, double &pensionAmount); // Getting tax data from the user 
    double taxAmount(int &maritalStatus, double &grossSalary, double &marriedIncome, double& taxableIncome, double &pensionAmount); // Calculating the tax amount owed 
};

int main() {

  FederalTax userAccount; // Creating an object of the FederalTax class
  int maritalStatus = 0;
  double grossSalary = 0;
  double marriedIncome = 0;
  double taxableIncome = 0;
  double pensionAmount = 0;
  userAccount.getData(maritalStatus,grossSalary,marriedIncome, taxableIncome, pensionAmount); // Getting the data from the user
  userAccount.taxAmount(maritalStatus, grossSalary, marriedIncome, taxableIncome, pensionAmount); // Getting the taxable income of the user

  return 0;   
}

void FederalTax::getData(int &maritalStatus, double &grossSalary, double &marriedIncome, double &taxableIncome, double &pensionAmount) {
  string maritalStatusString = "";
  int childrenUnder14 = 0;
  double incomeFirstSpouse = 0;
  double incomeSecondSpouse = 0;
  double pensionPercentage = 0;
  double pensionAmount = pensionPercentage/100;

  //Getting the marital status of the user 
  cout << "What is your marital status? (1 for single, 2 for married): " << endl;
  cin >> maritalStatus; 

  //Calculating marital status, gross salary, children under 14, and pension percentage
  if (maritalStatus == 1) {
    maritalStatusString = "single";
    cout << "What is your gross salary? " << endl;
    cin >> grossSalary;
    cout << "How many children under 14 do you have? " << endl;
    cin >> childrenUnder14;
    cout << "What percentage of your salary would you like to contribute to your pension fund? " << endl;
    cin >> pensionPercentage;
    
    cout << "Your Marital Status is " << maritalStatusString << endl; 
    cout << "Your gross salary is " << grossSalary << endl;
    cout << "The number of children under 14 you have is " << childrenUnder14 << endl;
    cout << "The percentage of your salary you want to contribute to your pension fund is "<< pensionPercentage << "% " << endl;
    taxableIncome = grossSalary - (4000 + (1500 * childrenUnder14) + (pensionPercentage/100 * grossSalary));
  }
  else if (maritalStatus == 2) {
    maritalStatusString = "married";
    cout << "What is the income of the first spouse? " << endl;
    cin >> incomeFirstSpouse;

    cout << "What is the income of the second spouse? " << endl;
    cin >> incomeSecondSpouse;

    cout << "How many children under 14 do you have? " << endl;
    cin >> childrenUnder14;

    cout << "What percentage of your salary would you like to contribute to your pension fund? " << endl;
    cin >> pensionPercentage;

    marriedIncome = incomeFirstSpouse + incomeSecondSpouse;
    cout << "The combined salary is: " << marriedIncome << endl;

    cout << "Your Marital Status is " << maritalStatusString << endl; 
    cout << "Your combine salary is " << marriedIncome << endl;
    cout << "The number of children under 14 you have is " << childrenUnder14 << endl;
    cout << "The percentage of your salary you want to contribute to your pension fund is "<< pensionPercentage << "% " << endl;
    taxableIncome = marriedIncome;
 }
}

double FederalTax::taxAmount(int &maritalStatus, double &grossSalary, double &marriedIncome, double &pensionAmount, double &taxableIncome) {

  double taxOwed = 0;
  int standardExemption = 0; 
  cout << "The gross salary is: " << grossSalary << endl;
  cout << "The married income is: " << marriedIncome << endl;

  if (maritalStatus == 1) {
    standardExemption = 4000;
    double personalExemption = 1500;
    taxableIncome = (standardExemption + pensionAmount + 1500);
  }
  else if (maritalStatus == 2) {
    standardExemption = 7000;
    taxableIncome = marriedIncome;
  }
  cout << "The standard exemption is: " << standardExemption << endl;
  cout << "The taxable income is: " << taxableIncome << endl;
  
  if (taxableIncome >= 0 && taxableIncome <= 15000) {
    taxOwed = taxableIncome * 0.15;
  }
  else if (taxableIncome >= 15001 && taxableIncome <= 40000) {
    taxOwed = 2250 + ((taxableIncome - 15000) * 0.25);
  }
  else if (taxableIncome > 40000) {
    taxOwed = 8460 + ((taxableIncome - 40000) * 0.35);
  }

  cout << "The tax owed is: " << taxOwed << endl;
  
  return taxOwed;
}