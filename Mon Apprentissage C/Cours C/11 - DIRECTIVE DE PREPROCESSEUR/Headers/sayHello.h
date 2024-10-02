/*
/-sayHello.h
/-HEADER
/-Role: Say Hello to the user via the terminal 
*/
/*--------------------------------------------*/
#ifndef sayHello_h          //If the constant has not been defined, the file has never been included
#define sayHello_h          // Define the constant so that next time the file is not included.
/*--------------------------------------------*/
#define HELLO   "Hello World !!"
/*--------------------------------------------*/

void HelloWorld();

/*--------------------------------------------*/
#endif /* sayHello_h */     //End of #ifndef to avoid infinite inclusion