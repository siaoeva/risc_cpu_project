# branch.s — test branches
.section .text
.global _start

_start:
    addi x1, x0, 5
    addi x2, x0, 5
    addi x3, x0, 10

    # BEQ: should branch to label_beq
    beq x1, x2, label_beq
    addi x4, x0, 0        # skipped if branch taken
label_beq:
    addi x4, x0, 1        # executed if branch taken

    # BNE: should branch to label_bne
    bne x1, x3, label_bne
    addi x5, x0, 0        # skipped if branch taken
label_bne:
    addi x5, x0, 1

    # BLT / BGE
    blt x1, x3, label_blt
    addi x6, x0, 0
label_blt:
    addi x6, x0, 1

    bge x3, x1, label_bge
    addi x7, x0, 0
label_bge:
    addi x7, x0, 1

    jal x0, _start        # infinite loop
