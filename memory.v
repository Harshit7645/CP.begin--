module Memory (
    input clock,
    input [31:0] instruction,
    input write_enable,
    output reg mem_request, 
    input m_grant, 
    output reg [31:0] data,
    output reg [31:0] page_hit_counter,
    output reg [31:0] page_miss_counter
);

    integer BASR[0:1][0:1][0:9];
    integer Row_buffer[0:255];
    reg [25:0] mem_address;
    reg BASR_isempty [0:1][0:9];
    integer bank_index;
    integer instrucn_last18;
    integer row;
    integer clk_counter;
    integer delay;
    integer channel;
    integer i;
    integer index;

    initial 
    begin 
        clk_counter<=0;
        page_miss_counter<=0;
        page_hit_counter<=0;
        BASR_isempty[0][0] = 1;
        BASR_isempty[0][1] = 1;
        BASR_isempty[0][2] = 1;
        BASR_isempty[0][3] = 1;
        BASR_isempty[0][4] = 1;
        BASR_isempty[0][5] = 1;
        BASR_isempty[0][6] = 1;
        BASR_isempty[0][7] = 1;
        BASR_isempty[0][8] = 1;
        BASR_isempty[0][9] = 1;
        BASR_isempty[1][0] = 1;
        BASR_isempty[1][1] = 1;
        BASR_isempty[1][2] = 1;
        BASR_isempty[1][3] = 1;
        BASR_isempty[1][4] = 1;
        BASR_isempty[1][5] = 1;
        BASR_isempty[1][6] = 1;
        BASR_isempty[1][7] = 1;
        BASR_isempty[1][8] = 1;
        BASR_isempty[1][9] = 1;
        for (i = 0; i < 256; i = i + 1) 
        begin
            Row_buffer[i] <=-1;
        end
    end

    always@(posedge clock) 
    begin
        mem_request<=0;
        #1;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(BASR[0][1][0] == clk_counter)
        begin
            BASR_isempty[0][0] <= 1;
            mem_request <= 1;
            BASR[0][1][0] <=0;
            data <= BASR[0][0][0];
        end
        if(BASR[0][1][1] == clk_counter)
        begin
            BASR_isempty[0][1] <= 1;
            mem_request <= 1;
            BASR[0][1][1] <=0;
            data <= BASR[0][0][1];
        end
        if(BASR[0][1][2] == clk_counter)
        begin
            BASR_isempty[0][2] <= 1;
            mem_request <= 1;
            BASR[0][1][2] <=0;
            data <= BASR[0][0][2];
        end
        if(BASR[0][1][3] == clk_counter)
        begin
            BASR_isempty[0][3] <= 1;
            mem_request <= 1;
            BASR[0][1][3] <=0;
            data <= BASR[0][0][3]; 
        end
        if(BASR[0][1][4] == clk_counter)
        begin
            BASR_isempty[0][4] <= 1;
            mem_request <= 1;
            BASR[0][1][4] <=0;
            data <= BASR[0][0][4];
        end
        if(BASR[0][1][5] == clk_counter)
        begin
            BASR_isempty[0][5] <= 1;
            mem_request <= 1;
            BASR[0][1][5] <=0;
            data <= BASR[0][0][5]; 
        end
        if(BASR[0][1][6] == clk_counter)
        begin
            BASR_isempty[0][6] <= 1;
            mem_request <= 1;
            BASR[0][1][6] <=0;
            data <= BASR[0][0][6];
        end
        if(BASR[0][1][7] == clk_counter)
        begin
            BASR_isempty[0][7] <= 1;
            mem_request <= 1;
            BASR[0][1][7] <=0;
            data <= BASR[0][0][7]; 
        end
        if(BASR[0][1][8] == clk_counter)
        begin
            BASR_isempty[0][8] <= 1;
            mem_request <= 1;
            BASR[0][1][8] <=0;
            data <= BASR[0][0][8];
        end
        if(BASR[0][1][9] == clk_counter)
        begin
            BASR_isempty[0][9] <= 1;
            mem_request <= 1;
            BASR[0][1][9] <=0;
            data <= BASR[0][0][9]; 
        end        
        if(BASR[1][1][0] == clk_counter)
        begin
            BASR_isempty[1][0] <= 1;
            mem_request <= 1;
            BASR[1][1][0] <=0;
            data <= BASR[1][0][0];
        end
        if(BASR[1][1][1] == clk_counter)
        begin
            BASR_isempty[1][1] <= 1;
            mem_request <= 1;
            BASR[1][1][1] <=0;
            data <= BASR[1][0][1]; 
        end
        if(BASR[1][1][2] == clk_counter)
        begin
            BASR_isempty[1][2] <= 1;
            mem_request <= 1;
            BASR[1][1][2] <=0;
            data <= BASR[1][0][2];
        end
        if(BASR[1][1][3] == clk_counter)
        begin
            BASR_isempty[1][3] <= 1;
            mem_request <= 1;
            BASR[1][1][3] <=0;
            data <= BASR[1][0][3]; 
        end
        if(BASR[1][1][4] == clk_counter)
        begin
            BASR_isempty[1][4] <= 1;
            mem_request <= 1;
            BASR[1][1][4] <=0;
            data <= BASR[1][0][4];
        end
        if(BASR[1][1][5] == clk_counter)
        begin
            BASR_isempty[1][5] <= 1;
            mem_request <= 1;
            BASR[1][1][5] <=0;
            data <= BASR[1][0][5]; 
        end
        if(BASR[1][1][6] == clk_counter)
        begin
            BASR_isempty[1][6] <= 1;
            mem_request <= 1;
            BASR[1][1][6] <=0;
            data <= BASR[1][0][6];
        end
        if(BASR[1][1][7] == clk_counter)
        begin
            BASR_isempty[1][7] <= 1;
            mem_request <= 1;
            BASR[1][1][7] <=0;
            data <= BASR[1][0][7]; 
        end
        if(BASR[1][1][8] == clk_counter)
        begin
            BASR_isempty[1][8] <= 1;
            mem_request <= 1;
            BASR[1][1][8] <=0;
            data <= BASR[1][0][8];
        end
        if(BASR[1][1][9] == clk_counter)
        begin
            BASR_isempty[1][9] <= 1;
            mem_request <= 1;
            BASR[1][1][9] <=0;
            data <= BASR[1][0][9]; 
        end


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(m_grant == 1)  
        begin
            mem_address <= instruction[25:0];
            bank_index <= mem_address/262144;
            #1;
            instrucn_last18 <= mem_address % 262144;
            row <= (mem_address % 262144) / 1024;
            channel <=mem_address[25];
            #1; 
            if(Row_buffer[bank_index] == -1)
            begin 
                page_miss_counter<=page_miss_counter+1;
                Row_buffer[bank_index] <=row;
                delay<=16;
            end
            else if(Row_buffer[bank_index] == row)
            begin 
                page_hit_counter<=page_hit_counter+1;
                delay<=12;
            end
            else 
            begin
                page_miss_counter<=page_miss_counter+1;
                Row_buffer[bank_index] <=row;
                delay<=18;
            end
            #1;
            if(BASR_isempty[channel][0] == 1) 
            begin 
                index<=0;
            end
            else if(BASR_isempty[channel][1] == 1) 
            begin 
                    index<=1;
            end
            else if(BASR_isempty[channel][2] == 1) 
            begin 
                index<=2;
            end
            else if(BASR_isempty[channel][3] == 1) 
            begin 
                index<=3;
            end
            else if(BASR_isempty[channel][4] == 1) 
            begin 
                index<=4;
            end
            else if(BASR_isempty[channel][5] == 1) 
            begin 
                index<=5;
            end
            else if(BASR_isempty[channel][6] == 1) 
            begin 
                index<=6;
            end
            else if(BASR_isempty[channel][7] == 1) 
            begin 
                index<=7;
            end
            else if(BASR_isempty[channel][8] == 1) 
            begin 
                index<=8;
            end
            else if(BASR_isempty[channel][9] == 1) 
            begin 
                index<=9;
            end
            else 
            begin 
                index<=-1;
            end                               
            #1;
            if(index !=-1)
            begin 
                BASR[channel][1][index] = delay;
                BASR[channel][1][index] =BASR[channel][1][index] + clk_counter;
                BASR[channel][0][index] = instruction;
                BASR_isempty[channel][index] <= 0;
                #1;
            end                          
        end
        #1;       
        clk_counter<=clk_counter+1;       
    end
endmodule
