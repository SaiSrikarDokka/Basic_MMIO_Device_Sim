#include <stdio.h>
#include "definations.h"
#include "cpu.h"
#include "memory.h"
#include "event_scheduler.h"

int main()
{
    //Load instructions into instruction queue
    FILE *file = fopen("instructions.txt", "r");
    if (!file) {
        perror("File open failed");
        return 1;
    }

    while (ins_cnt < MAX_INSTRUCTIONS) {
        fscanf(file, "%x", &ins_queue[ins_cnt].ins);

        if (ins_queue[ins_cnt].ins == 0x00000000) {
            break;  // stop at sentinel
        }
        ins_cnt++;
    }
    printf("Loaded %d instructions into the instruction queue.\n", ins_cnt);

    fclose(file);


    schedule_event(0, run_cpu); // Schedule the first instruction execution at time 0
    for(int i = 0; i < 150; i++)
    {
        if(max_ins && event_to_be_exec == 0)
        {
            printf("Maximum instructions executed. Halting simulation.\n");
            break;
        }
        run_scheduler();

    }
    printf("Memory State at the end of simulation:\n");
    for (byte i = 0; i < 10; i++)
    {
        printf("Memory[%d] = %d\n", i, mem[i]);
    }
    printf("\nDevice Memory State at the end of simulation:\n");
    for (byte i = 0; i < 10; i++)
    {
        printf("Device memory[%d] = %d\n", i, dev_memory[i]);
    }
    // print_device_memory();

    return 0;
}