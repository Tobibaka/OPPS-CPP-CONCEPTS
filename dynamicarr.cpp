//Write a program that uses an overloaded constructor to dynamically allocate memory to an array and thus find the largest of its elements
#include <iostream>
using namespace std;
class DynamicArray {
private:
    int* arr;
    int size;
public:
    // Overloaded Constructor
    DynamicArray(int s) {
        size = s;
        arr = new int[size];
    }
    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }
    void inputElements() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    int findLargest() {
        int largest = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }
        return largest;
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    DynamicArray arr(n);
    arr.inputElements();
    cout << "Largest element is: " << arr.findLargest() << endl;
    return 0;
}
