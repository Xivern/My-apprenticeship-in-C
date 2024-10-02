#include <stdlib.h>                                         //Lines with the # symbol are what we call preprocessor directives 
#include <stdio.h>                                          //Use #include to include one file in another

#include "..\Headers\sayHello.h"
/*----------------------------*/
#define MAX_SIZE    100                                     //We can give a value to a word without using memory and which can be used throughout the file.
                                                            //Most of the time, we add a #define to a header file
/*----------------------------*/
#define MACRO()     printf("Message send by my macro\n"); \
                    printf("I can also write multiple line\n");\
                    printf("I just need to put \\ at the end of my lineof code\n");

#define ADULT(age)  if (age >= 18)\
                        printf("You are an adult !\n");\
                    else\
                        printf("You're not an adult\n");
/*----------------------------*/
#if condition                                                           //We can also add condition in preprocessor language
    /* Source code to compile if condition is true */
#elif condition2
    /* Otherwise if condition 2 is true compile this source code */
#endif
/*----------------------------*/

int main()
{
    //We are using the C89 version to create this code 

    /*-------------------------------------------------*/
    printf("---------------------------------------------\n");
    printf("|          Welcome to the program           |\n");
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/
    char Table1[MAX_SIZE] = "First table", Table2[MAX_SIZE] = "Second table";       //We use the value of MAX_SIZE to define the maximum value for our tables
    
    printf("Inside the first table : %s\n", Table1);
    printf("Inside the second table : %s\n", Table2);

    HelloWorld();
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/
    //There are also predefined preprocessor directives : 
    printf("- Current line in the code : %d\n", __LINE__);
    printf("- File where the main code is executed : \"%s\"\n", __FILE__);
    printf("- Today's date : %s\n", __DATE__);
    printf("- Current time : %s\n", __TIME__);
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/
    //We can also use macro to write code with #define
    MACRO();                                                                        //The compiler will see the following line : printf("Message send by my macro\n");
    printf("---------------------------------------------\n");
    ADULT(17);                                                                      //We can also add parameters to our #define
    printf("---------------------------------------------\n");
    /*-------------------------------------------------*/
    return 0;
}
