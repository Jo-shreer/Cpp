#include <iostream>
using namespace std;

class smartptr
{
    private:
    int *p;
    
    public:
    smartptr(int *ptr = NULL)
    {
        p = ptr;
        cout << "Constructor" << *p << endl;
    }
    ~smartptr()
    {
        delete p;
        cout << "Destructor" << endl;
    }
    int& operator*()
    {
        return *p;
    }
    void print()
    {
        cout << "p:" << *p << endl;
    }
};

int main()
{
    smartptr sp(new int(40));
    *sp = 45;
    sp.print();
    return 0;
}
