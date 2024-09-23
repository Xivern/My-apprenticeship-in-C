#include <stdlib.h>
#include <stdio.h>

//presentation of functions
/*-------------------------------------------------------*/
int tenfold(int number)
{   
    int result = 0;             //Initialise the variable we require for the function

    result = number*10;         //Fill in the instructions here

    return result;              //Return the result. The variable type must be the same as the function type.
    //return 3*nombre;          //We can also perform the same function with a single line
}
/*-------------------------------------------------------*/
int additionINT(int a, int b)
{
    return a+b;
}
/*-------------------------------------------------------*/
void sayHELLO()
{
    printf("HelloWorld !\n");
}
/*-------------------------------------------------------*/
int main(int argc, char const *argv[])
{
    int numberA = 0, numberB = 0, additionResult;

    sayHELLO();

    while (numberA == 0 && numberB == 0)
    {
        printf("Please enter 2 numbers, I'll add them up for you.\n");
        printf("Your first number  : ");
        scanf("%d", &numberA);
        printf("Your second number : ");
        scanf("%d", &numberB);

        printf("Let me make the following calculation :\n>> %d + %d", numberA, numberB);
        additionResult = additionINT(numberA, numberB);
        printf(" = %d\n", additionResult);

        printf("--------------------------\n");
        printf("If we multiply the result by 10, we have the following result :\n");
        printf(">> %d * 10 = %d\n", additionResult, tenfold(additionResult));               //We can also avoid creating a new variable to store the result
        printf("--------------------------\n");

        printf("END of the program...");
    }
    
    return 0;
}
