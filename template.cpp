#include <iostream>

using namespace std;

template <class T>
class Swap {
    T a, b;

public:
    Swap(T x, T y) {
        a = x;
        b = y;
    }

    void swaped() {
        T temp = a;
        a = b;
        b = temp;
    }

    void show_data() {
        cout << " a=" << a << " b=" << b << endl;
    }
};

int main() {
    int m, n;
    float m1, m2;
    

    cout << "Enter two integers: ";
    cin >> m >> n;

    cout << "Enter two floats: ";
    cin >> m1 >> m2;

    

    Swap<int> c1(m, n);
    Swap<float> c2(m1, m2);
    c1.show_data();
    
    c1.swaped();
    c1.show_data();
    
    c2.show_data();
    c2.swaped();
    c2.show_data();

    return 0;
}