/*
Function pointers in C are pointers that point to a function instead of a data value. They are used for:
Implementing callback functions
Creating tables of functions
Dynamic function dispatch
*/


#include <stdio.h>

// A simple function that we will point to
void greet() 
{
    printf("Hello from a function pointer!\n");
}

int main() {
    // Declare a function pointer
    void (*funcPtr)();

    // Point it to the greet function
    funcPtr = greet;

    // Call the function using the pointer
    funcPtr();

    return 0;
}
