#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int addition, subtraction, multiplication, divisionINT;
    float divisionFLOAT;

    printf("----------------------------------\n");
    printf("   Mathematics with language C\n");
    printf("----------------------------------\n");

    //Example of an addition in C with the sign "+" 
    addition = 11+5;
    printf("Addition of 11 and 5         = %03d \n", addition);

    //Example of an subtraction in C with the sign "-" 
    subtraction = 11-5;
    printf("subtraction of 11 and 5      = %03d \n", subtraction);

    //Example of an multiplication in C with the sign "*" 
    multiplication = 11*5;
    printf("multiplication of 11 and 5   = %03d \n", multiplication);

    //Example of an division in C with the sign "/" 
    divisionINT   = 11/5;
    divisionFLOAT = 11.0/5.0;
    printf("division of 11 and 5 [int]   = %03d \n", divisionINT);
    printf("division of 11 and 5 [float] = %.1f \n", divisionFLOAT);

    //typical example of using modulo in C with the sign "%"
    int userValue;
    int heures, minutes;

    printf("----------------------------------\n");
    printf("Hi, give me minutes and I'll tell you how many hours it is : ");
    scanf("%d", &userValue);

    //Calculation
    heures  = userValue/60;
    minutes = userValue%60;

    //Result
    printf("For %d minutes, it's been %d hours and %d minutes !\n", userValue, heures, minutes);

    /*------------------------------------------------------------------------------------------*/

    int absoluteINT = -50;
    double power = 5;

    printf("----------------------------------\n");
    printf("     Using MATH.H language C      \n");
    printf("----------------------------------\n");

    //example of the absolute value for an integer in C
    printf("Value before absolute value calculation : %03d \n", absoluteINT);
    absoluteINT = abs(absoluteINT);                                                 //Function : int abs(int n); (https://en.cppreference.com/w/c/numeric/math/abs)
    printf("Value after absolute value calculation  : %03d \n", absoluteINT);

    //example of the power function for an integer in C
    printf("The result for 10^%.0f = ", power);
    power = pow(10, power);                                                         //Function : double pow(double base, double exponent); (https://en.cppreference.com/w/c/numeric/math/pow)
    printf("%.0f \n", power);

    printf("----------------------------------\n");

    return 0;
}
