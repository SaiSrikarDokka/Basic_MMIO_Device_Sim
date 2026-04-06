#include "memory.h"
byte mem_addr;
int mem_data;
int mem[10];
int mem_data_out;

void mem_read()
{
    printf("Reading %d from memory address %d\n", mem[mem_addr], mem_addr);
    mem_data_out = mem[mem_addr];
}

void mem_write()
{ 
    printf("Writing %d to memory address %d\n", mem_data, mem_addr);
    mem[mem_addr] = mem_data;
}