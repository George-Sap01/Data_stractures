#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

bool TR_search_BST(TREE_PTR root, elem x);
bool TR_insert_BST(TREE_PTR *root, elem x); 
bool TR_delete_BST(TREE_PTR *root, elem x);

#endif