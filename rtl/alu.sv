//alu.sv
//basic arithmetic logic 
`timescale 1ns/1ps

module alu(
    input   logic[31:0] a, b,
    input   cpu_defs::AluOp  alu_op,
    output  logic[31:0] result
);
    import cpu_defs::*;

    always_comb begin : alu_logic
        case(alu_op)
            ALU_ADD: result = a + b; 
            ALU_SUB: result = a - b; 
            ALU_AND: result = a & b; 
            ALU_OR: result = a | b; 
            ALU_XOR: result = a ^ b; 
            ALU_SLL: result = a << b[4:0]; //SLL shift left logical, mask b since a is 32 bit and should only be shifted by max 31 bit
            ALU_SRL: result = a >> b[4:0]; //SRL shift right logical
            ALU_SRA: result = $signed(a) >>> b[4:0] //SRA shift right arithmetic, basically SRL for signed integers
            ALU_SLT: result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0; //SLT set less than (signed) (condition) ? value_if_true : value_if_false
            ALU_SLTU: result = (a < b) ? 32'd1 : 32'd0; //SLT set less than unsigned
            default: result = 32'd0; 
        endcase
    end

endmodule
