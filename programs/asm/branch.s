# branch.s — test branches
.section .text
.global _start

_start:
    addi x1, x0, 5          # x1 = 5
    addi x2, x0, 5          # x2 = 5
    addi x3, x0, 10         # x3 = 10

    # BEQ: should branch to label_beq
    beq x1, x2, label_beq   # if x1 == x2 (5 == 5, true), take branch label_beq
    addi x4, x0, 0          # x4 = 0, should be skipped if branch taken

label_beq:
    addi x4, x0, 1          # x4 = 1, executed if branch taken

    # BNE: should branch to label_bne
    bne x1, x3, label_bne   # if x1 != x3 (5 != 10, true), take branch label_bne
    addi x5, x0, 0          # x5 = 0, should be skipped if branch taken

label_bne:
    addi x5, x0, 1          # x5 = 1, executed if branch taken

    # BLT / BGE s
    blt x1, x3, label_blt   # if x1 < x3 (5 < 10, true), take label_blt
    addi x6, x0, 0          # x6 = 0, should be skipped if branch taken

label_blt:
    addi x6, x0, 1          # x6 = 1, executed if branch taken

    bge x3, x1, label_bge   # if x3 >= x1 (10 >= 5), take branch label_bge
    addi x7, x0, 0          # x7 = 0, should be skipped if branch taken
label_bge:
    addi x7, x0, 1          # x7 = 1, executed if branch taken
    beq x1, x3, label_beq_f # if x1 == x3 (5 == 10, false), take branch label_beq_f
    addi x8, x0, 0          # x8 = 0, should be skipped if branch taken
label_beq_f:
    addi x6, x0, 1          # x8 = 1, executed if branch taken

end:
    jal x0, end             # stay at end
    