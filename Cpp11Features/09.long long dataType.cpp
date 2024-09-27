#include <iostream>

int main() 
{
    long long largeNumber = 9223372036854775807; // Maximum signed long long
    unsigned long long largeUnsigned = 18446744073709551615ULL; // Maximum unsigned long long

    std::cout << "Signed long long: " << largeNumber << std::endl;
    std::cout << "Unsigned long long: " << largeUnsigned << std::endl;

    // Performing arithmetic
    long long sum = largeNumber + 1; // This will overflow
    std::cout << "Sum (overflowed): " << sum << std::endl;

    return 0;
}
