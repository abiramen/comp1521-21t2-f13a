# Demonstrating do-while loops in MIPS
# Abiram Nadarajah, July 2021

        .text
main:
        li      $t0, 0          # i = 0

loop:
        addi    $t0, $t0, 1     # i = i + 1

        li      $v0, 1          # printf("%d", i)
        move    $a0, $t0    
        syscall

        li      $v0, 11         # printf("\n")
        li      $a0, '\n'
        syscall

        blt     $t0, 10, loop   # while (i < 10)

        li $v0, 0               # return 0;
        jr $ra
