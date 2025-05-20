
#include <stdio.h>

void changePointer(int **p) {
    static int x = 10;
    *p = &x;  // Change the pointer to point to x
}

int main() {
    int *ptr = NULL;
    changePointer(&ptr);  // Pass address of ptr
    printf("Value pointed to by ptr: %d\n", *ptr);
    return 0;
}
