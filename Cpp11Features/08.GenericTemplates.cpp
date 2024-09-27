#include<iostream>
using namespace std;

template<typename T1, typename T2>
void displayName(T1 x, T2 y)
{
	cout << x << " " <<y << endl;
}

int main()
{
	displayName(10,"Hello");
	displayName(10,87.67);
	return 0;
}
