
/*What happens if you free the same pointer twice?*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *p = (int *)malloc(sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 42;
    printf("Value: %d\n", *p);

    free(p);   // ✅ First free is correct
    free(p);   // ❌ Second free causes undefined behavior

    printf("Program finished\n");

    return 0;
}
