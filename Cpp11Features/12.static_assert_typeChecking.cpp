#include <type_traits>

template <typename T>
void checkType() {
    static_assert(std::is_integral<T>::value, "Template type must be an integral type");
}

int main() {
    checkType<int>();   // This will compile
    // checkType<double>(); // Uncommenting this line will cause a compile error
    return 0;
}
