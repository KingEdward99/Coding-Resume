/* Name Eddy Koundjou Yem
  Date: September 15 

  Description:
  This program allows the user to manipulate bits of a 32-bit integer.
  The user can:
    1. Set (turn on) a specific bit
    2. Clear (turn off) a specific bit
*/
#include <stdio.h>

int main() {

  //Stores the number whose bits will be modified
  int num = 0;

  //Stores the bit position the user wants to modify
  int bit_num = 0;

  //Stores the user's choice 
  int choice;

  //Infinite loop to continuously allow to bit manipulation
  while(1)
    {
      //Print the 32-bit binary representation of num 
      //Loop starts from the most significant bit (31)
      //and goes down to the least significant bit (0)
      for (int i = 31; i >= 0; i--)
        {
          //Check if bit i is set using bitwise AND 
          //
          printf("%i",((num & (1 << i))?1:0));
        }
      printf("\n Enter 1. to set bit:");
      printf("\n Enter 2. to clear bit");
      printf("\n Enter 3 to exit"); 
      printf("\n Enter your choice: ");
      scanf("%d", &choice);
      
      if(choice == 1 || choice == 2)
      {
        printf("Enter bit position to set or clear bit");
        scanf("%d",&bit_num); 
      }

      if(choice == 1)
      {
        num |= 1 << bit_num; 
      }

      if (choice == 2)
      {
        num &= ~(1 << bit_num);
      }  
    }
}