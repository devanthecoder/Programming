#include <stdio.h>
#include <stdlib.h>
void Merge(int* A, int start, int middle, int end){
    int n1 = middle-start+1;
    int n2 = end-middle;
    int* L = (int *)calloc(n1, sizeof(int)), *R = (int*)calloc(n2, sizeof(int));
    for(int i=0;i<n1;i++) L[i] = A[i+start];
    for(int i=0;i<n2;i++) R[i] = A[i+middle+1];
    int i1=0, i2=0, i=start;
    while(i1<n1 && i2<n2){
        if(L[i1]<R[i2]){
            A[i] = L[i1];
            i++; i1++;
        }
        else{
            A[i] = R[i2];
            i++; i2++;
        }
    }
    while(i1<n1){
        A[i] = L[i1];
        i++; i1++;    
    }
    while(i2<n2){
        A[i] = R[i2];
        i++; i2++;    
    }
}
void PrintArray(int* A, int start, int end){
    for(int i=start;i<=end;i++){
        printf((i==end)?"%d\n":"%d ", A[i]);
    }
}
void MergeSort(int* A, int start, int end){
    if(start!=end){
        PrintArray(A, start, end);
        int middle = (start+end)/2;
        MergeSort(A, start, middle);
        MergeSort(A, middle+1, end);
        Merge(A, start, middle, end);
        PrintArray(A, start, end);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int* A = (int *)calloc(n, sizeof(int));
    for(int i=0;i<n;i++)scanf("%d", &A[i]);
    MergeSort(A, 0, n-1);
}