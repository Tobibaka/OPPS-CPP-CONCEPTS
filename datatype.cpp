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
        cout << "a=" << a << " b=" << b << endl;
    }
};

int main() {
    int m;
    float n;

    cout << "Enter an int and a float: ";
    cin >> m >> n;

    Swap<float> c(m, n);

    cout << "Before swap : ";
    c.show_data();
    c.swaped();
    cout << "After swap  : ";
    c.show_data();

    return 0;
}