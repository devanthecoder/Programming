#include <stdio.h>
#include <math.h>
#include "Determinant.c"
#include "Submatrix.c"
int adjointofmatrix(int n, int matrix[n][n], float adjoint[n][n]){
    float cofactor[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int submatrix[n-1][n-1];
            subofmatrix(n,n,matrix,j+1,i+1,submatrix);
            adjoint[i][j]=pow(-1,i+j)*determinant(n-1,submatrix);
        }
    }
}
// int main(){
//     int n;
//     printf("Enter the size of the Matrix:");
//     scanf("%d", &n);
//     int matrix[n][n];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             printf("Enter the element in row %d and column %d:",i+1,j+1);
//             scanf("%d",&matrix[i][j]);
//         }
//     }
//     printf("Matrix is:\n");
//     for(int i=0;i<n;i++){
//         printf("[ ");
//         for(int j=0;j<n;j++){
//             printf("%d ",matrix[i][j]);
//         }
//         printf("]\n");
//     }
//     printf("\n");
//     int adjoint[n][n];
//     adjointofmatrix(n,matrix,adjoint);
//     printf("Adjoint of the Matrix is:\n");
//     for(int i=0;i<n;i++){
//         printf("[ ");
//         for(int j=0;j<n;j++){
//             printf("%d ",adjoint[i][j]);
//         }
//         printf("]\n");
//     }
// }