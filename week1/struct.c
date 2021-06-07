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

int main(void) {
    // bring Abiram into existence here.
    struct student abiram;

    // set Abiram's details
    // we are directly accessing a struct,
    // so we use . to access its fields.
    strcpy(abiram.name, "Abiram");
    strcpy(abiram.degree, "Computer Science");
    abiram.year = 2;

    // now, let's create Jashank.
    struct student *jashank = create_student("Jashank", "Computer Science", 6);

    // whoops, Jashank is actually in his 7th year.
    // we need to use the -> notation, since jashank is
    // a pointer to a struct.
    // note that this is the same as (*jashank).year
    jashank->year = 7;

    // print Abiram and Jashank's details.
    printf(
        "%s is in year %d of their degree in %s\n",
        abiram.name, abiram.year, abiram.degree
        );
    printf("%s is in year %d of their degree in %s\n",
        jashank->name, jashank->year, jashank->degree
        );
}

// Create a student using malloc, and assign properties to them.
struct student *create_student(char name[], char degree[], int year) {
    struct student *new_student = malloc(sizeof(struct student));
    // this time, we have a pointer to a struct
    // we use our stab -> notation.
    strcpy(new_student->name, name);
    strcpy(new_student->degree, degree);
    new_student->year = year;
}