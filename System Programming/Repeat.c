#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define MFILE 10

void cmp(const char *, struct stat *);

int main(int argc, char **argv) {
    int j, k;
    struct stat sb;
    time_t last_time[MFILE + 1];

    if (argc < 2) {
        fprintf(stderr, "usage: lookout filename ...\n");
        exit(1);
    }

    if (--argc > MFILE) {
        fprintf(stderr, "lookout: too many filenames\n");
        exit(1);
    }

    // Initialization
    for (j = 1; j <= argc; j++) {
        if (stat(argv[j], &sb) == -1) {
            fprintf(stderr, "lookout: couldn't stat %s\n", argv[j]);
            exit(1);
        }
        last_time[j] = sb.st_mtime;
    }

    // Repeat the following steps 5 times
    for (k = 0; k < 5; k++) {
        sleep(1); // Wait for 1 second

        // Check for changes in file attributes
        for (j = 1; j <= argc; j++) {
            if (stat(argv[j], &sb) == -1) {
                fprintf(stderr, "lookout: couldn't stat %s\n", argv[j]);
                exit(1);
            }
            cmp(argv[j], &sb); // Compare file attributes
        }
    }

    // If no change detected, terminate without printing anything
    exit(0);
}

void cmp(const char *name, struct stat *sb) {
    struct stat tmp_sb;
    if (stat(name, &tmp_sb) == -1) {
        fprintf(stderr, "lookout: couldn't stat %s\n", name);
        exit(1);
    }

    if (tmp_sb.st_size != sb->st_size) {
        printf("3"); // Change of st_size
    }
    if (tmp_sb.st_mtime != sb->st_mtime) {
        printf("5"); // Change of st_mtime
    }
    exit(0);
}