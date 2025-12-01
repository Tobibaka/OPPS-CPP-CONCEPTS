#include <iostream>

using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Overloading the << operator using a friend function
    // The friend function is declared inside the class but defined outside.
    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(10, 20);
    Point p2(30,20);

    // This calls the friend function operator<<(cout, p1)
    cout << "The coordinates are: " << p1 << p2 << endl;

    return 0;
}
