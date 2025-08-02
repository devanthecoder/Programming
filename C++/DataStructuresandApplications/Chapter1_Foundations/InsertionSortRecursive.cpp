#include <iostream>
using namespace std;
void InsertionSort(int n, double* arr){
    if(n==1) return;
    InsertionSort(n-1, arr);
    double toInsert = arr[n-1];
    int index;
    for(index=n-2;arr[index]>toInsert && index>=0;index--){
        arr[index+1]=arr[index];
    }
    arr[index+1] = toInsert;
}
int main() {
    int n;
    cin >> n;
    double *arr = new double[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    cout << "The unsorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
    InsertionSort(n, arr);
    cout << "The sorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
}