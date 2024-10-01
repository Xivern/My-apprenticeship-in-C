#include "..\Headers\stringManipulation.h"

int numberCharacters(const char* string)
{
    char actualCharactere =0;
    int  nombreCharactere = 0;

    do
    {
        actualCharactere = string[nombreCharactere];        //We analyse the charactere
        nombreCharactere++;    
    } while (actualCharactere != '\0');                     //If the character is ‘\0’, this means that we have completed the array of characters. So we exit the loop
    
    nombreCharactere--;                                     //We delete the '\0' among the number of charactere we count

    return nombreCharactere;
}