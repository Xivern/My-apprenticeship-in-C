#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\geometry.h"

static int integerGlobal = 0;                                       //Creation of a global variable accessible throughout the files
                                                                    //Without "static", the variable will be accessible throughout the project
                                                                    //If we put ‘static’ inside a function, then the variable will not be deleted at the end of the function call

static double areaCalculation(double _width, double _lenght);      //We call the function earlier in the program to inform the main function of the existence.
                                                            //This method is rarely used, We prefer to create additional files to insert prototypes
/*------------------------------------------------*/

int main(int argc, char const *argv[])
{
    double width = 0.0, lenght = 0.0;

    printf("Enter a length and width and I'll give you the area of the quadrilateral :\n");
    printf("Width : ");
    scanf("%lf", &width);
    printf("Lenght : ");
    scanf("%lf", &lenght);
    printf("Let me make the following calculation :\n");
    printf(">> %.2f x %.2f = %.2f cm2\n", width, lenght, areaCalculation(width, lenght));

    /*--------------------------------------------*/
    printf("-----------------------------------\n");

    double height = 0.0;

    printf("I will now give you the volume of your figure. Please enter the height :\n");
    printf("Height : ");
    scanf("%lf", &height);
    printf("Here's the calculation for the volume of your figure :\n");
    printf(">>  %.2f x  %.2f x  %.2f =  %.2f cm3\n", width, lenght, height, volume(width, lenght, height));

    /*--------------------------------------------*/
    printf("-----------------------------------\n");
    printf("You've entered the area calculation function %d times !\n", integerGlobal);
    printf("---------END OF THE PROGRAM--------\n");

    return 0;
}

/*------------------------------------------------*/
static double areaCalculation(double _width, double _lenght)    //"static" allows our function to be called only in this .c file 
{
    integerGlobal++;
    return (_width*_lenght);
}
/*------------------------------------------------*/