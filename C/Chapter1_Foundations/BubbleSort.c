#include <stdio.h>
#include <stdlib.h>
void Swap(double* a, double* b){
    double temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(double* A, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]) Swap(&A[j], &A[j+1]);
        }
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
    BubbleSort(A, n);
    PrintArray(A, n);
}