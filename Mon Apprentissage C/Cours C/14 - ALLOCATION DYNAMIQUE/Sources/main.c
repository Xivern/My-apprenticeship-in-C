#include <stdio.h>
#include <stdlib.h>

#include "..\Headers\coordinates.h"

int main()
{
    //We are using the C89 version to create this code 

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                       Welcome to the program                       |\n");
    printf("| We show you how to create variables using dynamic allocation in  C |\n");    
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    //You can find out the size of the type you are using on your machine using the sizeof function
    printf("Sizes of different types on our machine :\n");
    printf("char : %lld bytes\n", sizeof(char));
    printf("int : %lld bytes\n", sizeof(int));
    printf("long : %lld bytes\n", sizeof(long));
    printf("double : %lld bytes\n", sizeof(double)); 
    /*--------------------------------------------------------------------------------*/
    //It is also possible to find out the size of the structures
    printf("Coordinate : %lld bytes\n", sizeof(Coordinates));
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/

    //Now, we will create our first dynamic allocation with malloc
    int *allocatedMemoryINT = NULL;                                 //This pointer will store the address dynamically allocated for an int
    allocatedMemoryINT = malloc(sizeof(int));                       //The malloc function writes the address that has been reserved to our pointer

    if (allocatedMemoryINT == NULL)                                 //We test "malloc"
    {
        printf("Critical ERROR : end of the programm...\n");
        exit(0);                                                    //We stop the program
    }

    printf("Here is the address we have dynamically allocated : %p\n", (void*)allocatedMemoryINT);
    /*--------------------------------------------------------------------------------*/
    //We can do what we want with the variable now

    printf("Give me a number between 1 and 100 :\n");
    printf("Your number (1 - 100) : ");
    scanf("%d", allocatedMemoryINT);

    while ((*allocatedMemoryINT < 1) || (*allocatedMemoryINT > 100))
    {
        printf("(!!) Not within the range, try again (1 - 100) : ");
        scanf("%d", allocatedMemoryINT);
    }
    
    printf("You have chosen the number %d !\n", *allocatedMemoryINT);

    /*--------------------------------------------------------------------------------*/
    free(allocatedMemoryINT);                                       //We release the allocated memory (Very important !)
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    //Use cases with dynamic tables
    int numberFamily = 0;
    int *ageFamily = NULL;

    printf("How many people are in your family ?\n");
    printf("Response : ");
    scanf("%d", &numberFamily);

    ageFamily = malloc(numberFamily * sizeof(int));

    if (ageFamily == NULL)
    {
        printf("Critical ERROR : end of the programm...\n");
        exit(0);
    }

    printf("Give me the ages of your family members :\n");
    
    for (int i = 0; i < numberFamily; i++)
    {
        printf(">> Age of member %d : ", i+1);
        scanf("%d", &ageFamily[i]);
    }

    printf("-------------\n");
    printf("Your family has the following ages :\n");

    for (int i = 0; i < numberFamily; i++)
    {
        printf("Member %d : %d years old.\n", i+1, ageFamily[i]);
    }    

    /*--------------------------------------------------------------------------------*/
    free(ageFamily);
    /*--------------------------------------------------------------------------------*/

    printf("----------------------------------------------------------------------\n");
    printf("|                        END OF THE PROGRAM...                       |\n");   
    printf("----------------------------------------------------------------------\n");

    return 0;
}
