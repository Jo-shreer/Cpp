#include <iostream>
constexpr int getSquare(int x) {  //constexpr function
    return x * x;                 // This will be evaluated at compile time
}

int main() {
    constexpr int squareOfFive = getSquare(5); // Evaluated at compile time
    std::cout << "Square of 5 is: " << squareOfFive << std::endl;
    return 0;
}
