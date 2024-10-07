#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\Headers\Ship.h"

int main()
{
    //We are using the C89 version to create this code 

    /*-------------------------------------------------*/
    printf("---------------------------------------------\n");
    printf("|          Welcome to the program           |\n");
    printf("|   We show you how to use structure in  C  |\n");    
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/
    //STRUCTURE

    Boat racingBoat[2];          //We create a custom type named "Boat" and a table with 2 different boat (ship.h)

    for (int i = 0; i < 2; i++)
    {
        InitializeBoatData(&racingBoat[i]);     //We initialize the data contains inside the structure Boat
    }

    racingBoat[0].price = 890000;
    racingBoat[0].enginePower = 130;
    racingBoat[0].size = 20.2;
    strcpy(racingBoat[0].name, "the Destroyeur");
    strcpy(racingBoat[0].reference, "tD-eP13s20");

    racingBoat[1].price = 950000;
    racingBoat[1].enginePower = 180;
    racingBoat[1].size = 22.7;
    strcpy(racingBoat[1].name, "the Devil");
    strcpy(racingBoat[1].reference, "tD-eP18s22");
    /*-------------------------------------------------*/
    for (int i = 0; i < 2; i++)                             //Thanks to the structure, we can show multiple data with only one for loop
    {
        printf("The following information is available for the boat : \"%s\" :\n", racingBoat[i].name);
        printf("- Reference : %s\n", racingBoat[i].reference);
        printf("- Size      : %.3f m2\n", racingBoat[i].size);
        printf("- Power     : %6d kW\n", racingBoat[i].enginePower);
        printf("- Price     : %d Euros\n", racingBoat[i].price);   
        printf("---------------------------------------------\n");
    }
    /*-------------------------------------------------*/
    //ENUMERATION
    DemandProduct France;
    int choiceUser;
    int boolNoError;

    printf("Hello chief, what is the current demand for france ? (1, 2, 3)\n");
    printf("--------\n");
    printf("1. demand is low\n");
    printf("2. demand is medium\n");
    printf("3. demand is high\n");
    printf("--------\n");
    printf("Your response : ");

    // Loop to handle incorrect inputs
    while (1) {
        boolNoError = scanf("%d", &choiceUser);  // Retrieve user input
        
        if (boolNoError == 1 && choiceUser >= 1 && choiceUser <= 3) {
            // If the input is valid (integer between 1 and 3)
            break;
        } else {
            // If the input is invalid (non-integer or out of range)
            printf("ERROR... Please enter a valid choice between 1 and 3: ");
            
            // Clear the input buffer in case of incorrect input (e.g. text)
            while (getchar() != '\n');  // Discard any remaining characters in the input buffer
        }
    }
    
    France = choiceUser;

    switch (France)
    {
    case LOW :
        printf("We can reduce the production of boat in direction of france\n");
        break;
    
    case MEDIUM :
        printf("We have a sustained production rate\n");
        break;
    
    case HIGH :
        printf("We must increase the rate of production immediately !\n");
        break;

    default:
        printf("Something went wrong...\n");
        break;
    }
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/

    return 0;
}
