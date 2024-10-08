#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    //We are using the C89 version to create this code 

    /*-------------------------------------------------*/
    printf("---------------------------------------------\n");
    printf("|          Welcome to the program           |\n");
    printf("|    We show you how to manage file in  C   |\n");    
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/
    //HOW TO OPEN A FILE
    /*------------------------------------------------------------------------------------------------*/
    /*                                  Prototype of the fopen function                               */
    /*                       FILE* fopen(const char* fileName, const char* openingMode);              */
    /*                                                                                                */
    /* > fileName     : name of the file we want to manage                                            */
    /* > opening mode : What we want to do with the file                                              */
    /*      - "r" : read only.                                  (File must be created before)         */
    /*      - "w" : write only.                                 (File will be create if not existing) */
    /*      - "a" : add mode.                                   (File will be create if not existing) */
    /*      - "a+": read/write addition at the end              (File will be create if not existing) */
    /*      - "r+": read and write                              (File must be created before)         */
    /*      - "w+": read and write, deleting the contents first (File will be create if not existing) */
    /*------------------------------------------------------------------------------------------------*/

    FILE* myFile = NULL;                                //We create a pointer that will be used to manage the file
    
    myFile = fopen("Ressources/test.txt", "w+");     //We create the file "text.txt" located at the Ressources folder and we can only read and write

    if (myFile != NULL)                                 //Check that the file has opened without a problem 
    {   
        //HOW TO WRITE TO A FILE
        /*------------------------------------------------------*/
        /*  - "fputc"   : writes a character to the file        */
        /*  - "fputs"   : writes a string to the file           */
        /*  - "fprintf" : writes a formatted string to the file */
        /*------------------------------------------------------*/

        fputc('A', myFile);     //We write only the character "A"
        /*------------------------------------------------------*/
        fputs(" 0 1 2\nNow, We write a string of characters using the \"fputs\" function !\n", myFile);     //We write a string of characters
        /*------------------------------------------------------*/
        char firstName[30], lastName[30];

        printf("I'd like to store some information about you. Can you give me your full name ?\n");
        printf("First name : ");
        scanf("%s", firstName);
        printf("Last name : ");
        scanf("%s", lastName);
        
        fprintf(myFile, "The user's name is %s %s", firstName, lastName);
        /*------------------------------------------------------*/
        rewind(myFile);                                                 //We need to reposition our cursor at the beginning of the file to read it
        /*------------------------------------------------------*/
        //HOW TO READ A FILE
        /*---------------------------------------------------*/
        /*  - "fgetc"  : read a character from a file        */
        /*  - "fgets"  : read a string from a file           */
        /*  - "fscanf" : read a formatted string from a file */
        /*---------------------------------------------------*/

        printf("---------------------------------------------\n");
        int fgetcLoop = 0, actualCharacter = 0;

        while (actualCharacter != EOF)                              //The loop continue until we are at the end of the file
        {
            actualCharacter = fgetc(myFile);
            printf("%c", actualCharacter);
            fgetcLoop++;
        }                     
        printf("\n>> Your file have %d characters\n", fgetcLoop);
        rewind(myFile);
        printf("---------------------------------------------\n");

        /*---------------------------------------------------*/  
        int  fgetsloop = 0;
        char actualLine[MAX_SIZE] = "";

        while (fgets(actualLine, MAX_SIZE, myFile) != NULL)         //The loop continue until we are at the end of the file
        {
            printf("%s", actualLine);                               //We read the current line contained in the array of characters
            fgetsloop++;
        }
        printf("\n>> Your file have %d lines\n", fgetsloop);
        rewind(myFile);
        printf("---------------------------------------------\n");

        /*---------------------------------------------------*/  
        int number[3]={0};

        fscanf(myFile, "A %d %d %d", &number[0], &number[1], &number[2]);                                   //We put the number from my file to the table "number"
        printf("The secret value from my file are : %d, %d and %d\n", number[0], number[1], number[2]);
        printf("---------------------------------------------\n");
        /*---------------------------------------------------*/          
        //HOW TO USE THE CURSOR IN A FILE
        /*---------------------------------------------------------------*/
        /*  - "ftell"  : indicates your current position in the file     */
        /*  - "fseek"  : positions the cursor at a precise point         */
        /*  - "rewind" : returns the cursor to the beginning of the file */
        /*---------------------------------------------------------------*/
        long positionMyFile = 0;
        positionMyFile = ftell(myFile);                                                     //Give to the variable "positionMyfile" the actual position of the cursor
        printf("- Your cursor is actually after the characters %ld !\n", positionMyFile);

        fseek(myFile, 5, SEEK_CUR);     //I move my cursor forward 5 characters
        fseek(myFile, 0, SEEK_SET);     //I put my cursor to the begining of the file
        fseek(myFile, 0, SEEK_END);     //I put my cursor at the end of my file

        rewind(myFile);                 //I put my cursor to the begining of the file

        fclose(myFile);     //We close the file
    }
    else
    {
        printf("Something went wrong with the file : \"text.txt\"...\n");
    }

    printf("---------------------------------------------\n");
    
    /*---------------------------------------------------*/  
    /*BONUS : renaming and deleting a file*/

    int userChoice = 0;

    printf("To guarantee the confidentiality of your data, you have a choice :\n");
    printf("- If you want to save your data in the \"Saves\" location, type 1\n");
    printf("- If you want to delete your data permanently, type 2\n");
    printf("- If you just want to quit the program, type 3\n");
    printf("Your response : ");

    scanf("%d", &userChoice);
    printf("---------------------------------------------\n");

    switch (userChoice)
    {
    case 1 :

        remove("Saves/Save_test.txt");                               //Delete the last save
        rename("Ressources/test.txt", "Saves/Save_test.txt");     //Move the file test.txt and rename it
        printf("Save done !\n");
        break;

    case 2 :
        remove("Ressources/test.txt");                               //Delete the file test.txt
        printf("Data removed !\n");
        break;
    
    default:
        break;
    }
    
    printf("BYE BYE...\n");
    printf("---------------------------------------------\n");

    return 0;
}
