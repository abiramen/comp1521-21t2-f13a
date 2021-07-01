#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    // 46329
    if (x > 46340) {
        goto print_too_big;
    }

print_square:
    y = x * x;
    printf("%d\n", y);
    goto end;
    
print_too_big:
    printf("square too big for 32 bits\n");
    
end:
    return 0;
}
