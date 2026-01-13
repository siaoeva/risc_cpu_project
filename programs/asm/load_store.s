# load_store.s — test LW, SW, LB, LBU, LH, LHU
.section .text
.global _start

_start:

    # store test data for basic sw, lw
    addi x1, x0, 0         # x1 = 0, base address
    addi x2, x0, 42        # x2 = 42, value to store

    # base test
    sw x2, 0(x1)           # store word at x2(42) at address 0
    lw x3, 0(x1)           # load from address 0 into x3 (should be 42)

    addi x4, x3, 1         # x4 = x3 + 1 (should be 43)

    # store test data for byte, halfword loads
    # data = 0x80FF7F01
    lui  x5, 0x80FF8       # upper 20 bits
    addi x5, x5, -255      # x5 = 0x80FF7F01
    sw   x5, 4(x1)         # store pattern at address 4

    # LB, LBU
    lb   x6,  4(x1)        # 0x01  -> 1
    lbu  x7,  4(x1)        # 0x01  -> 1

    lb   x8,  6(x1)        # 0xFF  -> -1 (0xFFFFFFFF)
    lbu  x9, 6(x1)        # 0xFF  -> 255

    #LH, LHU
    lh   x10, 4(x1)        # 0x7F01 -> +32513
    lhu  x11, 4(x1)        # 0x7F01 -> 32513

    lh   x12, 6(x1)        # 0x80FF -> negative
    lhu  x13, 6(x1)        # 0x80FF -> 33023

end:
    jal x0, end             # stay at end
    