# jump.s — test JAL and JALR
.section .text
.global _start

_start:
    # Test JAL
    addi x1, x0, 0          # x1 = 0 (marker)

    jal  x5, jal_target     # x5 = PC + 4 (return address), PC jumps to jal_target

    addi x1, x0, 99         # x1 = 99, should be skipped by jump

jal_target:
    addi x1, x0, 1          # x1 = 1, should be executed with jump

    # Test JALR

    la   x6, jalr_target    # pseudo-instruction (usually separated into auipc, addi), load address of jalr_target into x6

    jalr x7, x6, 0          # x7 = PC + 4 (return address), PC jumps to PC = x6 + 0 (jalr_target) 

    addi x2, x0, 99         # x2 = 99, should be skipped by jump

jalr_target:
    addi x2, x0, 1          # x2 = 1, should be executed with jump

    # Test JALR with offset

    la   x8, jalr_base      # load address of jalr_base into x8
    addi x8, x8, 4          # x8 = jalr_base + 4

    jalr x9, x8, 0          # x9 = PC + 4 (return address), PC jumps to jalr_base + 4

    addi x3, x0, 99         # x3 = 99, should be skipped by jump

jalr_base:
    nop                     # no operation
jalr_offset_target:
    addi x3, x0, 1          # x3 = 1, should be executed with jump
    
end:
    jal x0, end             # stay at end
