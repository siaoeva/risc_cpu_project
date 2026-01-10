`timescale 1ns/1ps

module tb_cpu();

    logic clk, reset;

    initial begin
        clk <= 1'b1;
        forever #10 clk <= !clk;
    end

    initial begin
        reset <= 1'b1;
        #20
        reset <= 1'b0;
    end

    cpu_top cpu(
        .clk    (clk),
        .reset  (reset)
    );

endmodule
