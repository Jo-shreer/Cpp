#include <iostream>

class A 
{
public:
    void hello() { std::cout << "Hello from A\n"; }
};

class B : public A {};
class C : public A {};

class D : public B, public C {};

int main() 
{
    D d;

    // This will cause a compile error:
    // d.hello(); // error: request for member 'hello' is ambiguous

    // You must disambiguate:
    d.B::hello();
    d.C::hello();

    return 0;
}

**************Solution**********
  /* Use virtual inheritance*/
  
#include <iostream>

class A 
{
public:
    void hello() { std::cout << "Hello from A\n"; }
};

class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};

int main() 
{
    D d;
    d.hello(); // Now OK: only one A in D
    return 0;
}
