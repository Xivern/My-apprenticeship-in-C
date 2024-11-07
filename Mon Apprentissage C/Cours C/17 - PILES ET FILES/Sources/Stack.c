#include <stdlib.h>
#include <stdio.h>
#include "..\Headers\Stack.h"

//LIFO (Last in First out)

Stack *stackInitialize()
{
    Stack *stack = NULL;
    stack = malloc(sizeof(*stack));

    //VERIFY WE HAVE NO ISSUE
    if (stack == NULL)
    {
        printf("ERROR DURING INITIALISATION...\n");
        exit(EXIT_FAILURE);
    }
    
    stack->first = NULL;

    return stack;
}

void stacking(Stack *stack, int newNumber)
{
    //CREATE A NEW ELEMENT
    StackElement *new = NULL;
    new = malloc(sizeof(*new));

    //VERIFY NO PROBLEM DURING INSERTION
    if (stack == NULL || new == NULL)
    {
        printf("ERROR DURING INSERTION...\n");
        exit(EXIT_FAILURE);
    }
    
    new->number = newNumber;        //ADD THE NEW NUMBER
    new->next = stack->first;       //ADD A LOGICAL LINK TO THE OLD NUMBER IN FIRST POSITION
    stack->first = new;             //NEW NUMBER IS NOW IN THE 1ST POSITION
}

int unstacking(Stack *stack)
{
    int unstackingNumber = 0;       //USE THE VARIABLE TO KEEP THE NUMBER WE JUST UNSTACKED

    //VERIFY THE STACK IS CREATED
    if (stack == NULL)              
    {
        printf("ERROR DURING UNSTACKING...\n");
        exit(EXIT_FAILURE);
    }

    //USE TO STORE THE ADDRESS OF THE POINTER TO BE UNSTACKED
    StackElement *unstackElement = NULL;
    unstackElement = stack->first;

    //VERIFY THE STACK ISN'T EMPTY AND INITIALIZED
    if (stack != NULL && stack->first != NULL)
    {
        unstackingNumber = unstackElement->number;
        stack->first = unstackElement->next;
        free(unstackElement);
    }
    
    return unstackingNumber;
}

void showStack(Stack *stack)
{
    if (stack == NULL)
    {
        printf("NO INITIALIZED STACK FOUND...\n");
        exit(EXIT_FAILURE);
    }
    
    int i = 1;

    StackElement *current= NULL;
    current = stack->first;

    while (current != NULL)
    {
        printf("Place %d in the stack : %d\n", i, current->number);
        current = current->next;
        i++;
    }
}