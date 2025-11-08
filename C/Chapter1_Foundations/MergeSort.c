#include <stdio.h>
#include <stdlib.h>
void PrintArray(double* A, int n){
    printf("[ ");
    for(int i=0;i<n;i++)printf("%.2lf ", A[i]);
    printf("]\n");
}
void Merge(double* A, int start, int middle, int end){
    if(start==end) return;
    int n1 = middle - start + 1;
    int n2 = end - middle;
    double* L = (double *)calloc(n1, sizeof(double));
    double* R = (double *)calloc(n2, sizeof(double));
    // PrintArray(L, n1);
    // PrintArray(R, n2);
    for(int i=0;i<n1;i++) L[i] = A[start+i];
    for(int i=0;i<n2;i++) R[i] = A[middle+1+i];
    int i1=0, i2=0, i=start;
    while(i1<n1 && i2<n2){
        if(L[i1]>R[i2]){
            A[i] = R[i2];
            // printf("%lf\n", A[i]);
            i++; i2++;
        }
        else{
            A[i] = L[i1];
            i++; i1++;
        }
    }
    while(i2<n2){
        A[i] = R[i2];
        i++; i2++;    
    }
    while(i1<n1){
        A[i] = L[i1];
        i++; i1++;    
    }
}
void MergeSort(double* A, int start, int end){
    if(start<end){
        int middle = (start+end)/2;
        MergeSort(A, start, middle);
        MergeSort(A, middle+1, end);
        Merge(A, start, middle, end);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    double* A = (double *)calloc(n, sizeof(double));
    for(int i=0;i<n;i++) scanf("%lf", &A[i]);
    PrintArray(A, n);
    MergeSort(A, 0, n-1);
    PrintArray(A, n);
}