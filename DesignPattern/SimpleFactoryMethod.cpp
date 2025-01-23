/*
A Factory Method is a design pattern that provides an interface for creating objects but allows 
subclasses to alter the type of objects that will be created.
It is often used to decouple the client code from the specific classes that need to be instantiated.
Simple Factory Method in C++
In a simple implementation of the Factory Method pattern, we can have a factory class with a method that creates and 
returns objects based on the provided input or configuration.
Let's consider a scenario where we have a Shape interface, and we have concrete classes Circle and Rectangle that implement the Shape interface. 
The factory class will decide which shape to create based on the provided type.
*/
#include <iostream>
using namespace std;

class Shape
{
    public:
    virtual void draw()
    {
        cout << "Class Shape:" << endl;
    }
};

class Circle : public Shape
{
    public:
    void draw()
    {
        cout << "Class Circle:" << endl;
    }
};

class Reactangle : public Shape
{
    public:
    void draw()
    {
        cout << "Class Reactangle" << endl;
    }
};

class ShapeFactory
{
  public:
  static Shape* CreateShape(const string& shapeType)
  {
      if(shapeType == "Circle")
      {
          return new Circle();
      }
      if(shapeType == "Reactangle")
      {
          return new Reactangle();
      }
      else
      {
          return nullptr;
      }
  }
};

int main()
{
    Shape *s1 = ShapeFactory::CreateShape("Circle");
    if(s1)
    {
        s1->draw();
    }
    else
    {
        cout << "Invalid" << endl;
    }
    Shape *s2 = ShapeFactory::CreateShape("Reactangle");
    if(s2)
    {
        s2->draw();
    }
    else
    {
        cout << "Invalid" << endl;
    }
    return 0;
}

