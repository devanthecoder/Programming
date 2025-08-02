#include <iostream>
using namespace std;
void PrintArray(double* arr, int n){
    cout << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
}
void Swap(double* a, double* b){
    double temp = *a;
    *a = *b;
    *b = temp;
}
void StoogeSort(double* A, int start, int end){
    if (A[start] > A[end]) Swap(&A[start], &A[end]);
    if (start+1<end){
        int sub = (end-start+1)/3;
        StoogeSort(A, start, end-sub);
        StoogeSort(A, start+sub, end);
        StoogeSort(A, start, end-sub);
    }
}
int main(){
    int n;
    cin >> n;
    double *arr = new double[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    cout << "The unsorted array is:" << endl;
    PrintArray(arr, n);
    StoogeSort(arr, 0, n-1);
    cout << "The sorted array is:" << endl;
    PrintArray(arr, n);
}