/* Name Eddy Koundjou Yem
  Date: September 15 
*/
#include <stdio.h>

int main() {
  int num = 0;
  int bit_num = 0;
  int choice;

  while(1)
    {
      for (int i = 31; i >= 0; i--)
        {
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