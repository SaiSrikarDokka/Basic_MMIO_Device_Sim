#ifndef DEVICE_H
#define DEVICE_H
#include "definations.h"
#include "ISR.h"
extern int dev_out;
extern byte dev_addr;
extern int dev_data_in;
extern int dev_memory[10];
void dev_write();
void dev_read();
void dev_op();
void raise_device_interrupt();
#endif