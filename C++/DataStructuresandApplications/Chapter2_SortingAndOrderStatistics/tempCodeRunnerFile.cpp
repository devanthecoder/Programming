#include <iostream>
#include <cstdlib>
#include <ctime>
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
int RANDOM(int a, int b){
    return a + rand()%(b-a+1);
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
int RandomPartition(double* A, int start, int end){
    int pivot = RANDOM(start, end);
    Swap(&A[pivot], &A[end]);
    return Partition(A, start, end);
}
int RandomizedSelect(double* A, int start, int end, int index){
    while(start!=end){
        int pivot = RandomPartition(A, start, end);
        int size = pivot - start + 1;
        if(index == size) return A[pivot];
        else if(index < size) end = pivot-1;
        else {
            start = pivot+1;
            index -= size;
        }
    }
    return A[start];
}
int main(){
    srand(time(0));
    int n;
    cin >> n; 
    double* A = new double[n];
    for(int i=0;i<n;i++)cin >> A[i];
    int i;
    cin >> i;
    cout << "The " << i << "th smallest element of the array is " << RandomizedSelect(A, 0, n-1, i) << ".";
}