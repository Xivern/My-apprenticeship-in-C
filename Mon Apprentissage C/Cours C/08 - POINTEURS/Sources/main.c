#include "..\Headers\timeday.h"

int main()
{
    /*-----------------------------------------------*/
    printf("----------------------------------------\n");
    printf("Welcome to the program\n");
    printf("We convert minutes to hours and minutes !\n");
    
    /*-----------------------------------------------*/
    int hours = 0, minutes = 0;

    printf("Please, enter the minutes you want me to convert : ");
    scanf("%d", &minutes);
    
    /*-----------------------------------------------*/
    int *ptrHours = &hours, *ptrMinutes = &minutes;                     //* means that we are creating a pointer, 
                                                                        //It is very important to initialise it with "NULL" if we don't put an adress to it

    printf("----------------------------------------\n");
    printf("Address where we can find the value of the variable minute: %p\n", (void*)ptrMinutes);      //Address of the 'minute' variable stored in the pointer
    printf("Value of the variable minute : %d\n", *ptrMinutes);                                         //Value of the variable to which the pointer points 
    printf("----------------------------------------\n");
    
    /*-----------------------------------------------*/
    /*WE CAN USE 2 METHOD FOR SETTING PARAMETERS TO A POINTER*/
    minuteToHour(ptrHours, ptrMinutes);                                 //Using pointers, we can modify the two variables
    //minuteToHour(&hours, &minutes);

    printf(">> RESULT : %d Hours %d minutes\n", hours, minutes);
    //printf(">> RESULT : %d Hours %d minutes", *ptrHours, *ptrMinutes);

    printf("-----------END OF THE PROGRAM-----------\n");

    return 0;
}