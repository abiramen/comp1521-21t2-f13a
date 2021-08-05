#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        struct stat s;
        if (stat(argv[i], &s) == -1) {
            perror(argv[i]);
            continue;
        }

        // octal number
        int mode = 0644;

        printf("-- file: %s --\n", argv[i]);


        printf("st_ino = %ld\n", s.st_ino);
        printf("st_mode = %o\n", s.st_mode);

        // if ((s.st_mode & S_IFMT) == S_IFREG) {
        //     printf("this is a regular file\n");
        // } else {
        //     printf("this is not a regular file\n");
        // }

        if (s.st_mode & S_IWGRP) {
            printf("group can write to file!\n");
        }

        if (S_ISREG(s.st_mode)) {
            printf("this is a regular file\n");
        } else {
            printf("this is not a regular file\n");
        }

        printf("st_uid = %d\n", s.st_uid);
        printf("st_gid = %d\n", s.st_gid);
        printf("st_size = %ld\n", s.st_size);
        printf("st_blksize = %ld\n", s.st_blksize);
        printf("st_blocks = %ld\n", s.st_blocks);
        printf("st_atime = %ld\n", s.st_atime);
        printf("st_mtime = %ld\n", s.st_mtime);
        printf("st_ctime = %ld\n", s.st_ctime);
        putchar('\n');
    }
}
