// Write a C program, first_line.c, which is given one command-line argument -
// the name of a file - and which prints the first line of that file to stdout.
// If given an incorrect number of arguments, or if there was an error opening
// the file, it should print a suitable error message.
//
// A line may be of any size.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>", argv[0]);
        return 1;
    }
    
    FILE *stream = fopen(argv[1], "r");
    // if (stream == NULL) {
    //     fprintf(stderr, "your error was %s for file %s\n", strerror(errno), argv[1]);
    //     return 1;
    // }

    if (stream == NULL) {
        perror(argv[1]);
        return 1;
    }

    int c; 
    while ((c = fgetc(stream)) != EOF) {
        putchar(c);
        if (c == '\n') {
            break;
        }
    }
    return 0;
}
