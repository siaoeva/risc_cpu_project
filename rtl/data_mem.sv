//data_mem.sv

`timescale 1ns/1ps

module data_mem (
    input  logic        clk,
    input  logic        we, // write enable (mem_write)
    input  logic [31:0] addr, // byte address from alu
    input  logic [31:0] wdata, // write data (rs2)
    output logic [31:0] rdata // read data
);

    // 256 x 32-bit data memory
    logic [31:0] dmem [0:255];

    //word-aligned address
    logic [7:0] word-addr;
    assign word_addr = addr[9:2];

    //sync write
    always_ff @(posedge clk) begin
        if (we) begin
            dmem[word_addr] <= wdata;
        end
    end

    //async read
    assign rdata = dmem[word_addr];

endmodule
