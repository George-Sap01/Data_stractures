#include "tree.h"


void TR_init(TREE_PTR* root){
    *root = NULL;
}


bool TR_empty(TREE_PTR root){
    return (root == NULL) ? true : false;
}


elem TR_data(TREE_PTR p){
    return p->data;
}


bool TR_insert_root(TREE_PTR *root, elem x)
{
    TREE_PTR newnode;

    if( *root != NULL)
        return false;

    newnode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if(!newnode){
        printf("adynamia desmeusis mnimis");
        return false;
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    
    *root = newnode;
    return true;
}


bool TR_insert_left(TREE_PTR node, elem x)
{
    TREE_PTR newnode;

    if( node->left != NULL)
        return false;

    newnode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if(!newnode){
        printf("adynamia desmeusis mnimis");
        return false;
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    
    node->left = newnode;
    return true;
}


bool TR_insert_right(TREE_PTR node, elem x)
{

    TREE_PTR newnode;

    if( node->right != NULL)
        return false;

    newnode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if(!newnode)
    {
        printf("adynamia desmeusis mnimis");
        return false;
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    
    node->right = newnode;
    return true;
}

/*
    διαγραφη της ριζας ενως δεντρου εφοσον δεν εχει παιδια
*/
bool TR_delete_root(TREE_PTR *root, elem *x) 
{
    if( (*root)->left != NULL || (*root)->right != NULL)
        return false;

    *x = (*root)->data;
    free(root);
    *root = NULL;
    return true;

}


bool TR_delete_left(TREE_PTR parent, elem *x)
{
    TREE_PTR current; //θα το βαλω να δειχνει αυτο που θα διαγραψω 

    if( parent->left == NULL)
        return false;

    current = parent->left;
    if(current->left != NULL || current->right != NULL)
        return false;

    *x = current->data;
    free(current);
    parent->left = NULL;
    return true;
}


bool TR_delete_right(TREE_PTR parent, elem *x)
{
    TREE_PTR current; //θα το βαλω να δειχνει αυτο που θα διαγραψω 

    if( parent->right == NULL)
        return false;

    current = parent->right;
    if(current->left != NULL || current->right!= NULL)
        return false;

    *x = current->data;
    free(current);
    parent->right = NULL;
    return true;
}


void TR_print_node(TREE_PTR v){
    printf(" %d ", v->data);
}


void TR_preorder(TREE_PTR v){
    if(v!=NULL)
    {
        TR_print_node(v);
        TR_preorder(v->left);
        TR_preorder(v->right);
    }
}


void TR_inorder(TREE_PTR v){
    if(v!=NULL)
    {
        TR_inorder(v->left);
        TR_print_node(v);
        TR_inorder(v->right);
        
    }
}

/*
                    10
            1               2
        3       5      7        11


    για την preorder: 

    TR_preorder(10) : 
                    εκτυπωνει 10, TR_preorder(10->αριστερα = 1), ...
    TR_preorder(1)  : 
                    εκτυπωνει 1, TR_preorder(1->αριστερα = 3), ...
    TR_preorder(3)  : 
                    εκτυπωνει 3, TR_preorder(3->left = NULL), TR_preorder(3->right = NULL)
    
    ΓΥΡΝΑΜΕ TR_preorder(1) (συνεχεια) : 
                    TR_preorder(1->δεξια = 5)
    TR_preorder(5)  :
                    εκτυπωνει 5, TR_preorder(5->left = NULL), TR_preorder(5->right = NULL)
    
    ΓΥΡΝΑΜΕ TR_preorder(1) και επειδη τελιωσε και αυτη παμε στην TR_preorder(10)

    TR_preorder(10) (συνεχεια):
                   TR_preorder(10->right = 2)
    TR_preorder(2)  :
                    εκτυπωνει 2, TR_preorder(2->αριστερα = 7), ...

    και παει λεγοντας.



    για την inorder: 
                
    TR_inorder(10) :
                    TR_inorder(10->left = 1), ...
    TR_inorder(1)  :
                    TR_inorder(1->left = 3), ...
    TR_inorder(3)  : 
                    TR_inorder(3->left = NULL), εκτυπωνει 3, TR_inorder(3->right = NULL)
    
    ΓΥΡΝΑΜΕ TR_inorder(1)(συνεχεια) :
                    TR_inorder(1->right = 5)
    TR_inorder(5)  :
                    TR_inorder(5->left = NULL), εκτυπωνει 5, TR_inorder(5->right = NULL)
    
    ΓΥΡΝΑΜΕ TR_inorder(1) και επειδη τελειωσε παμε στην  TR_inorder(10):
                    εκτυπωνει 10, TR_inorder(10->δεξια = 2)
    TR_inorder(2)  :
                    TR_inorder(2->left = 7), ...
    TR_inorder(7)  :
                    TR_inorder(7->left = NULL), εκτυπωνει 7, TR_inorder(7->right = NULL)
    
    ΓΥΡΝΑΜΕ TR_inorder(2) (συνεχεια):
                    εκτυπωνει 2, TR_inorder(2->right = 11)


*/