//instr_mem.sv
`timescale 1ns/1ps
module instr_mem(
    input   logic[7:0]  addr, //8 bit address to select instruction
    output  logic[31:0] instr //instruction at addr
) 
    //256 x 32-bit instruction memory (imem)
    logic[31:0] imem [0:255];

    //load hexadecimal program at start of simulation into imem
    initial begin
        $readmemh("program.hex", imem);
    end

    assign instr = imem[addr]

endmodule
