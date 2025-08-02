#include <iostream>
#include <cmath>
using namespace std;

void PrintArray(double* arr, int n){
    cout << "[ ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "]" << endl;
}
int * CountingSort(int* A, int n, int k){
    int* C = new int[k+1]{0};
    int* B = new int[n];
    for(int j=0;j<n;j++) C[A[j]]++;
    for(int i=1;i<=k;i++)C[i]+=C[i-1];
    for(int j=n-1;j>=0;j--){
        --C[A[j]];
        B[C[A[j]]] = A[j];
    }
    return B;
}
double* CountingSortDecimal(double* A, int n, int k, int d){
    int scale = pow(10, d);
    int k_ = k * scale + 1;
    int* C = new int[k_]{0};
    double* B = new double[n];
    for(int j = 0; j < n; j++){
        int key = (int)(A[j] * scale + 0.5);
        C[key]++;
    }
    for(int i = 1; i < k_; i++) C[i] += C[i - 1];
    for(int j = n - 1; j >= 0; j--){
        int key = (int)(A[j] * scale + 0.5);
        B[--C[key]] = A[j];
    }
    return B;
}
void CountingSortInplace(int* A, int n, int k){
    int* C = new int[k+1];
    for(int i=0;i<=k;i++) C[i]=0;
    for(int j=0;j<n;j++) C[A[j]]++;
    int index=0;
    for(int i=0;i<=k;i++){
        while(C[i]>0){
            A[index] = i;
            index++; C[i]--;
        }
    }
}