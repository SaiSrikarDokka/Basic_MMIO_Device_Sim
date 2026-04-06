#include "event_scheduler.h"
event event_queue[150]; // Simple event queue 
int event_to_be_exec = 0;
int curr_time = 0;
bool max_ins = false;
int ins_cnt = 0;
void schedule_event(int time, event_handler handler)
{
    if(event_queue[time].handler != NULL) {
        printf("Warning: Writing to next cycle as only one event per cycle is supported. Overwriting existing event to time %d\n", time+1);
        schedule_event(time + 1, handler); // Schedule for next cycle if current cycle is occupied
    }
    else{
    printf("Scheduling event at time %d\n", time);
    event_queue[time].time = curr_time;
    event_queue[time].handler = handler;
    event_to_be_exec++;
    }
    
}

void run_scheduler()
{
    printf("[Time %d] \n", curr_time);
    if (event_queue[curr_time].handler != NULL)
    {
        event_queue[curr_time].handler();
    }
    else {
        printf("No event scheduled at time %d\n", curr_time);
    }
    curr_time++;
    event_to_be_exec--;
    printf("\n ---------------------------------- \n\n");
}