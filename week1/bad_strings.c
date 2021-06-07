// Try compiling and running this program.
// There won't be any errors, but the program
// won't behave as expected.

// What change do we need to make to fix this?

#include <stdio.h>

int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';
    printf("%s", str);
    return 0;
}
