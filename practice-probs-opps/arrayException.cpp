#include <iostream>
using namespace std;

class ArrayException {
private:
    string message;
public:
    ArrayException(string msg) : message(msg) {}
    
    string what() {
        return message;
    }
};

class SafeArray {
private:
    int* arr;
    int size;
public:
    SafeArray(int n) {
        size = n;
        arr = new int[size];
    }
    
    ~SafeArray() {
        delete[] arr;
    }
    
    void setValue(int index, int value) {
        if (index < 0 || index >= size) {
            throw ArrayException("Array index out of bounds!");
        }
        arr[index] = value;
    }
    
    int getValue(int index) {
        if (index < 0 || index >= size) {
            throw ArrayException("Array index out of bounds!");
        }
        return arr[index];
    }
    
    int getSize() {
        return size;
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    SafeArray arr(n);
    
    try {
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            arr.setValue(i, val);
        }
        
        cout << "\nArray elements: ";
        for (int i = 0; i < n; i++) {
            cout << arr.getValue(i) << " ";
        }
        cout << endl;
        
        // Intentionally accessing out of bounds
        cout << "\nTrying to access index " << n << " (out of bounds)..." << endl;
        cout << arr.getValue(n) << endl;
    }
    catch (ArrayException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    cout << "Program continues after exception handling." << endl;
    
    return 0;
}
