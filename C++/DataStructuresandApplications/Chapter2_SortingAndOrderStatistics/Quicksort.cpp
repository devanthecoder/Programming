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
int Partition(double* A, int start, int end){
    double pivot = A[end];
    int i = start-1;
    for(int j=start;j<end;j++){
        if(A[j]<pivot){
            i++;
            Swap(&A[i], &A[j]);
        }
    }
    Swap(&A[i+1], &A[end]);
    return i+1;
}
int HoarePartition(double* A, int start, int end){
    double pivot = A[start];
    int i = start-1, j = end + 1;
    while (true){
        do j--;
        while(A[j]>pivot);
        do i++;
        while(A[i]<pivot);
        if(i<j) Swap(&A[i],&A[j]);
        else return j;
    }
}
pair<int, int> PartitionEqual(double* A, int start, int end) {
    double pivot = A[end];
    int lt = start;       // A[start..lt-1] < pivot
    int i = start;        // A[lt..i-1] == pivot
    int gt = end;         // A[gt+1..end] > pivot

    while (i <= gt) {
        if (A[i] < pivot) {
            Swap(&A[i], &A[lt]);
            i++;
            lt++;
        }
        else if (A[i] > pivot) {
            Swap(&A[i], &A[gt]);
            gt--;
        }
        else {
            i++;
        }
    }

    return {lt, gt};  // A[lt..gt] == pivot
}

void QuickSort(double* A, int start, int end){
    if (start < end){
        pair <int, int> pivotpoints = PartitionEqual(A, start, end);
        QuickSort(A, start, pivotpoints.first-1);
        QuickSort(A, pivotpoints.second+1, end);
    }
}
int main(){
    int n;
    cin >> n;
    double *arr = new double[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    cout << "The unsorted array is:" << endl;
    PrintArray(arr, n);
    QuickSort(arr, 0, n-1);
    cout << "The sorted array is:" << endl;
    PrintArray(arr, n);
}