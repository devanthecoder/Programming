#include <iostream>
#include <cmath>
using namespace std;
void Swap(double* a, double* b){
    double temp = *a;
    *a = *b;
    *b = temp;
}
int SetPivot(double* arr, int start, int end){
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<=arr[end]){
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i+1], &arr[end]);
    return i+1;
}
void QuickSort(double* arr, int start, int end){
    if(start<end){
        int pivot = SetPivot(arr, start, end);
        QuickSort(arr, start, pivot-1);
        QuickSort(arr, pivot+1, end);
    }
}
int main() {
    int n;
    cin >> n;
    double *arr = new double[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    cout << "The unsorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
    QuickSort(arr, 0, n-1);
    cout << "The sorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
}