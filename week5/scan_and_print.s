# SPIM provides a method of defining constants, similar to C #define
LEN = 5

################################################################################
        .data
numbers:        .word 0, 0, 0, 0, 0     # numbers[5]

################################################################################
# .text <MAIN>
        .text
main:
        li      $t0, 0                          # int i = 0;
        la      $t1, numbers		        # &numbers[i] 
        
scan_loop:
        bge     $t0, LEN, scan_loop__after      # while (i < LEN)

        li      $v0, 5                          # scanf("%d", &numbers[i])  
        syscall
        sw      $v0, ($t1)
        
        addi	$t0, $t0, 1                     # i = i + 1
        addi    $t1, $t1, 4			# update &numbers[i] 
                                                # (add 4 since ints are 4 bytes)
        j	scan_loop
scan_loop__after:
        li      $t0, 0                          # i = 0

print_loop:
        bge     $t0, LEN, print_loop__after     # while (i < LEN)
        
        mul     $t1, $t0, 4                     # 4 * i 
        lw	$a0, numbers($t1)               # load numbers[i]
                                                # &numbers[i] = numbers + 4 * i
        li      $v0, 1                          # printf("%d", numbers[i])
        syscall

        li      $v0, 11                         # printf("\n")
        li      $a0, '\n'
        syscall

        addi	$t0, $t0, 1                     # i = i + 1
        j       print_loop

print_loop__after:
        li      $v0, 0                          # return 0;
        jr      $ra

