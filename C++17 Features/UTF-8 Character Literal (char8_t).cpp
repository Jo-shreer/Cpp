/*
Introduced the char8_t type to represent UTF-8 code units explicitly:

Before C++17:
UTF-8 strings were supported as const char* or char[], 
but there was no dedicated UTF-8 character type.
This sometimes caused confusion and bugs when handling UTF-8 data.

Why useful?
Improves type safety when working with UTF-8 text.
Makes intent explicit: you know when data is UTF-8 encoded.
*/

#include <iostream>

int main() 
{
    char8_t c = u8'A';
    std::cout << "UTF-8 char literal (cast to char): " << static_cast<char>(c) << "\n";
    return 0;
}

Output:
UTF-8 char literal (cast to char): A
