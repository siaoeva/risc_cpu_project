//cpu_defs.sv
//enum definitions
`timescale 1ns/1ps
package cpu_defs;

    //ALU op codes
    typedef enum logic[3:0] { 
        ALU_ADD = 4'b0000,
        ALU_SUB = 4'b0001,

        ALU_AND = 4'b0010,
        ALU_OR = 4'b0011,
        ALU_XOR = 4'b0100,

        ALU_SLL = 4'b0101, 
        ALU_SRL = 4'b0110,
        ALU_SRA = 4'b0111,

        ALU_SLT = 4'b1000,
        ALU_SLTU = 4'b1001,

        ALU_ILLEGAL = 4'b1111
    } AluOp;

    //Immediate types
    typedef enum logic[2:0] {
        IMM_I = 3'd0,
        IMM_S = 3'd1,
        IMM_B = 3'd2,
        IMM_U = 3'd3,
        IMM_J = 3'd4
    } ImmType;

endpackage
