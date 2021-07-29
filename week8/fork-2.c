#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
    printf("Hello\n");
    if (fork() != 0) {
        printf("Gan bei\n"); // parent
        // if fork fails, fork returns -1 and parent goes here
    } else {
        printf("Prost\n");  // child
    }
    printf("Goodbye\n");
}

// case 3: we failed to fork :(
// Hello (printed by parent)
// Gan bei (printed by parent)
// Goodbye

// case 1: all of parent goes first
// Hello (printed by parent)
// Gan bei
// Goodbye
// <scheduler switches to child>
// Prost
// Goodbye

// case 2: child gets to complete first
// Hello (printed by parent again)
// <scheduler switches to child>
// Prost
// Goodbye
// <scheduler switches to child>
// Gan bei
// Goodbye

// Child process prints:
// Prost
// Goodbye

// Parent process prints:
// Hello (before fork)
// Gan bei
// Goodbye
