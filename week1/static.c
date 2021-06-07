// What do you expect this program to print?
// What do you expect this program to print if we add
// static in front of line 8?
#include <stdio.h>

int counter(void) {
    // what happens if we turn this int into a static int?
    int count = 0;
    count++;
    return count;
}

int main(void) {
    printf("first count %d\n", counter());
    printf("second count %d\n", counter());
    return 0;
}
