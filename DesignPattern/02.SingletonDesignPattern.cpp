#include <iostream>

class Singleton 
{
    private:
    // Private constructor to prevent instantiation
    Singleton() 
    {
        std::cout << "Singleton instance created." << std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    public:
    static Singleton& getInstance() {
        static Singleton instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    void showMessage() 
    {
        std::cout << "Hello from the Singleton!" << std::endl;
    }
};

int main() 
{
    Singleton& singletonInstance = Singleton::getInstance();
    singletonInstance.showMessage();

    return 0;
}
