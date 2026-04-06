#include "cpu.h"


int reg[3];
instruction ins_queue[MAX_INSTRUCTIONS];
// {
//     { .ins = 0x00030100 },
//     { .ins = 0x00030201 },
//     { .ins = 0x00030302 },
//     { .ins = 0x00030403 },
//     { .ins = 0x00030504 },
//     // Store instructions
//     { .ins = 0x00050100},
//     { .ins = 0x00050501},
//     { .ins = 0x0006000A},
//     { .ins = 0x00050200},
//     { .ins = 0x00050601},
//     { .ins = 0x00060A05}
//     // remaining elements default to 0
// };
int resume = 0;
int cycles = 1;
int pc = 0;
int interrupt_mode = 0;
bool branch_mode = false;
instruction curr_ins;
void fetch_instruction()
{
    
    if(resume==0)
    {
        pc++;
        curr_ins = ins_queue[pc];
        branch_mode = false; // Reset branch mode at the start of each instruction fetch
        printf("Fetching instruction at PC: %d\n", pc);
    }
    if(pc == ins_cnt-1)
    {
        max_ins = true;
    }
}

void decode_execute()
{
    int op = curr_ins.bytes.op;
    int src = curr_ins.bytes.src;
    int des = curr_ins.bytes.des;
    if(resume == 1)
    {
            printf("Load complete, resuming execution\n");
            reg[des] = mmu_data_out;
            resume = 0;
    }
    else{
    switch(op)
    {
        
        case 1: 
            printf("Load memory from %d to %d\n", src, des);
            mmu_addr = src;
            resume = 1;
            schedule_event(curr_time + 1, mmu_read);
            cycles++;
            break;

        case 2:
            
            mmu_addr = des;
            mmu_data_in = reg[src];
            printf("Store %d from %d to %d\n",mmu_data_in, src, des);
            schedule_event(curr_time + 1, mmu_write);
            cycles++;
            break;

        case 3:
            printf("Store operand %d to %d\n", src, des);
            mmu_addr = des;
            mmu_data_in = src;
            schedule_event(curr_time + 1, mmu_write);
            cycles++;
            break;
        case 4:
            printf("Performing device operation with operand %d\n", src);
            dev_data_in = src;
            schedule_event(curr_time + 1, dev_op);
            cycles++;
            break;
        case 5:
            printf("Load value %d to register %d\n", src, des);
            reg[des] = src;
            break;
        case 6:
            src_addr = src;
            des_addr = des;
            ctrl_reg = reg[0]; // Set control register for memory to device transfer
            data_length = reg[1]; // Set data length for transfer
            schedule_event(curr_time + 1, dma_transfer);
            cycles++;
            break;
        case 7 :
            printf("Performing parallel task \n");
            break;
        case 8:
            if(reg[src] == 1)
            {
            printf("Branch condition is true \n");
            pc = des-1; // Set PC to target address (subtract 1 because it will be incremented in fetch)
            
            branch_mode = true;
            }
            else{
                printf("Branch condition false");
            }
            break;
            
        default:
            printf("Support of instruction is to be added\n");
            break;
    }
}
}

void check_interrupt()
{
    if (!is_isr_empty()) {
        interrupt_mode = true;
        
        printf("Interrupt detected! Switching to interrupt mode.\n");
    }
}

void ISR_handler()
{
    int interrupt_val = dequeue_isr();
    printf("Handling interrupt with value: %d\n", interrupt_val);
    if(interrupt_val == 1) {
        printf("Device wait completed, performing necessary operations.\n");
        reg[3] = 0;
    }
    if(interrupt_val == 2) {
        printf("DMA transfer completed, performing necessary operations.\n");
        reg[3] = 0;
    }
}

void run_cpu()
{
    if(interrupt_mode)
    {
        ISR_handler();
        interrupt_mode = false; // Reset interrupt mode after handling
    
    }
    else{
    fetch_instruction();
    decode_execute();
    }
    check_interrupt();
    if(!max_ins || branch_mode)
    {
        printf("CPU is Scheduled to run next instruction at %d cycle\n",curr_time+ cycles);
        schedule_event(curr_time + cycles, run_cpu); // Schedule next instruction execution after 1 time unit
    }
    cycles = 1; // Reset cycles for the next instruction
}