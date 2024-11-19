/*copyReverse -- copyReverse name1 to name2*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 100 /* size of chunk to be read*/
#define PERM 0644   /*file permission for new file*/

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int copyReverse(const char *name1, const char *name2) {
    int infile, outfile;
    ssize_t nread;
    char buffer[BUFSIZE];
    off_t fSize, begBlockIdx, sizePartialBlock;

    if ((infile = open(name1, O_RDONLY)) == -1) {
        perror("Error opening input file");
        return -1;
    }

    if ((fSize = lseek(infile, 0, SEEK_END)) == -1) {
        perror("Error getting file size");
        close(infile);
        return -1;
    }

    sizePartialBlock = fSize % BUFSIZE;
    int numBlocks = fSize / BUFSIZE;

    if ((outfile = open(name2, O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1) {
        perror("Error opening output file");
        close(infile);
        return -1;
    }

    if (sizePartialBlock > 0) {
        begBlockIdx = fSize - sizePartialBlock;
        if (lseek(infile, begBlockIdx, SEEK_SET) == -1) {
            perror("Error seeking input file");
            close(infile);
            close(outfile);
            return -1;
        }

        if ((nread = read(infile, buffer, sizePartialBlock)) == -1) {
            perror("Error reading input file");
            close(infile);
            close(outfile);
            return -1;
        }

        for (int i = 0; i < nread / 2; i++) {
            swap(&buffer[i], &buffer[nread - i - 1]);
        }

        if (write(outfile, buffer, nread) == -1) {
            perror("Error writing to output file");
            close(infile);
            close(outfile);
            return -1;
        }
    }

    for (int cnt = 0; cnt < numBlocks; cnt++) {
        begBlockIdx = fSize - sizePartialBlock - (cnt * BUFSIZE);
        if (lseek(infile, begBlockIdx, SEEK_SET) == -1) {
            perror("Error seeking input file");
            close(infile);
            close(outfile);
            return -1;
        }

        if ((nread = read(infile, buffer, BUFSIZE)) == -1) {
            perror("Error reading input file");
            close(infile);
            close(outfile);
            return -1;
        }

        for (int i = 0; i < nread / 2; i++) {
            swap(&buffer[i], &buffer[nread - i - 1]);
        }

        if (write(outfile, buffer, nread) == -1) {
            perror("Error writing to output file");
            close(infile);
            close(outfile);
            return -1;
        }
    }

    close(infile);
    close(outfile);
    return 0;
}

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