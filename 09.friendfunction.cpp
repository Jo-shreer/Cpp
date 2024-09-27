#include <iostream>
using namespace std;

class Box 
{
    private:
    double length;

    public:
    Box(double len) : length(len) {}
    friend void printLength(const Box& box);
};

void printLength(const Box& box) 
{
    cout << "Length of the box: " << box.length << endl;
}

int main() 
{
    Box box(10.5);
    printLength(box); // Call the friend function
    return 0;
}
