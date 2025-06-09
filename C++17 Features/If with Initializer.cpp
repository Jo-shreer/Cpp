/*
1. You can initialize variables inside the if condition

Before - You had to declare variables before the if, 
so their scope is broader than needed

auto it = map.find(key);
if (it != map.end()) 
{
    // use it
}
// 'it' still exists here, can cause errors

1. Limits variable scope, safer code
2. Cleaner, less boilerplate

*/

#include <iostream>
#include <map>

int main() 
{
    std::map<int, std::string> map = {{1, "one"}, {2, "two"}};
    int key = 1;

    if (auto it = map.find(key); it != map.end()) 
    {
        std::cout << "Found key " << key << ": " << it->second << std::endl;
    } else 
    {
        std::cout << "Key not found\n";
    }

    return 0;
}
