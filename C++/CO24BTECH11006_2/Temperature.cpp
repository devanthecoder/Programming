#include <iostream>
using namespace std;
float* TriDiagMatrix_Solution(int n, float** A, float* b){
    float*p = new float[n];
    float*q = new float[n];
    float*x = new float[n];
    p[0]=-A[0][1]/A[0][0], q[0] = b[0]/A[0][0];
    for(int i=1;i<n;i++){
        p[i] = -A[i][i+1]/(A[i][i]+A[i][i-1]*p[i-1]);
        q[i] = (b[i] - A[i][i-1]*q[i-1])/(A[i][i] + A[i][i-1]*p[i-1]);
    }
    x[n-1] = q[n-1];
    for(int i=n-2;i>=0;i--)x[i]=p[i]*x[i+1] + q[i];
    return x;
}
int main(){
    float len, divlen,hottemp,coldtemp,del2T;
    cout << "Enter length of rod: ";
    cin >> len;
    cout << "Enter length of each division of the rod: ";
    cin >> divlen;
    cout << "Enter temperature at hot end of rod: ";
    cin >> hottemp;
    cout << "Enter temperature at cold end of rod: ";
    cin >> coldtemp;
    cout << "Input in value of d^2T/dx^2: ";
    cin >> del2T;
    int size = (len / divlen) - 0.1;
    float *b = new float[size];
    b[0]= del2T*divlen*divlen-hottemp;
    for(int i=1;i<size-1;i++)b[i]=del2T*divlen*divlen;
    b[size-1]=del2T*divlen*divlen-coldtemp;
    float **A = new float*[size];
    for(int i=0;i<size;i++)A[i] = new float[size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)A[i][j]=0;
        A[i][i]=-2;
        if(i)A[i][i-1]=1;
        if(i!=size-1)A[i][i+1]=1;
    }
    cout << "Matrix A is:" << endl;
    for(int i=0;i<size;i++){
        cout << "[ ";
        for(int j=0;j<size;j++)cout << A[i][j] << " ";
        cout << "]" << endl;
    }
    cout << "Vector b is:" << endl;
    cout << "[ ";
    for(int i=0;i<size;i++){
        cout << b[i] << " ";
    }
    cout << "]" << endl;
    float* x = TriDiagMatrix_Solution(size, A, b);
    cout << "The temperatures along the rod are:" << endl << "[ " << hottemp << " ";
    for(int i=0;i<size;i++){
        cout << x[i] << " ";
    }
    cout << coldtemp << " ]";
}