#include <iostream>
using namespace std;
int NoOfInversions = 0;
void Merge(double* arr, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;

    double *arr1 = new double[n1];
    double *arr2 = new double[n2];

    for(int i = 0; i < n1; i++) arr1[i] = arr[start + i];
    for(int i = 0; i < n2; i++) arr2[i] = arr[mid + 1 + i];
    int i1=0, i2=0;
    for(int i=start;i<=end;i++){
        if(i1 < n1 && i2 < n2){
            arr[i] = arr1[i1]<arr2[i2]?arr1[i1]:arr2[i2];
            NoOfInversions += arr1[i1]>arr2[i2]?n1-i1:0;
            arr1[i1]<arr2[i2]?i1++:i2++;
        }
        else if(i1 < n1){
            arr[i] = arr1[i1];
            i1++;
        }
        else if(i2 < n2){
            arr[i] = arr2[i2];
            i2++;
        }
    }
}
void MergeSort(double* arr, int start, int end){
    if(start!=end){
        int mid=(start+end)/2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        Merge(arr, start, mid, end);
    }
    else return;
}
int main() {
    int n;
    cin >> n;
    double *arr = new double[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    cout << "The unsorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
    MergeSort(arr, 0, n-1);
    cout << "The sorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
    cout << "The number of inversions in the original array is " << NoOfInversions << ".";
}