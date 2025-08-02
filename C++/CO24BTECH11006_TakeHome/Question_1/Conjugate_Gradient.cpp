#include <iostream>
#include <chrono>
using namespace std;
double* axpy(int n, double a, double* x, double* y){
    double* axy = new double[n];
    for(int i=0;i<n;i++) axy[i] = a*x[i]+y[i];
    return axy;
}
double* matvec(int n, double** A, double* y){
    double* Ay = new double[n]();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) Ay[i] += A[i][j]*y[j];
    }
    return Ay;
}
double dot(int n, double* x, double* y){
    double result = 0;
    for(int i=0;i<n;i++) result += x[i]*y[i];
    return result;
}
double* Residual(int n, double* b, double** A, double* x){
    double* Ax = matvec(n, A, x);
    double* r = axpy(n, -1, Ax, b);
    delete[] Ax;
    return r;
}
int iterationCount = 0;
double* Conjugate_Gradient(int n, double z, double** A, double* b, double* xg){
    double* x = new double[n];
    for(int i=0;i<n;i++) x[i] = xg[i];
    double* r = Residual(n, b, A, x);
    double* d = new double[n];
    for(int i=0;i<n;i++) d[i] = r[i];
    double s = dot(n, r, r);
    while(s>z){
        double* Ad = matvec(n, A, d);
        double alpha = dot(n, r, d)/dot(n, d, Ad);
        double* new_x = axpy(n, alpha, d, x);
        delete[] x;
        x = new_x;
        double* new_r = axpy(n, -alpha, Ad, r);
        delete[] r;
        r = new_r;
        double beta = -dot(n, new_r, Ad)/dot(n, d, Ad);
        delete[] Ad;
        double* new_d = axpy(n, beta, d, r);
        delete[] d;
        d = new_d;
        s = dot(n, r, r);
        iterationCount++;
    }
    delete[] r;
    delete[] d;
    return x;
}
int main(){
    double z;
    cout << "Enter the value of tolerance, z: ";
    cin >> z;
    int n;
    cout << "Enter the size of matrix A and vector b: ";
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
        for(int j=0;j<n;j++)cout << A[i][j] << " ";
        cout << "]" << endl;
    }
    double* b = new double[n];
    for(int i=0;i<n;i++) {
        cout << "Input the value of element " << i+1 << " of vector b: ";
        cin >> b[i];
    }
    cout << "Vector b is:" << endl;
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << "]" << endl;
    double* vg = new double[n];
    for(int i=0;i<n;i++){
        cout << "Input the value of element " << i+1 << " of vector xg: ";
        cin >> vg[i];
    }
    cout << "The vector consisting of initial guess voltages, vg is:" << endl << "[ ";
    for(int i=0;i<n;i++) cout << vg[i] << " ";
    cout << "]" << endl;
    auto start = chrono::high_resolution_clock::now();
    double* v = Conjugate_Gradient(n,z,A,b,vg);
    auto end = chrono::high_resolution_clock::now();
    auto timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Voltages at each of the junctions are:" << endl;
    for(int i=0;i<n;i++) cout << "V" << i+1 << " = " << v[i] << endl;
    cout << "Number of iterations: " << iterationCount << endl;
    cout << "Time taken to find voltages using Conjugate Gradient: " << timeTaken << " microseconds" << endl;
    delete[] b;
    delete[] vg;
    delete[] v;
    for(int i=0;i<n;i++) delete[] A[i];
    delete[] A;
}