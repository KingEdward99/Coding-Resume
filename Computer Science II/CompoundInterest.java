/*
 * 
 * Name: Eddy Koundjou Yem
 * Date: 09/15/2024
 * Last Updated: 09/25/2024
 * 
 * A program that calculates the balance of the user account after a specified number of years 
 * using the following equation: A = P(1 + (r/n))^(nt)
 * 
 * where A is the amount of money in the account after a specififed number of years 
 * P is the principal amount that was originlaly deposiited into the account 
 * r is the annual interest rate 
 * n is the number of times per year that the interest is compounded
 * t is the specified number of years
 * 
 * The methods we need: declaring the variables, input, interest calculator 
 */

 import java.util.Scanner; 
 class compoundInterestCalculator {
    //declaring necessary variables 
    double principalAmount; //How much the user is investing
    double annualInterestRate; // the annual interest rate 
    double actualInterestRate = annualInterestRate / 100; //converting it into a decimal for calcualtion purposes 
    int compoundInterest = 12; // Assuming the interest rate is applied monthly 
    int time; // the amount of years the investment will remain in the account 

    // Asking the user to input the necessary financial information 
    void compoundInterestInput() {
        Scanner input = new Scanner(System.in);

        System.out.println(" Enter your principal amount ");
        principalAmount = input.nextDouble();

        System.out.println("Enter the annual interest rate ");
        annualInterestRate = input.nextDouble(); 

        System.out.println("Enter the amount of year you will be leaving your money in ");
        time = input.nextInt(); 
        input.close();
    }
    //Calculating the final amount after the user-inputted information
    double finalMoneyCalculator() {
        return principalAmount*(1 + (Math.pow((actualInterestRate/compoundInterest),(actualInterestRate*time))));
    }
     
 }

class CompoundInterest {
    public static void main(String[] args) {
        //New object 
        compoundInterestCalculator InterestCalculator = new compoundInterestCalculator(); 
        double finalMoney;  // The user's investment after the inputted information 
        

        //Displaying the results 
        System.out.println("Welcome to the savings program. You can predict how much money you will make over time if you enter some money in your saivngs account.");
        InterestCalculator.compoundInterestInput(); 

        finalMoney = InterestCalculator.finalMoneyCalculator(); 
        System.out.println("The final money is: " + finalMoney); 
    }
}