#ifndef EVENT_SCHEDULER_H
#define EVENT_SCHEDULER_H
#include <stdbool.h>
#include "definations.h"
extern int curr_time; // Declare current_time as an external variable
extern bool max_ins; // Declare max_ins as an external variable
extern int event_to_be_exec; // Declare event_to_be_exec as an external variable
extern int ins_cnt;
void schedule_event(int time, event_handler handler);
void run_scheduler();

#endif