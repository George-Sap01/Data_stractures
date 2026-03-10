#include "queue.h"

void queue_init(Queue* q, size_t capacity){
    q->data = (elem*)malloc(sizeof(elem) * capacity);
    if(!q->data){
        printf("Error at memory allocation");
        exit(0);
    }

    q->finish = -1;
    q->capacity = capacity;
}

bool empty_queue(Queue q){
    return (q.finish == -1) ? true : false;
}

bool full_queue(Queue q){
    return (q.finish == q.capacity -1) ? true : false;
}

bool enqueue(Queue* q, elem x){
    if(full_queue(*q))
        return false;
    else
    {
        q->finish++;
        q->data[q->finish] = x;
        return true;
    }
}

bool dequeue(Queue* q, elem *x){
    
    if(empty_queue(*q))
        return false;
    
    size_t i;
    
    *x = q->data[0];
    for(i = 0; i<q->finish; i++)
        q->data[i] = q->data[i+1]; 

    q->finish--;
}

// elem = int in this function by defualt. If elem != int, need to change the %d
void print(Queue q){
    size_t i;
    for(i=0; i<q.finish; i++)
        printf("%d ", q.data[i]);
    
}
