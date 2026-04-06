#ifndef ISR_H
#define ISR_H
#include <stdio.h>
#include <stdbool.h>

#define MAX_ISR 10

extern int isr_queue[MAX_ISR];
extern int front;
extern int rear;
bool is_isr_empty();
void enqueue_isr(int val);
void raise_interrupt(int val);
int dequeue_isr();
bool is_isr_full();

#endif