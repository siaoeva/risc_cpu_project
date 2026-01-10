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
    lui  x6, 0x80FF8       # upper 20 bits
    addi x6, x6, -255      # x6 = 0x80FF7F01
    sw   x6, 4(x1)         # store pattern at address 4

    # LB, LBU
    lb   x7,  4(x1)        # 0x01  -> 1
    lbu  x8,  4(x1)        # 0x01  -> 1

    lb   x9,  6(x1)        # 0xFF  -> -1 (0xFFFFFFFF)
    lbu  x10, 6(x1)        # 0xFF  -> 255

    #LH, LHU
    lh   x11, 4(x1)        # 0x7F01 -> +32513
    lhu  x12, 4(x1)        # 0x7F01 -> 32513

    lh   x13, 6(x1)        # 0x80FF -> negative
    lhu  x14, 6(x1)        # 0x80FF -> 33023

    # set signature base address for result storage
    lui x5, 0x80001        # x5 = 0x80001000, signature base address

    # store results from registers into memory

    sw x3,   0(x5)         # LW result (42)
    sw x4,   4(x5)         # +1 result (43)

    sw x7,   8(x5)         # LB  +1
    sw x8,  12(x5)         # LBU +1

    sw x9,  16(x5)         # LB  -1
    sw x10, 20(x5)         # LBU 255

    sw x11, 24(x5)         # LH  signed
    sw x12, 28(x5)         # LHU unsigned

    sw x13, 32(x5)         # LH  negative
    sw x14, 36(x5)         # LHU unsigned


    jal x0, _start 
