#include <stdio.h>
#include <stdlib.h>
int LinearSearch(double* A, int n, double x){
    for(int i=0;i<n;i++){
        if(A[i]==x) return i;
    }
    return -1;
}
int main(){
    int n;
    scanf("%d", &n);
    double* A = (double *)calloc(n, sizeof(double));
    for(int i=0;i<n;i++)scanf("%lf", &A[i]);
    int x;
    scanf("%d", &x);
    printf("%d", LinearSearch(A, n, x));
}