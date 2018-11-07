#ifndef __THREADS_H__
#define __THREADS_H__

#include "q.h"
struct TCB_t **RunQ;

void start_thread(void (*function) (void)){
    void *stackP = (void*) malloc(sizeof(8192));
    TCB_t *tcb = (struct TCB_t*)malloc(sizeof(struct TCB_t));
    init_TCB(tcb,function,stackP,8192);
    AddQueue(RunQ, tcb);
}

void run(){
    ucontext_t parent; // get a place to store the main context, for faking
    getcontext(&parent); // magic sauce
    swapcontext(&parent, &((*RunQ)->context)); // start the first thread
}

void yield(){
    RotateQ(RunQ);
    swapcontext(&((*RunQ)->prev->context), &((*RunQ)->context));
}
#endif