#include <stdlib.h>
#include <stdio.h>

#include "..\Headers\ChainList.h"

List *Initialize()
{
    List *list = NULL;                                  //We create a pointer to allocate dynamically according to the size of the structure
    Element *element = NULL;                            //We create a pointer to allocate dynamically according to the size of the structure
    
    list = malloc(sizeof(*list));
    element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)                //We verify we don't have any issue
    {
        printf("ERROR DURING INITIALISATION...\n");
        exit(EXIT_FAILURE);
    }
    
    element->number = 0;                                //We initialise number to 0.
    element->next = NULL;                               //Our first element on the the list are also the last element.
    list->first = element;                              //We point the first element on the list

    return list;
}

void insertion(List *list, int newNumber)
{
    //CREATE A NEW ELEMENT
    Element *new = NULL;

    new = malloc(sizeof(*new));

    if (new == NULL)
    {
        printf("ERROR DURING INSERTION...\n");
        exit(EXIT_FAILURE);
    }
    
    new->number = newNumber;                            //We copy the value set as a parameter


    //INSERT THE NEW ELEMENT AT THE BEGINNING OF THE LIST
    new->next = list->first;                            //The new element is placed before the old first element (It is now the first)
    list->first = new;                                  //The control list point now to the new 1st element 
}

void deletion(List *list)
{
    if (list == NULL)
    {
        printf("ERROR DURING DELETION...\n");
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
        Element *toDelete = NULL;

        toDelete = list->first;
        list->first = list->first->next;
        free(toDelete);
    }
}

void showList(List *list)
{
    int i = 1;

    if (list == NULL)
    {
        printf("ERROR DURING DELETION...\n");
        exit(EXIT_FAILURE);
    }

    Element *actualElement = NULL;

    actualElement = list->first;

    while (actualElement != NULL)
    {
        printf("> Elements %d : %d\n", i, actualElement->number);
        actualElement = actualElement->next;
        i++;
    }
}