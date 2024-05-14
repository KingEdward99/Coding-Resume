/*
The program outputs the first 20 terms of a sequence defined by the recurrence relation 
an = c1an-1 + c2an-2, a1 = c3, a2 = c4, where the integers c1, c2, c3, and c4 are input.

*/

import java.util.Scanner;

public class Sequence {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input values of c1, c2, c3, and c4
        System.out.println("Enter the value of c1: ");
        double c1 = scanner.nextDouble();
        System.out.print("Enter the value of c2: ");
        double c2 = scanner.nextDouble();
        System.out.print("Enter the value of c3: ");
        double c3 = scanner.nextDouble();
        System.out.print("Enter the value of c4: ");
        double c4 = scanner.nextDouble();

        scanner.close(); 
        
        // Generate and print the first 20 terms of the sequence
        createSequence(c1, c2, c3, c4);
    }
    
    public static void createSequence(double c1, double c2, double c3, double c4) {
        // Initialize an array to store the first 20 terms of the sequence
        double[] sequence = new double[20];
        
        // Assign the first two terms of the sequence
        sequence[0] = c3;
        sequence[1] = c4;
        
        // Generate the remaining terms of the sequence
        for (int i = 2; i < 20; i++) {
            sequence[i] = c1 * sequence[i-1] + c2 * sequence[i-2];
        }
        
        // Print the first 20 terms of the sequence
        System.out.println("The first 20 terms of the sequence are:");
        for (double term : sequence) {
            System.out.print(term + " ");
        }
    }
}







