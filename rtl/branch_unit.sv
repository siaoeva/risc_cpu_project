//branch_unit.sv

`timescale 1ns/1ps

module branch_unit (
    input  logic        branch,
    input  logic [2:0]  funct3,
    input  logic        zero, // ALU zero flag: did the ALU compute rs1 - rs2 = 0?
    input  logic        alu_lt, // SLT/SLTU result
    output logic        take_branch
);

    always_comb begin
        take_branch = 1'b0;

        if(branch) begin
            case(funct3)
                3'b000: take_branch = zero; //BEQ
                3'b001: take_branch = !zero; //BNE
                3'b100: take_branch = alu_lt; //BLT
                3'b101: take_branch = !alu_lt; //BGE
                3'b110: take_branch = alu_lt; //BLTU
                3'b111: take_branch = !alu_lt; //BGEU
            endcase
        end
    end
endmodule
