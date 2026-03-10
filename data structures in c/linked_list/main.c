#include <stdio.h>
#include "linked_list.h"

void ll_print(llptr head);
/* inserts x in a ascending order*/
bool insert(llptr *head, int x);


int main()
{
    llptr head;
    ll_init(&head);
    printf("Hello world!!!\n");
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 2);
    insert(&head, 21);
    insert(&head, 1);

    ll_print(head);

    return 0;
}

void ll_print(llptr head){
    llptr current;
    current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}


bool insert(llptr *head, int x){
    
    llptr cur, prev;

    if(*head == NULL)
        return ll_insert_start(head, x);
    else
    {   
        cur = *head;
        prev = cur;
        while(cur != NULL)
        {
            if(cur->data > x){

                if(cur == *head)
                    return ll_insert_start(head, x); 
                else
                    return ll_insert_after(prev, x);                
            }
            prev = cur;
            cur = cur->next;            
        }
        return ll_insert_after(prev, x);
    }
}