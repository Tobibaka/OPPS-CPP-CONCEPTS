#include <iostream>
using namespace std;

int main() {
    int r = 2, c = 2;
    
    // Allocate memory for two 2x2 matrices
    int** mat1 = new int*[r];
    int** mat2 = new int*[r];
    int** result = new int*[r];
    
    for (int i = 0; i < r; i++) {
        mat1[i] = new int[c];
        mat2[i] = new int[c];
        result[i] = new int[c];
    }
    
    // Input matrix 1
    cout << "Enter elements for matrix 1 (2x2):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat1[i][j];
        }
    }
    
    // Input matrix 2
    cout << "Enter elements for matrix 2 (2x2):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat2[i][j];
        }
    }
    
    // Add matrices
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    
    // Display result
    cout << "\nResultant matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    // Free memory
    for (int i = 0; i < r; i++) {
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] result[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] result;
    
    return 0;
}
