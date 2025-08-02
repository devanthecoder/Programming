#include <iostream>
using namespace std;
void LU_Decomposition(int n, float **A, float **L, float **U){
    for(int j=0;j<n;j++){
        for(int i=0;i<=j;i++){
            L[i][j]=(float)(i==j);
            float sum = 0;
            for(int k=0;k<i;k++)sum+=L[i][k]*U[k][j];
            U[i][j] = A[i][j]-sum;
        }
        for(int i=j+1;i<n;i++){
            U[i][j]=0;
            float sum = 0;
            for(int k=0;k<j;k++)sum+=L[i][k]*U[k][j];
            L[i][j] = (A[i][j]-sum)/U[j][j];
        }
    }
}
float *Forward_Substitution(int n, float** L, float* b){
    float* y = new float[n];
    for(int i=0;i<n;i++){
        float sum = 0;
        for(int j=0;j<i;j++)sum+=L[i][j]*y[j];
        y[i]=(b[i]-sum)/L[i][i];
    }
    return y;
}
float *Backward_Substitution(int n, float** U, float* y){
    float* x = new float[n];
    for(int i=n-1;i>=0;i--){
        float sum = 0;
        for(int j=i+1;j<n;j++)sum+=U[i][j]*x[j];
        x[i]=(y[i]-sum)/U[i][i];
    }
    return x;
}
int main(){
    int n;
    cout << "Give value for size of matrix A and vector b: ";
    cin >> n;
    float **A = new float*[n];
    float *b = new float[n];
    for(int i=0;i<n;i++){
        A[i] = new float[n];
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
    for(int i=0;i<n;i++){
        cout << "Input the value of element " << i+1 << " of vector b: ";
        cin >> b[i];
    }
    cout << "Vector b is:" << endl << "[ ";
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << "]" << endl;
    float ** L = new float*[n];
    float ** U = new float*[n];
    for(int i=0;i<n;i++){
        L[i] = new float[n];
        U[i] = new float[n];
    }
    LU_Decomposition(n, A, L, U);
    cout << "Lower Triangular Matrix L is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << L[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "Upper Triangular Matrix U is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << U[i][j] << " ";
        cout << "]" << endl;
    }
    float* y = Forward_Substitution(n, L, b);
    float* x = Backward_Substitution(n, U, y);
    cout << "Solution vector x is:" << endl << "[ ";
    for(int i=0;i<n;i++){
        cout << x[i] << " ";
    }
    cout << "]" << endl;
}