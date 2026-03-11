#include "binary_search_tree.h"


bool TR_search_BST(TREE_PTR root, elem x) //BST binary search tree
{
    TREE_PTR current;

    current = root;

    while( current != NULL )
    {
        if( x == current->data )
            return true;
        else if ( x < current->data )
            current = current->left;
        else
            current = current->right;
    }

    return false;
}


bool TR_insert_BST(TREE_PTR *root, elem x)
{
    TREE_PTR current;

    if(*root == NULL)
    {
        TR_insert_root(root, x);
        return true;
    }

    current = *root;
    while(1)
    {
        if( x == current->data ) //δεν επιτρεπεται να εισαγω ενα δεδομενο δευτερη φορα 
        {
            return false;
        }
        else if( x < current->data )
        {
            if(current->left == NULL) //αν ειναι κενο το current->left 
            {
                TR_insert_left(current, x);
                return true;
            }
            else 
                current = current -> left;
        }
        else
        {
            if( current -> right == NULL )
            {
                TR_insert_right(current, x);
                return true;
            }
            else
                current = current -> right;
        }
    }
}


bool TR_delete_BST(TREE_PTR *root, elem x)
{

    TREE_PTR current, parent, next_ordered;
    int p; /* 1->αριστερο παιδι του current, 2->δεξι παιδι */

    if( *root == NULL) //ειναι αδειο το δενδρο 
        return false;

    /*αναζητηση του κομβου*/
    parent = NULL;
    current = *root;
    while( current != NULL)
    {
        if( x == current->data)
            break;
        else if( x < current->data) 
        {
            parent = current;
            current = current->left;
            p = 1; 
            // o parent εχει αριστερο παιδι το current 
        }
        else
        {
            parent = current;
            current = current->right;
            p = 2; 
            // o parent εχει δεξι παιδι το current
        }
    }

    if (current == NULL) // δεν υπαρχει αυτο που θελουμε να διαγραψουμε
        return false;

    if( current->left == NULL && current->right == NULL) // Περιπτωση: δεν εχει παιδια ο κομβος
    {
        free(current);
        if(parent == NULL)//parent = NULL μονο στην περιπτωση οπου διαγραφουμε το κομβο οπου δειχνει το root και ο κομβος αυτος δεν εχει παιδια
            *root = NULL;
        else
            (p == 1) ? (parent->left = NULL) : (parent->right = NULL); 
        
        return true;
    }
    else if( (current->left == NULL && current->right != NULL)) //Περιπτωση: εχει μονο δεξι παιδι
    {
       if( parent == NULL ) //θα διαγραψουμε το κομβο που δειχνεται απο το root
            *root = current->right;
        else
            (p==1) ? (parent->left = current->right) : (parent->right = current->right);
        
        free(current);
        return true;
    }
    else if(current->left != NULL && current->right == NULL) //Περιπτωση: εχει μονο αριστερο παιδι
    {
        if( parent == NULL )
            *root = current->left;
        else
            (p==1) ? (parent->left = current->left) : (parent->right = current->left);
        
        free(current);
        return true;
    }
    else // Περιπτωση: εχει ακριβως δυο παιδια
    {

        //briskei ton epomeno stin inorder
        p = 1; // το δεξι παιδι δεν εχει αριστερο παιδι
        next_ordered = current->right; // next_ordered = δεξι παιδι του κομβου που θελουμε να διαγραψουμε

        while( next_ordered->left != NULL )
        {
            parent = next_ordered;
            next_ordered = next_ordered->left;
            p=2;
        }

        //antallasei times me ton komvo poy diagrafetai
        current->data = next_ordered->data;

        if( p==1 )
            current->right = next_ordered->right;
        else
            parent->left = next_ordered->right;
        

        free(next_ordered);
        return true;
    }
}

