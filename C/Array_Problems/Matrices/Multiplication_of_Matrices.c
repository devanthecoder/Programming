#include <stdio.h>
void multiplysquare(int n, double matrix1[n][n], double matrix2[n][n], double product[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double produt=0;
            for(int l =0;l<n;l++){
                produt += matrix1[i][l]*matrix2[l][j];
            }
            product[i][j]=produt;
        }
    }
}
void powermatrix(int n, double matrix[n][n], int m, double final[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            final[i][j]=(i==j)?1:0;
        }
    }
    double temp[n][n];
    for(int i=0;i<m;i++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=final[i][j];
            }
        }
        multiplysquare(n, matrix, temp, final);
    }
}
int fact(int n){
    int fac=1;
    for(int i=1;i<=n;i++)fac*=i;
    return fac;
}
int main(){
    int n;
    printf("Enter the size of the Matrix:");
    scanf("%d", &n);
    // printf("Enter the number of columns in Matrix 1:");
    // scanf("%d", &n);
        double matrix[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("Enter the element in row %d and column %d:",i+1,j+1);
                scanf("%lf",&matrix[i][j]);
            }
        }
        printf("Matrix is:\n");
        for(int i=0;i<n;i++){
            printf("[ ");
            for(int j=0;j<n;j++){
                printf("%lf ",matrix[i][j]);
            }
            printf("]\n");
    }
    printf("\nE to the power of matrix is approx:\n");
    int A=0;
    double e[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)e[i][j]=0;
    while(A<20){
        double power[n][n];
        powermatrix(n, matrix, A, power);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                e[i][j]+=(double)power[i][j]/fact(A);
            }
        }
        A++;
    }
    for(int i=0;i<n;i++){
        printf("[ ");
        for(int j=0;j<n;j++){
            printf("%lf ",e[i][j]);
        }
        printf("]\n");
    }
}