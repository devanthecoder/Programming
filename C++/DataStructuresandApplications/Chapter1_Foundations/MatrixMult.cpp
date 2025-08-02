#include <iostream>
#include <vector>
using namespace std;
typedef vector <vector <int>> matrix;
void MatrixMultiply(int n, matrix A, matrix B, matrix& C){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
int main(){
    int n;
    cout << "Enter the size of matrices: ";
    cin >> n;
    // while(!is2Power(n))n++;
    // cout << n;
    matrix A(n, vector <int>(n,0)), B(n, vector <int>(n,0)), C(n, vector <int>(n,0));
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
    MatrixMultiply(n, A, B, C);
    cout << "Matrix C = A * B is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << C[i][j] << " ";
        cout << "]" << endl;
    }
}