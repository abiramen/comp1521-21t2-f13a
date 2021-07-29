#include <stdio.h>

int main(void) {
    int nums[3] = {0, 1, 2};

    char *casted_ptr = (char *)nums;

    printf("nums is at %p\n", nums);
    printf("nums + 1 is at %p\n", nums + 1);
    printf("dodgy nums + 1 is at %c\n", *(casted_ptr + 1));

}
