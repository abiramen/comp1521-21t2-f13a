### One possible (and quite old) approach to loading programs into memory is to load the entire program address space into a single contiguous chunk of RAM, but not necessarily at location 0.

For example:
![](contiguous.png)

Doing this requires all the addresses in the program to be rewritten relative to the new base address before we can perform its instructions.

Consider the following MIPS code, where 
- `loop1` is located at 0x1000 -> 0x9000
- `end_loop1` is located at 0x1028 -> 0x9028
- `array` is located at 0x2000. -> 0xa000

If the program containing this code is loaded starting at address A = 0x8000, which instructions need to be rewritten, and what addresses are in the relocated code?



Source:
```mips
   li  $t0, 0
   li  $t1, 0
   li  $t2, 20  # elements in array
loop1:
   bge $t1, $t2, end_loop1 <- need to update
   mul $t3, $t1, 4
   la  $t4, array <-
   add $t3, $t3, $t4
   lw  $t3, ($t3)
   add $t1, $t1, $t3
   add $t1, $t1, 1
   j   loop1 <-
end_loop1:
```
