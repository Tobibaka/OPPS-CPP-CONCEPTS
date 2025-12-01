#include <iostream>

using namespace std;

// Function to swap two integers using pass by reference
void swapByRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;

    // x and y are passed by reference
    swapByRef(x, y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
