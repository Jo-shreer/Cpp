/*
1. You can unpack tuples, pairs, structs, arrays into variables directly

Earlier
std::pair<int,int> p = {1, 2};
int x = p.first;
int y = p.second;

1. Makes code more expressive and concise
2. No need to refer to .first and .second repeatedly
3. Works with any tuple-like types

*/

#include <iostream>
#include <tuple>

int main() 
{
    auto [x, y] = std::make_pair(1, 2);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    return 0;
}
