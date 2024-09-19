/*
 * 
 * Name: Eddy Koundjou Yem
 * Date: 09/15/2024
 * 
 * A program that calculates the balance of the user account after a specified number of years 
 * using the following equation: A = P(1 + (r/n))^(nt)
 * 
 * where A is the amount of money in the account after a specififed number of years 
 * P is the principal amount that was originlaly deposiited into the account 
 * r is the annual interest rate 
 * n is the number of times per year that the interest is compounded
 * t is the specified number of years
 */

 import java.util.Scanner; 

 public class CompoundInterest {

    static void compoundInterestCalculator (double principalAmount, double userRate, double compoundInterest, int time, double finalMoney, double interestRate, double exponentialRate){
        System.out.println("Your principal amount is: $" + principalAmount);

        System.out.println("Your interest rate is " + userRate + "%");

        System.out.println("The amount of times per year the interest is applied is: " + compoundInterest);

        System.out.println("The amount of years the money will be compounded is " + time + " years");

        //The final amount calculated
        finalMoney = principalAmount*(1 + Math.pow((interestRate/compoundInterest),exponentialRate));
        System.out.println("Your final amount is: $" + finalMoney);
    }
    /* 
    static void userInput() {
        double principalAmount = 0; 
        double userRate = 0; 
        int compoundInterest = 0;
        int time = 0; 
        //Necessary input programs 
        Scanner input = new Scanner(System.in); 

        System.out.println("Welcome to the savings program. You can predict how much money you will make over time if you enter some money in your saivngs account.");

        //Asking the user necessary information
        System.out.println("Enter the principal amount you want to deposit ");
        principalAmount = input.nextDouble(); 

        System.out.println("Enter the interest rate: ");
        userRate = input.nextDouble(); 

        System.out.println("Enter the number of times per year that the interest is applied"); 
        compoundInterest = input.nextInt();

        System.out.println("Enter the amount of years the money will be compounded");
        time = input.nextInt(); 

        input.close(); 
    }
    */

    
    public static void main(String[] args) {


        //CompoundInterest interestCalculator = new CompoundInterest(); 
        // Necessary variables for the program
        double finalMoney = 0; 
        double principalAmount = 0; 
        double userRate = 0; 
        double compoundInterest = 0; 
        int time = 0; 
        double interestRate = 0; 
        double exponentialRate = 0;  
        
        

        //Necessary input programs 
        
        Scanner input = new Scanner(System.in); 

        System.out.println("Welcome to the savings program. You can predict how much money you will make over time if you enter some money in your saivngs account.");

        //Asking the user necessary information
        System.out.println("Enter the principal amount you want to deposit ");
        principalAmount = input.nextDouble(); 

        System.out.println("Enter the interest rate: ");
        userRate = input.nextDouble(); 

        System.out.println("Enter the number of times per year that the interest is applied"); 
        compoundInterest = input.nextInt();

        System.out.println("Enter the amount of years the money will be compounded");
        time = input.nextInt(); 
        


        System.out.println("The principal amount is :" + principalAmount);
        System.out.println("The user rate is: " + userRate);
        System.out.println("The compound interest " + compoundInterest);
        System.out.println("The time is " + time);
        compoundInterestCalculator(principalAmount, userRate, compoundInterest, time, finalMoney, interestRate, exponentialRate);
        input.close(); 

    }
}