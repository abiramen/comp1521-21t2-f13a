#include <stdio.h>
#define N 10

int main(void) {
    char str[N] = { 'H', 'i', '\0' };
    printf("%s\n", str);
    return 0;
}

// Try compiling this file with
// gcc -E flags.c
// gcc -S flags.c
// gcc -c flags.c
// gcc flags.c
// to figure out what each of these flags do.
