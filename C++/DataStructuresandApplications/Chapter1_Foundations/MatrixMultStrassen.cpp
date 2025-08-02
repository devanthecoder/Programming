#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> intvec;
typedef vector<intvec> matrix;
typedef pair<int, int> index;

matrix AddMatrix(index Astart, index Bstart, matrix A, matrix B, int Size, int isSubtracting) {
    matrix C(Size, intvec(Size, 0));
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            C[i][j] = A[Astart.first + i][Astart.second + j] + (isSubtracting ? -B[Bstart.first + i][Bstart.second + j] : B[Bstart.first + i][Bstart.second + j]);
        }
    }
    return C;
}

int is2Power(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

void MatrixMultiplyStrassen(index Astart, index Bstart, index Cstart, matrix A, matrix B, matrix &C, int Size) {
    if (Size == 1) {
        C[Cstart.first][Cstart.second] += A[Astart.first][Astart.second] * B[Bstart.first][Bstart.second];
    } else {
        int nextSize = Size / 2;
        index A11 = Astart;
        index A12 = {Astart.first, Astart.second + nextSize};
        index A21 = {Astart.first + nextSize, Astart.second};
        index A22 = {Astart.first + nextSize, Astart.second + nextSize};
        index B11 = Bstart;
        index B12 = {Bstart.first, Bstart.second + nextSize};
        index B21 = {Bstart.first + nextSize, Bstart.second};
        index B22 = {Bstart.first + nextSize, Bstart.second + nextSize};

        matrix S1 = AddMatrix(B12, B22, B, B, nextSize, 1);
        matrix S2 = AddMatrix(A11, A12, A, A, nextSize, 0);
        matrix S3 = AddMatrix(A21, A22, A, A, nextSize, 0);
        matrix S4 = AddMatrix(B21, B11, B, B, nextSize, 1);
        matrix S5 = AddMatrix(A11, A22, A, A, nextSize, 0);
        matrix S6 = AddMatrix(B11, B22, B, B, nextSize, 0);
        matrix S7 = AddMatrix(A12, A22, A, A, nextSize, 1);
        matrix S8 = AddMatrix(B21, B22, B, B, nextSize, 0);
        matrix S9 = AddMatrix(A11, A21, A, A, nextSize, 1);
        matrix S10 = AddMatrix(B11, B12, B, B, nextSize, 0);

        matrix P1(nextSize, intvec(nextSize, 0));
        matrix P2(nextSize, intvec(nextSize, 0));
        matrix P3(nextSize, intvec(nextSize, 0));
        matrix P4(nextSize, intvec(nextSize, 0));
        matrix P5(nextSize, intvec(nextSize, 0));
        matrix P6(nextSize, intvec(nextSize, 0));
        matrix P7(nextSize, intvec(nextSize, 0));

        index null = {0, 0};
        MatrixMultiplyStrassen(A11, null, null, A, S1, P1, nextSize);
        MatrixMultiplyStrassen(null, B22, null, S2, B, P2, nextSize);
        MatrixMultiplyStrassen(null, B11, null, S3, B, P3, nextSize);
        MatrixMultiplyStrassen(A22, null, null, A, S4, P4, nextSize);
        MatrixMultiplyStrassen(null, null, null, S5, S6, P5, nextSize);
        MatrixMultiplyStrassen(null, null, null, S7, S8, P6, nextSize);
        MatrixMultiplyStrassen(null, null, null, S9, S10, P7, nextSize);

        // C11 = P5 + P4 - P2 + P6
        matrix temp1 = AddMatrix(null, null, P5, P4, nextSize, 0);
        matrix temp2 = AddMatrix(null, null, temp1, P2, nextSize, 1);
        matrix C11 = AddMatrix(null, null, temp2, P6, nextSize, 0);

        matrix C12 = AddMatrix(null, null, P1, P2, nextSize, 0);
        matrix C21 = AddMatrix(null, null, P3, P4, nextSize, 0);

        // C22 = P5 + P1 - P3 - P7
        temp1 = AddMatrix(null, null, P5, P1, nextSize, 0);
        temp2 = AddMatrix(null, null, temp1, P3, nextSize, 1);
        matrix C22 = AddMatrix(null, null, temp2, P7, nextSize, 1);

        for (int i = 0; i < nextSize; i++) {
            for (int j = 0; j < nextSize; j++) {
                C[Cstart.first + i][Cstart.second + j] += C11[i][j];
                C[Cstart.first + i][Cstart.second + j + nextSize] += C12[i][j];
                C[Cstart.first + i + nextSize][Cstart.second + j] += C21[i][j];
                C[Cstart.first + i + nextSize][Cstart.second + j + nextSize] += C22[i][j];
            }
        }
    }
}

void MatrixMultiplyStrassenGeneralize(index Astart, index Bstart, index Cstart, matrix A, matrix B, matrix& C, int Size){
    int zeroRowsCount=0, runningSize=Size;
    while(!is2Power(runningSize)){
        zeroRowsCount++;
        for(int i=Astart.first;i<runningSize+Astart.first;i++){
            A[i].push_back(0);
            B[i].push_back(0);
            C[i].push_back(0);
        }
        A.push_back(intvec(A[0].size(), 0));
        B.push_back(intvec(A[0].size(), 0));
        C.push_back(intvec(A[0].size(), 0));
        runningSize++;
    }
    MatrixMultiplyStrassen(Astart, Bstart, Cstart, A, B, C, runningSize);
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
    matrix A(n, intvec(n,0)), B(n, intvec(n,0)), C(n, intvec(n,0));
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
    MatrixMultiplyStrassenGeneralize({0,0}, {0,0}, {0,0}, A, B, C, n);
    cout << "Matrix C = A * B is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << C[i][j] << " ";
        cout << "]" << endl;
    }
}
