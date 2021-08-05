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
...
2. Assuming that the code is already loaded in memory, but that none of bigArray is loaded, and that only the working set is held in memory, how many *page faults* are likely to be generated during the execution of this code?
...
