

#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Pointer ptr stores: " << ptr << endl;
    cout << "Value at ptr (*ptr): " << *ptr << endl;

    return 0;
}


Value of x: 10
Address of x: 0x7ffee84e5a4c  // your address will differ
Pointer ptr stores: 0x7ffee84e5a4c
Value at ptr (*ptr): 10







