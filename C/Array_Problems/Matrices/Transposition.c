#include <stdio.h>
int transposition(int row, int column, int matrix[row][column], int transpose[column][row]){
    for(int i=0;i<column;i++){
            for(int j=0;j<row;j++){
                transpose[i][j] = matrix[j][i];
            }
    }
}
int main(){
    int row,column;
    printf("Enter the number of rows in the Matrix:");
    scanf("%d", &row);
    printf("Enter the number of columns in the Matrix:");
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
    printf("\n");
    int transpose[column][row];
    transposition(row,column,matrix,transpose);
    printf("Transpose of Matrix is:\n");
    for(int i=0;i<column;i++){
        printf("[ ");
        for(int j=0;j<row;j++){
            printf("%d ",transpose[i][j]);
        }
        printf("]\n");
    }
}
