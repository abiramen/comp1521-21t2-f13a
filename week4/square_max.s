    .text
main:
    # $t0 = x, $t1 = y
    
    la $a0, enter_number # printf("Enter a number: ");
    li $v0, 4
    syscall
    
    li $v0, 5   # scanf("%d", &x);
    syscall     # $v0 = x
    
    move $t0, $v0 # $t0 = x
    
    bgt $t0, 46340, print_too_big

    mul $t1, $t0, $t0 # y = x * x;
    
    move $a0, $t1 # printf("%d\n", y);
    li $v0, 1
    syscall
    
    li $a0, '\n' # printf("\n");
    li $v0, 11
    syscall
    
    j end
    
print_too_big:
    la $a0, too_big # printf("square too big for 32 bits\n");
    li $v0, 4
    syscall
    
end:
    li $v0, 0
    jr $ra

    .data
enter_number:
    .asciiz "Enter a number: "
too_big:
    .asciiz "square too big for 32 bits\n"

