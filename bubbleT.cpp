#include <iostream>

using namespace std;

template <class T>
void bubbleSort(T arr[], int n) {
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

template <class T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
}    


int main() {
    int n;
    cout << "Enter number of integers: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    cout << "Sorted integers: ";
    printArray(arr, n);

    return 0;
}