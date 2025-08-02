#include <iostream>
#include <cmath>
using namespace std;
double dot(int n, double* x, double* y){
    double product = 0;
    for(int i=0;i<n;i++) product += x[i]*y[i];
    return product;
}
double* axpy(int n, double a, double* x, double* y){
    double* axy = new double[n];
    for(int i=0;i<n;i++) axy[i] = a*x[i]+y[i];
    return axy;
}
double** Transposition(int n, double** A){
    double** transA = new double*[n];
    for(int i=0;i<n;i++){
        transA[i] = new double[n];
        for(int j=0;j<n;j++) transA[i][j] = A[j][i];
    }
    return transA;
}
double** Grahm_Schmidt(int n, double** A){
    double** transQ = new double*[n];
    double** V = new double*[n];
    for(int i=0;i<n;i++){
        transQ[i] = new double[n];
        V[i] = new double[n];
    }
    double** transA = Transposition(n, A);
    for(int i=0;i<n;i++){
        V[i] = transA[i];
        for(int j=0;j<i;j++){
            double cj = dot(n, transA[i], V[j])/dot(n, V[j], V[j]);
            double* temp = axpy(n, -cj, V[j], V[i]);
            V[i] = temp;
        }
        double norm = sqrt(dot(n, V[i], V[i]));
        transQ[i] = axpy(n, (1/norm)-1, V[i], V[i]);
    }
    double** Q = Transposition(n, transQ);
    for(int i=0;i<n;i++){
        delete[] V[i];
        delete[] transQ[i];
    }
    delete[] V;
    delete[] transQ;
    return Q;
}
int main(){
    int n;
    cout << "Give value for size of matrix A whose orthogonalized matrix Q we want to find: ";
    cin >> n;
    double** A = new double*[n];
    for(int i=0;i<n;i++){
        A[i] = new double[n];
        for(int j=0;j<n;j++){
            cout << "Input the value in row " << i+1 << " and column " << j+1 << " of matrix A: ";
            cin >> A[i][j];
        }
    }
    cout << "Matrix A is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++) cout << A[i][j] << " ";
        cout << "]" << endl;
    }
    double** Q = Grahm_Schmidt(n, A);
    cout << "Orthogonalized Matrix Q is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++) cout << Q[i][j] << " ";
        cout << "]" << endl;
    }
    for(int i=0;i<n;i++) delete[] Q[i];
    delete[] Q;
    for(int i=0;i<n;i++) delete[] A[i];
    delete[] A;
}