#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef int elem;

typedef struct STACK{
    elem* data;
    size_t top;
    size_t capacity;
}Stack;

void Stack_init(Stack* s, size_t capacity);
bool Stack_empty(Stack s);
bool Stack_full(Stack s);
bool Stack_push(Stack *s, elem x);
bool Stack_pop(Stack *s, elem* x);

#endif