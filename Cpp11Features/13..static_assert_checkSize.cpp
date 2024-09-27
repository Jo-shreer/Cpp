#include <iostream>

struct MyStruct {
    int a;
    double b;
};

static_assert(sizeof(MyStruct) == 16, "Size of MyStruct should be 16 bytes");

int main() {
    std::cout << "MyStruct size is valid." << std::endl;
    return 0;
}
