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
void MatrixAddRecursive(index Astart, index Aend, index Bstart, index Bend, index Cstart, index Cend, matrix A, matrix B, matrix& C){
    if(Astart==Aend && Bstart==Bend && Cstart==Cend) C[Cstart.first][Cstart.second] = A[Astart.first][Astart.second] + B[Bstart.first][Bstart.second];
    else{
        index Amiddle = {(Astart.first+Aend.first)/2, (Astart.second + Aend.second)/2};
        index Bmiddle = {(Bstart.first+Bend.first)/2, (Bstart.second + Bend.second)/2};
        index Cmiddle = {(Cstart.first+Cend.first)/2, (Cstart.second + Cend.second)/2};
        MatrixAddRecursive(Astart, Amiddle, Bstart, Bmiddle, Cstart, Cmiddle, A, B, C);
        MatrixAddRecursive({Astart.first, Amiddle.second+1}, {Amiddle.first, Aend.second}, {Bstart.first, Bmiddle.second+1}, {Bmiddle.first, Bend.second}, {Cstart.first, Cmiddle.second+1}, {Cmiddle.first, Cend.second}, A, B, C);
        MatrixAddRecursive({Amiddle.first+1,Astart.second}, {Aend.first, Amiddle.second}, {Bmiddle.first+1,Bstart.second}, {Bend.first, Bmiddle.second}, {Cmiddle.first+1,Cstart.second}, {Cend.first, Cmiddle.second}, A, B, C);
        MatrixAddRecursive({Amiddle.first+1,Amiddle.second+1}, Aend, {Bmiddle.first+1,Bmiddle.second+1}, Bend, {Cmiddle.first+1,Cmiddle.second+1}, Cend, A, B, C);
        // MatrixAddRecursive({Amiddle.first+1,Astart.second}, {Aend.first, Amiddle.second}, {Bstart.first, Bmiddle.second+1}, {Bmiddle.first, Bend.second}, {Cmiddle.first+1,Cmiddle.second+1}, Cend, A, B, C);
        // MatrixAddRecursive({Astart.first, Amiddle.second+1}, {Amiddle.first, Aend.second}, {Bmiddle.first+1,Bstart.second}, {Bend.first, Bmiddle.second}, Cstart, Cmiddle, A, B, C);
        // MatrixAddRecursive({Astart.first, Amiddle.second+1}, {Amiddle.first, Aend.second}, {Bmiddle.first+1,Bmiddle.second+1}, Bend, {Cstart.first, Cmiddle.second+1}, {Cmiddle.first, Cend.second}, A, B, C);
        // MatrixAddRecursive({Amiddle.first+1,Amiddle.second+1}, Aend, {Bmiddle.first+1,Bmiddle.second+1}, Bend, {Cmiddle.first+1,Cmiddle.second+1}, Cend, A, B, C);
    }
}
void MatrixAddRecursiveGeneralize(index Astart, index Aend, index Bstart, index Bend, index Cstart, index Cend, matrix &A, matrix& B, matrix& C){
    int zeroRowsCount=0, size=Aend.first - Astart.first + 1;
    while(!is2Power(Aend.first - Astart.first + 1)){
        zeroRowsCount++;
        for(int i=Astart.first;i<=Aend.first;i++){
            A[i].push_back(0);
            B[i].push_back(0);
            C[i].push_back(0);
        }
        A.push_back(vector <int>(A[0].size(), 0));
        B.push_back(vector <int>(A[0].size(), 0));
        C.push_back(vector <int>(A[0].size(), 0));
        Aend.first++;Aend.second++;
        Bend.first++;Bend.second++;
        Cend.first++;Cend.second++;
    }
    MatrixAddRecursive(Astart, Aend, Bstart, Bend, Cstart, Cend, A, B, C);
    for(int i=0;i<zeroRowsCount;i++){
        for(int j=Astart.second;j<=size+Astart.second;j++)C[j].pop_back();
        C.pop_back();
    }
    for(int j=Astart.second;j<=size+Astart.second;j++)C[j].pop_back();
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
    MatrixAddRecursiveGeneralize({0,0}, {n-1, n-1}, {0,0}, {n-1, n-1}, {0,0}, {n-1, n-1}, A, B, C);
    cout << "Matrix C = A * B is:" << endl;
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<n;j++)cout << C[i][j] << " ";
        cout << "]" << endl;
    }
}
