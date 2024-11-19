/* copyReverse -- copyReverse namel to name2 */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

//  !!! DO NOT CHANGE BUFSIZE
#define BUFSIZE  100        /* size of chunk to be read */
#define PERM  0644          /* file permission for new file */

// Swapping two char variables pointed by a and b
void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

/* copyReverse namel to name2 */
int copyReverse(const char *namel, const char *name2)
{
    int infile, outfile;
    ssize_t nread;
    char buffer[BUFSIZE];

    // Open the input file for reading
    if ((infile = open(namel, O_RDONLY)) == -1)
        return (-1);

    // Open the output file for writing
    if ((outfile = open(name2, O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1)
    {
        close(infile);
        return (-2);
    }

    // Find the size of the input file using lseek
    int fSize = lseek(infile, 0, SEEK_END);
    if (fSize == -1) {
        close(infile);
        close(outfile);
        return (-3);
    }

    // Calculate the number of full blocks and the size of the partial block
    int numBlocks = fSize / BUFSIZE;
    int sizePartialBlock = fSize % BUFSIZE;

    // If there's a partial block, read, reverse, and write it first
    if (sizePartialBlock > 0)
    {
        lseek(infile, 0, SEEK_SET);  // Move to the beginning of the file
        nread = read(infile, buffer, sizePartialBlock);

        if (nread == -1) {
            close(infile);
            close(outfile);
            return (-4);
        }

        // Reverse the partial block
        for (int i = 0; i < nread / 2; i++) {
            swap(&buffer[i], &buffer[nread - i - 1]);
        }

        // Write the reversed partial block
        if (write(outfile, buffer, nread) == -1) {
            close(infile);
            close(outfile);
            return (-5);
        }
    }

    // Reverse the full blocks
    for (int cnt = 0; cnt < numBlocks; cnt++)
    {
        // Move to the beginning of the (numBlocks - cnt - 1)-th block
        lseek(infile, fSize - sizePartialBlock - ((cnt + 1) * BUFSIZE), SEEK_SET);

        // Read the block into buffer
        nread = read(infile, buffer, BUFSIZE);
        if (nread == -1) {
            close(infile);
            close(outfile);
            return (-6);
        }

        // Reverse the buffer
        for (int i = 0; i < nread / 2; i++) {
            swap(&buffer[i], &buffer[nread - i - 1]);
        }

        // Write the reversed block into the output file
        if (write(outfile, buffer, nread) == -1) {
            close(infile);
            close(outfile);
            return (-7);
        }
    }

    // Close the files
    close(infile);
    close(outfile);

    return 0; // Normal return
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: copyReverse file1 file2 \n");
        exit(-1);
    }

    int retcode = 0;
    retcode = copyReverse(argv[1], argv[2]);

    if (retcode < 0) {
        printf("An error occurred during file processing\n");
        exit(-1);
    }

    return 0;
}
