#include <stdio.h>
#include <string.h>

// Function to reverse the string in place
void reverse(char *str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() 
{
    char str[] = "Hello, World!";  // You can change this string
    reverse(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
