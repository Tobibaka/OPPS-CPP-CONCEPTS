//Develop a C++ program that handles array out of bounds exception using C++
#include <iostream>
using namespace std;
class Array {
private:
    int* arr;
    int size;
public:
    Array(int s) {
        size = s;
        arr = new int[size];
    }
    ~Array() {
        delete[] arr;
    }
    void setElement(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of bounds");
        }
        arr[index] = value;
    }
    int getElement(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of bounds");
        }
        return arr[index];
    }
};
int main() {
    Array arr(5);
    try {
        arr.setElement(0, 10);
        arr.setElement(1, 20);
        arr.setElement(6, 30);  // This will throw an exception
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}