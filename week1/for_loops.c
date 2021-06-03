#include <stdio.h>

int main(void) {
    // print every number from 1 to 10 inclusive with a while loop.
    int i = 1;
    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }

    printf("i was equal to %d when the while loop finished.\n", i);

    // print every number from 1 to 10 inclusive with a for loop.
    for (int j = 1; j <= 10; i++) {
        printf("%d\n", j);
    }

    // you can be evil and use a for loop exactly like a while loop...
}
