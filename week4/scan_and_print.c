#include <stdio.h>
#define LEN 5

int main(void) {
    int numbers[LEN] = {0};

    int i = 0;
    while (i < LEN) {
        scanf("%d", &numbers[i]);
        i++;
    }

    i = 0;
    while (i < LEN) {
        printf("%d\n", numbers[i]);
        i++;
    }
}
