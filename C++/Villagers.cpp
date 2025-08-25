#include <iostream>
using namespace std;
void Merge(int* arr, int start, int mid, int end){
     int n1 = mid - start + 1;
    int n2 = end - mid;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    for(int i = 0; i < n1; i++) arr1[i] = arr[start + i];
    for(int i = 0; i < n2; i++) arr2[i] = arr[mid + 1 + i];
    int i1=0, i2=0;
    for(int i=start;i<=end;i++){
        if(i1 < n1 && i2 < n2){
            arr[i] = arr1[i1]<=arr2[i2]?arr1[i1]:arr2[i2];
            // i++;
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
void MergeSort(int* arr, int start, int end){
    if(start!=end){
        int mid=(start+end)/2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        Merge(arr, start, mid, end);
    }
    else return;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0;i<n;i++)cin >> arr[i];
        MergeSort(arr, 0, n-1);
        long long int min=0;
        for(int i=n-1;i>=0;i-=2){
            min += arr[i];
        }
        cout << min << endl;
    }
}