// Create a student using command line input.
// Make sure to check out struct.c first!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define MAX_DEGREE_LENGTH 64

struct student {
    char name[MAX_NAME_LENGTH];
    char degree[MAX_DEGREE_LENGTH];
    int year;
};

struct student *create_student(char name[], char degree[], int year);

// Sometimes you might see char **argv instead of
// char *argv[]. These function the same, and 
// are essentially an array of strings.
int main(int argc, char *argv[]) {
    
    // Remember that the name of the program is stored in argv[0].
    if (argc != 4) {
        printf("Usage: ./args name degree year\n");
        return 1;
    }

    // atoi converts a string into an integer.
    struct student *student = create_student(argv[1], argv[2], atoi(argv[3]));

    printf("%s is in year %d of their degree in %s\n",
        student->name, student->year, student->degree
        );
}

// Create a student using malloc, and assign properties to them.
struct student *create_student(char name[], char degree[], int year) {
    struct student *new_student = malloc(sizeof(struct student));
    
    // A challenge question:
    // You might notice that we use strncpy here, instead of
    // strcpy like struct.c - why?
    strncpy(new_student->name, name, MAX_NAME_LENGTH);
    strncpy(new_student->degree, degree, MAX_DEGREE_LENGTH);
    new_student->year = year;
}