/*
    Name: Eddy Koundjou Yem
    This program reads in a file and then converts the lowercase letters to uppercase letters 
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>  // Include ctype.h for the toupper function

#define BUFSIZE  512        /* size of chunk to be read */
#define PERM  0644          /* file permission for new file */

/* copy namel to name2 */
int copyConvert(const char *namel, const char *name2)
{
    int infile, outfile; // name for the input & output file 
    ssize_t nread; //number of bytes to read
    char buffer[BUFSIZE]; //buffer that holds the data that will be read 

    //Opening the file in read-only mode 
    if ((infile = open(namel, O_RDONLY)) == -1)
        return (-1);

    //opening the file in write only mode 
    if ((outfile = open(name2, O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1) {
        close(infile);
        return (-2);
    }

    /* now read from namel BUFSIZE chars at a time */
    while ((nread = read(infile, buffer, BUFSIZE)) > 0) {
        /* convert every lower-case char into upper-case char */
        for (ssize_t i = 0; i < nread; i++) {
            if (islower(buffer[i])) {
                buffer[i] = toupper(buffer[i]);
            }
        }

        /* write converted chars into outfile */
        if (write(outfile, buffer, nread) != nread) {
            close(infile);
            close(outfile);
            return (-3); // error writing to outfile
        }
    }

    close(infile);
    close(outfile);

    if (nread == -1)
        return (-4);   /* error on last read */
    else
        return (0);    /* all is well */
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: copyConvert file1 file2 \n");
        exit(-1);
    }

    int retcode = 0;
    retcode = copyConvert(argv[1], argv[2]);
    if (retcode == 0) {
        printf("Success!\n");
    } else {
        printf("Failure!\n");
    }

    return 0;
}
