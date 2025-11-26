#include<iostream>
using namespace std;

class vctr {
    int n;
    float a[50], b[50];
public:
    void get() {
        int i;
        cout << "Enter the dimension: ";
        cin >> n;
        cout << "Enter the first vector: ";
        for (i = 0; i < n; i++) cin >> a[i];
        cout << "Enter the second vector: ";
        for (i = 0; i < n; i++) cin >> b[i];
        cout << endl;
    }

    void mdfy() {
        int c, p;
        cout << "Enter: 1--To modify 1st vector\n";
        cout << "       2--To modify 2nd vector\n";
        cin >> c;
        switch (c) {
        case 1:
            cout << "Enter position to modify: ";
            cin >> p;
            cout << "Enter the modified value: ";
            cin >> a[p - 1];
            break;
        case 2:
            cout << "Enter position to modify: ";
            cin >> p;
            cout << "Enter the modified value: ";
            cin >> b[p - 1];
            break;
        default:
            cout << "INVALID!";
        }
        cout << endl;
    }

    void sclr() {
        int s, i;
        cout << "Enter the Scalar value: ";
        cin >> s;
        for (i = 0; i < n; i++) {
            a[i] = a[i] * s;
            b[i] = b[i] * s;
        }
        cout << endl;
    }

    void dis() {
        int i;
        cout << "The 1st vector: (" << a[0];
        for (i = 1; i < n; i++) cout << "," << a[i];
        cout << ")\n";
        cout << "The 2nd vector: (" << b[0];
        for (i = 1; i < n; i++) cout << "," << b[i];
        cout << ")\n";
    }

    void add() {
        cout << "Resultant Vector (1st + 2nd): (";
        cout << a[0] + b[0];
        for (int i = 1; i < n; i++) cout << "," << a[i] + b[i];
        cout << ")\n";
    }
};

int main() {
    int o = 0, a;
    vctr v;
    cout << "Create the vectors: \n";
    v.get();
    while (o != 1) {
        cout << "Enter: 1--Modify\n";
        cout << "       2--Scalar\n";
        cout << "       3--Display\n";
        cout << "       4--Add both vectors\n";
        cout << "       5--Exit\n";
        cin >> a;
        switch (a) {
        case 1: v.dis(); v.mdfy(); v.dis(); break;
        case 2: v.dis(); v.sclr(); v.dis(); break;
        case 3: v.dis(); break;
        case 4: v.dis(); v.add(); break;
        case 5: o = 1; break;
        default: cout << "INVALID\n";
        }
    }
    return 0;
}
