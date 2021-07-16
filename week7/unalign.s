        .data
something:
        .word 0
        .text
main:
        li      $t1, 1
        lw      $t0, something($t1)     # something + 1
