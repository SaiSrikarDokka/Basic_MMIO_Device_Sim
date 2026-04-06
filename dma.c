#include "dma.h"
byte src_addr;
byte des_addr;
int data_length;
int ctrl_reg;
void dma_transfer(){
    if(ctrl_reg == 1) // DMA read from memory to device
    {
        printf("DMA Read: Memory to Device\n");
        for(int i = 0; i < data_length; i++)
        {
            mem_addr = src_addr + i;
            dev_addr = des_addr-10 + i;
            mem_read();
            dev_data_in = mem_data_out;
            dev_write();
        }
    }
    else if(ctrl_reg == 2) // DMA read from device to memory
    {
        printf("DMA Transfer: Device to Memory\n");



        for(int i = 0; i < data_length; i++)
        {
            mem_addr = des_addr + i;
            dev_addr = src_addr-10 + i;
            dev_read();
            mem_data = dev_out;
            mem_write();

        }
    }
    schedule_event(curr_time + 2, raise_dma_interrupt); 
}

void raise_dma_interrupt()
{
    printf("Raising DMA interrupt\n");
    raise_interrupt(2); // Raise an interrupt with value 2 to indicate DMA transfer completion
}