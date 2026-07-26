//wap to implement bubble sort using template class and friend function for numbers and chars or strings
#include <iostream>
using namespace std;
template <class T>
class BubbleSort {
public:
    void sort(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

     friend void printArray(T arr[], int n) {
        
    }
};

template <class T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
}
int main() {
    int n;
    cout << "Enter number of integers: ";
    cin >> n;
    BubbleSort<int> intSorter;
    int arr[100];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    intSorter.sort(arr, n);
    cout << "Sorted integers: ";
    printArray(arr, n);
    
    // Now for characters or strings
    cout << "\nEnter number of characters: ";
    cin >> n;

    BubbleSort<char> charSorter;
    char charArr[100];
    cout << "Enter " << n << " characters:\n";
    for (int i = 0; i < n; ++i) {
        cin >> charArr[i];
    }

    charSorter.sort(charArr, n);
    cout << "Sorted characters: ";
    printArray(charArr, n);

    return 0;
}