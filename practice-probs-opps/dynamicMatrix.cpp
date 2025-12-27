#include <iostream>
using namespace std;

class Matrix {
private:
    int** mat; 
    int r, c;
public:
    Matrix(int rows, int cols) : r(rows), c(cols) {
        mat = new int*[r];
        for (int i = 0; i < r; i++) {
            mat[i] = new int[c];
        }
    }       
    
    ~Matrix() {
        for (int i = 0; i < r; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        cout << "Memory freed." << endl;
    }   
    
    void input() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> mat[i][j];
            }
        }
    }
    
    void add(Matrix m1, Matrix m2) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
            }
        }
    }
    
    void display() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 3);
    Matrix result(2, 4);
    
    cout << "Enter elements for matrix 1 (2x2):\n";
    mat1.input();
    
    cout << "Enter elements for matrix 2 (2x2):\n";
    mat2.input();
    
    result.add(mat1, mat2);
    
    cout << "\nResultant matrix:\n";
    result.display();
    
    return 0;
}
