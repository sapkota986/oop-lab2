#include <iostream>
using namespace std;

class matrix {
    int a[3][3];
public:
    matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                a[i][j] = 0;
            }
        }
    }

    void setmatrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> a[i][j];
            }
        }
    }

    void showmatrix()  {
        cout << "Matrix is:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    matrix operator+( matrix& m) const {
        matrix c;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                c.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        return c;
    }
};

int main() {
    matrix a, b, c;

    cout << "Set the value of  matrix A:" << endl;
    a.setmatrix();

    cout << "Set the value of matrix B:" << endl;
    b.setmatrix();

    c = a + b;

    cout << "Matrix A is:" << endl;
    a.showmatrix();

    cout << "Matrix B is:" << endl;
    b.showmatrix();

    cout << "The resultant matrix is:" << endl;
    c.showmatrix();

    return 0;
}
