/*
/-Ship.h
/-HEADER
/-Role: Stock prototypes related to the manipulation of table
*/

#ifndef Ship_h
#define Ship_h

typedef struct Boat Boat;   //Means that writing the word "Boat" is now equivalent to writing "struct Boat"
struct Boat                 //create structure that contains different type within it
{
    int price;              //Boat price
    int enginePower;        //Boat engine power (kW)

    double size;            //Boat size (m2)
    
    char name[50];          //Boat's name    
    char reference[30];     //Boat's reference
};

enum DemandProduct
{
    LOW = 1, MEDIUM = 2, HIGH = 3
};
typedef enum DemandProduct DemandProduct;

void InitializeBoatData(Boat *MyStruct);

#endif /* Ship_h */