#include <iostream>
using namespace std;
class Base {
public:
void display() {
    cout << "Display of Base class" << endl;
}
virtual void show() {
    cout << "Show of Base class" << endl;
}
};
class Derived: public Base {
public:
void display() {
    cout << "Display of Derived class" << endl;
}
void show() override {
    cout << "Show of Derived class" << endl;
}
};
int main () {
    Base b;
    Derived d;
    Base* ptr;
    ptr = &b;//
    cout<<"ptr points to Base object:"<<endl;
    ptr->display();
    ptr->show();
    ptr = &d;
    cout<<"ptr points to Derived object:"<<endl;
    ptr->display();
    ptr->show();
    Derived* dptr;
    dptr = &d;
    cout<<"dptr points to Derived object:"<<endl;
    dptr->display();
    dptr->show();
}