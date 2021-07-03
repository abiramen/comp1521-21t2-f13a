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
        
        // numbers[0] = *(numbers + 0)
        // numbers[1] = *(numbers + 1) = actual address is numbers + 4
        // numbers[i] = *(numbers + i) = actual address is numbers + 4 * i
        // numbers[i] = i[numbers] = *(i + numbers)
        
    }
}
