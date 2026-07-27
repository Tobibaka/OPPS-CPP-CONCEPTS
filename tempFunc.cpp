#include <iostream>

using namespace std;

template <class T>
void Swap(T& x,T& y) {
    T temp = x;
    x = y;
    y = temp;
}
int main() {
    char ch1, ch2;
    cout << "Enter two characters: ";
    cin >> ch1 >> ch2;
    cout << "Before Swap: " << ch1 << " " << ch2 << endl;
    Swap(ch1, ch2);
    cout << "After Swap: " << ch1 << " " << ch2 << endl;
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Before Swap: " << a << " " << b << endl;
    Swap(a, b);
    cout << "After Swap: " << a << " " << b << endl;
    float m, n;
    cout << "Enter two floats: ";
    cin >> m >> n;
    cout << "Before Swap: " << m << " " << n << endl;
    Swap(m, n);
    cout << "After Swap: " << m << " " << n << endl;
    return 0;
}