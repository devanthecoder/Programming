#include <stdio.h>
#include <stdlib.h>
void InsertionSort(double* A, int n){
    for(int i=1;i<n;i++){
        int toInsert = A[i];
        int j=i-1;
        for(;A[j]>toInsert;j--){
            A[j+1]=A[j];
        }
        A[j+1] = toInsert;
    }
}
void PrintArray(double* A, int n){
    printf("[ ");
    for(int i=0;i<n;i++)printf("%.2lf ", A[i]);
    printf("]\n");
}
int main(){
    int n;
    scanf("%d", &n);
    double* A = (double *)calloc(n, sizeof(double));
    for(int i=0;i<n;i++) scanf("%lf", &A[i]);
    PrintArray(A, n);
    InsertionSort(A, n);
    PrintArray(A, n);
}