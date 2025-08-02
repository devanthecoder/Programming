#include <iostream>
#include <vector>
using namespace std;
typedef vector <int> intvec;
typedef vector <vector <int>> matrix;
matrix FormSpecialMatrix(matrix A, matrix B, int Size) {
    matrix M(2*Size, intvec(2*Size, 0));
    for(int i=0;i<Size;i++){
        for(int j=0;j<Size;j++){
            M[i][j+Size]=A[i][j];
            M[i+Size][j+Size]=B[i][j];
        }
    }
    return M;
}
matrix MatrixSquare(int n, matrix A){
    matrix A2(n, intvec(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                A2[i][j]+=A[i][k]*A[k][j];
            }
        }
    }
    return A2;
}
matrix MatrixMultiply(int n, matrix A, matrix B){
    matrix M = FormSpecialMatrix(A, B, n);
    matrix M2 = MatrixSquare(2*n, M);
    matrix AB(n, intvec(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            AB[i][j] = M2[i][j+n];
        }
    }
    return AB;
}
int main(){
    int n;
    cout << "Enter the size of matrices: ";
    cin >> n;
    // while(!is2Power(n))n++;
    // cout << n;
    matrix A(n, vector <int>(n,0)), B(n, vector <int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "Enter the element at position ("<<i<<", "<<j<<") of Array A: ";
            cin >> A[i][j];
        }
    }
    cout << "Matrix A is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << A[i][j] << " ";
        cout << "]" << endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "Enter the element at position ("<<i<<", "<<j<<") of Array B: ";
            cin >> B[i][j];
        }
    }
    cout << "Matrix B is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << B[i][j] << " ";
        cout << "]" << endl;
    }
    matrix C = MatrixMultiply(n, A, B);
    cout << "Matrix C = A * B is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << C[i][j] << " ";
        cout << "]" << endl;
    }
}