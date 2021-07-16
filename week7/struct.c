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
    int stu_id;         // 04 bytes
    char course[9]:     // 09 bytes
    char term[5];       // 05 bytes
    char grade[3];      // 03 bytes
    double mark;        // 08 bytes 
};

struct _queue {
    int nitems;     // # items currently in queue
    int head;       // index of oldest item added
    int tail;       // index of most recent item added
    int maxitems;   // size of array
    Item *items;    // malloc'd array of Items
};
