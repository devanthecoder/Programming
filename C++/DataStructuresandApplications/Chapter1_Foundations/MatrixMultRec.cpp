#include <iostream>
#include <vector>
using namespace std;
typedef vector <vector <int>> matrix;
typedef pair <int, int> index;
int is2Power(int n){
    while(n%2==0){
        n/=2;
    }
    if(n==1)return 1;
    else return 0;
}
void MatrixMultiplyRecursive(index Astart, index Bstart, index Cstart, matrix A, matrix B, matrix& C, int Size){
    if(Size==1) C[Cstart.first][Cstart.second] += A[Astart.first][Astart.second] * B[Bstart.first][Bstart.second];
    else{
        int nextSize = Size/2;
        index Astart11 = Astart;
        index Astart12 = {Astart.first, Astart.second + nextSize};
        index Astart21 = {Astart.first + nextSize, Astart.second};
        index Astart22 = {Astart.first + nextSize, Astart.second + nextSize};
        index Bstart11 = Bstart;
        index Bstart12 = {Bstart.first, Bstart.second + nextSize};
        index Bstart21 = {Bstart.first + nextSize, Bstart.second};
        index Bstart22 = {Bstart.first + nextSize, Bstart.second + nextSize};
        index Cstart11 = Cstart;
        index Cstart12 = {Cstart.first, Cstart.second + nextSize};
        index Cstart21 = {Cstart.first + nextSize, Cstart.second};
        index Cstart22 = {Cstart.first + nextSize, Cstart.second + nextSize};
        MatrixMultiplyRecursive(Astart11, Bstart11, Cstart11, A, B, C, nextSize);
        MatrixMultiplyRecursive(Astart12, Bstart21, Cstart11, A, B, C, nextSize);
        MatrixMultiplyRecursive(Astart11, Bstart12, Cstart12, A, B, C, nextSize);
        MatrixMultiplyRecursive(Astart12, Bstart22, Cstart12, A, B, C, nextSize);
        MatrixMultiplyRecursive(Astart21, Bstart11, Cstart21, A, B, C, nextSize);
        MatrixMultiplyRecursive(Astart22, Bstart21, Cstart21, A, B, C, nextSize);
        MatrixMultiplyRecursive(Astart21, Bstart12, Cstart22, A, B, C, nextSize);
        MatrixMultiplyRecursive(Astart22, Bstart22, Cstart22, A, B, C, nextSize);
    }
}
void MatrixMultiplyRecursiveGeneralize(index Astart, index Bstart, index Cstart, matrix A, matrix B, matrix& C, int Size){
    int zeroRowsCount=0, runningSize=Size;
    while(!is2Power(runningSize)){
        zeroRowsCount++;
        for(int i=Astart.first;i<runningSize+Astart.first;i++){
            A[i].push_back(0);
            B[i].push_back(0);
            C[i].push_back(0);
        }
        A.push_back(vector <int>(A[0].size(), 0));
        B.push_back(vector <int>(A[0].size(), 0));
        C.push_back(vector <int>(A[0].size(), 0));
        runningSize++;
    }
    MatrixMultiplyRecursive(Astart, Bstart, Cstart, A, B, C, runningSize);
    for(int i=0;i<zeroRowsCount;i++){
        for(int j=Astart.second;j<=Size+Astart.second;j++)C[j].pop_back();
        C.pop_back();
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
    MatrixMultiplyRecursiveGeneralize({0,0}, {0,0}, {0,0}, A, B, C, n);
    cout << "Matrix C = A * B is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << C[i][j] << " ";
        cout << "]" << endl;
    }
}
