#include <iostream>
using namespace std;
void InsertionSort(int n, double* arr){
    for(int SizeofSorted=1;SizeofSorted<n;SizeofSorted++){
        double toInsert = arr[SizeofSorted];
        int index;
        for(index=SizeofSorted-1;arr[index]>toInsert && index>=0;index--){
            arr[index+1]=arr[index];
        }
        arr[index+1] = toInsert;
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
    InsertionSort(n, arr);
    cout << "The sorted array is:" << endl << "[ ";
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << "]" << endl;
}