#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\Stack.h"
#include "..\Headers\Queue.h"

int main()
{
    //We are using the C89 version to create this code 

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                       Welcome to the program                       |\n");
    printf("|                We show you how to use stack and file               |\n");    
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                                STACK                               |\n");    
    printf("----------------------------------------------------------------------\n");

    int valueDeleted = 0;

    //INITIALIZE
    Stack *myStackList = NULL;
    myStackList = stackInitialize();
    
    //ADD RANDOM NUMBER TO THE STACK
    stacking(myStackList, 10);
    stacking(myStackList, 100);
    stacking(myStackList, 1000);
    stacking(myStackList, 10000);
    stacking(myStackList, 100000);

    //SHOW THE STACK
    printf("-- Current status of the stack : --\n");
    showStack(myStackList);
    printf("-- END --\n");

    //UNSTACK 2 VARIABLES
    valueDeleted = unstacking(myStackList);
    printf("[Deletion of %d]\n", valueDeleted);
    valueDeleted = unstacking(myStackList);
    printf("[Deletion of %d]\n", valueDeleted);

    //SHOW THE STACK
    printf("-- Current status of the stack : --\n");
    showStack(myStackList);
    printf("-- END --\n");
    
    /*---------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                                QUEUE                               |\n");    
    printf("----------------------------------------------------------------------\n");

    //INITIALIZE
    Queue *myQueueList = NULL;
    myQueueList = queueInitialize();

    //ADD RANDOM NUMBER TO THE STACK
    queuing(myQueueList, 50);
    queuing(myQueueList, 500);
    queuing(myQueueList, 5000);
    queuing(myQueueList, 50000);
    queuing(myQueueList, 500000);

    //SHOW THE QUEUE
    printf("-- Current status of the queue : --\n");
    showQueue(myQueueList);
    printf("-- END --\n");

    //UNQUEUE 2 VARIABLES
    valueDeleted = unqueuing(myQueueList);
    printf("[Deletion of %d]\n", valueDeleted);
    valueDeleted = unqueuing(myQueueList);
    printf("[Deletion of %d]\n", valueDeleted);

    //SHOW THE QUEUE
    printf("-- Current status of the queue : --\n");
    showQueue(myQueueList);
    printf("-- END --\n");
    
    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                        END OF THE PROGRAM...                       |\n");   
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/

    return 0;
}