#include <stdio.h>
void transposition(int row, int column, int *matrix, int *transpose){
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++)*(transpose + j*column+i)=*(matrix+i*row+j);
    }
}
void printMatrix(int row, int column, int *matrix){
    for(int i=0;i<column;i++){
        printf("[");
        for(int j=0;j<row;j++)printf("%d ",*(matrix+i*row+j));
        printf("]\n");
    }
    printf("\n");
}
int main(){
    int row, column;
    scanf("%d %d",&row,&column);
    int matrix[column][row],transpose[row][column];
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    transposition(row,column,matrix,transpose);
    printf("Matrix and its Transpose are:\n");
    printMatrix(row,column,matrix);
    printMatrix(column,row,transpose);
}