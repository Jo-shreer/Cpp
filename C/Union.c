/*
A union is a collection of variables of different data types stored in the same memory location, 
meaning only one member can hold a value at any given time.
In a union, all members share the same memory location. 
The size of a union equals the size of its largest member. Only one member can be used at a time.
*/

#include <stdio.h>

// Define a union
union Data 
{
    int i;
    float f;
    char str[20];
};

int main() 
{
    union Data data;
    data.i = 10;
    printf("data.i = %d\n", data.i);

    data.f = 3.14;
    printf("data.f = %.2f\n", data.f);

    strcpy(data.str, "Hello");
    printf("data.str = %s\n", data.str);

    // Note: Accessing previous members now may give garbage values
    printf("data.i (now) = %d\n", data.i);  // May print garbage

    return 0;
}
