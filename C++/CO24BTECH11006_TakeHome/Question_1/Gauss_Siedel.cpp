#include <iostream>
#include <chrono>
using namespace std;
double mod2(int n, double* x){
    double modu = 0;
    for(int i=0;i<n;i++){
        modu += x[i]*x[i];
    }
    return modu;
}
double* Residual(int n, double* b, double** A, double* x){
    double* Ax = new double[n]();
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++) Ax[i] += A[i][j]*x[j];
    }
    double *r = new double[n];
    for(int i=0; i<n;i++) r[i] = b[i]-Ax[i];
    delete[] Ax;
    return r;
}
int iterationCount =0;
double *Gauss_Siedel(int n, double w, double* b, double** A, double* xg, double z){
    double* x = new double[n];
    for(int i=0;i<n;i++) x[i] = xg[i];
    double *r = Residual(n, b, A, x);
    double s = mod2(n, r);
    while(s>z){
        for(int i=0;i<n;i++){
            double sum = b[i];
            for(int j=0;j<i;j++) sum -= A[i][j]*x[j];
            for(int j=i+1;j<n;j++) sum -= A[i][j]*xg[j];
            x[i] = (1-w)*xg[i] + (w/A[i][i])*sum;
        }
        r = Residual(n, b, A, x);
        s = mod2(n, r);
        for(int i=0;i<n;i++) xg[i] = x[i];
        iterationCount++;
    }
    delete[] r;
    return x;
}
int main(){
    double w, z;
    cout << "Enter the value of weight, w used for SOR method (Set w=1 for Gauss-Siedel): ";
    cin >> w;
    cout << "Enter the value of tolerance, z: ";
    cin >> z;
    int n;
    cout << "Give value for size of matrix A and vector b: ";
    cin >> n;
    double **A = new double*[n];
    double *b = new double[n];
    double *vg = new double[n];
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
    for(int i=0;i<n;i++){
        cout << "Input the value of element " << i+1 << " of vector b: ";
        cin >> b[i];
    }
    cout << "Vector b is:" << endl << "[ ";
    for(int i=0;i<n;i++) cout << b[i] << " ";
    cout << "]" << endl;
    for(int i=0;i<n;i++){
        cout << "Input the initial guess for voltage value at node " << i+1 << ": ";
        cin >> vg[i];
    }
    cout << "The vector consisting of initial guess voltages, vg is:" << endl << "[ ";
    for(int i=0;i<n;i++) cout << vg[i] << " ";
    cout << "]" << endl;
    auto start = chrono::high_resolution_clock::now();
    double *v = Gauss_Siedel(n,w,b,A,vg,z);
    auto end = chrono::high_resolution_clock::now();
    auto timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Voltages at each of the junctions are:" << endl;
    for(int i=0;i<n;i++)cout << "V" << i+1 << " = " << v[i] << endl;
    cout << "Number of iterations required to find voltages: "<< iterationCount << endl;
    cout << "Time taken to find voltages using Gauss-Siedel/SOR: " << timeTaken << " microseconds" << endl;
    delete[] b;
    delete[] vg;
    delete[] v;
    for(int i=0;i<n;i++){
        delete[] A[i];
    }
    delete[] A;
}