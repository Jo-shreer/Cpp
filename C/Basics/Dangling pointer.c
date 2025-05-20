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
