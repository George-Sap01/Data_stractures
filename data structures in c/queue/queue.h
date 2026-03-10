#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int elem;

typedef struct{

    elem* data;
    size_t finish;
    size_t capacity;
}Queue;


void queue_init(Queue* q, size_t capacity);
bool empty_queue(Queue q);
bool full_queue(Queue q);
bool enqueue(Queue* q, elem x);
bool dequeue(Queue* q, elem *x);
void print(Queue q);

#endif