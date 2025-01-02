#include <iostream>
using namespace std;

class Point 
{
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading the + operator
    Point operator+ (const Point& other) const 
    {
        return Point(x + other.x, y + other.y);
    }

    // Overloading the << operator for output
    friend ostream& operator<<(ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);
    
    // Using overloaded + operator
    Point p3 = p1 + p2; // This calls the overloaded operator+

    cout << "Point 1: " << p1 << endl;
    cout << "Point 2: " << p2 << endl;
    cout << "Point 3 (p1 + p2): " << p3 << endl;

    return 0;
}
