#include <iostream>
#include <cmath>
using namespace std;
double** Minor(int n, double** A, int row, int col){
    double** minor = new double*[n-1];
    int newi = 0;
    for(int i=0;i<n;i++){
        if(i==row) continue;
        minor[newi] = new double[n-1];
        int newj = 0;
        for(int j=0;j<n;j++){
            if(j==col) continue;
            minor[newi][newj] = A[i][j];
            newj++;
        }
        newi++;
    }
    return minor;
}
double Det(int n, double** A){
    double det = 0;
    if(n==1){
        det = A[0][0];
    } 
    else{
        for(int j=0;j<n;j++){
            double** minor = Minor(n, A, 0, j);
            det += A[0][j]*pow(-1,j)*Det(n-1, minor);
            for(int i=0;i<n-1;i++) delete[] minor[i];
            delete[] minor;
        }
    }
    return det;
}
double** Adjoint(int n, double** A){
    double** adjoint = new double*[n];
    for(int i=0;i<n;i++){
        adjoint[i] = new double[n];
        for(int j=0;j<n;j++){
            double** minor = Minor(n, A, j, i);
            adjoint[i][j] = pow(-1,i+j)*Det(n-1, minor);
            for(int k=0;k<n-1;k++) delete[] minor[k];
            delete[] minor;
        }
    }
    return adjoint;
}
double** Inverse(int n, double** A){
    double det = Det(n, A);
    double** adjoint = Adjoint(n, A);
    double** inverse = new double*[n];
    for(int i=0;i<n;i++){
        inverse[i] = new double[n];
        for(int j=0;j<n;j++) inverse[i][j] = adjoint[i][j]/det;
    }
    for(int i=0;i<n;i++) delete[] adjoint[i];
    delete[] adjoint;
    return inverse;
}
double Norm(double** A, int n){
    double max = 0;
    for(int i=0;i<n;i++){
        double sum = 0;
        for(int j=0;j<n;j++) sum += fabs(A[i][j]);
        if(sum>max) max = sum;
    }
    return max;
}
double ConditionNumber(int n, double** A){
    double** A_Inv = Inverse(n, A);
    double normA = Norm(A, n);
    double normA_Inv = Norm(A_Inv, n);
    double k = normA*normA_Inv;
    for(int i=0;i<n;i++) delete[] A_Inv[i];
    delete[] A_Inv;
    return k;
}
int main(){
    int n;
    cout << "Give value for size of matrix A whose condition number we want to find: ";
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
    double k = ConditionNumber(n, A);
    cout << "Condition number of matrix A is: " << k << endl;
    for(int i=0;i<n;i++) delete[] A[i];
    delete[] A;
}