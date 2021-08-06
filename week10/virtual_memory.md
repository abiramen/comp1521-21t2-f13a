# Virtual memory

**Poll**: How are you feeling about virtual memory?

### Memory hierarchy
![yoinked and improved from os slides](cs3231-memory-hierarchy.png)

### Cool things virtual memory lets us do
- swapping to a 'backing store'
    - we can swap memory to another drive
    - allows us to run processes even if we don't have sufficient memory
- not need contiguous free memory
- process/kernel isolation
    - allows for processes to exist independently, and not modify the memory of other processes
- shared object libraries
    - libraries like `stdio.h` are all from libc

#### Non-contiguous allocation?

Here's some physical memory. What if I want to load another process requiring three 'blocks' of memory?
```
   +------+------+------+------+------+------+
   |      |      | USED | USED | USED |      |
   +------+------+------+------+------+------+
```
- could shift them, but this is expensive
- virtual memory allows us to map from process memory to physical memory, avoiding the need for contiguous blocks


### Some things to consider
- addressing in machine code (such as MIPS) operates on actual addresses
    - we have to do this, since we don't know where in physical memory our program will get loaded
- we use virtual addressing
    - we have hardware to translate a process' view of virtual memory to actual, physical memory

### When might we not need virtual memory?
- embedded systems
    - example: microcontrollers on washing machines

### Pages and frames
- **Pages** are a fixed size region of virtual memory.
    - About 4096 byte blocks
- **Frames** are fixed size regions of physical memory
- Virtual pages map to physical frames
- **Segments** are when a virtual memory system uses non-fixed regions
- Page/frame sizes are often a power of 2 - this allows us to perform bitwise operations to speed things up.

#### Page tables
**Page tables** are a per-process mapping of virtual pages to physical frames.

**Inverted page tables** are an operating system construct which map physical frames to virtual page numbers. This will be important for this week's lab!

### Q7 - What is the difference between a virtual address and physical address?
A virtual address is an address within a process' address space - these addresses are mapped to physical addresses within RAM.

### What tends to happen when we access a virtual address which isn't in our address space?
**Segmentation faults** occur when we attempt to access addresses outside our address space (eg NULL).

### Let's say that hypothetically page/frame sizes were 4096 bytes each - how would we map virtual address to physical addresses?

- the last 3 hexadecimal digits of an address refer to the offset of memory within a page
- the remaining digits represent a page number

Take virtual address 0x5736cf8e
number: 5736c offset: f8e

page table:
map page 5736c to physical frame 01337

virtual address 0x5736cf8e maps to physical address 0x01337f8e

This translation from virtual addresses to physical addresses is often backed by physical hardware called a **translation lookaside buffer** - a quick way of looking up translations.

### Q5 - Each new process in a computer system will have its own address space. Which parts of the address space contain initial values at the point when the process starts running? Which parts of the address space can be modified as the process executes?
- Code
    - readable, executable
    - we have to load in code when our process starts
- Data
    - rodata
        - "hello"
        - loaded in when the process is created
    - Global variables and static data
        - readable, and writeable
        - initialise them in memory when the process starts
        - we can modify it
    - Dynamic data (heap)
        - Resizeable region
        - malloc allocates memory on the heap
        - same permissions as static data
- Stack
    - modifiable as the process goes on
    - readable, writeable

### Q3 - Assume we have 6 virtual memory pages and 4 physical memory pages and are using a least-recently-used (LRU) replacement strategy.

See `lru_example.md`.

### Let's take a look at the starter code for this week's lab!
See `lru.c`.

```
$ dcc lru.c -o lru
$ ./lru 4 6
Simulating 4 pages of physical memory, 6 pages of virtual memory
5
Time 0: virtual page 5 loaded to physical page 0
3
Time 1: virtual page 3 loaded to physical page 1
5
Time 2: virtual page 5 -> physical page 0
3
Time 3: virtual page 3 -> physical page 1
0
Time 4: virtual page 0 loaded to physical page 2
1
Time 5: virtual page 1 loaded to physical page 3
2
Time 6: virtual page 2  - virtual page 5 evicted - loaded to physical page 0
2
Time 7: virtual page 2 -> physical page 0
3
Time 8: virtual page 3 -> physical page 1
5
Time 9: virtual page 5  - virtual page 0 evicted - loaded to physical page 2
```

### Q6 - One possible (and quite old) approach to loading programs into memory is to load the entire program address space into a single contiguous chunk of RAM, but not necessarily at location 0.
See `contiguous.md`.

### Q8 - Consider a process whose address space is partitioned into 4KB pages and the pages are distributed across physical memory.
See `paged_proc.md`.

### Q9 - Working sets and page faults
See `working_set.md`.
