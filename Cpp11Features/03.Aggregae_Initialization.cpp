#include <iostream>
#include <vector>
using namespace std;
class Test		        //Aggregate class/struct
{
	private:
	int age;
	string name;
	
	public:
	Test(int age, string name) :age(age), name(name){}
	
	void show()
	{
	    cout << "name:" << name << "age:" << age << endl;
	}
};

int main()
{
    Test t1 = { 5, "abc"};       //Aggregate Initialization
    t1.show();
    return 0;
}
