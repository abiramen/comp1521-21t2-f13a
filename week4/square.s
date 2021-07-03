    .text
main:
    # $t0 = x, $t1 = y
    
    la          $a0, string     # printf("Enter a number: ");
    li          $v0, 4
    syscall
    
    li          $v0, 5          # scanf("%d", &x);
    syscall                     
    move        $t0, $v0        # Store x in t0
    
    mul         $t1, $t0, $t0   # y = x * x;
        
    move        $a0, $t1        # printf("%d", y);
    li $v0, 1
    syscall 
    
    li $a0, '\n'                # printf("\n")
    li $v0, 11
    syscall
    
    li $v0, 0                   # return 0;
    jr $ra
    
    .data
string:
    .asciiz "Enter a number: "
