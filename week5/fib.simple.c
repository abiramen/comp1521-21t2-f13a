#include <stdio.h>

int fib(int n) {
    if (n < 2) goto fib__base;

    return fib(n - 1) + fib(n - 2);

fib__base:
    return n;
}

int main(void) {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);

    printf("Fibonacci of ");
    printf("%d", n);
    printf(" is ");
    printf("%d", fib(n));
    printf("\n");

    return 0;
}
