#ifndef MEM_H
#define MEM_H

#include <stdint.h>
#include "definations.h"

// Declare global memory (not define)
extern int mem[10];
extern byte mem_addr;
extern int mem_data;
extern int mem_data_out;

// Function declarations
void mem_read();
void mem_write();

#endif