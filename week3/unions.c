union { 
    int a;
    int b;
} u1;

union {
    unsigned short a;
    char b;
} u2;

union {
    int a;
    char b[12];
} u3;

union {
    int a;
    char b[14];
} u4;

union {
    unsigned int a;
    int b; 
    struct {
        int x;
        int y;
    } c;
} u5;