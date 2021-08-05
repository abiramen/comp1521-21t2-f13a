# Processes and threads

- CPU cores can only really do one thing at a time
- Instead, we get the illusion of multitasking by switching between different processes really quickly - this is done by the process scheduler 

However, we need to preserve information about the process if we want to be able to switch seamlessly so that the process doesn't notice.

# Processes

need to preserve the following information about state:

- Values of CPU registers (trapframe)
    - Program counter

# Threads

**Threads** are just a unit of execution within a process which has been designed to be able to run independently of the rest of the process.

All processes contain at least one thread.

Processes contain a lot more information about them than threads - for example:

- processes require their own address space - that is, its own space in memory
    - threads share the same address space as their parent process
    - threads only really need to keep track of their execution state; that is, where within the thread they are up to
    - this means that global variables are shared between threads
- processes share other resources, such as open files
