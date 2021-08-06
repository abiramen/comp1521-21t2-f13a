### Working sets and page faults

The **working set** of a process could be defined as the set of pages being referenced by the process over a small window of time. This would naturally include the pages containing the code being executed, and the pages holding the data being accessed by this code.

```c
int bigArray[100000];
// ...
int sum = 0;
for (int i = 0; i < 100000; i++)
    sum += bigArray[i];
```

Assume that pages are 4096 bytes, all of the above code fits in a single page, the sum and i variables are implemented in registers, and there is just one process running in the system.

1. How large is the working set of this piece of code?
- 1 page for the actual code
- 1 page for a section of the array
- we have a page fault once we reach the end of a section, and need to load in a new section
2. Assuming that the code is already loaded in memory, but that none of bigArray is loaded, and that only the working set is held in memory, how many *page faults* are likely to be generated during the execution of this code?
We get a page fault whenever we try to load a new page of the array. The array requires `ceiling(4 * 100000 / 4096) = 98` pages, so we get 98 page faults. 

## Resident set
The resident set is the set of pages for a process which map to an actual physical frame.
