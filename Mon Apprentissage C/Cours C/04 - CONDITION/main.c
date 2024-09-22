#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*----------------------------------------------------*/
    printf("----------------------------------------------\n");
    
    //Presentation of the condition if...else
    int numberA = 0, numberB = 0;

    printf("Please enter 2 numbers and I will indicate the highest number !\n");
    printf("Number A : ");
    scanf("%d", &numberA);
    printf("Number B : ");
    scanf("%d", &numberB);

    if (numberA > numberB)          //This is a condition : if A is greater than B
    {
        printf("The number \"%d\" is greater than the number \"%d\"\n", numberA, numberB);
    }
    else if (numberA < numberB)     //This is a condition : if B is greater than A
    {
        printf("The number \"%d\" is greater than the number \"%d\"\n", numberB, numberA);
    }
    else                            //This is a condition : if the first two conditions are false
    {
        printf("The numbers \"%d\" and \"%d\" are equal\n", numberA, numberB);
    }

    /*----------------------------------------------------*/
    printf("----------------------------------------------\n");

    //Presentation of the condition switch
    int scaleOfRichter = 0;

    printf("You want to learn more about the earthquakes ?\n");
    printf("Give me a number between 1 and 9 on the scale of Richter and I will give you the effects : ");
    scanf("%d", &scaleOfRichter);

    switch (scaleOfRichter)
    {
        case 1:
            printf("[MICRO] : Not felt or rarely.\n");
            break;
        
        case 2:
            printf("[MINOR] : Lightly felt.\n");
            break;
        
        case 3:
            printf("[MINOR] : Often felt but rarely causes damage.\n");
            break;
        
        case 4:
            printf("[LIGHT] : Felt but causes little to no damage.\n");
            break;

        case 5:
            printf("[MODERATE] : Felt by everyone, damage to fragile buildings.\n");
            break;
        
        case 6:
            printf("[STRONG] : Felt in the surroundings, moderate to severe damage.\n");
            break;

        case 7:
            printf("[MAJOR] : Felt over a wide area, severe damage.\n");
            break;

        case 8:
            printf("[DEVASTATING] : Felt over immense areas, very severe damage.\n");
            break;
        
        case 9:
            printf("[DEVASTATING] : (Almost) total destruction, permanent ground alterations.\n");
            break;        

        default:
            printf("There must be an error...\n");
            break;
    }

    /*----------------------------------------------------*/
    printf("----------------------------------------------\n");
    
    printf("END OF THE PROGRAM...\n");

    return 0;
}
