#include <stdio.h>

typedef struct item Item;

struct _queue {
    int nitems;     // 04 bytes
    int head;       // 04 bytes
    int tail;       // 04 bytes
    int maxitems;   // 04 bytes
    Item *items;    // 04 bytes
};

int main(void) {
    printf("sizeof struct is %zu\n", sizeof(size_t));
    return 0;
}
