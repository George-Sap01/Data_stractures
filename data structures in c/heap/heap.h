#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_SIZE 30

typedef int elem;

struct heap_tree{

    elem data[MAX_SIZE];
    int N; //to plithos twn stoixeiwn tou pinaka
};

typedef struct heap_tree HEAP;

void heap_init(HEAP *heap);
bool heap_insert(HEAP *heap, elem x);
void swap(elem *x, elem *y);
bool heap_delete(HEAP *heap, elem *x); //διαγραφει την ριζα του δενδρου

#endif