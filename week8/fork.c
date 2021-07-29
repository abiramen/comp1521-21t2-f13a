#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>

int main(void) {
    int x = 1;
    pid_t pid = fork();
    if (pid < 0) {
        err(1, "fork failed");
    } else if (pid > 0) {
        x++; printf ("x = %d\n", x); // parent prints out 2
    } else { // pid = 0
        x--; printf ("x = %d\n", x); // child prints out 0
    }
}

