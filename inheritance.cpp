//Create a base class in C++ called Shape. Use this class to store two double-type values that could be used to compute the area of figures. Derive two specific classes called Triangle and Rectangle from the base shape. Add to the base class a member function getata() to initialize base class data members and another member function displayArea() to compute and display the area of figures. Make displayArea() a virtual function and redefine this function in the derived classes to suit their requirements. Using these classes, design a program that will accept the dimension of the triangle or rectangle interactively and display the area.
#include <iostream>
using namespace std;
class Shape {protected:
protected:
    double width;
    double height;
public:
    void getdata(double w, double h) {
        width = w;
        height = h;
    }
    virtual void displayArea() {
        cout << "Area of Shape" << endl;
    }
};

class Triangle : public Shape {
public:
    void displayArea() {
        cout << "Area of Triangle: " << 0.5 * width * height << endl;
    }
};

class Rectangle : public Shape {
public:
    void displayArea() {
        cout << "Area of Rectangle: " << width * height << endl;
    }
};

int main() {
    Shape* shape;
    Triangle t;
    Rectangle r;
    double w, h;

    cout << "Enter width and height for Triangle: ";
    cin >> w >> h;
    t.getdata(w, h);
    shape = &t;
    shape->displayArea();

    cout << "Enter width and height for Rectangle: ";
    cin >> w >> h;
    r.getdata(w, h);
    shape = &r;
    shape->displayArea();

    return 0;
}