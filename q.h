#ifndef __Q_H__
#define __Q_H__


#include "TCB.h"

void NewItem(TCB_t *item){
        item->prev = item;
        item->next = item;
}
void AddQueue(TCB_t** head, TCB_t* item){
    if(*head == NULL){
        NewItem(item);
        *head = item;
    }
    else{
        item->prev = (*head)->prev;
        item->next = *head;
        (*head)->prev->next = item;
        (*head)->prev = item;
    }
}
TCB_t* DelQueue(TCB_t** head){
    if(*head == NULL){
        printf("%s\n", "Queue is empty");
        return NULL;
    }
    else if((*head)->next == *head && (*head)->prev == *head){
        *head = NULL;
        return *head;
    }
    else{
        TCB_t *tcb = (struct TCB_t*)malloc(sizeof(struct TCB_t));
        tcb = *head;
        (*head)->next->prev = (*head)->prev;
        (*head)->prev->next = (*head)->next;
        *head = (*head)->next;
        tcb->prev = NULL;
        tcb->next = NULL;
        return tcb;
    }
}
void RotateQ(TCB_t** head){
    AddQueue(head, DelQueue(head));
}
#endif