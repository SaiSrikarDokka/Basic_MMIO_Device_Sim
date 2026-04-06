#ifndef DEFINATIONS_H
#define DEFINATIONS_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>


typedef uint8_t byte;
typedef union{
    unsigned int ins;
    struct {
        byte des,src;
        short int op;
        
    } bytes;
} instruction;
typedef void (* event_handler)();
typedef struct {
    int time;
    event_handler handler;
} event;

#endif