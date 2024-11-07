#include <stdlib.h>
#include <stdio.h>
#include "..\Headers\Queue.h"

//FIFO (First in First out)

Queue *queueInitialize()
{
    Queue *queue = NULL;
    queue = malloc(sizeof(*queue));

    //VERIFY WE HAVE NO ISSUE
    if (queue == NULL)
    {
        printf("ERROR DURING INITIALISATION...\n");
        exit(EXIT_FAILURE);
    }
    
    queue->first = NULL;

    return queue;
}

void queuing(Queue *queue, int newNumber)
{
    //CREATE A NEW ELEMENT
    QueueElement *new = NULL;
    new = malloc(sizeof(*new));

    //VERIFY NO PROBLEM DURING INSERTION
    if (new == NULL || queue == NULL)
    {
        printf("ERROR DURING INSERTION...\n");
        exit(EXIT_FAILURE);
    }
    
    new->number = newNumber;                    //ADD THE NEW NUMBER
    new->next = NULL;                           //ADD A LOGICAL LINK TO THE NEXT NUMBER TO NULL

    //CASE OUR QUEUE ISN'T EMPTY
    if (queue->first != NULL)
    {
        QueueElement *currentElement = NULL;
        currentElement = queue->first;

        while (currentElement->next != NULL)
        {
            currentElement = currentElement->next;
        }

        currentElement->next = new;
    }
    else
    {
        queue->first = new;
    }
}

int unqueuing(Queue *queue)
{
    if (queue == NULL)
    {
        printf("ERROR DURING UNQUEUING...\n");
        exit(EXIT_FAILURE);
    }
    
    int unqueuingNumber = 0;

    if (queue->first != NULL)
    {

        QueueElement *unqueueElement = NULL;
        unqueueElement = queue->first;

        unqueuingNumber = unqueueElement->number;
        queue->first = unqueueElement->next;
        free(unqueueElement);
    }
    
    return unqueuingNumber;
}

void showQueue(Queue *queue)
{
    if (queue == NULL)
    {
        printf("NO INITIALIZED QUEUE FOUND...\n");
        exit(EXIT_FAILURE);
    }

    int i = 1;

    QueueElement *currentElement = NULL;
    currentElement = queue->first;

    while (currentElement != NULL)
    {
        printf("Place %d in the queue : %d\n", i, currentElement->number);
        currentElement = currentElement->next;
        i++;
    }
}