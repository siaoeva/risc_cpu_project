//control.sv

`timescale 1ns/1ps

module control(
    input   logic [6:0]         opcode, //defines type/category of instruction
    input   logic [2:0]         funct3, //further specifies the operation within type provided by opcode
    input   logic [6:0]         funct7, //specifically for R-type ALU operations (and a few others), further differentiates operations

    output  logic               reg_write, //write enable for regfile.sv
    output  logic               mem_write, //write enable for data_mem.sv
    
    output  cpu_defs::AluOp     alu_op, //which alu operation to perform for alu.sv
    output  logic               alu_a_pc, // controls alu's 1st operand, 0 = use rs1, 1 = use PC
    output  logic               alu_b_imm, //controls alu's 2nd operand, 0 = use rs2, 1 = use immediate

    output  logic               branch, //whether it's a branch instruction 
    output  logic               jal, //whether it's a jal instruction
    output  logic               jalr, //wheter it's a jalr instruction

    output  cpu_defs::ImmType   imm_sel, //which instruction type to correctly extract immediate
    output  cpu_defs::WbSel     wb_sel //which data to writeback
);
    import cpu_defs::*;

    always_comb begin : control_logic
        //default
        reg_write   = 0;
        mem_write   = 0;
        
        alu_op      = ALU_ILLEGAL;
        alu_a_pc    = 0;
        alu_b_imm   = 0;

        branch      = 0;
        jal         = 0;
        jalr        = 0;

        imm_sel     = IMM_ILLEGAL;
        wb_sel      = WB_ALU;
        
        case(opcode)
            //OP, R-type , operation (ADD, SUB, AND, OR, XOR, etc. )
            7'b0110011: begin 
                reg_write   = 1;
                wb_sel      = WB_ALU;

                case ({funct7, funct3})
                    10'b0000000_000:    alu_op = ALU_ADD;
                    10'b0100000_000:    alu_op = ALU_SUB;

                    10'b0000000_111:    alu_op = ALU_AND;
                    10'b0000000_110:    alu_op = ALU_OR;
                    10'b0000000_100:    alu_op = ALU_XOR;

                    10'b0000000_001:    alu_op = ALU_SLL;
                    10'b0000000_101:    alu_op = ALU_SRL;
                    10'b0100000_101:    alu_op = ALU_SRA;

                    10'b0000000_010:    alu_op = ALU_SLT;
                    10'b0000000_011:    alu_op = ALU_SLTU;

                    default:            alu_op = ALU_ILLEGAL;
                endcase
            end

            //OP-IMM, I-type ALU (ADDI, ANDI, ORI, etc.)
            7'b0010011: begin
                reg_write   = 1;
                alu_b_imm   = 1; //use immediate
                imm_sel     = IMM_I;
                wb_sel      = WB_ALU;

                case (funct3)
                    3'b000:     alu_op = ALU_ADD;

                    3'b111:     alu_op = ALU_AND;
                    3'b110:     alu_op = ALU_OR;
                    3'b100:     alu_op = ALU_XOR;

                    3'b010:     alu_op = ALU_SLT;
                    3'b011:     alu_op = ALU_SLTU;

                    3'b001:     alu_op = ALU_SLL;

                    3'b101: begin
                        if (funct7 == 7'b0000000)
                            alu_op = ALU_SRL;
                        else if (funct7 == 7'b0100000) 
                            alu_op = ALU_SRA;
                    end
                    default: alu_op = ALU_ILLEGAL;
                endcase
            end

            //LOAD, I-type loads data from dmem to rd
            7'b0000011: begin
                reg_write = 1;
                alu_op = ALU_ADD; // used for address calculation
                alu_b_imm = 1; // use immediate for address = base register (rs1) + immediate offset
                imm_sel = IMM_I;
                wb_sel = WB_MEM;

            end

            //STORE, S-type, stores data to dmem
            7'b0100011: begin
                mem_write = 1;
                alu_b_imm = 1; // base + offset
                alu_op = ALU_ADD; // address calc
                imm_sel = IMM_S;
            end

            //BRANCH, B-type
            7'b1100011: begin
                branch = 1;
                alu_b_imm = 0; // ALU uses rs2, not immediate
                imm_sel = IMM_B;
                case(funct3)
                    3'b000: alu_op = ALU_SUB; //BEQ, equal, use sub to determine if two are equal. 
                    3'b001: alu_op = ALU_SUB; //BNE, not equal
                    3'b100: alu_op = ALU_SLT; //BLT, signed less than
                    3'b101: alu_op = ALU_SLT; //BGE, signed greater than or equal, inverted above
                    3'b110: alu_op = ALU_SLTU; //BLTU, unsigned less than
                    3'b111: alu_op = ALU_SLTU; //BGEU, unsigned greather than or equal, inverted above

                    default: alu_op = ALU_ILLEGAL;
                endcase
            end

            //LUI, U-type, load upper immediate
            7'b0110111: begin
                reg_write = 1;
                //alu_b_imm = 1; // select imm
                //alu_op = ALU_ADD;
                wb_sel = WB_IMM;
                imm_sel = IMM_U;
            end

            //AUIPC, U-type, add upper immediate to PC
            7'b0010111: begin
                reg_write = 1;
                alu_b_imm = 1;
                alu_op = ALU_ADD;
                alu_a_pc = 1;
                imm_sel = IMM_U;
                wb_sel = WB_ALU;
            end

            //JAL, J-type, jump and link
            7'b1101111: begin
                reg_write = 1;
                jal = 1;
                wb_sel = WB_PC4;
                imm_sel = IMM_J;
            end

            //JALR, I-type, jump and link register
            7'b1100111: begin
                reg_write = 1;
                jalr = 1;

                alu_op = ALU_ADD;
                alu_b_imm = 1;

                wb_sel = WB_PC4;
                imm_sel = IMM_I;
            end

        
        endcase
    end

endmodule
