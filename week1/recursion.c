#include <stdio.h>
#define ARRAY_LEN 10

void print_array(int array[], int index, int length);

int main(void) {
    int nums[ARRAY_LEN] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 8};
    // Here, we print the elements of an array with a for loop.
    printf("Print an array with a for loop:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nums[i]);
    }

    // Here, we use our recursive function.
    printf("\nPrint an array with recursion:\n");
    print_array(nums, 0, ARRAY_LEN);
    return 0;
}

// Recursively print an array.
void print_array(int array[], int index, int length) {
    // Make sure we haven't reached the end of the array.
    if (index < length) {
        // print the current element in the array
        printf("%d\n", array[index]);
        // make a call to print the next element in the array
        print_array(array, index + 1, length);
    }
}

// Question: What change would we have to make to print_array
// to print the array backwards?