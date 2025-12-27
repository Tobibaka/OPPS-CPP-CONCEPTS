#include <iostream>
using namespace std;

template <class T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "Maximum of " << x << " and " << y << " is: " << findMax(x, y) << endl;

    float a, b;
    cout << "\nEnter two floats: ";
    cin >> a >> b;
    cout << "Maximum of " << a << " and " << b << " is: " << findMax(a, b) << endl;

    char c1, c2;
    cout << "\nEnter two characters: ";
    cin >> c1 >> c2;
    cout << "Maximum of " << c1 << " and " << c2 << " is: " << findMax(c1, c2) << endl;

    return 0;
}
