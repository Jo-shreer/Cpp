#include <iostream>
using namespace std;

class Box; 

class BoxManager 
{
    public:
    void setLength(Box& box, double len);
    void printLength(const Box& box);
};
class Box 
{
    private:
    double length;

    public:
    Box(double len) : length(len) {}
    friend class BoxManager;
};

void BoxManager::setLength(Box& box, double len) 
{
    box.length = len; 
}

void BoxManager::printLength(const Box& box) 
{
    cout << "Length of the box: " << box.length << endl; // Accessing the private member
}

int main() 
{
    Box box(10.0);
    BoxManager manager;
    manager.printLength(box);
    manager.setLength(box, 15.5); 
    manager.printLength(box); 
    return 0;
}
