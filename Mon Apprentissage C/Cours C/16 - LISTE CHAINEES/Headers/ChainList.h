/*
/-ChainList.h
/-HEADER
/-Role: Stock prototypes related to the chain list explanation
*/

#ifndef ChainList_h
#define ChainList_h

typedef struct Element Element;
struct Element
{
    int number;                     //DATA : In this example we choose an integer
    Element *next;                  //A pointer is used to link the elements together
};

typedef struct List List;
struct List
{
    Element *first;                 //Contains a pointer to the first element of the list 
};

/*----------------------------------------*/
List *Initialize();
/*----------------------------------------*/
void insertion(List *list, int newNumber);
/*----------------------------------------*/
void deletion(List *list);
/*----------------------------------------*/
void showList(List *list);
/*----------------------------------------*/

#endif /* ChainList_h */