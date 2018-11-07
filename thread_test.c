//Haonan Yin

#include "threads.h"

// a few functions with infinite loops (put a yield in each loop)
void function1(){
    int i=1;
    while(1){
        i++;
        printf("%d\n", i);
        yield();
    }
}

void function2(){
    while(1){
        printf("%s\n", "Hello, world!");
        yield();
    }
}

int main(){
    RunQ = (struct TCB_t**)malloc(sizeof(struct TCB_t));
    *RunQ = NULL;
    start_thread(function1);
    start_thread(function2);
    run();
}