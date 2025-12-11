//regfile.sv
//register file, async reads and sync writes to register
`timescale 1ns/1ps
module regfile(
    input   logic           clk, // system clock
    input   logic           we, // write enable
    input   logic [4:0]     rs1, // register source 1
    input   logic [4:0]     rs2, 
    input   logic [4:0]     rd, // register destination
    input   logic [31:0]    wdata, // data to write

    output  logic [31:0]    rs1_data, // data from rs1
    output  logic [31:0]    rs2_data
);
    // 32 x 32-bit registers
    logic [31:0] regs [31:0];

    // async reads
    assign rs1_data = (rs1 == 0) ? 32'd0 : regs[rs1];
    assign rs2_data = (rs2 == 0) ? 32'd0 : regs[rs2];

    //sync writes
    always_ff @(posedge clk) begin 
        if (we && rd != 0)
            regs[rd] <= wdata;
    end

endmodule
