#include <iostream>
using namespace std;
void SelectionSort(int n, double* arr){
    for(int i=0;i<n-1;i++){
        double min = arr[i];
        int minindex = i;
        for(int j=i+1;j<n;j++){
            if(min>arr[j]){
                min = arr[j];
                minindex = j;
            }
        }
        double temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
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
    SelectionSort(n, arr);
    cout << "The sorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
}