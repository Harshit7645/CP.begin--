module Memory_Controller (
    input clock,
    input reset,
    input [31:0] instruction,
    input write_enable, 
    output [31:0] page_hit_counter,
    output [31:0] page_miss_counter
);

    parameter serving_queue_const = 10;
    parameter channelsnum=2;
    wire [31:0] value;
    wire memory_req;
    reg memory_grant;
    reg proc_to_mem;
    reg busy;
    
    integer instrucn_queue[0:5000];
    integer iq_front;
    integer iq_tail;
    integer values_queue[0:serving_queue_const-1];
    integer values_queue_front;
    integer values_queue_tail;
    integer service_queue[0:channelsnum-1][0:serving_queue_const-1];
    integer serv_queue_size;
    integer sq_front;
    integer sq_tail;

    integer bus_clkcounter;
    integer clkcounter;
    integer i;
    integer temp;
    integer addtomem;
    
    Memory mem1(clock,addtomem,write_enable,memory_req,memory_grant,value,page_hit_counter,page_miss_counter);
    
    initial 
    begin 
        iq_front<=0;
        iq_tail<=0;
        values_queue_front<=0;
        values_queue_tail<=0;
        sq_front<=0;
        sq_tail<=0;
        bus_clkcounter<=-1;
        clkcounter<=0;
        busy<=0;
        serv_queue_size<=0;
        service_queue[1][0] =-1;
        service_queue[1][1] =-1;
        service_queue[1][2] =-1;
        service_queue[1][3] =-1;
        service_queue[1][4] =-1;
        service_queue[1][5] =-1;
        service_queue[1][6] =-1;
        service_queue[1][7] =-1;
        service_queue[1][8] =-1;
        service_queue[1][9] =-1;
    end

    always@(posedge clock) 
    begin
        #1;
        $display("clkcounter : %d",clkcounter);
        memory_grant<=0;
        #1;
        // add req
        if(reset)
        begin
            instrucn_queue[iq_tail]<=instruction;
            iq_tail<=iq_tail+1;
            $display("added %d th request %d in rq",iq_tail,instruction);
        end
                
// bus busy
        if(busy) 
        begin 
            $display("bus busy");
            if(bus_clkcounter == 8) 
            begin 
//transfer complete
                if(proc_to_mem)
                begin 
                    temp = i;
                    case (values_queue[values_queue_front]) 
                        service_queue[0][0] : i<= 0;
                        service_queue[0][1] : i<= 1;
                        service_queue[0][2] : i<= 2;
                        service_queue[0][3] : i<= 3;
                        service_queue[0][4] : i<= 4;
                        service_queue[0][5] : i<= 5;
                        service_queue[0][6] : i<= 6;
                        service_queue[0][7] : i<= 7;
                        service_queue[0][8] : i<= 8;
                        service_queue[0][9] : i<= 9;
                    endcase                
                    #1;
                    service_queue[1][temp] <=0;
                    values_queue[values_queue_front] <=0;
                    values_queue_front<=(values_queue_front+1)%serving_queue_const;
                end
                else
                begin 
                    service_queue[0][sq_tail] <= instrucn_queue[iq_front];
                    addtomem<=instrucn_queue[iq_front];
                    memory_grant<=1;
                    instrucn_queue[iq_front] <=0;
                    iq_front<=iq_front+1;
                    sq_tail<=(sq_tail+1)%serving_queue_const;
                    serv_queue_size<=serv_queue_size+1;
                end
                busy<=0;
                bus_clkcounter<=-1;
            end
            else 
            begin 
                bus_clkcounter<=bus_clkcounter+1;
            end
        end

//bus idle

        else 
        begin 
            if(values_queue_front == values_queue_tail ) 
            begin 
// move from instrucn_queue to service_queue
                if(iq_front!=iq_tail && serv_queue_size<serving_queue_const)
                begin 
//tranferring request started 
                    proc_to_mem<=0;
                    busy<=1;
                    bus_clkcounter<=0;
                end
            end 
            else 
            begin 
// transferring value from value_queue started
                bus_clkcounter<=0;
                proc_to_mem<=1;
                busy<=1;
            end
        end

        #1;
                                                                                                                         
        if(memory_req==1) 
        begin   
// push value into dq from memory
            $display("returned from mem into dq : %d at %d",value,values_queue_tail);  
            values_queue[values_queue_tail]<=value;
            values_queue_tail<=(values_queue_tail+1)%serving_queue_const;                   
        end
        #1;
        if(sq_front!=sq_tail && service_queue[1][sq_front]==0) 
        begin 
// removing front of sq if served
            service_queue[0][sq_front]<=0;
            service_queue[1][sq_front]<=-1;
            sq_front<=(sq_front+1)%serving_queue_const;
            serv_queue_size<=serv_queue_size-1;
        end        
        #1;        
        clkcounter<=clkcounter+1;       
    end
endmodule