#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[]) {
    // ./basic-spawn program-name arg1
    if (argc < 3) {
        printf("Usage: ./basic-spawn program-name arg1");
    }
    pid_t new_process;
    char *new_argv[] = {argv[2], NULL};
    posix_spawn(&new_process, argv[1], NULL, NULL, new_argv, environ);

    printf("Created new process");
}
