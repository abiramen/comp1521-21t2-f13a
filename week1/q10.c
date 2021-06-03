#include <stdio.h>
#define ARRAY_LEN 10

int main(void) {
    int nums[ARRAY_LEN] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 8};
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}
