/*
    This is a milk economic program. It prompts the user for how much milk they produced and based on that information, 
    it calculates the amount of milk cartons you need
    it calculates the cost of producing milk
    it calculates the profit of the milk

    A milk caton holds 3.78 liters (L)
    The cost of producing one liter of milk is $0.38
    The profit of each carton of milk is $0.27
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    //Variables for the program
    double milk_carton = 3.78; // how many liters a carton can hold
    double produce_milk_cost = 0.38; // cost of producing milk 
    double amount_milk_produced; // how much milk was produced
    int milk_cartons_needed; // how many cartons you need based on the milk produced
    double milk_cartons_needed_cost; // cost of the cartons you need
    double carton_milk_profit = 0.27; // the profit of the milk carton
    double milk_profit; // the total profit of the milk 

    //Prompting the user to enter the amount of milk you produced
    cout << "Enter the amount of milk that was produced this morning: ";
    cin >> amount_milk_produced;

    //Calculation section
    milk_cartons_needed = ceil(amount_milk_produced / milk_carton);
    milk_cartons_needed_cost = produce_milk_cost * amount_milk_produced;
    milk_profit =  milk_cartons_needed * carton_milk_profit;

    //Outputting the results 
    cout << "The amount of milk cartons you need are: " << milk_cartons_needed << " carton(s)." << endl;
    cout << "The cost of producing this amount of milk is: $" << milk_cartons_needed_cost << endl;
    cout << "The profit is: $" << milk_profit << endl; 
}