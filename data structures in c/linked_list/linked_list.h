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
};

typedef struct node llnode;
typedef struct node* llptr;


void ll_init(llptr *head);
bool ll_empty(llptr head);
elem ll_data(llnode p);
bool ll_insert_start(llptr *head, elem x);
bool ll_insert_after(llptr p, elem x);
bool ll_delete_start(llptr *head, elem *x);
bool ll_delete_after(llptr prev, elem *x);
void ll_destroy(llptr *head);

#endif