#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\Headers\Student.h"
#include "..\Headers\Hash.h"

void insertStudent(StudentElement* table[], int size, char* name, int age, double averageScore) 
{
    int index = basicHashing(name, size);

    // CREATE & INITIALIZE THE NEW ELEMENT
    StudentElement* newStudent = NULL;
    newStudent = malloc(sizeof(*newStudent));

    if (newStudent == NULL) 
    {
        printf("ERROR : MEMORY ALLOCATION FAILED...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        strcpy(newStudent->name, name);
        newStudent->age = age;
        newStudent->averageScore = averageScore;
        newStudent->next = NULL;
    }

    // COLLISION MANAGEMENT BY CHAINING
    if (table[index] == NULL) 
    {
        table[index] = newStudent;
    } 
    else 
    {
        newStudent->next = table[index];
        table[index] = newStudent;
    }
}

StudentElement* searchStudent(StudentElement* table[], int size, char* name) 
{
    int index = basicHashing(name, size);

    StudentElement* current = NULL;
    current = table[index];

    // SCANS THE CHAINED LIST AT THIS INDEX
    while (current != NULL) 
    {
        if (strcmp(current->name, name) == 0) 
        {
            return current; // Student found
        }
        else
        {
            current = current->next;
        }
    }

    return NULL; // Student not found
}

void freeHashTable(StudentElement* table[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        StudentElement* current = NULL;
        current = table[i];

        while (current != NULL)
        {
            StudentElement* toFree = NULL;
            toFree = current;
            current = current->next;

            free(toFree);
        }

        table[i] = NULL;
    }
}