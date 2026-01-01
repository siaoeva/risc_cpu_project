//load_unit.sv

module load_unit(
    input  logic [31:0] mem_data,
    input  logic [1:0]  addr, // lower 2 bits of address, selects which byte within a 32-bit word is wanted
    input  logic [2:0]  funct3,
    output logic [31:0] load_data
);

always_comb begin
    case(funct3)
        3'b010: load_data = mem_data; //LW, load word, load full 32-bit, no extension needed

        3'b000: begin //LB, load byte
            case(addr) // which byte within the word is wanted
                2'b00: load_data = {{24{mem_data[7]}}, mem_data[7:0]}; // read byte 0 (least significant byte), sign extend it to 32 bits
                2'b01: load_data = {{24{mem_data[15]}}, mem_data[15:8]};
                2'b10: load_data = {{24{mem_data[23]}}, mem_data[23:16]};
                2'b11: load_data = {{24{mem_data[31]}}, mem_data[31:24]};
            endcase
        end
        3'b001: begin //LH, load halfword
            if (addr[1] == 1'b0) // only addr[1] is used to address halfwords
                load_data = {{16{mem_data[15]}}, mem_data[15:0]}; //read least significant half, sign extend
            else
                load_data = {{16{mem_data[31]}}, mem_data[31:16]};
        end
        3'b100: begin //LBU, load byte unsigned
            case(addr)
                2'b00: load_data = {24'b0, mem_data[7:0]}; // read byte 0 (least significant byte), zero extend it to 32 bits
                2'b01: load_data = {24'b0, mem_data[15:8]};
                2'b10: load_data = {24'b0, mem_data[23:16]};
                2'b11: load_data = {24'b0, mem_data[31:24]};
            endcase
        end
        3'b101: begin //LHU
            if (addr[1] == 1'b0)
                load_data = {16'b0, mem_data[15:0]}; //read least significant half, zero extend
            else
                load_data = {16'b0, mem_data[31:16]};
        end

    endcase
end

endmodule
