# sanity.s 
# simple RV32I test

.section .text          # place the following instructions into the .text section, where executable machine code goes
.global _start          # label _start, visible to the linker, entry point to the program

_start:
    # immediate arithmetic
    addi x1, x0, 5      # x1 = 5
    addi x2, x0, 10     # x2 = 10
    addi x3, x0, -80    # x3 = -80

    # register arithmetic
    add  x4, x1, x2     # x4 = x1 + x2 = 5 + 10 = 15
    sub  x5, x4, x1     # x5 = x4 - x1 = 15 - 5 = 10
    and  x6, x4, x2     # x6 = x4 & x2 = 32'b1111 & 32'b1010 = 32'b1010 = 10
    or   x7, x4, x1     # x7 = x4 | x1 = 32'b1111 | 32'b0101 = 32'b1111 = 15
    xor  x8, x4, x1     # x8 = x4 ^ x1 = 32'b1111 ^ 32'b0101 = 32'b1010 = 10

    # shift operations
    sll  x9, x1, x0     # x9 = x1 << x0 = 5 << 0 = 5
    srl  x10, x2, x1    # x10 = x2 >> x1 = 32'b1010 >> 5 = 32'b0000 = 0
    sra  x11, x3, x1    # x11 = x3 >>> x1 = 32'b10110000 >>> 5 = 32'b11111101 = -3

end:
    jal x0, end             # stay at end
    