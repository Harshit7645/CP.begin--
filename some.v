`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.04.2023 00:09:12
// Design Name: 
// Module Name: top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`define WRITE 1
`define HIT 1
`define MISS 0
`define READ 0


module Cache (
    clk,
    rst,
    address,
    data_in,
    data_out,
    hit_counter,
    miss_counter   
);
    input clk;
    input rst;
    input [31:0] address;
    input data_in;
    output data_out;
    output [31:0] hit_counter;
    output [31:0] miss_counter;

    
    reg data_out;
    reg [31:0] hit_counter;
    reg [31:0] miss_counter;

    reg [31:0] mem_add;
    reg c0,c2,c3,c1;
    
    parameter SET = 256;
    parameter ASSO = 4;
    parameter LS = 64;
    parameter DELAY = 8;

    integer i,j,k,a,b,c,d,e;
    integer LRUCtr = 0;
    integer lru_index = 0;

    integer TAG [0:255] [0:3];
    integer LRU [0:255] [0:3];
    //LRU is used to 
    integer Dirty [0:255] [0:3];
    //dirty bit is used to tell the write back instrucn into the memory.
    integer Valid [0:255] [0:3];
    //Valid matrix is used to tell the valid bit of the correspoding set block of the correspodning index
    integer offset;//this is the offset of the currently used instrucn.
    integer index;//this is the index of the currently used instrucn.
    integer Tag;//this is the tag of the currently used instrucn

    integer OTag;
    integer hit;//this is used to check fi there is a hit in the cache or not.
    integer mshr_hit;//this is used to check fi there is a hit in the MSHR or not.
    integer clk_counter;//this is used as a  global counter for the clock cycles.
    integer rindex;//this is the mshr index indicator.
    integer mshr_curr_LRU;//this is the index of the block 0,1,2,3 if there is a 
    integer mshr_currtag;//this variable is used to store the current instruction which is being sent to the MSHR to check diff conditions.
    integer mshr [0:3];//THIS Is the MSHR used to store the miss under miss instructions.
    integer mshr_time [0:3];//this is the clock cycles counter to check if they have already finished their total 8 cycles or not so that other instructions can be moved to the MSHR.
    integer mp;//mp is the MSHR pointer of the index which is going to be moved to the Ccahe Memory
    integer queue [0:199] ;//this is the data structure which we are using to the fetch the instructions if they are not in the MSHR And then fetch them sequentially.
    integer qfront;//this is the variable to denote the front and back of the queue data structure array.
    integer qback;
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i < 256; i = i + 1) begin
                for (j = 0; j < 4; j = j + 1) begin
                    TAG[i][j] <= -1;
                    LRU[i][j] <= 0;
                    Valid[i][j] <= 0;
                    Dirty[i][j] <= 0;
                end
            end
            qfront<=0;
            qback<=0;
            b<=-1;
            a<=-1;
            mshr[0]<=-1;
            mshr[1]<=-1;
            mshr[2]<=-1;
            mshr[3]<=-1;
            hit_counter <= 0;
            miss_counter <= 0;
            mshr_time[0]<=-1;
            mshr_time[1]<=-1;
            mshr_time[2]<=-1;
            mshr_time[3]<=-1;
            clk_counter<=0;
            hit<=0;
            mshr_hit<=0;
            mp<=0;      
            //above is the MSHR initiailisation stage.   
        end 
        else 
        begin
            Tag <= (address / LS) / SET;
            index <= (address / LS) % SET;
            offset <= address % LS;
            #1;
            //the below stages are used to check all the blocks if the tag we are searching for is currently present or not.
            // if hit
            c0 <= (TAG[index][0] == Tag) ? 1 : 0;
            c1 <= (TAG[index][1] == Tag) ? 1 : 0;
            c2 <= (TAG[index][2] == Tag) ? 1 : 0;
            c3 <= (TAG[index][3] == Tag) ? 1 : 0;
            if(c0)
                a<=0; 
                else if(c1) 
                a<=1; 
                else if(c2) 
                a<=2;
                else if (c3)
                a<=3;
                else 
                a<=-1;
                //in the above code a gives us the block index of the block which is giving us a hit.
            #1;           
             if (a!=-1 && Valid[index][a] ) begin
                 hit_counter <= hit_counter + 1;
                 LRU[index][a] <= LRUCtr;
                 LRUCtr <= LRUCtr + 1;
                 if (data_in == `WRITE)
                     Dirty[index][a] <= 1;
                 data_out <= `HIT;
                 hit<=1;
             end   
             //the above code assigns the LRU[index][a] the corresponding LRU counter value if there is the hit situation for the cache memory block.   
            #1;
            if(!hit) begin
                begin
                    mshr_currtag <=(mshr[0]/LS)/SET;
                    #1;
                    if(!mshr_hit && mshr[0]!= -1 && (mshr_currtag == Tag)) 
                    begin
                        mshr_hit<= 1;
                        miss_counter <= miss_counter +1;
                        #1;
                        data_out <= `MISS;
                    end
                    #1;
                end
                    //the above code checks if there is a miss in the code.    
                begin
                    mshr_currtag <=(mshr[1]/LS)/SET;
                    #1;
                    if(!mshr_hit && mshr[1]!= -1 && (mshr_currtag == Tag)) 
                    begin
                    miss_counter <= miss_counter +1;
                        mshr_hit<= 1;
                        #1;
                        data_out <= `MISS;
                    end
                    #1;
                end
                        
                begin
                    mshr_currtag <=(mshr[2]/LS)/SET;
                    #1;
                    if(!mshr_hit && mshr[2]!= -1 && (mshr_currtag == Tag) ) 
                    begin
                        mshr_hit<= 1;
                        miss_counter <= miss_counter +1;
                        #1;
                        data_out <= `MISS;
                    end
                    #1;
                end
                        
                begin
                    mshr_currtag <=(mshr[3]/LS)/SET;
                    #1;
                    if(!mshr_hit && mshr[3]!= -1 && (mshr_currtag == Tag) ) 
                    begin
                        mshr_hit<= 1;
                        miss_counter <= miss_counter +1;
                        #1;
                        data_out <= `MISS;
                    end
                end
            end

            #1;
            if(!hit && !mshr_hit) begin
                // miss
                miss_counter <= miss_counter + 1;
                if(mshr[mp] == -1) begin
                    mshr[mp] <=address;
                    mshr_time[mp] <= clk_counter;
                    mp<=(mp+1)%4;                   
                end
                else 
                begin
                    queue[qback] <= address;
                    qback<=(qback+1)%200;                   
                end
                data_out <= `MISS;               
            end
            begin
                if(mshr_time[0] + DELAY == clk_counter )
                begin
                    b <= 0;
                end 
                if(mshr_time[1] + DELAY == clk_counter )
                begin
                    b <= 1;
                end
                if(mshr_time[2] + DELAY == clk_counter )
                begin
                    b <= 2;
                end 
                if(mshr_time[3] + DELAY == clk_counter )
                begin
                    b <= 3;
                end
            end
            #1;
            if(b!=-1)
             begin
                mem_add<=mshr[b];
                rindex<=(mshr[b]/LS)%SET;
                mshr_currtag <=(mshr[b]/LS)/SET;
                mshr_curr_LRU <= 0;
                #1;
                if (LRU[rindex][1] < LRU[rindex][mshr_curr_LRU]) begin
                        mshr_curr_LRU <= k;
                    end
                    #1;
                if (LRU[rindex][2] < LRU[rindex][mshr_curr_LRU]) begin
                        mshr_curr_LRU <= k;
                    end
                    #1;
                if (LRU[rindex][3] < LRU[rindex][mshr_curr_LRU]) begin
                        mshr_curr_LRU <= k;
                    end
                    #1;

                if(Dirty[rindex][mshr_curr_LRU]) begin
                    OTag <= TAG[rindex][mshr_curr_LRU]; // Writeback the Data to memory
                    mem_add<= ((OTag << SET) + (rindex) << LS);
                    Dirty[rindex][mshr_curr_LRU] <= 0;
                end
                TAG[rindex][mshr_curr_LRU] <= mshr_currtag;
                Valid[rindex][mshr_curr_LRU] <= 1;
                LRU[rindex][mshr_curr_LRU] <= LRUCtr;
                mshr[b]<=-1;
                LRUCtr <= LRUCtr + 1;
                if(qfront != qback)begin // adding from queue
                    mshr[b] = queue[qfront];
                    #1;
                    mshr_time[b]<=clk_counter;
                    qfront<=qfront+1;
                end
                else begin
                    mshr_time[b]<=-1;
                end
            end
            #1;
            mshr_hit=0;
            clk_counter<=clk_counter+2;
            hit=0;
            b<=-1;
       end       
    end
    
endmodule