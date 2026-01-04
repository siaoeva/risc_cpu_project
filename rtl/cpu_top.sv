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

    //IF
    logic [31:0] instr;

    instr_mem imem (
        .addr   (pc[9:2]), // upper bits are for expansion, imem is only 256 instructions, selectable with 8 bits
        .instr  (instr)
    );

    //ID
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;
    logic [4:0] rs1, rs2, rd;

    assign opcode   = instr[6:0];
    assign rd       = instr[11:7];
    assign funct3   = instr[14:12];
    assign rs1      = instr[19:15];
    assign rs2      = instr[24:20];
    assign funct7   = instr[31:25]; 

    logic               reg_write;
    logic               mem_write;
    logic               mem_to_reg; 
    logic               alu_src;
    logic               branch;
    cpu_defs::AluOp     alu_op;
    cpu_defs::ImmType   imm_sel;
    
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

    logic [31:0] rs1_data, rs2_data;
    logic [31:0] wb_data;

    regfile rf (
        .clk    (clk),
        .we     (reg_write),
        .rs1    (rs1),
        .rs2    (rs2),
        .rd     (rd),
        .wd     (wb_data),
        .rd1    (rs1_data),
        .rd2    (rs2_data)

    );

    logic [31:0] imm;

    imm_gen immgen(
        .instr  (instr),
        .imm_sel(imm_sel),
        .imm    (imm)
    );

    logic [31:0] alu_b;

    assign alu_b = alu_src ? imm : rs2_data;

    logic [31:0]    alu_result;
    logic           zero;

    alu alu_unit (
        .a      (rs1_data),
        .b      (alu_b),
        .alu_op (alu_op),
        .result (alu_result),
        .zero   (zero) // ask how to implement in alu
    );

    logic [31:0] mem_data;

    data_mem dmem (
        .clk    (clk),
        .we     (mem_write),
        .addr   (alu_result[9:2]),
        .wdata  (rs2_data),
        .rdata  (mem_data)
    );

    logic [31:0] load_data;

    load_unit load_u (
        .mem_data   (mem_data),
        .addr       (alu_result[1:0]),
        .funct3     (funct3),
        .load_data  (load_data)
    );

    assign wb_data = mem_to_reg ? load_data : alu_result;

    logic take_branch; 

    branch_unit branch_u (
        .branch     (branch),
        .funct3     (funct3),
        .zero       (zero),
        .alu_lt     (alu_result[0]), // for SLT/SLTU
        .take_branch(take_branch)
    );

    assign pc_next = take_branch ? (pc + imm) : (pc + 32'd4);




endmodule