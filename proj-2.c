//Haonan Yin

#include "sem.h"
#include <unistd.h>
struct Semaphore *S;
void function1(){
    int i=1;
    while(1){
        P(S);
        i++;
        printf("%d\n", i);
        sleep(1);
        V(S);
    }
}

void function2(){
    
    while(1){
        P(S);
        printf("%s\n", "Hello, world!");
        sleep(1);
        V(S);
    }
}

int main(){
    S=(struct Semaphore*)malloc(sizeof(struct Semaphore));
    InitSem(S,1);
    RunQ = (struct TCB_t**)malloc(sizeof(struct TCB_t));
    *RunQ = NULL;
    start_thread(function1);
    start_thread(function2);
    run();
    return 0;
}