/*
/-Stack.h
/-HEADER
/-Role: Stock prototypes related to the stack explanation
*/

#ifndef Stack_h
#define Stack_h

typedef struct StackElement StackElement;
struct StackElement
{
    int number;
    StackElement *next;
};

typedef struct Stack Stack;
struct Stack
{
    StackElement *first;
};

/*----------------------------------------*/
Stack *stackInitialize();
/*----------------------------------------*/
void stacking(Stack *stack, int newNumber);
/*----------------------------------------*/
int unstacking(Stack *stack);
/*----------------------------------------*/
void showStack(Stack *stack);
/*----------------------------------------*/

#endif /* Stack_h */