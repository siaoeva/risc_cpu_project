//control.sv

`timescale 1ns/1ps

module control(
    input   logic [6:0]         opcode, //defines type/category of instruction
    input   logic [2:0]         funct3, //further specifies the operation within type provided by opcode
    input   logic [6:0]         funct7, //specifically for R-type ALU operations (and a few others), further differentiates operations

    output  cpu_defs::AluOp     alu_op, //which alu operation to perform for alu.sv
    output  logic               reg_write, //write enable for regfile.sv
    output  logic               mem_write, //write enable for data_mem.sv
    output  logic               branch, //whether it's a branch instruction 
    output  logic               alu_src, //controls alu's 2nd operand, 0 = use rs2, 1 = use immediate
    output  cpu_defs::ImmType   imm_sel, //which instruction type to correctly extract immediate
    output  logic               mem_to_reg // 0 if writing ALU result, 1 if writing mem load data to reg
);
    import cpu_defs::*;

    always_comb begin : control_logic
        //default
        alu_op      = ALU_ILLEGAL;
        reg_write   = 0;
        mem_write   = 0;
        branch      = 0;
        alu_src     = 0;
        imm_sel     = IMM_ILLEGAL;
        mem_to_reg  = 0;
        
        case(opcode)
            //R-type (ADD, SUB, AND, OR, XOR, etc. )
            7'b0110011: begin 
                reg_write   = 1;
                alu_src     = 0; //use rs2

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

            //I-type ALU (ADDI, ANDI, ORI, etc.)
            7'b0010011: begin
                reg_write   = 1;
                alu_src     = 1; //use immediate
                imm_sel     = IMM_I;

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

            //Load, loads data from dmem to rd
            7'b0000011: begin
                reg_write = 1;
                alu_src = 1; // use immediate for address = base register (rs1) + immediate offset
                alu_op = ALU_ADD; // used for address calculation
                mem_to_reg = 1;

            end

            //Store
            7'b0100011: begin
                mem_write = 1;
                alu_src = 1; // base + offset
                alu_op = ALU_ADD; // address calc
                imm_sel = IMM_S;
            end

            //Branch
            7'b1100011: begin
                branch = 1;
                alu_src = 0; // ALU uses rs2, not immediate
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

            //add U-type, J-type expansion later

        
        endcase
    end

endmodule
