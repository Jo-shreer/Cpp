#include<iostream>
using namespace std;

class ShallowDeep
{
	private:
	int a, b;
	int *ptr;
	
	public:
	ShallowDeep()
	{
		a = 0;
		b = 0;
	}
	
	ShallowDeep(int x, int y, int p)
	{
		a =x;
		b = y;
		ptr = new int;
		*ptr = p;
	}
	ShallowDeep(const ShallowDeep &obj)
	{
		a = obj.a;
		b = obj.b;
		ptr = new int;
		*ptr = *obj.ptr;
	}
	void showData()
	{
	    cout << "a:" << a << " " << "b:" << b << " " << "*ptr:" << *ptr << " "<< endl;
	}
};

int main()
{
	ShallowDeep d1(3,5,6);
	ShallowDeep d2(d1);
	d1.showData();
	
	return 0;
}

