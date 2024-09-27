#include <iostream>

class Coffee 
{
	public:
    virtual ~Coffee() = default;
    virtual double cost() const = 0;
};

class SimpleCoffee : public Coffee {
public:
    double cost() const override {
        return 5.0;
    }
};

class CoffeeDecorator : public Coffee 
{
	protected:
    Coffee* coffee;

	public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}

    double cost() const override {
        return coffee->cost();
    }
};

class MilkDecorator : public CoffeeDecorator 
{
	public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double cost() const override {
        return CoffeeDecorator::cost() + 2.0;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double cost() const override {
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
