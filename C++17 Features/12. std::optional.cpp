/*
std::optional<T> — a type that may or may not contain a value of type T.

Before C++17:
Representing “optional” (maybe a value, maybe not) was usually done by:
Using pointers (raw or smart), which are verbose and error-prone.
Using special sentinel values, which might be confusing or invalid.

Why is it better?
Explicitly models “optional” state.
Safer and cleaner code.
Has convenient API to check, get values, or provide defaults.

*/
#include <iostream>
#include <optional>

std::optional<int> find_even(int x) 
{
    if (x % 2 == 0)
        return x;
    else
        return std::nullopt;
}

int main() 
{
    auto val = find_even(5);
    if (val)
        std::cout << "Found even: " << *val << "\n";
    else
        std::cout << "No even number\n";

    return 0;
}

Output:
No even number
