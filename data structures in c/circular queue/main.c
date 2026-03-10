#include "c_queue.h"
#include <stdio.h>

#define QUEUE_SIZE 100

int main()
{
    Queue q;
    queue_init(&q, QUEUE_SIZE);

    int choice, num;

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
                if(enqueue(&q, num))
                    printf("update is done");
                else
                    printf("queue is full!");
                break;
            case 2:
                if( dequeue(&q, &num))
                    printf("the number %d was poped", num);
                else
                    printf("the queue was empty!");
                break;
            case 3:
                if(q.start != -1)
                {
                    int i;
                    i = q.start;

                    while(1)
                    {
                        printf("%d ", q.data[i]);
                        if( i == q.finish)
                            break;
                        i = (i+1) % q.capacity;
                    }                
                }
                else
                    printf("the queue is empty");
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