#include "D-linked_list.h"

void dll_init(dllptr *head){
    *head = NULL;
}

bool dll_empty(dllptr head){
    return (head == NULL) ? true : false;
}

elem dll_data(dllnode p){
    return p.data;
}

bool dll_insert_start(dllptr *head, elem x){

    dllnode* newnode;
    newnode = (dllptr)malloc(sizeof(dllnode));
    if(!newnode){
        printf("Error at allocating memory");
        return false;
    }

    newnode->data = x;
    newnode->next = *head;
    newnode->prev = NULL;
    
    if( newnode->next != NULL)
        newnode->next->prev = newnode;
    
    *head = newnode;
    return true;
}

bool dll_insert_after(dllptr p, elem x){

    dllnode* newnode;
    newnode = (dllptr)malloc(sizeof(dllnode));
    if(!newnode){
        printf("Error at allocating memory");
        return false;
    }

    newnode->data = x;
    newnode->next = p->next;
    p->next = newnode;
    if(newnode->next != NULL)
        newnode->next->prev = newnode;
    
    return true;
}

bool dll_delete_start(dllptr *head, elem *x){
    
    if(dll_empty(*head))
        return false;

    dllptr temp = *head;
    
    *x = (*head)->data;
    (*head) = (*head)->next;
    if( (*head) != NULL )
        (*head)->prev = NULL;
    
    free(temp);
    return true;
}

bool dll_delete_after(dllptr prev, elem *x){
    
    if(prev->next == NULL)
        return false;

    dllptr current = prev->next;

    *x = current->data;
    prev->next = current->next;

    if(prev != NULL)
        prev->next->prev = prev;

    free(current);
    return true;
}

void dll_destroy(dllptr *head){

    dllptr current;
    while(*head != NULL)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
    }
}
