#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef int elem;

struct node{
    elem data;
    struct node* next;
    struct node* prev;
};

typedef struct node dllnode;
typedef struct node* dllptr;


void dll_init(dllptr *head);
bool dll_empty(dllptr head);
elem dll_data(dllnode p);
bool dll_insert_start(dllptr *head, elem x);
bool dll_insert_after(dllptr p, elem x);
bool dll_delete_start(dllptr *head, elem *x);
bool dll_delete_after(dllptr prev, elem *x);
void dll_destroy(dllptr *head);

#endif