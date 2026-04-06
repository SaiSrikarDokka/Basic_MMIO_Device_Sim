#include "device.h"
#include "event_scheduler.h"
int dev_memory[10]; // Simulated device memory
byte dev_addr;
int dev_data_in;
int dev_out;
void dev_write()
{
    printf("Device write operation: %d with %d\n", dev_addr,dev_data_in);
    dev_memory[dev_addr] = dev_data_in;
}
void dev_read()
{
    // printf("Device read operation: %d\n", dev_ctrl);
    dev_out = dev_memory[dev_addr];
}
void dev_op()
{
    for (int i = 0; i < 10; i++)
    {
        dev_addr = i;
       dev_memory[i] = dev_memory[i] * 12;  
    }
    schedule_event(curr_time + 5, raise_device_interrupt);
}
void raise_device_interrupt()
{
    printf("Raising device interrupt\n");
    raise_interrupt(1); // Raise an interrupt with value 1 to indicate device operation completion
}
void print_device_memory(){
    for (int i = 0; i < 10; i++)
    {
        printf("Device memory[%d] = %d\n", i, dev_memory[i]);
    }
}