#include "..\Headers\tableManipulation.h"

void InsertDataToTable (int table[], int sizeTable, int value)
{
    printf("----------------------------------------\n");
    printf("We are going to write the value %d in all the cells of the table :\n", value);
    printf(">>-START-<<\n");
    /*-------------------------------*/
    for (int i = 0; i < sizeTable; i++)
    {
        table[i] = value;
    }
    /*-------------------------------*/
    printf(">>--END--<<\n");   
    printf("----------------------------------------\n");
}