#include <stdio.h>
#include "stack.h"

#define STACK_CAPACITY 3

int main()
{
    Stack a;
    int choice, num;

    Stack_init(&a, STACK_CAPACITY);

    while(1)
    {
        system("cls");
        printf("\t------MENU------");
        printf("\n\t1. Insert Number");
        printf("\n\t2. Pop Number");
        printf("\n\t3. Print");
        printf("\n\t4. Exit");
        printf("\n\tselect a number: ");
        scanf("%d", &choice);
        printf("\n\n");
        switch(choice)
        {
            
            case 1:
                printf("give a number: ");
                scanf("%d", &num);
                if(Stack_push(&a, num))
                    printf("update is done");
                else
                    printf("Stack is full!");
                break;
            case 2:
                if( Stack_pop(&a, &num))
                    printf("the number %d was poped", num);
                else
                    printf("the Stack was empty!");
                break;
            case 3:
                if(!Stack_empty(a))
                {
                    for(int i=0; i<=a.top; i++)
                        printf("%d ", a.data[i]);
                }
                else
                    printf("the Stack is empty");
                break;
            case 4:
                printf("Bye!! ");
                exit(0);
        }
        printf("\n\n");
        system("pause");
    
    }

    return 0;
}