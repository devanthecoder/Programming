#include <stdio.h>
int main(){
        // Program block for adding any n Matrices of any size
    int row,column,n;
    printf("Enter the number of matrices being added:");
    scanf("%d",&n);
    printf("Enter the number of rows of each of the Matrices being added:");
    scanf("%d", &row);
    printf("Enter the number of columns each of the Matrices being added:");
    scanf("%d", &column);
    int sumn[row][column];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            sumn[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        printf("Enter the elements of matrix %d:\n",i);
        int matrix[row][column];
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                printf("Enter the element in row %d and column %d:",i+1,j+1);
        scanf("%d",&matrix[i][j]);
            }
        }
        printf("Matrix is:\n");
        for(int i=0;i<row;i++){
            printf("[ ");
            for(int j=0;j<column;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("]\n");
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                sumn[i][j]+=matrix[i][j];
            }
        }
    }    
    printf("Sum of the %d matrices are:\n",n);
    for(int i=0;i<row;i++){
        printf("[ ");
        for(int j=0;j<column;j++){
            printf("%d ",sumn[i][j]);
        }
        printf("]\n");
    }
}