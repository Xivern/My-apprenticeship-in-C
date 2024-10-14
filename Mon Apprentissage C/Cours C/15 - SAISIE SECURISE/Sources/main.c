#include <stdio.h>
#include <stdlib.h>

#include "..\Headers\Keyboard.h"

int main()
{
    //We are using the C89 version to create this code 

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                       Welcome to the program                       |\n");
    printf("|                We show you how to enter text securely              |\n");    
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    //"scanf" is easy to use but has a few weaknesses :
    //  > Does not take spaces
    //  > Can cause buffer overflows
    /*--------------------------------------------------------------------------------*/
    //FGETS (Prevents buffer overflow)
    char firstName[20];

    printf("Hello, can you tell me your name ?\n");
    printf("Your name : ");
    fgets(firstName, 20, stdin);                         //stdin means keyboard input
    printf("Nice to meet you %s", firstName);
    printf("---------------------------------\n");

    //Now, we are protected from buffer overflow but we have "\n" at the end of our string
    /*--------------------------------------------------------------------------------*/
    //We will create our own function with fgets but without "\n"
    char lastName[20];

    printf("What is your last name ?\n");
    printf("Your last name : ");
    secureRead(lastName, 20);                           //fgets but we replace \n with \0
    printf("Hello sir %s %s", lastName, firstName);
    printf("---------------------------------\n");

    //With this function, we delete the "\n" at the end of the character string
    /*--------------------------------------------------------------------------------*/
    //We have to solve the issue with the character that are stocked in the buffer area
    //We add a new function named "deletebuffer" on secureRead to avoid that issue
    
    printf("Soory, can you tell me again your last name ?\n");
    printf("Your last name : ");
    secureRead(lastName, 20);                           //fgets but we replace \n with \0
    printf("Hello sir %s %s", lastName, firstName);
    printf("---------------------------------\n");

    //Thanks to that modification, that work well
    /*--------------------------------------------------------------------------------*/
    //Now, we wil see the "strtol" function
    //STRTOL (Convert a string into a long)
    /*
    long exemple = 0;

    exemple = strtol( " 148", NULL, 10 );                           // exemple = 148
    exemple = strtol( " 148.215", NULL, 10 );                       // exemple = 148
    exemple = strtol( " 148.215", NULL, 10 );                       // exemple = 148
    exemple = strtol( " 148+34", NULL, 10 );                        // exemple = 148
    exemple = strtol( " 148 sheet of paper", NULL, 10 );            // exemple = 148
    exemple = strtol( " there are 2 sheets of paper", NULL, 10 );   // exemple = 0 (ERROR : must begin with a number)
    */
    /*--------------------------------------------------------------------------------*/
    long userAge = 0;

    printf("How old are you ?\n");
    printf("Your age : ");
    userAge = secureReadLONG();
    printf("So you are %ld years old\n", userAge);
    printf("---------------------------------\n");

    /*--------------------------------------------------------------------------------*/
    //Finally, we wil see the "strtod" function
    //STRTOD (Convert a string into a double)
    double userWeight = 0;

    printf("How much do you weigh ?\n");
    printf("Your weight : ");
    userWeight = secureReadDOUBLE();
    printf("So you weigh %f kilos\n", userWeight);

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                        END OF THE PROGRAM...                       |\n");   
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/
    
    return 0;
}
