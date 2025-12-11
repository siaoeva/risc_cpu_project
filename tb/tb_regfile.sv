//tb_regfile.sv

`timescale 1ns/1ps

module tb_regfile;
    //inputs
    logic           clk; // system clock
    logic           we; // write enable
    logic [4:0]     rs1; // register source 1
    logic [4:0]     rs2; 
    logic [4:0]     rd; // register destination
    logic [31:0]    wdata; // data to write

    //outputs
    logic [31:0]    rs1_data; // data from rs1
    logic [31:0]    rs2_data;

    //instantiate regfile
    regfile uut (
        .clk(clk),
        .we(we),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .wdata(wdata),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data)
    );

    initial begin
        $dumpfile("tb_regfile.vcd"); //name output vcd
        $dumpvars(0, tb_regfile); //dump everything recursively
    end

    //clock generation
    initial clk = 0;
    always #5 clk = ~clk; //changes every 5 ns, 10 ns period

    //testing
    initial begin
        $display("=== Register File Test ===");
        
        rs1 = 1; rs2 = 2; // reading from regs[1] and regs[2]. initially every element in regs is 0
        #1; //wait 1 time unit
        $display("Read x1 = %0d, x2= %0d. Expected x1 = x2 = 0.", rs1_data, rs2_data);

        // write 42 to x1
        rd = 1; wdata = 42; we = 1;
        #10; // wait one full cycle, ensuring a posedge happens
        we = 0; 
        #1;
        $display("After write: x1 = %0d, x2 = %0d. Expected x1 = 42, x2 = 0.", rs1_data, rs2_data);

        //try writing to x0, should remain 0
        rd = 0; wdata = 99; we = 1;
        #10; we = 0;
        #1;
        $display("After write: x0 = %0d. Expected always x0 = 0.", uut.regs[0]);

        //write 5 to x2
        rd = 2; wdata = 5; we = 1;
        #10; we = 0;
        rs1 = 1; rs2 = 2;
        #1;
        $display("After write: x1 = %0d, x2 = %0d. Expected x1 = 42, x2 = 5.", rs1_data, rs2_data);


        $display ("=== Register File Test Complete ===");
        $finish;
    end
endmodule
