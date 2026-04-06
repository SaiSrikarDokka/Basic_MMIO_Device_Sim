#ifndef CPU_H
#define CPU_H
#include "definations.h"
#include "memory.h"
#include "mmu.h"
#include "event_scheduler.h"
#include "device.h"
#include "ISR.h"
#include "dma.h"
#define MAX_INSTRUCTIONS 40
// Global CPU register declaration
extern int reg[3];
extern instruction ins_queue[MAX_INSTRUCTIONS];
extern int pc;
// Function declaration
void decode_execute();
void run_cpu();

#endif