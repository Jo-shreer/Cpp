#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *ptr = (int*) malloc(sizeof(int));
    *ptr = 42;
    free(ptr);   // Free the dynamically allocated memory (ptr becomes a dangling pointer)
    *ptr = 10;    // Dangling pointer dereferenced – undefined behavior

    //fix
   free(ptr);
   ptr = NULL;
   return 0;
}
