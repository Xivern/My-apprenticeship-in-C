#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\Headers\Keyboard.h"

static void deleteBuffer()                  //We don't want to share that function to another files
{
    int c = 0;

    while (c != '\n' && c != EOF)
    {
        c = getchar();                      //As long as we haven't found any return, we empty the buffer
    }
    
}

int secureRead(char *chain, int chainSize)
{
    char *position = NULL;

    if (fgets(chain, chainSize, stdin) != NULL)
    {
        position = strchr(chain, '\n');             //We are looking for \n

        if (position != NULL)                       //Found !
        {
            *position = '\0';                       //We replace \n with \0 (position currently points to its address, so we modify it directly)
        }
        else                                        //If we don't found '\n' character : thats means the user has exceeded the allocated memory
        {
            deleteBuffer();
        }
        return 1;
    }
    
    deleteBuffer();                         //ANY ERROR ? We delete everything inside the buffer
    
    return 0;                               //ERROR
}

int secureReadINT()
{
    char numberToInt[50] = {0};

    if (secureRead(numberToInt, 50))
    {
        return atol(numberToInt);           //Read OK : We return the int value
    }
    
    return 0;       //ERROR
}

long secureReadLONG()
{
    char numberToLong[50] = {0};

    if (secureRead(numberToLong, 50))
    {
        return strtol(numberToLong, NULL, 10);    //Read OK : We return the long value
    }
    
    return 0;       //ERROR
}

double secureReadDOUBLE()
{
    char numberToDouble[50] = {0};
    char *replacePosition = NULL;

    if (secureRead(numberToDouble, 50))
    {
        replacePosition = strchr(numberToDouble, ',');  //We want to search if the user use ','

        if (replacePosition != NULL)                    //Found
        {
            *replacePosition = '.';
            
            return strtod(numberToDouble, NULL);            //READ OK : We return double value
        }
        else
        {
            return strtod(numberToDouble, NULL);            //READ OK : We return double value
        }
    }

    return 0;
}