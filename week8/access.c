#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (access(argv[1], X_OK) == 0) {
        // man 2 access says access returns 0 if we do have access
        printf("You can execute %s\n", argv[1]);
    } else {
        printf("You can't execute %s\n", argv[1]);
    }
    return 0;
}
