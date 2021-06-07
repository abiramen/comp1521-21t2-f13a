#include <stdio.h>


int main(void) {
    char *foo = "hello";
    char *bar = "world";

    printf("%s %s\n", foo, bar);

    // but what if i want to say hullo?
    foo[1] = 'u';
    
    // this code will result in a segmentation fault. why?
}
