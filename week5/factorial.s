################################################################################
# COMP1521 21T2 fri13a
# Compute a factorial in MIPS assembly
# Abiram Nadarajah, July 2021

################################################################################
# .data
        .data
exclamation:
        .asciiz "! = "                  # needed to print 5! = 120, for example.
################################################################################
# .text <main>
        .text
main:

# Frame:        $ra, $s0
# Uses:         $a0, $s0, $v0
# Clobbers:     $a0, $v0
#
# Callees:
#       - factorial (clobbers ...)
#
# Locals:
#       - 'number'      in $s0
#
# Structure:
#       -> [prologue]
#       -> body
#       -> [epilogue]
#
# Returns:
#       - exit_status   in $v0

main__prologue:
        addi    $sp, $sp, -8            # Set up stack frame
        sw      $ra, 4($sp)
        sw      $s0, 0($sp)

main__body:
        li      $v0, 5                  # scanf("%d", &number)
        syscall                         

        move 	$s0, $v0		# $s0 = number

        move    $a0, $s0		# printf("%d", number)
        li      $v0, 1
        syscall

        la      $a0, exclamation        # printf("! = ");
        li      $v0, 4
        syscall

        # A recap of calling conventions:
        # i (the caller) pass in arguments using registers $a0 to $a3
                # argument registers do not need to preserved by the callee
        # i expect the return value of my function to be in $v0
        # i expect the stack pointer to be the same after the callee is done
        # i also expect the $s0 to $s7 to be the same
                # if callee changes any $s registers,
                # it has to restore their values
        # i cannot expect $t0 to $t9 to be the same 
                # factorial can completely obliterate these registers
                # in fact, i need to assume it's been completely obliterated


        move    $a0, $s0                # Call factorial(number)
        jal     factorial               

        move    $a0, $v0                # printf("%d", factorial(number))
        li      $v0, 1
        syscall

        li      $a0, '\n'               # printf("\n")
        li      $v0, 11
        syscall

main__epilogue:
        lw      $a0, 0($sp)             # Restore from stack
        lw      $ra, 4($sp)
        addi    $sp, $sp, 8

        li $v0, 0                       # return 0;
        jr $ra

################################################################################
# .text <factorial>
        .text
factorial:
# Frame:        $ra, $s0
# Uses:         $s0, $a0, $v0
# Clobbers:     $a0, $v0
#
# Arguments:
#       - n             in $a0
#
# Callees:
#       - factorial (clobbers ...)
#
# Locals:
#       - 'number'      in $s0
#
# Structure:
#       -> [prologue]
#       -> body
#       -> [epilogue]
#
# Returns:
#       - exit_status   in $v0

factorial__prologue:
        addi    $sp, $sp, -12                   # Set up stack frame
        sw      $ra, 4($sp)		
        sw      $s0, 0($sp)

factorial__body:
        ble     $a0, 0, factorial__base         # if n <= 0 goto factorial_base;
        
factorial__mul:
        move 	$s0, $a0		        # factorial(n-1)
        addi    $a0, $a0, -1
        jal     factorial

        mul     $v0, $v0, $s0                   # return n * factorial(n-1)
        j	factorial__epilogue             

factorial__base:
        li      $v0, 1                          # return 1;

factorial__epilogue:
        lw      $s0, 0($sp)                     # restore stack
        lw      $ra, 4($sp)
        addi    $sp, $sp, 8
        jr      $ra
