#include <stdio.h>

int* getPointer() {
    int x = 42;   // x is a local variable
    return &x;    // returning address of a local variable (bad!)
}

int main() {
    int *ptr = getPointer();
    printf("%d\n", *ptr);  // ⚠️ Undefined behavior: ptr is dangling
    return 0;
}


// OR

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 100;
    free(ptr);     // memory freed
    printf("%d\n", *ptr);  // ⚠️ Dangling pointer access
    return 0;
}
