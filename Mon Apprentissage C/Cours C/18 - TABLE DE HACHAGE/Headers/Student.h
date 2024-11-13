/*
/-Student.h
/-HEADER
/-Role: Stock prototypes related to the student
*/

#ifndef Student_h
#define Student_h

typedef struct StudentElement StudentElement;
struct StudentElement
{
    char name[100];
    int age;
    double averageScore;
    StudentElement *next;
};

/*----------------------------------------*/
void insertStudent(StudentElement* table[], int size, char* name, int age, double averageScore);
/*----------------------------------------*/
StudentElement* searchStudent(StudentElement* table[], int size, char* name);
/*----------------------------------------*/
void freeHashTable(StudentElement* table[], int size);
/*----------------------------------------*/

#endif /* Student_h */