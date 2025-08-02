#include <stdio.h>
int main(){
    int row,column;
    printf("Enter the number of rows of the Matrix:");
    scanf("%d", &row);
    printf("Enter the number of columns of the Matrix:");
    scanf("%d", &column);
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
}
