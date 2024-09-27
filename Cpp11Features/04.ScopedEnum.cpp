#include <iostream>

// Defining a scoped enum
enum class Color {
    Red,
    Green,
    Blue
};

// Defining another scoped enum
enum class Fruit {
    Apple,
    Banana,
    Cherry
};

int main() 
{
    Color color = Color::Red; // Using the scoped enumerator
    Fruit fruit = Fruit::Apple;

    // Using switch-case with scoped enums
    switch (color) {
        case Color::Red:
            std::cout << "Color is Red" << std::endl;
            break;
        case Color::Green:
            std::cout << "Color is Green" << std::endl;
            break;
        case Color::Blue:
            std::cout << "Color is Blue" << std::endl;
            break;
    }

    // Uncommenting the following line would cause a compile-time error
    // std::cout << color << std::endl; // Error: cannot convert 'Color' to 'int'

    return 0;
}
