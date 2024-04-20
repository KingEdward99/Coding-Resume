//A program that can calculate the federal tax for a single person based on their income.
#include <iostream>
using namespace std;

class FederalTax {
    void getData(); // Getting basic info from the user
    void taxAmount();
};

int main() {

  FederalTax userAccount; // Creating an object of the FederalTax class

  return 0;   
}

void FederalTax::getData() {
   double incomeFirstSpouse; 
   double incomeSecondSpouse;
   int pensionFund; 
   int maritalStatus;
   int childrenUnder14; 
}

void FederalTax::taxAmount() {
  //Tax rates 
  double lowIncomeTaxRate = 0.15;
  double midIncomeTaxRate = 0.25;
  double highIncomeTaxRate = 0.35;
}