//cpu_top.sv

`timescale 1ns/1ps

module cpu_top(
    input logic clk,
    input logic reset
);
    import cpu_defs::*;

    //PC, tracks address of instruction
    logic [31:0] pc;
    logic [31:0] pc_next;

    always_ff @(posedge clk) begin
        if (reset)
            pc <= 32'b0;
        else
            pc <= pc_next;
    end

    //IF, instruction fetch
    logic [31:0] instr;

    instr_mem imem (
        .addr   (pc[9:2]), // upper bits are for expansion, imem is only 256 instructions, selectable with 8 bits. [9:2] because pc is byte addressable, but imem is in words. pc/4 is equal to right shifting by 2 in binary
        .instr  (instr) // fetched instruction from pc address
    );

    //ID, instruction decode
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;
    logic [4:0] rs1, rs2, rd;

    //based on established conventions
    assign opcode   = instr[6:0];
    assign rd       = instr[11:7];
    assign funct3   = instr[14:12];
    assign rs1      = instr[19:15];
    assign rs2      = instr[24:20];
    assign funct7   = instr[31:25]; 


    logic               reg_write; // write enable for regfile.sv
    logic               mem_write; // we for data_mem.sv
    logic               mem_to_reg; // whether writeback uses loaded memory (1) or alu result (0), used in wb mux
    logic               alu_src; // use rs1 (0) or imm (1) as alu_b, in alu.sv
    logic               branch; // if it's a branch instruction, used in branch_unit.sv
    cpu_defs::AluOp     alu_op; // which operation for alu.sv
    cpu_defs::ImmType   imm_sel; // which instr type to generate immediates for imm_gen.sv
    
    control control_unit (
        .opcode     (opcode),
        .funct3     (funct3),
        .funct7     (funct7),
        .alu_op     (alu_op),
        .reg_write  (reg_write),
        .mem_write  (mem_write),
        .branch     (branch),
        .alu_src    (alu_src),
        .imm_sel    (imm_sel),
        .mem_to_reg (mem_to_reg)
    );

    logic [31:0] rs1_data, rs2_data; // read data from 2 registers
    logic [31:0] wb_data; // writeback data read from register

    regfile rf (
        .clk    (clk),
        .we     (reg_write),
        .rs1    (rs1),
        .rs2    (rs2),
        .rd     (rd),
        .wdata  (wb_data),
        .rd1    (rs1_data),
        .rd2    (rs2_data)

    );

    logic [31:0] imm; // immediate

    imm_gen immgen(
        .instr  (instr),
        .imm_sel(imm_sel),
        .imm    (imm)
    );

    //EX, execute
    logic [31:0] alu_b; // second input to alu

    assign alu_b = alu_src ? imm : rs2_data;

    logic [31:0]    alu_result; 
    logic           zero; // zero flag, is the alu_result 0? used by branch_unit.sv

    alu alu_unit (
        .a      (rs1_data),
        .b      (alu_b),
        .alu_op (alu_op),
        .result (alu_result),
        .zero   (zero)
    );

    logic take_branch; // whether to take branch or increment as usual for PC

    branch_unit branch_u (
        .branch     (branch),
        .funct3     (funct3),
        .zero       (zero),
        .alu_lt     (alu_result[0]), // for SLT/SLTU
        .take_branch(take_branch)
    );

    //MEM, data memory access
    logic [31:0] mem_data; // data read from data memory

    data_mem dmem (
        .clk    (clk),
        .we     (mem_write),
        .addr   (alu_result[9:2]),
        .wdata  (rs2_data),
        .rdata  (mem_data)
    );

    logic [31:0] load_data; // loaded data given address from ALU and formatted according to funct3

    load_unit load_u (
        .mem_data   (mem_data),
        .addr       (alu_result[1:0]),
        .funct3     (funct3),
        .load_data  (load_data)
    );

    // WB, writeback
    assign wb_data = mem_to_reg ? load_data : alu_result;

    //IF, instruction fetch, looping back 
    assign pc_next = take_branch ? (pc + imm) : (pc + 32'd4);




endmodule