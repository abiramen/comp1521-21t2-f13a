### Assume we have 6 virtual memory pages and 4 physical memory frames and are using a least-recently-used (LRU) replacement strategy.

What will happen if these virtual memory pages were accessed, each one second apart?

```
5 3 5 3 0 1 2 2 3 5
```

- A **page fault** is when we realise we don't have a page physically loaded in memory.
- We resolve a page fault by either finding a free frame in memory, or evicting another page.

Here's our 4 physical pages over time ('inverted page table'):
```
initially empty.
  [0] [1] [2] [3]
 +---+---+---+---+
 |   |   |   |   |
 +---+---+---+---+
t = 0: 5
  [0] [1] [2] [3]
 +---+---+---+---+
 | 5 |   |   |   |
 +---+---+---+---+
t = 1: 3
  [0] [1] [2] [3]
 +---+---+---+---+
 | 5 | 3 |   |   |
 +---+---+---+---+
t = 2: 5
  [0] [1] [2] [3]
 +---+---+---+---+
 | 5 | 3 |   |   |
 +---+---+---+---+
t = 3: 3
  [0] [1] [2] [3]
 +---+---+---+---+
 | 5 | 3 |   |   |
 +---+---+---+---+
t = 4: 0
  [0] [1] [2] [3]
 +---+---+---+---+
 | 5 | 3 | 0 |   |
 +---+---+---+---+
t = 5: 1
  [0] [1] [2] [3]
 +---+---+---+---+
 | 5 | 3 | 0 | 1 |
 +---+---+---+---+
t = 6: 2
  [0] [1] [2] [3]
 +---+---+---+---+
 | 2 | 3 | 0 | 1 |
 +---+---+---+---+
evicted: 5
t = 7: 2
  [0] [1] [2] [3]
 +---+---+---+---+
 | 2 | 3 | 0 | 1 |
 +---+---+---+---+
t = 8: 3
  [0] [1] [2] [3]
 +---+---+---+---+
 | 2 | 3 | 0 | 1 |
 +---+---+---+---+
t = 9: 5
  [0] [1] [2] [3]
 +---+---+---+---+
 | 2 | 3 | 5 | 1 |
 +---+---+---+---+
evicted: 0
```
