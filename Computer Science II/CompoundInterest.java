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
    public static void main(String[] args) {
        // Necessary variables for the program
        double finalMoney = 0; 
        double principalAmount = 0; 
        double userRate = 0; 
        double interestRate = userRate/100; 
        int compoundInterest = 0;
        int time = 0; 

        //Necessary input programs 
        Scanner input = new Scanner(System.in); 

        System.out.println("Welcome to the savings program. You can predict how much money you will make over time if you enter some money in your saivngs account.");

        
        System.out.println("Enter the principal amount you want to deposit ");
        finalMoney = input.nextDouble(); 

        System.out.println(" Enter the interest rate: ");
        userRate = input.nextDouble(); 

        System.out.println("Enter the number of times per year that the interest is applied"); 
        compoundInterest = input.nextInt();

        System.out.println("Enter the amount of years the money will be compounded");
        time = input.nextInt(); 

        
        
    }

 }