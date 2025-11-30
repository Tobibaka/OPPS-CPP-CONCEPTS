#include <iostream>
using namespace std;

class Base {
protected:
    int alpha;
public:
    Base(int a) : alpha(a) {
        cout << "Base constructor called with alpha = " << alpha << endl;
    }
    
    void displayBase() {
        cout << "Alpha: " << alpha << endl;
    }
};

class Derived1 : public Base {
protected:
    int beta;
public:
    Derived1(int a, int b) : Base(a), beta(b) {
        cout << "Derived1 constructor called with beta = " << beta << endl;
    }
    
    void displayDerived1() {
        cout << "Alpha: " << alpha << ", Beta: " << beta << endl;
    }
};

class Derived2 : public Derived1 {
private:
    int gamma;
public:
    Derived2(int a, int b, int g) : Derived1(a, b), gamma(g) {
        cout << "Derived2 constructor called with gamma = " << gamma << endl;
    }
    
    void displayAll() {
        cout << "\nFinal values:" << endl;
        cout << "Alpha: " << alpha << endl;
        cout << "Beta: " << beta << endl;
        cout << "Gamma: " << gamma << endl;
    }
};

int main() {
    int a, b, g;
    
    cout << "Enter value for alpha: ";
    cin >> a;
    cout << "Enter value for beta: ";
    cin >> b;
    cout << "Enter value for gamma: ";
    cin >> g;
    
    cout << "\nCreating Derived2 object:\n";
    Derived2 obj(a, b, g);
    
    obj.displayAll();
    
    return 0;
}
