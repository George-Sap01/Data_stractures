#include <stdio.h>
#include "heap.h"
#include <time.h>
#include <stdlib.h>

#define size 100

void main(void)
{
    int choice, i, j;
    int data;
    int array[size], N;
    HEAP heap, heapsort_heap;

    heap_init(&heap);

    while(1)
    {

        srand(time(NULL));
        system("cls");
        printf("MENU HEAP: ");
        printf("\n---------------");
        printf("\n1-Eisagogi");
        printf("\n2-Diagrafi");
        printf("\n3-Ektypwsi");
        printf("\n4-Heapsort");
        printf("\n5-Eksodos");
        printf("\nEpilogi? ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nDwse stoixeio: ");
                scanf("%d", &data);
                if(heap_insert(&heap, data))
                    printf("Egine i eisagwgi! ");
                else
                    printf("Den egine i eisagwgi! O swros gemise");
                break;
            case 2:
                if(heap_delete(&heap, &data))
                    printf("egine i apomakrinsi tou %d", data);
                else
                    printf("den egine i antigrafi, o swros einai adeios");
                break;
            case 3:
                for( i=0; i<heap.N; i++)
                    printf("%d ", heap.data[i]);
                break;
            case 4:
                do{
                    printf("dvse megethos pinaka: ");
                    scanf("%d", &N);

                    if( N<1 || N>100)
                        printf("give a number <100 and >1");
                    
                } while (N<1 || N>100);
                
                for(i=0; i<N; i++)
                    array[i] = rand() % 100;
                
                if( N == 1)
                    printf("[ %d ]", array[0]);
                else
                {
                    printf("[%d, ",array[0]);
                    for(i=1; i<N-1; i++)
                        printf("%d, ",array[i]);
                    printf("%d]", array[N-1]);    
                }
                    
                heap_init(&heapsort_heap);
                for(i=0; i<N; i++)
                    heap_insert(&heapsort_heap, array[i]);
                
                printf("\nSorted: ");
                for(i=0; i<N; i++)
                {
                    heap_delete(&heapsort_heap, &data);
                    printf("%d ", data);
                }

                break;
            
            case 5:
                printf("Bye Bye!!");
				exit(0);
			default:
				printf("Lathos eisodos!");

        }

        printf("\n\n");
		system("pause");

    }



}
