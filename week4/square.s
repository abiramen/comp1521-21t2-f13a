    .text
main:
   
    # $t0 = x, $t1 = y
    
    la $a0, string # printf("Enter a number: ");
    li $v0, 4
    syscall
    
    li $v0, 5   # scanf("%d", &x);
    syscall     # $v0 = x
    
    move $t0, $v0 # $t0 = x
    
    mul $t1, $t0, $t0 # y = x * x;
 
bp_1:
    move $a0, $t1 # printf("%d\n", y);
    li $v0, 1
    syscall 
    
    li $a0, '\n'
    li $v0, 11
    syscall
    
    li $v0, 0 # return 0;
    jr $ra
    
    .data
string:
    .asciiz "Enter a number: "
