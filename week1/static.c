#include <stdio.h>

int counter(void) {
    // right now, this int isn't static.
    int count = 0;
    count++;
    return count;
}

int main(void) {
    printf("first count %d\n", counter());
    printf("second count %d\n", counter());
    return 0;
}
