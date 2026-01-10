# jump.s — test JAL and JALR
.section .text
.global _start

_start:
    addi x1, x0, 5

    # JAL: jump forward 8 bytes (2 instructions)
    jal x2, label_jal_skip
    addi x3, x0, 0         # skipped
label_jal_skip:
    addi x3, x0, 1         # executed after jump

    # JALR: jump to x4 + offset
    addi x4, x0, 8
    jalr x5, x4, 0         # jump to PC = x4 + 0 (simulate)
    addi x6, x0, 0         # skipped
