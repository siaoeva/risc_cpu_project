//tb_alu.sv
//testbench for alu.sv

`timescale 1ns/1ps //time unit/time precision

module tb_alu;

    //inputs
    logic[31:0] a, b;
    cpu_defs::AluOp       alu_op;

    //output
    logic[31:0] result;

    //instantiate alu
    alu uut (
        .a(a),
        .b(b),
        .alu_op(alu_op),
        .result(result)
    );

    import cpu_defs::*;

    

    initial begin
        $dumpfile("tb_alu.vcd"); //name output vcd
        $dumpvars(0, tb_alu); //dump everything recursively
    end

    //testing 
    initial begin
        $display("=== ALU Unit Test ===");
        a = 10; b = 5; 

        alu_op = ALU_ADD;
        #1;
        $display("ADD: %0d + %0d = %0d", a, b, result);

        alu_op = ALU_SUB;
        #1;
        $display("SUB: %0d - %0d = %0d", a, b, result);

        alu_op = ALU_AND;
        #1;
        $display("AND: b%04b & b%04b = b%04b", a, b, result);

        alu_op = ALU_OR;
        #1;
        $display("OR: b%04b | b%04b = b%04b", a, b, result);

        alu_op = ALU_XOR;
        #1;
        $display("XOR: b%04b ^ b%04b = b%04b", a, b, result);

        alu_op = ALU_SLL;
        #1;
        $display("SLL: b%04b << %0d = b%04b", a, b[4:0], result);

        alu_op = ALU_SRL;
        #1;
        $display("SRL: b%04b >> %0d = b%04b", a, b[4:0], result);

        a = -5; b = 3; 
        alu_op = ALU_SLT;
        #1;
        $display("SLT: %0d < %0d ? 1:0 = %0d", $signed(a), $signed(b), result);

        a = 32'hFFFFFFFF; b = 1; 
        alu_op = ALU_SLTU;
        #1;
        $display("SLTU: %0d < %0d ? 1:0 = %0d", a, b, result);

        $display("=== ALU Test Complete ===");
        $finish;
    end
endmodule
