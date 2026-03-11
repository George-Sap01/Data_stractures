#include "heap.h"


void heap_init(HEAP *heap){
    heap->N=0;
}


bool heap_insert(HEAP *heap, elem x)
{
    int posParent, posCurrent;

    // an den xwraei stin swro
    if(heap->N == MAX_SIZE)
        return false;
    
    //eisagogi tou neo komvou
    heap->data[heap->N] = x;
    heap->N ++;

    //antimetathesi me ton gonea efoson exei mikroteri timi
    posCurrent = heap->N - 1; //h thesi tou x
    while(posCurrent > 0)
    {
        posParent = (posCurrent - 1)/2;
        //exei megaliteri timi apo gonea. ANTIMETATHESI
        if( heap->data[posCurrent] > heap->data[posParent])
        {
            swap( &heap->data[posCurrent], &heap->data[posParent]);
            posCurrent = posParent;
        }
        else //pire tin oristiki tou thesi. DIAKOPI
            break;
    }

    return true;
}


void swap(elem *x, elem *y){
    elem temp = *x;
    *x = *y;
    *y = temp;
}


bool heap_delete(HEAP *heap, elem *x)
{
    int posCurrent, posLeft, posRight, pos;

    //an o swros einai adeios
    if(heap->N == 0)
        return false;

    //epistrofi tis rizas 
    *x = heap->data[0];

    //topothetisi tou teleutaiou stoixeiou sti riza 
    heap->data[0] = heap->data[heap->N -1];
    heap->N --;

    //antallagi me to megalitero paidi tou
    posCurrent = 0; // vriskomaste stin riza gia auto einai 0
    while( posCurrent < heap->N )
    {
        posLeft = 2*posCurrent + 1; //θεση αριστερου παιδιου
        posRight = 2*posCurrent + 2; //θεση δεξιου παιδιου

        if(posLeft >= heap->N)
            posLeft = -1;
        if(posRight >= heap->N)
            posRight = -1;
        
        if(posLeft == -1 && posRight == -1) // den exei paidia 
            break;
        else if( posLeft != -1 && posRight == -1) //exei mono aristero paidi(den ginetai na exei mono deji paidi giati einai plires)
        {
            if( heap->data[posCurrent] < heap->data[posLeft] )
            {
                swap(&heap->data[posCurrent], &heap->data[posLeft]);
                posCurrent = posLeft;
            }
            else
                break;
        }
        else //exei 2 paidia 
        {
            //euresi tou megaliterou apo ta 2 paidia 
            if(heap->data[posLeft] < heap->data[posRight])
                pos = posRight;
            else
                pos =posLeft;
            // allios: pos = (heap->data[posLeft] < heap->data[posRight]) ? posRight : posLeft;
            
            if(heap->data[posCurrent] < heap->data[pos])
            {
                swap(&heap->data[posCurrent], &heap->data[pos]);
                posCurrent = pos;
            }
            else
                break;
        }
    }

    return true;
}