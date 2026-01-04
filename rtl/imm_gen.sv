//imm_gen.sv
//immediate generator for instruction types I, S, B, U, J, sign-extend and piece together
`timescale 1ns/1ps


module imm_gen(
    input   logic[31:0]         instr,
    input   cpu_defs::ImmType   imm_sel,
    output  logic[31:0]         imm

);
    import cpu_defs::*;
    always_comb begin
        case(imm_sel)
            IMM_I: imm = {{20{instr[31]}}, instr[31:20]};                                           //I-type, immediate
            IMM_S: imm = {{20{instr[31]}}, instr[31:25], instr[11:7]};                              //S-type, store
            IMM_B: imm = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};   //B-type, branch
            IMM_U: imm = {instr[31:12], 12'b0};                                                     //U-type, upper
            IMM_J: imm = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0}; //J-type, jump
            default: imm = 32'd0;
        endcase
    end

endmodule
