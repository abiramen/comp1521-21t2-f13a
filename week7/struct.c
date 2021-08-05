// where in memory these structs are
// size of each element within the struct
struct _coord {     // 0x1000
    double x;       // 08 bytes - 0x1000 to 0x1007
    double y;       // 08 bytes - 0x1008 to 0x100f
};
// assume this is mips32 - pointers are 04 bytes
typedef struct _node Node;
struct _node {      // 0x2000
    int value;      // 04 bytes - 0x2000 to 0x2003
    Node *next;     // 04 bytes - 0x2004 to 0x2007
};

struct _enrolment {     // 0x3000
    int stu_id;         // 04 bytes - 0x3000 to 0x3003
    char course[9]:     // 09 bytes - 0x3004 to 0x300c
    char term[5];       // 05 bytes - 0x300d to 0x3011
    char grade[3];      // 03 bytes - 0x3012 to 0x3014
                        /* 03 bytes of padding - 0x3015 to 0x3017 */
    double mark;        // 08 bytes - 0x3018 to 0x301f
};

// sizeof(struct _enrolment);

// unaligned read/write - bad address
// lw or sw

struct _queue {
    int nitems;     // 04 bytes
    int head;       // 04 bytes
    int tail;       // 04 bytes
    int maxitems;   // 04 bytes
    Item *items;    // 04 bytes
};

// sizeof(struct _queue);
