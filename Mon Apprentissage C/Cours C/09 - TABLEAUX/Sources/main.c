#include "..\Headers\tableManipulation.h"

int main()
{
    //We are using the C89 version to create this code 

    /*-------------------------------------------------*/
    printf("----------------------------------------\n");
    printf("|        Welcome to the program        |\n");
    printf("|     We show you how a table works    |\n");    
    printf("----------------------------------------\n");
    /*-------------------------------------------------*/
    int integerTable[10] = {0};                             //That how we define table : type name[size].
                                                            //We can also initialize the table with the "{0}" or use the "for loop".

    printf("Table adress : %p\n", (void*)integerTable);     //without any range, the "integerTabel" work like a pointer
    printf("----------------------------------------\n");

    //Then we can put data in the table
    for (int i = 0; i < 10; i++)
    {
        integerTable[i] = i;
        /*
        That loop means :
        integerTable[0] = 0;
        integerTable[1] = 1;
        ...
        integerTable[9] = 9;
        */
       printf("Value of cell %d in the table : %d\n", i, *(integerTable+i));    //Show the user the data contained in each cell of the table with pointers
       //printf("Value of cell %d in the table : %d\n", i, integerTable[i]);    //Other way to show to the user the data contained in each cell of the table
    }
    /*-------------------------------------------------*/
    InsertDataToTable(integerTable, 10, 100);    //We duplicate the value 100 to all the cells inside the table

    //Let's take a look at each cell
    for (int i = 0; i < 10; i++)
    {
       printf("Value of cell %d in the table if now : %d\n", i, *(integerTable+i));     //Show the user the data contained in each cell of the table with pointers
       //printf("Value of cell %d in the table : %d\n", i, integerTable[i]);            //Other way to show to the user the data contained in each cell of the table
    }
    printf("----------------------------------------\n");
    /*-------------------------------------------------*/

    return 0;
}
