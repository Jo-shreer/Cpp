/*The Decorator Design Pattern is a structural pattern used to add new functionalities to an object dynamically, 
without altering its structure. 
It allows for flexible extension of object behavior by "wrapping" an object with additional behavior, 
keeping the original object's interface intact.

Key Components of the Decorator Pattern:
Component: This is an interface or abstract class defining the operations that can be dynamically added to an object.
ConcreteComponent: This is the actual object being wrapped. It implements the Component interface and has its base behavior.
Decorator: This abstract class implements the Component interface and has a reference to a Component object. The Decorator class passes the request to the wrapped ConcreteComponent and may add its own behavior.
ConcreteDecorator: These are concrete classes that extend the Decorator class and add additional behavior to the wrapped object.
Real-World Example:
Suppose you have a basic Window object that can be decorated with various features, such as scrolling, borders, or color. 
You can dynamically "decorate" this object to give it additional functionality without changing its core behavior.

C++ Example Implementation:
Component Interface: The base interface for the object and its decorators.
ConcreteComponent: A basic class implementing the Component interface.
Decorator: The base decorator class implementing the Component interface.
ConcreteDecorator: Adds specific features or functionality to the ConcreteComponent.

Key Advantages of the Decorator Pattern:
Open/Closed Principle: You can add new functionality to objects without modifying the existing code, 
			adhering to the open/closed principle.
Flexible: You can add different combinations of functionality at runtime without creating multiple subclasses.
Single Responsibility: Each decorator class has a single responsibility, making the code more modular and easier to maintain.

Use Cases:
GUI Components: Adding additional features to GUI elements such as buttons, windows, 
		text fields (e.g., adding borders, scrollbars, tooltips, etc.).
I/O Streams: In many libraries (like the C++ standard library), decorators are used for I/O stream classes
		(e.g., ifstream, ofstream wrapped with iostream functionality).
Logging: Adding features like logging, error handling, or monitoring to objects dynamically.

Conclusion:
The Decorator Pattern provides a powerful way to dynamically add behavior to objects, especially when combined with other patterns.
By using decorators, you can extend functionality without changing the core object's class, making the system more 
flexible and maintainable.
*/

#include <iostream>

class Coffee 
{
    public:
    virtual double cost() const = 0;
    virtual ~Coffee() = default;
};

class SimpleCoffee : public Coffee 
{
    public:
    double cost() const override 
    {
        return 5.0;
    }
};

class CoffeeDecorator : public Coffee 
{
   protected:
   Coffee* coffee;

   public:
   CoffeeDecorator(Coffee* c) : coffee(c) {}

    double cost() const override 
    {
        return coffee->cost();
    }
};

class MilkDecorator : public CoffeeDecorator 
{
    public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double cost() const override 
    {
        return CoffeeDecorator::cost() + 2.0;
    }
};

class SugarDecorator : public CoffeeDecorator 
{
    public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double cost() const override 
    {
        return CoffeeDecorator::cost() + 1.0;
    }
};

int main() 
{
    Coffee* simpleCoffee = new SimpleCoffee();
    std::cout << "Cost of simple coffee: " << simpleCoffee->cost() << std::endl;

    Coffee* milkCoffee = new MilkDecorator(simpleCoffee);
    std::cout << "Cost of milk coffee: " << milkCoffee->cost() << std::endl;

    Coffee* sugarMilkCoffee = new SugarDecorator(milkCoffee);
    std::cout << "Cost of sugar and milk coffee: " << sugarMilkCoffee->cost() << std::endl;

    delete simpleCoffee;
    delete milkCoffee;
    delete sugarMilkCoffee;

    return 0;
}
