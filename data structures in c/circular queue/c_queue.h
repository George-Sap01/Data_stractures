#ifndef C_QUEUE_H
#define C_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef int elem;

typedef struct{
    elem* data;
    size_t capacity;
    size_t start;
    size_t finish;
}Queue;

void queue_init(Queue* q, size_t capacity);
bool empty_queue(Queue q);
bool full_queue(Queue q);
bool enqueue(Queue* q, elem x);
bool dequeue(Queue* q, elem *x);

#endif