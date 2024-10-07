#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\Headers\Ship.h"

void InitializeBoatData(Boat *MyStruct)         //We can use pointer to modify multiple data inside the structure
{
    MyStruct->price = 0;                        //When we use pointers, we have to write "pointer->data"
    MyStruct->enginePower = 0;                  //That means : "(*pointer.data)"
    MyStruct->size = 0.0;
    strcpy(MyStruct->name, "");
    strcpy(MyStruct->reference, "");
}