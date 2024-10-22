#include <stdio.h>
#include <stdlib.h>

#include "..\Headers\ChainList.h"

int main()
{
    //We are using the C89 version to create this code 

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                       Welcome to the program                       |\n");
    printf("|                We show you how to use the chain list               |\n");    
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    int firstUserChoice = 0, secondUserChoice = 0;
    int userNumber = 0, userPosition = 0;

    List *myList = NULL;
    myList = Initialize();

    do
    {   

    printf("---------------LIST---------------\n");
    printf("Currently, we have %d elements in the list :\n", sizeList(myList));
    showList(myList);

    printf("----------------------------------\n");
    printf("What do you want to do ?\n");
    printf("1. Add an item in the list\n");
    printf("2. remove an item from the list\n");
    printf("3. Leave\n");
    printf("----------------------------------\n");
    printf(">> Your choice : ");

    scanf("%d", &firstUserChoice);

    switch (firstUserChoice)
    {
    case 1 :
        userNumber = 0;

        printf("What do you want to do ?\n");
        printf("1. Add an item to the top of the list\n");
        printf("2. Add an item to a specific location in the list\n");
        printf("----------------------------------\n");
        printf(">> Your choice : ");

        scanf("%d", &secondUserChoice);

        if (secondUserChoice == 1)
        {
            printf(">> Please enter the number you want to put at the top of the list : ");
            scanf("%d", &userNumber);
            insertion(myList, userNumber);
        }
        else if (secondUserChoice == 2)
        {
            userPosition = 0;

            printf(">> Please enter the number you want to put on the list : ");
            scanf("%d", &userNumber);
            printf(">> After the position of which element you want to add your number : ");
            scanf("%d", &userPosition);
            insertAfterPosition(myList, userNumber, userPosition);
        }
        else
        {
            printf("ERROR...");
        }
        break;

    case 2 :

        printf("What do you want to do ?\n");
        printf("1. delete an item to the top of the list\n");
        printf("2. delete an item to a specific location in the list\n");
        printf("3. Delete all\n");
        printf("----------------------------------\n");
        printf(">> Your choice : ");

        scanf("%d", &secondUserChoice);

        if (secondUserChoice == 1)
        {
            deletion(myList);
            printf("The first item in the list has been removed\n");
        }
        else if (secondUserChoice == 2)
        {
            userPosition = 0;

            printf(">> What is the position of the number you want to delete : ");
            scanf("%d", &userPosition);

            deleteAtPosition(myList, userPosition);
        }
        else if (secondUserChoice == 3)
        {
            deleteAll(myList);
        }
        else
        {
            printf("ERROR...");
        }
        break;
    
    default:
        break;
    }

    } while (firstUserChoice == 1 || firstUserChoice == 2);

    deleteAll(myList);                                          //We free the space used by our variables

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                        END OF THE PROGRAM...                       |\n");   
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    
    return 0;
}
