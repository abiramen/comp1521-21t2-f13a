# Q7-9: fopen

### What does fopen do? What are its parameters?
- opens a file, associates a stream with it, and returns a pointer we can pass to other library functions (like `fgets`, `fgetc`)
    - takes in a pathname
    - a 'mode'
        - `man 3 fopen`

### What are some circumstances it may return NULL?
    - returns NULL when there is an error
        - EINVAL when we have an invalid mode
        - malloc failure -> out of memory
        - no perms
        - EEXIST if the file exists and we're not allowed to overwrite
        - file doesnt exist for reading

### How do you print the specific reason it returned NULL?
    - errno is a special global variable which contains error numbers

```c
FILE *stream = fopen("somefile", "r");
if (stream == NULL) {
    if (errno == EINVAL) {
        fprintf(stderr, "invalid mode");
    }
}
```
