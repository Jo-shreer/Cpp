#include <iostream>
using namespace std;

class Animal 
{
    public:
    virtual void sound() const {
        cout << "Some animal sound." << endl;
    }
};

class Dog : public Animal 
{
    public:
    void sound() const override {
        cout << "Bark!" << endl;
    }
};

int main() {
    Animal* animals[1]; // Array of Animal pointers
    animals[0] = new Dog();

    for (int i = 0; i < 1; ++i) 
    {
        animals[i]->sound(); // Dynamic binding
    }
    delete animals[0];
    return 0;
}



OR

*********************************************************************************************************************
class Base
{
	public:
	virtual void show()
	{
		cout << "In Base" << endl;
	}
};

class Derived : public Base
{
	public:
	void show()
	{
		cout << "In Derived"  << endl;
	}
};

int main()
{
	Base *bp = new Derived();
	unique_ptr<Base> bp1 = make_unique<Derived>();
	bp1->show();
	bp->show();
	return 0;
}




