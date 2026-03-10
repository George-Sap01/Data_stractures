#include "stack.h"

void Stack_init(Stack* s, size_t capacity)
{    
    s->data = (elem*)malloc(sizeof(elem) * capacity);
    if(!(s->data)){
        printf("Error at memory allocation.");
        exit(0);
    }

    s->top = -1;
    s->capacity = capacity;
}


bool Stack_empty(Stack s){
    return (s.top == -1) ? true : false;
}


bool Stack_full(Stack s){
    return (s.top == s.capacity - 1) ? true : false;
}


bool Stack_push(Stack *s, elem x){
    if(Stack_full(*s))
        return false;
    else
    {
        s->top += 1;
        s->data[s->top] = x;
        return true;
    } 
}


bool Stack_pop(Stack *s, elem* x){
    if(Stack_empty(*s))
        return false;
    else
    {
        *x = s->data[s->top];
        s->top -= 1;
        return true;
    }
}
