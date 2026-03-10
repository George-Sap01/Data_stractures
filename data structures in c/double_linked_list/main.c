#include "d-linked_list.h"
#include <stdio.h>

void dll_print(dllptr head);

int main()
{
    int x;
    dllptr head, prev, current;

    dll_init(&head);

    // insertion of 1 in the start
    dll_insert_start(&head, 1);
    printf("\n");
    dll_print(head);

    // insertion of 2 in the start
    dll_insert_start(&head, 2);
    printf("\n");
    dll_print(head);


    // insertion of 3 after the first element 
    dll_insert_after(head, 3);
    printf("\n");
    dll_print(head);

    // insertion of 5 after the second element 
    dll_insert_after(head->next, 5);
    printf("\n");
    dll_print(head);

    // insertion of 9 in the start
    dll_insert_start(&head, 9);
    printf("\n");
    dll_print(head);

    //insertion of 7 in the second to last position  
    current = head;
    prev = current;
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    dll_insert_after(prev, 7);
    printf("\n");
    dll_print(head);

    //insertion of 10 in the last position 
    dll_insert_after(current, 10);
    printf("\n");
    dll_print(head);

    dll_destroy(&head);
    return 0;
}


void dll_print(dllptr head){
    dllptr cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}