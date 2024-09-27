//copy constructor , Move constructor 

#include <iostream>
using namespace std;

class A
{
    private:
    int *p;
    
    public:
    A()
    {
        p = new int[100];
        cout << "default constructor" << endl;
    }
    
    A(const A &obj)
    {
        p = new int[100];
        for(int i =0; i <100; i++)
            p[i] = obj.p[i];
        cout << "copy constructor" << endl;
    }
    
    A(const A &&obj) :p(obj.p)
    {
        cout << "move constructor" << endl;
    }
    
};

int main()
{
    A a;
    A b = move(a);
    A c(move(a));
    return 0;
}
