#include <stdio.h>

// Define a struct for a person
struct Person 
{
    char name[50];
    int age;
};

int main() 
{
    // Create a variable of type struct Person
    struct Person person1;

    // Assign values to the fields
    strcpy(person1.name, "Alice");
    person1.age = 25;

    // Print the values
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);

    return 0;
}
