module Processor (
    input clk,
    input [31:0] instrucn,
    input write_enable,
    output reg out,
    output reg [31:0] read_counter,
    output reg [31:0] write_counter,
    output reg [31:0] page_hit_counter,
    output reg [31:0] page_miss_counter
); 
    initial 
    begin
        page_hit_counter<=0;
        page_miss_counter<=0;
        read_counter<=0;
        write_counter<=0;
    end
    Memory_Controller mc(clk,instrucn,write_enable,out,page_hit_counter,page_miss_counter);
endmodule

