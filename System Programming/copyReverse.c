
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFSIZE 100 /* size of chunk to be read */
#define PERM 0644 /* file permission for new file */
// Function to swap two characters
void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}
// Function to reverse the contents of one file into another
int copyReverse(const char *name1, const char *name2) {
    int infile, outfile;
    ssize_t nread;
    char buffer[BUFSIZE];
    off_t fSize, begBlockIdx, sizePartialBlock;
    // Open the input file for reading
    if ((infile = open(name1, O_RDONLY)) == -1) {
        perror("Error opening input file");
        return -1;
    }
    // Get the file size using lseek
    if ((fSize = lseek(infile, 0, SEEK_END)) == -1) {
        perror("Error getting file size");
        close(infile);
        return -1;
    }
    // Calculate the size of the partial block and number of full blocks
    sizePartialBlock = fSize % BUFSIZE;
    int numBlocks = fSize / BUFSIZE;
    
    // Open the output file for writing, create if it doesn't exist
    if ((outfile = open(name2, O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1) {
        perror("Error opening output file");
        close(infile);
        return -1;
    }
    
    // Handle the partial block at the end if it exists
    if (sizePartialBlock > 0) {
        begBlockIdx = fSize - sizePartialBlock;
        if (lseek(infile, begBlockIdx, SEEK_SET) == -1) {
            perror("Error seeking input file");
            close(infile);
            close(outfile);
            return -1;
        }
// Read the partial block
if ((nread = read(infile, buffer, sizePartialBlock)) == -1) {
perror("Error reading input file");
close(infile);
close(outfile);
return -1;
}
// Reverse the buffer in-place
for (int i = 0; i < sizePartialBlock / 2; i++) {
swap(&buffer[i], &buffer[sizePartialBlock - i - 1]);
}
// Write the reversed partial block to the output file
if (write(outfile, buffer, nread) == -1) {
perror("Error writing to output file");
close(infile);
close(outfile);
return -1;
}
}
// Handle the remaining full blocks in reverse order
for (int cnt = 0; cnt < numBlocks; cnt++) {
// Calculate the position of the current block
begBlockIdx = fSize - sizePartialBlock - ((cnt + 1) * BUFSIZE);
if (lseek(infile, begBlockIdx, SEEK_SET) == -1) {
perror("Error seeking input file");
close(infile);
close(outfile);
return -1;
}
// Read the block into the buffer
if ((nread = read(infile, buffer, BUFSIZE)) == -1) {
perror("Error reading input file");
close(infile);
close(outfile);
return -1;
}
// Reverse the buffer in-place
for (int i = 0; i < BUFSIZE / 2; i++) {
swap(&buffer[i], &buffer[BUFSIZE - i - 1]);
}
// Write the reversed buffer to the output file
if (write(outfile, buffer, nread) == -1) {
perror("Error writing to output file");
close(infile);
close(outfile);
return -1;
}
}
// Close both input and output files
close(infile);
close(outfile);
return 0;
}
// Main function to handle command-line arguments
int main(int argc, char **argv) {
if (argc != 3) {
printf("Usage: copyReverse file1 file2\n");
exit(-1);
}
int retcode = copyReverse(argv[1], argv[2]);
if (retcode == 0) {
printf("File reversed successfully!\n");
} else {
printf("Failed to reverse file.\n");
}
return retcode;
}
