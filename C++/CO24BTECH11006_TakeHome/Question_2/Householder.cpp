#include <iostream>
#include <cmath>
using namespace std;
double mod(int n, double* x){
    double modu = 0;
    for(int i=0;i<n;i++) modu += x[i]*x[i];
    return sqrt(modu);
}
double** MatrixMultiply(int n, double** A, double** B){
    double** C = new double*[n];
    for(int i=0;i<n;i++){
        C[i] = new double[n]();
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++) C[i][j] += A[i][k]*B[k][j];
            if(fabs(C[i][j])<1e-10) C[i][j]=0;
        }
    }
    return C;
}
double** Transposition(int n, double** A){
    double** transA = new double*[n];
    for(int i=0;i<n;i++){
        transA[i] = new double[n];
        for(int j=0;j<n;j++) transA[i][j] = A[j][i];
    }
    return transA;
}
double* matvec(int n, double** A, double* y){
    double* Ay = new double[n]();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) Ay[i] += A[i][j]*y[j];
    }
    return Ay;
}
double** HouseholderTransform(int n, double** A){
    double** Q = new double*[n];
    for(int i=0;i<n;i++){
        Q[i] = new double[n];
        for(int j=0;j<n;j++) Q[i][j] = (i==j)?1:0;
    }
    for(int i=0;i<n;i++){
        double* x = new double[n-i];
        for(int j=0;j<n-i;j++) x[j] = A[j+i][i];
        double normx = mod(n-i, x);
        double* u = new double[n]();
        for(int j=i;j<n;j++){
            if(j==i) u[j] = sqrt((normx-x[j-i])/(2*normx));
            else u[j] = -x[j-i]/(2*u[i]*normx);
        }
        double** H = new double*[n];
        for(int j=0;j<n;j++){
            H[j] = new double[n];
            for(int k=0;k<n;k++) H[j][k] = ((j==k)?1:0)-2*u[j]*u[k];
        }
        double** Q1 = MatrixMultiply(n, Q, H);
        double** A1 = MatrixMultiply(n, H, A);
        for(int j=0;j<n;j++) for(int k=0;k<n;k++){
            Q[j][k] = Q1[j][k];
            A[j][k] = A1[j][k];
        }
        for(int j=0;j<n;j++) {
            delete[] H[j];
            delete[] Q1[j];
            delete[] A1[j];
        }
        delete[] Q1;
        delete[] A1;
        delete[] H;
        delete[] x;
        delete[] u;
    }
    return Q;
}
double* Backward_Substitution(int n, double** U, double* y){
    double* x = new double[n];
    for(int i=n-1;i>=0;i--){
        double sum = 0;
        for(int j=i+1;j<n;j++) sum += U[i][j]*x[j];
        x[i] = (y[i]-sum)/U[i][i];
    }
    return x;
}
int main(){
    int n;
    cout << "Give value for size of matrix A and vector b: ";
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
    double** Q = HouseholderTransform(n, A);
    cout << "The orthogonalized matrix Q is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++) cout << Q[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "The upper triangular matrix R is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++) cout << A[i][j] << " ";
        cout << "]" << endl;
    }
    double* b = new double[n];
    for(int i=0;i<n;i++){
        cout << "Input the value of element " << i+1 << " of vector b: ";
        cin >> b[i];
    }
    cout << "Vector b is:" << endl << "[ ";
    for(int i=0;i<n;i++) cout << b[i] << " ";
    cout << "]" << endl;
    double* B = matvec(n, Transposition(n, Q), b);
    double* x = Backward_Substitution(n, A, B);
    cout << "The solution vector x is:" << endl << "[ ";
    for(int i=0;i<n;i++) cout << x[i] << " ";
    cout << "]" << endl;
    delete[] b;
    delete[] B;
    delete[] x;
    for(int i=0;i<n;i++) delete[] Q[i];
    delete[] Q;
    for(int i=0;i<n;i++) delete[] A[i];
    delete[] A;
}