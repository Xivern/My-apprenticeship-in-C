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

    List *myList = NULL;

    myList = Initialize();

    insertion(myList, 10);
    insertion(myList, 20);
    insertion(myList, 30);
    insertion(myList, 40);

    showList(myList);

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                        END OF THE PROGRAM...                       |\n");   
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    
    return 0;

}
