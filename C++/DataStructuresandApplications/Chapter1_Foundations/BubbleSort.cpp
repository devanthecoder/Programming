#include <iostream>
using namespace std;
void PrintArray(double* arr, int n){
    cout << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
}
void BubbleSort(int n, double* arr){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>=i;j--){
            if(arr[j]<arr[j-1]){
                double temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            PrintArray(arr,n);
        }
    }
}
int main() {
    int n;
    cin >> n;
    double *arr = new double[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    cout << "The unsorted array is:" << endl;
    PrintArray(arr, n);
    BubbleSort(n, arr);
    cout << "The sorted array is:" << endl;
    PrintArray(arr, n);
}