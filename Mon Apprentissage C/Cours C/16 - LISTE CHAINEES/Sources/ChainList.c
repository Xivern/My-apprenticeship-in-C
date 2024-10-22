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

    list->size++;

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

    list->size++;
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

        list->size--;
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

void insertAfterPosition(List *list, int newNumber, int position)
{
    if (list == NULL)
    {
        printf("ERROR DURING INSERTION...\nPLEASE CHECK THAT YOU HAVE INITIALIZED THE LIST CORRECTLY...\n");
        exit(EXIT_FAILURE);
    }

    //CREATE A NEW ELEMENT
    Element *new = NULL;
    new = malloc(sizeof(*new));

    if (new == NULL)
    {
        printf("ERROR DURING INSERTION...\n");
        exit(EXIT_FAILURE);
    }

    new->number = newNumber;

    // Traverse the list until the position
    Element *actualElement = NULL;
    actualElement = list->first;

    int i = 1;

    while (actualElement != NULL && i < position)
    {
        actualElement = actualElement->next;
        i++;
    }

    // If we reach the end of the list before the desired position
    if (actualElement == NULL)
    {
        printf("ERROR DURING INSERTION...\nOUT OF RANGE\n");
        free(new);
        exit(EXIT_FAILURE);
    }

    // Insert the new element after "actualElement"
    new->next = actualElement->next;
    actualElement->next = new;

    list->size++;
}

void deleteAtPosition(List *list, int position)
{
    if (list == NULL)
    {
        printf("ERROR DURING INSERTION...\nPLEASE CHECK THAT YOU HAVE INITIALIZED THE LIST CORRECTLY...\n");
        exit(EXIT_FAILURE);
    }

    if (list->first == NULL)  // Check if the list is empty
    {
        printf("ERROR DURING DELETION...\nNOTHING TO DELETE\n");
        return;
    }

    // Check if the position is valid (it should be >= 1)
    if (position < 1)
    {
        printf("ERROR DURING DELETION...\nINVALID POSITION\n");
        return;
    }

    if (position > list->size)
    {
        printf("ERROR DURING DELETION...\nOUT OF RANGE\n");
        return;
    }

    Element *actualElement = NULL;
    actualElement = list->first;
        
    int i = 1;

    Element *toDelete = NULL;

    switch (position)
    {
    case 1 :

        toDelete = list->first;
        list->first = list->first->next;
        free(toDelete);

        list->size--;

        break;
    
    default:

        while (actualElement != NULL && i < position - 1)       //We go 1 element before the position
        {
            actualElement = actualElement->next;
            i++;
        }

        // Extra safety check to avoid dereferencing a NULL pointer
        if (actualElement == NULL || actualElement->next == NULL)
        {
            printf("ERROR DURING DELETION...\nOUT OF RANGE\n");
            return;
        }

        toDelete = actualElement->next;
        actualElement->next = actualElement->next->next;
        free(toDelete);

        list->size--;
        break;
    }
}

void deleteAll(List *list)
{
    if (list == NULL)
    {
        printf("ERROR DURING INSERTION...\nPLEASE CHECK THAT YOU HAVE INITIALIZED THE LIST CORRECTLY...\n");
        exit(EXIT_FAILURE);
    }

    Element *toDelete = NULL;

    // Loop through the list and delete each element
    while (list->first != NULL)
    {
        toDelete = list->first;
        list->first = list->first->next;
        free(toDelete);
    }
    
    list->size = 0;

    printf("All elements successfully deleted...\n");
}

int sizeList(List *list)
{
    return list->size;
}