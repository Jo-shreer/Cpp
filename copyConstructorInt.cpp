#include <iostream>
using namespace std;
class Base
{
    int *p;
    
    public:
    Base()
    {
        p = nullptr;
    }
    
    Base(int value)
    {
        p = new int(value);
    }
    
    Base(const Base &b1)
    {
        p = new int(*b1.p);
    }
    
    void print()
    {
        cout << *p << endl;
    }
};
int main()
{
    Base b1(2);
    Base b2 = b1;
    b1.print();
    b2.print();
    
}
