#include "tree.h"
#include <stdio.h>

int main()
{
    elem x;
    TREE_PTR root;

    TR_init(&root);
    
    TR_insert_root(&root, 10);

    TR_insert_left(root, 2);
    TR_insert_right(root, 4);

    TR_insert_left(root->left, 5);
    TR_insert_right(root->left, 6);

    TR_insert_left(root->right, 8);
    TR_insert_right(root->right, 9);

    TR_insert_right(root->right->right, 32);

    TR_preorder(root);

    return 0;

    return 0;
}