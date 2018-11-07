#ifndef SEM_H
#define SEM_H

#include "threads.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Semaphore{
    int value;
    TCB_t **Q;
}Semaphore;

void InitSem(struct Semaphore *S, int x){
    S->value = x;
    S->Q = (struct TCB_t**)malloc(sizeof(struct TCB_t));;
    *(S->Q)=NULL;
}

void P(struct Semaphore *S){
    TCB_t *tcb;
    S->value--;
    if(S->value < 0){
        tcb = DelQueue(RunQ);
        AddQueue(S->Q, tcb);
        swapcontext(&(tcb->context), &((*RunQ)->context));
    }
    
}

void V(struct Semaphore *S){
    TCB_t *tcb;
    S->value++;
    if(S->value<=0){
        tcb = DelQueue(RunQ);
        AddQueue(S->Q, tcb);
    }
    yield();
}
#endif