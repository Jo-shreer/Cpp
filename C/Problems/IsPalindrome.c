#include <stdio.h>

int is_palindrome(const char *str) {
    const char *start = str;
    const char *end = str;

    // Move end pointer to the last character (before null terminator)
    while (*end != '\0') {
        end++;
    }
    end--;  // Step back from '\0' to last character

    // Compare characters from start and end moving towards center
    while (start < end) {
        if (*start != *end) {
            return 0;  // Not palindrome
        }
        start++;
        end--;
    }
    return 1;  // Is palindrome
}

int main() {
    const char *test = "madam";
    printf("%s is %sa palindrome\n", test, is_palindrome(test) ? "" : "not ");
    return 0;
}
