#include "ISR.h"

int isr_queue[MAX_ISR];
int front = 0;
int rear = 0;

// Check if empty
bool is_isr_empty() {
    return front == rear;
}

// Check if full
bool is_isr_full() {
    return (rear + 1) % MAX_ISR == front;
}

// Enqueue
void enqueue_isr(int val) {
    if (is_isr_full()) {
        printf("ISR Queue Full\n");
        return;
    }
    isr_queue[rear] = val;
    rear = (rear + 1) % MAX_ISR;
}

// Dequeue
int dequeue_isr() {
    if (is_isr_empty()) {
        printf("ISR Queue Empty\n");
        return -1;
    }
    int val = isr_queue[front];
    front = (front + 1) % MAX_ISR;
    return val;
}

void raise_interrupt(int val)
{
    enqueue_isr(val); 
}