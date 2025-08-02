#include <stdio.h>
int main(){
    int row,column,n;
    printf("Enter the number of matrices being added:");
    scanf("%d",&n);
    printf("Enter the number of rows of each of the Matrices being added:");
    scanf("%d", &row);
    printf("Enter the number of columns each of the Matrices being added:");
    scanf("%d", &column);
    int matrix[row][column];
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("Enter the element in row %d and column %d",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Transpose of your Matrix is:\n");
    for(int i=0;i<row;i++){
        printf("[ ");
    for(int j=0;j<column;j++){
            printf("%d ",transpose[i][j]);
        }
        printf("]\n");
    }
    int transpose[column][row];
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            transpose[i][j]=matrix[j][i];
        }
    }
    printf("Transpose of your Matrix is:\n");
    for(int i=0;i<column;i++){
        printf("[ ");
    (int j=0;j<row;j++){
            printf("%d ",transpose[i][j]);
        }
        printf("]\n");
    }
}



    







