#include <stdio.h>
#include <math.h>
#include "Adjoint.c"
float inversion(int n, int matrix[n][n], float inverse[n][n]){
    adjointofmatrix(n,matrix,inverse);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inverse[i][j]/=(float)determinant(n,matrix);
        }
    }
}
int main(){
    int n;
    printf("Enter the size of the Matrix:");
    scanf("%d", &n);
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter the element in row %d and column %d:",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Matrix is:\n");
    for(int i=0;i<n;i++){
        printf("[ ");
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
    float inverse[n][n];
    inversion(n,matrix,inverse);
    printf("Inverse of the Matrix is:\n");
    for(int i=0;i<n;i++){
        printf("[ ");
        for(int j=0;j<n;j++){
            printf("%0.2lf ",inverse[i][j]);
        }
        printf("]\n");
    }
}