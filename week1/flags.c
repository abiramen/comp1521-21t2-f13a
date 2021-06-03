#include <stdio.h>
#define N 10

int main(void) {
    char str[N] = { 'H', 'i', '\0' };
    printf("%s\n", str);
    return 0;
}

// gcc -E gcc_flags.c
// gcc -S gcc_flags.c
// gcc -c gcc_flags.c
// gcc gcc_flags.c
