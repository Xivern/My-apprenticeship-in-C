#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    //Presentation of the while loop
    /*
    When running a while loop, we first check if the condition is met.
    If this is not the case, we then execute the code  
    */
    int loopIteration = 0;

    printf("-------START OF LOOP WHILE-------\n");
    while (loopIteration <= 5)
    {
        printf("Iteration : %d\n", loopIteration);
        loopIteration++;
    }
    printf("---------------END---------------\n");

    /*------------------------------------------*/

    //Presentation of the do while loop
    /*
    Unlike the while loop, we execute at least once the code before checking if the condition is good
    */
    int loopIteration2 = 0;

    printf("------START OF LOOP DO WHILE-----\n");
    do
    {   
        printf("Iteration : %d\n", loopIteration2);
        loopIteration2++;
    } while (loopIteration2 <= 5);
    printf("---------------END---------------\n");

    //Presentation of the for loop
    /*
    Allows you to perform a certain number of times one or more actions
    */

    printf("--------START OF LOOP FOR--------\n");
    for (int i = 0; i <= 10; i++)
    {
        if (i == 0)
        {
            continue;                       //Allows to ignore the current iteration action
        }
        else if (i == 6)
        {
            break;                          //Allows to immediately exit the loop
        }
        printf("Iteration : %d\n", i);        
    }
    printf("---------------END---------------\n");
    
    return 0;
}
