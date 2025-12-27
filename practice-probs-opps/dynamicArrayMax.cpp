#include <iostream>
using namespace std;

class Array {
private:
    int* arr;
    int size;
public:
    // Default constructor
    Array() {
        size = 5;
        arr = new int[size];
        cout << "Default constructor: Array of size " << size << " created." << endl;
    }
    
    // Parameterized constructor (overloaded)
    Array(int n) {
        size = n;
        arr = new int[size];//initialize dynamic array
        cout << "Parameterized constructor: Array of size " << size << " created." << endl;
    }
    // Destructor
    ~Array() {
        delete[] arr;
        cout << "Destructor called: Memory freed." << endl;
    }
    
    void input() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    
    int findLargest() {
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
    
    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    Array arr(n);  // Using overloaded constructor
    arr.input();
    arr.display();
    
    cout << "Largest element: " << arr.findLargest() << endl;  
    delete  &arr;
    cout <<"aaaaaaaaaaaa" << arr.findLargest() << endl;
    return 0;
}
