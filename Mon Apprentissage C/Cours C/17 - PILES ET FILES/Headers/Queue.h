/*
/-Queue.h
/-HEADER
/-Role: Stock prototypes related to the Queue explanation
*/

#ifndef Queue_h
#define Queue_h

typedef struct QueueElement QueueElement;
struct QueueElement
{
    int number;
    QueueElement *next;
};

typedef struct Queue Queue;
struct Queue
{
    QueueElement *first;
};

/*----------------------------------------*/
Queue *queueInitialize();
/*----------------------------------------*/
void queuing(Queue *queue, int newNumber);
/*----------------------------------------*/
int unqueuing(Queue *queue);
/*----------------------------------------*/
void showQueue(Queue *queue);
/*----------------------------------------*/

#endif /* Queue_h */