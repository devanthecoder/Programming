#include <iostream>
#include <chrono>
using namespace std;
void LU_Decomposition(int n, double **A, double **L, double **U){
    for(int j=0;j<n;j++){
        for(int i=0;i<=j;i++){
            L[i][j]=(double)(i==j)?1:0;
            double sum = 0;
            for(int k=0;k<i;k++)sum+=L[i][k]*U[k][j];
            U[i][j] = A[i][j]-sum;
        }
        for(int i=j+1;i<n;i++){
            U[i][j]=0;
            double sum = 0;
            for(int k=0;k<j;k++)sum+=L[i][k]*U[k][j];
            L[i][j] = (A[i][j]-sum)/U[j][j];
        }
    }
}
double *Forward_Substitution(int n, double** L, double* b){
    double* y = new double[n];
    for(int i=0;i<n;i++){
        double sum = 0;
        for(int j=0;j<i;j++)sum+=L[i][j]*y[j];
        y[i]=(b[i]-sum)/L[i][i];
    }
    return y;
}
double *Backward_Substitution(int n, double** U, double* y){
    double* x = new double[n];
    for(int i=n-1;i>=0;i--){
        double sum = 0;
        for(int j=i+1;j<n;j++)sum+=U[i][j]*x[j];
        x[i]=(y[i]-sum)/U[i][i];
    }
    return x;
}
int main(){
    int n;
    cout << "Give value for size of matrix A and vector b: ";
    cin >> n;
    double **A = new double*[n];
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
        for(int j=0;j<n;j++)cout << A[i][j] << " ";
        cout << "]" << endl;
    }
    double *b = new double[n];
    for(int i=0;i<n;i++){
        cout << "Input the value of element " << i+1 << " of vector b: ";
        cin >> b[i];
    }
    cout << "Vector b is:" << endl;
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << "]" << endl;
    double ** L = new double*[n];
    double ** U = new double*[n];
    for(int i=0;i<n;i++){
        L[i] = new double[n];
        U[i] = new double[n];
    }
    auto start = chrono::high_resolution_clock::now();
    LU_Decomposition(n, A, L, U);
    double* y = Forward_Substitution(n, L, b);
    double* v = Backward_Substitution(n, U, y);
    auto end = chrono::high_resolution_clock::now();
    auto timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Lower Triangular Matrix L:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << L[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "Upper Triangular Matrix U:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << U[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "Voltages at each of the junctions are:" << endl;
    for(int i=0;i<n;i++)cout << "V" << i+1 << " = " << v[i] << endl;
    
    cout << "Time taken to find voltages using LU Decomposition: " << timeTaken << " microseconds" << endl;
}