#include "c_queue.h"

void queue_init(Queue* q, size_t capacity){
    q->data = (elem*)malloc(sizeof(elem) * capacity);
    if(!q->data){
        printf("Error at allocating memory");
        exit(0);
    }
    q->start = -1;
    q->finish = -1;
    q->capacity = capacity;    
}

bool empty_queue(Queue q){
    return (q.start == -1) ? true : false;
}

/*   
    q.capacity = 4
    to be true we need to have: finish + 1 = start
1)  
    0   1   2   3
    s           f
2)
    0   1   2   3
        f   s           

*/
bool full_queue(Queue q){
    return (q.start == (q.finish + 1)% q.capacity) ? true : false;
}

/*   
    q.capacity = 4
1)  
    0   1   2   3
    s           
    f
2)
    0   1   2   3
    s       f 
3)          
    0   1   2   3
        s   f 
4)
    0   1   2   3
        s       f
5)
    0   1   2   3
        f       s       
    

*/

bool enqueue(Queue* q, elem x){
    
    if(full_queue(*q))
        return false;
    else
    {
        if(empty_queue(*q)){
            q->start = 0;
            q->finish = 0;
        }
        else
            q->finish = (q->finish + 1) % q->capacity;
    }
    q->data[q->finish] = x;
    return true;
}

bool dequeue(Queue* q, elem *x){
    
    if(empty_queue(*q))
        return true;
    else
    {
        *x = q->data[q->start];
        if(q->start == q->finish)
        {
            q->start = -1;
            q->finish = -1;
        }
        else
        {
            q->start = (q->start + 1) % q->capacity;
        }
        return true;
    }
}
