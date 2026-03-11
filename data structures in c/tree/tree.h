#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int elem;

struct node{
    elem data;
    struct node* left;
    struct node* right;
};

typedef struct node TREE_NODE;
typedef struct node* TREE_PTR;

void TR_init(TREE_PTR* root);
bool TR_empty(TREE_PTR root);
elem TR_data(TREE_PTR p);
//insert
bool TR_insert_root(TREE_PTR *root, elem x);
bool TR_insert_left(TREE_PTR node, elem x); 
bool TR_insert_right(TREE_PTR node, elem x);
//delete
bool TR_delete_root(TREE_PTR *root, elem *x);
bool TR_delete_left(TREE_PTR parent, elem *x);
bool TR_delete_right(TREE_PTR parent, elem *x);
//print
void TR_preorder(TREE_PTR v); 
void TR_print_node(TREE_PTR v);
void TR_inorder(TREE_PTR v);

#endif
