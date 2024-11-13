#include <stdio.h>
#include <stdlib.h>

#include "..\Headers\Hash.h"

int basicHashing(char *chain, int size)
{
    int hashNumber = 0;

    for (int i = 0; chain[i] != '\0'; i++)
    {
        hashNumber += chain[i];
    }
    
    hashNumber %= size;

    return hashNumber;
}