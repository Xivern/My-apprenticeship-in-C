#include <string.h>         //This library can be used to add functions for manipulating character arrays

#include "..\Headers\stringManipulation.h"

int main()
{
    //We are using the C89 version to create this code 

    /*-------------------------------------------------*/
    printf("---------------------------------------------\n");
    printf("|          Welcome to the program           |\n");
    printf("| We show you how to manipulate characteres |\n");    
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/
    char letter = 'A';                                                          //We mainly use the ‘char’ type for letters (only one)

    printf("> Number representing the letter %c in C : %d\n", letter, letter);  //Using the ASCII table (0 to 127)
    /*-------------------------------------------------*/
    char hellophrase[] = " Hello";                                              //We can only write to the array in this way during initialisation
    char worldPhrase[6];                                                        //Don't forget to add one more cell to stock "\0"

    worldPhrase[0] = 'W';
    worldPhrase[1] = 'o';
    worldPhrase[2] = 'r';
    worldPhrase[3] = 'l';
    worldPhrase[4] = 'd';
    worldPhrase[5] = '\0';                                                      //Not essential, during the initialisation, all the cells are initialized with the symbol "\0"

    printf("> Now my sentence is : %s%s\n", hellophrase, worldPhrase);
    printf("--------------------------------------------\n");
    /*-------------------------------------------------*/
    char userName[50];
    char copyUserName[50];                                                     //Variable used to present the strcpy function

    printf("Can you tell me your name : ");
    scanf("%s", userName);
    printf("Hello %s ! Nice to meet you.\n", userName);

    strcpy(copyUserName, userName);                                             //Function that copy one string within another
    printf("I save your name on a new variable : %s\n", copyUserName);
    strcat(copyUserName, hellophrase);
    printf("%s !\n", copyUserName);                                             //Used to concatenate string 1 and 2 in string 1
    /*-------------------------------------------------*/
    int numberLettersWithStrlen = strlen(userName);                             //Count the number of charactere with the strlen
    int nbrLettersWithMyFunction = numberCharacters(userName);                  //Count the number of charactere with my own function

    printf("-----------STATISTIC OF YOUR NAME-----------\n");
    printf("Number of characters with the strlen function : %d\n", numberLettersWithStrlen);
    printf("Number of characters with my function : %d\n", nbrLettersWithMyFunction);    
    printf("--------------------------------------------\n");
    /*-------------------------------------------------*/
    char inBrief[100];

    sprintf(inBrief, "%s ! you have %d letters in your name.", copyUserName, nbrLettersWithMyFunction);
    printf(">> To summarize : %s\n", inBrief);
    printf("--------------------------------------------\n");

    return 0;
}