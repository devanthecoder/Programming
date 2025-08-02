#include <iostream>
#include <cmath>
using namespace std;
void MergeSort(double* arr, int start, int end){
    if(end == start) return;
    if(end - start == 1){
        if(arr[end] < arr[start]){
            double temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
        }
        return;
    }

    int mid = (start + end) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);

    int n1 = mid - start + 1;
    int n2 = end - mid;
    double* arr1 = new double[n1];
    double* arr2 = new double[n2];

    for (int i = 0; i < n1; i++) arr1[i] = arr[start + i];
    for (int i = 0; i < n2; i++) arr2[i] = arr[mid + 1 + i];

    int i1 = 0, i2 = 0, i = start;
    while(i1 < n1 && i2 < n2){
        bool takeFromArr1 = arr1[i1] < arr2[i2];
        arr[i++] = takeFromArr1 ? arr1[i1++] : arr2[i2++];
    }
    while(i1 < n1) arr[i++] = arr1[i1++];
    while(i2 < n2) arr[i++] = arr2[i2++];

    delete[] arr1;
    delete[] arr2;
}
int BinarySearch(double *arr, int start, int end, double x){
    if(start >= end) return -1;
    int mid=(start+end)/2;
    if(arr[mid]==x) return mid;
    else if(arr[mid]>x) return BinarySearch(arr, start, mid, x);
    else return BinarySearch(arr, mid+1, end, x);
}
int hasSum(double* S, int n, double x){
    MergeSort(S, 0, n-1);
    for (int i = 0; i < n - 1; i++) {
        double toSearch = x - S[i];
        int index = BinarySearch(S, i + 1, n - 1, toSearch);
        if (index != -1) return 1;
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    double *S = new double[n];
    for(int i=0;i<n;i++) cin >> S[i];
    cout << "The array 'S' is:" << endl;
    for(int i=0;i<n;i++) cout << S[i] << " ";
    cout << endl;
    double x;
    cin >> x;
    cout << "The number for which we want to find a viable sum in the array is " << x << "." << endl;
    cout << hasSum(S, n, x);
}