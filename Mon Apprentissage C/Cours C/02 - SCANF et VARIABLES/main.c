#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //Presentation of types
    signed char signedChar = -50;           //-128 to 127                       [1 byte]    [NO DECIMAL]
    unsigned char unsignedChar = 50;        //0 to 255                          [1 byte]    [NO DECIMAL]

    int signedinteger = -10000;             //-32 768 to 32 767                 [2 byte]    [NO DECIMAL]
    unsigned int unsignedinteger = 10000;       //0 to 65 535                       [2 byte]    [NO DECIMAL]

    long signedLong = -80000;               //-2 147 483 648 to 2 147 483 647   [4 byte]    [NO DECIMAL]
    unsigned long unsignedLong = 80000;     //0 to 4 294 967 295                [4 byte]    [NO DECIMAL]

    float floatVariable = 50.43;            //Number with comma                 [4 byte]    [DECIMAL]
    double doubleVariable = 800.56;         //Number with comma                 [8 byte]    [DECIMAL]

    const unsigned int currentYear = 2024;   //Constant variable that can no longer be changed in the program.

    /*-----------------------------------*/

    printf("----------------------------\nList Variable:\n----------------------------\n");
    
    printf("char          : %10d !\n", signedChar);                        //%d for char variable
    printf("Unsigned char : %10u !\n", unsignedChar);             //%d for unsigned char variable

    printf("int           : %10d !\n", signedinteger);                      //%d for int variable
    printf("Unsigned int  : %10u !\n", unsignedinteger);           //%u for unsigned int variable

    printf("Long          : %10ld !\n", signedLong);                       //%ld for long variable
    printf("Unsigned Long : %10lu !\n", unsignedLong);            //%lu for unsigned long variable

    printf("Float         : %10f !\n", floatVariable);                    //%f for float variable
    printf("Double        : %10f !\n", doubleVariable);                  //%f for double variable

    printf("----------------------------\n");

    /*-----------------------------------*/

    int ageUser = 0;                        //Initialization of the varaible

    printf("Please tell us your age: ");
    scanf("%d", &ageUser);                  //Retrieves the data entered by the user. 
                                            //We first define the type of variable and then add the name where the data entered will be saved
    printf("Oh! You are %d years old !!\n", ageUser);
    printf("----------------------------\n");

    return 0;
}
