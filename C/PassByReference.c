#include <stdio.h>

void updateValue(int *x) 
{
    *x = 10;
}

int main() 
{
    int a = 5;
    printf("Before: a = %d\n", a);
    updateValue(&a);
    printf("After: a = %d\n", a);  // output 10
    return 0;
}
