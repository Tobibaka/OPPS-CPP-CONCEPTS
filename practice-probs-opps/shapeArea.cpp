#include <iostream>
using namespace std;

class Shape {
protected:
    double dim1, dim2;
public:
    void get_data() {
        cout << "Enter dimensions: ";
        cin >> dim1 >> dim2;
    }
    
    virtual void display_area() {
        cout << "Area calculation not defined for base class." << endl;
    }
};

class Triangle : public Shape {
public:
    void display_area() {
        double area = 0.5 * dim1 * dim2;
        cout << "Area of Triangle: " << area << endl;
    }
};

class Rectangle : public Shape {
public:
    void display_area() {
        double area = dim1 * dim2;
        cout << "Area of Rectangle: " << area << endl;
    }
};

int main() {
    Shape* shapePtr;//base class pointer
    int choice;
    
    cout << "Select shape:\n1. Triangle\n2. Rectangle\nEnter choice: ";
    cin >> choice;
    
    if (choice == 1) {
        Triangle t;
        shapePtr = &t;//base class pointer pointing to derived class object
        cout << "Enter base and height: ";
        shapePtr->get_data();//base class pointer calling derived class method
        shapePtr->display_area();
    } else if (choice == 2) {
        Rectangle r;
        shapePtr = &r;//base class pointer pointing to derived class object
        cout << "Enter length and width: ";
        shapePtr->get_data();//base class pointer calling derived class method
        shapePtr->display_area();
    } else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
