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
    
    for (int j = 0; j <= 10; j++) {
        printf("%d\n", j);
    }
    // j stops existing outside the for loop, meaning the next line won't work
    // we can fix this by declaring `int j;` on line 13.
    // printf("j was equal to %d when the for loop finished.\n", j);


    // you can be evil and use a for loop exactly like a while loop...
    // print every number from 1 to 10 inclusive with a spicy while loop.
    int k = 1;
    for (; k <= 10; ) {
        printf("%d\n", k);
        k++;
    }
}
