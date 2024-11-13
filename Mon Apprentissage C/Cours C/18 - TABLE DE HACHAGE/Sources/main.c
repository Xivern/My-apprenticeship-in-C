#include <stdio.h>
#include <stdlib.h>

#include "..\Headers\Student.h"
#include "..\Headers\Keyboard.h"

#define TABLE_SIZE 100

int main()
{
    //We are using the C89 version to create this code 

    //Chained lists have one big drawback: going through them can take a long time if they contain a lot of elements.
    //Using a hash table saves time in this respect.

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                       Welcome to the program                       |\n");
    printf("|                  We show you how to use hash table                 |\n");    
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/

    //INITIALIZE HASH TABLE --
    StudentElement* TwelfthGradeA[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        TwelfthGradeA[i] = NULL;
    }

    StudentElement* foundStudent = NULL;
    //------------------------

    int totalStudent = 0;
    char name[50];
    int age;
    double averageScore;

    printf("Please give me the student full name : ");
    secureRead(name, 50);
    printf("Please enter the age: ");
    age = secureReadINT();  
    printf("Please enter average score: ");
    averageScore = secureReadDOUBLE();  

    insertStudent(TwelfthGradeA, TABLE_SIZE, name, age, averageScore);
    totalStudent++;
    
    /*--------------------------------------------------------------------------------*/
    int userChoice = 0;

    do
    {    
        printf("----------------------------------------------------------------------\n");
        printf("|                 You currently have %03d students                    |\n", totalStudent);
        printf("|                      What do you want to do ?                      |\n");
        printf("----------------------------------------------------------------------\n");
        printf("1. Add a new student.\n");
        printf("2. Search information about an existing student.\n");
        printf("3. Leave the apps.\n");
        printf("----------------------------------------------------------------------\n");
        printf("Your choice :");
        userChoice = secureReadINT();

        switch (userChoice)
        {
        case 1:

            printf("Please give me the student full name : ");
            secureRead(name, 50);
            printf("Please enter the age: ");
            age = secureReadINT();  
            printf("Please enter average score: ");
            averageScore = secureReadDOUBLE();  

            insertStudent(TwelfthGradeA, TABLE_SIZE, name, age, averageScore);
            totalStudent++;

            break;
        
        case 2:
            
            //SEARCH THE STUDENT
            printf("Enter name of student to search : ");
            secureRead(name, 50);

            foundStudent = searchStudent(TwelfthGradeA, TABLE_SIZE, name);

            if (foundStudent != NULL) 
            {
                printf("> Student name : %s\n> Age : %d\n> Average Score: %.2f\n",
                foundStudent->name, foundStudent->age, foundStudent->averageScore);
            }
            else 
            {
                printf("Student not found.\n");
            }

            break;
        
        case 3:

            printf("Bye bye...\n");
            break;

        default:
            printf("Invalid choice. Please select 1, 2, or 3.\n");
            break;
        }
    } while (userChoice != 3);

    // FREE THE MEMORY
    freeHashTable(TwelfthGradeA, TABLE_SIZE);

    /*--------------------------------------------------------------------------------*/
    printf("----------------------------------------------------------------------\n");
    printf("|                        END OF THE PROGRAM...                       |\n");   
    printf("----------------------------------------------------------------------\n");
    /*--------------------------------------------------------------------------------*/

    return 0;
}