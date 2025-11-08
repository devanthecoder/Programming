#include <stdio.h>
#include <stdlib.h>
int BinarySearch(double* A, int start, int end, double x){
    if(start<=end){
        int middle = (start+end)/2;
        if(A[middle]>x) BinarySearch(A, start, middle-1, x);
        else if(A[middle]<x) BinarySearch(A, middle+1, end, x);
        else return middle;
    }
    else return -1;
}
int main(){
    int n;
    scanf("%d", &n);
    double* A = (double *)calloc(n, sizeof(double));
    for(int i=0;i<n;i++)scanf("%lf", &A[i]);
    int x;
    scanf("%d", &x);
    printf("%d", BinarySearch(A, 0, n-1, x));
}