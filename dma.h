#ifndef DMA_H
#define DMA_H
#include "definations.h"
#include "memory.h"
#include "device.h"
#include "ISR.h"
#include "event_scheduler.h"
extern int ctrl_reg;
extern byte src_addr;
extern byte des_addr;
extern int data_length;
void dma_transfer();
void raise_dma_interrupt();
#endif



