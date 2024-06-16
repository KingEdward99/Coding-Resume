/*
  Name: Eddy Koundjou Yem

  Date: 07/16/2024

  Description: This program calculates the tax amount owed by a user based on their marital status, gross salary, pension percentage, and the number of children under 14. 
  The program first asks the user for their marital status, gross salary, pension percentage, and the number of children under 14. 
  The program then calculates the taxable income of the user based on their marital status, gross salary, pension percentage, and the number of children under 14.
  The program then calculates the tax amount owed by the user based on their taxable income. 
  The program then outputs the taxable income, pension amount, pension percentage, and the tax amount owed by the user.
*/
#include <iostream>
using namespace std;

class FederalTax {
  public:
    int maritalStatus;
    double grossSalary;
    double taxableIncome; 
    void getData(int &maritalStatus, double &grossSalary, double& taxableIncome, double &pensionPercentage, int &childrenUnder14); // Getting tax data from the user 
    double taxAmount(int &maritalStatus, double &grossSalary,double& taxableIncome, double &pensionPercentage, int &childrenUnder14); // Calculating the tax amount owed 
};

int main() {

  FederalTax userAccount; // Creating an object of the FederalTax class
  int maritalStatus = 0;
  double grossSalary = 0;
  double taxableIncome = 0;
  double pensionPercentage = 0;
  int childrenUnder14 = 0;
  userAccount.getData(maritalStatus,grossSalary, taxableIncome, pensionPercentage, childrenUnder14); // Getting the data from the user
  userAccount.taxAmount(maritalStatus, grossSalary, taxableIncome, pensionPercentage, childrenUnder14); // Getting the taxable income of the user

  return 0;   
}

void FederalTax::getData(int &maritalStatus, double &grossSalary, double &taxableIncome, double &pensionPercentage, int& childrenUnder14) {
  string maritalStatusString = "";
  double incomeFirstSpouse = 0;
  double incomeSecondSpouse = 0;

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

    grossSalary = incomeFirstSpouse + incomeSecondSpouse;
    cout << "Your Marital Status is " << maritalStatusString << endl; 
    cout << "Your combined salary is: " << grossSalary << endl;
    cout << "The number of children under 14 you have is " << childrenUnder14 << endl;
    cout << "The percentage of your salary you want to contribute to your pension fund is "<< pensionPercentage << "% " << endl;
 }
}

double FederalTax::taxAmount(int &maritalStatus, double &grossSalary, double &taxableIncome, double &pensionPercentage, int& childrenUnder14) {

  double taxOwed = 0;
  int standardExemption = 0; 
  double pensionAmount = grossSalary * (pensionPercentage/100);

  if (maritalStatus == 1) {
    standardExemption = 4000;
    double personalExemption = 1500;
    taxableIncome = grossSalary - (standardExemption + (personalExemption * (1+childrenUnder14)) + pensionAmount);
  }
  else if (maritalStatus == 2) {
    standardExemption = 7000;
    double personalExemption = 1500;
    taxableIncome = grossSalary - (standardExemption +  (personalExemption * (2+childrenUnder14)) + pensionAmount);
  }

  cout << "Your taxable income is: " << taxableIncome << endl;
  
  if (taxableIncome >= 0 && taxableIncome <= 15000) {
    taxOwed = taxableIncome * 0.15;
  }
  else if (taxableIncome >= 15001 && taxableIncome <= 40000) {
    taxOwed = 2250 + (0.25 * (taxableIncome - 15000));
  }
  else if (taxableIncome > 40000) {
    taxOwed = 8460 + (0.35 * (taxableIncome - 40000));
  }

  cout << "The tax owed is: "  << taxOwed << endl;
  return taxOwed;
}