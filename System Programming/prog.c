#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
 
void check_changes(struct stat *prev, struct stat *curr) {
   int first = 1;
 
   if (prev->st_mode != curr->st_mode) {
       if (!first) printf(" ");
       printf("1");
       first = 0;
   }
   if (prev->st_nlink != curr->st_nlink) {
       if (!first) printf(" ");
       printf("2");
       first = 0;
   }
   if (prev->st_size != curr->st_size) {
       if (!first) printf(" ");
       printf("3");
       first = 0;
   }
   if (prev->st_atime != curr->st_atime) {
       if (!first) printf(" ");
       printf("4");
       first = 0;
   }
   if (prev->st_mtime != curr->st_mtime) {
       if (!first) printf(" ");
       printf("5");
       first = 0;
   }
   
   // If changes are printed, exit
   if (!first) {
       printf("\n");
       exit(0);
   }
}
 
int main(int argc, char *argv[]) {
   if (argc < 2 || argc > 11) {
       fprintf(stderr, "Usage: %s <file1> [file2 ... file10]\n", argv[0]);
       exit(1);
   }
 
   struct stat prev_stats[10], curr_stats[10];
   
   // Get initial file stats for each file
   for (int i = 1; i < argc; i++) {
       if (stat(argv[i], &prev_stats[i - 1]) != 0) {
           perror("stat");
           exit(1);
       }
   }
 
   for (int seconds = 0; seconds < 5; seconds++) {
       sleep(1);  // Wait for 1 second
 
       // Check each file for changes
       for (int i = 1; i < argc; i++) {
           if (stat(argv[i], &curr_stats[i - 1]) != 0) {
               perror("stat");
               exit(1);
           }
 
           // Compare current stats with previous stats
           check_changes(&prev_stats[i - 1], &curr_stats[i - 1]);
       }
 
       // Update the previous stats
       memcpy(prev_stats, curr_stats, sizeof(prev_stats));
   }
 
   return 0;
}