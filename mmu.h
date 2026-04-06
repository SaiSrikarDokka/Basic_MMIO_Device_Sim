#ifndef MMU_H
#define MMU_H
#include "definations.h"
#include "memory.h"
#include "device.h"

extern byte mmu_addr;
extern int mmu_data_in;
extern int mmu_data_out;

void mmu_read();
void mmu_write();
#endif