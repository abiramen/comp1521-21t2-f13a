########################################################
        .data
enter_number:
        .asciiz "Enter a number: "
fib_out_1:
        .asciiz "Fibonacci of "
fib_out_2:
        .asciiz " is "
########################################################
# .text <main>
        .text
main:
main__prologue:
        addi    $sp, $sp, -4
        sw      $ra, ($sp)

main__body:
        li      $v0, 4                  # printf("Enter a number: ");
        la      $a0, enter_number
        syscall

        li      $v0, 5                  # scanf("%d", &n);
        syscall
        move    $t0, $v0

        li      $v0, 4                  # printf("Fibonacci of ");
        la      $a0, fib_out_1
        syscall

        li      $v0, 1                  # printf("%d", n);
        move    $a0, $t0
        syscall

        li      $v0, 4                  # printf(" is ");
        la      $a0, fib_out_2
        syscall

        move    $a0, $t0                # Call fib(n)
        jal     fib                     

        move    $a0, $v0                # printf("%d", fib(n));
        li      $v0, 1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

main__epilogue:
        lw      $ra, ($sp)
        addi    $sp, $sp, 4

        li      $v0, 0
        jr      $ra


########################################################
# .text <fib>
        .text
fib:
# Args:
#       - n     in $a0
fib__prologue:
        addi    $sp, $sp, -12
        sw      $s0, 0($sp)
        sw      $s1, 4($sp)
        sw      $ra, 8($sp)
fib__body:
        blt     $a0, 2, fib__base       # if (n < 2) goto fib__base:
        move    $s0, $a0

        addi    $a0, $s0, -1            # call fib(n - 1)
        jal     fib
        move    $s1, $v0

        addi    $a0, $s0, -2            # call fib(n - 2)
        jal     fib

        add     $v0, $v0, $s1           # v0 = fib(n - 2) + fib(n - 1)
        j       fib__epilogue

fib__base:
        move    $v0, $a0                # return n;
fib__epilogue:
        lw      $s0, 0($sp)
        lw      $s1, 4($sp)
        lw      $ra, 8($sp)
        addi    $sp, $sp, 12
        jr      $ra
