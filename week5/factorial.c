// Simple factorial using recursion.
// Abiram Nadarajah, July 2021

#include <stdio.h>

int factorial(int n) {
    if (n <= 0) { // base case (n really shouldn't be negative.)
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    int number;
    scanf("%d", &number);
    printf("%d! = %d\n", number, factorial(number));
}
