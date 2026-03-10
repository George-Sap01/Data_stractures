#include "linked_list.h"

void ll_init(llptr *head){
    *head = NULL;
}

bool ll_empty(llptr head){
    return (head == NULL) ? true : false;
}

elem ll_data(llnode p){
    return p.data;
}

bool ll_insert_start(llptr *head, elem x){

    llnode* newnode;
    newnode = (llptr)malloc(sizeof(llnode));
    if(!newnode){
        printf("Error at allocating memory");
        return false;
    }

    newnode->data = x;
    newnode->next = *head;
    *head = newnode;
    return true;
}

bool ll_insert_after(llptr p, elem x){

    llnode* newnode;
    newnode = (llptr)malloc(sizeof(llnode));
    if(!newnode){
        printf("Error at allocating memory");
        return false;
    }

    newnode->data = x;
    newnode->next = p->next;
    p->next = newnode;
    return true;

}

bool ll_delete_start(llptr *head, elem *x){
    
    if(ll_empty(*head))
        return false;

    llptr temp = *head;
    
    *x = (*head)->data;
    (*head) = (*head)->next;
    free(temp);
    
    return true;
}

bool ll_delete_after(llptr prev, elem *x){
    
    if(prev->next == NULL)
        return false;
    llptr current = prev->next;

    *x = current->data;
    prev->next = current->next;
    free(current);
    return true;
}

void ll_destroy(llptr *head){

    llptr current;
    while(*head != NULL)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
    }
}
