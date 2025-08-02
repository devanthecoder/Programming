#include <stdio.h>
int subofmatrix(int row, int column, int matrix[row][column], int removerow, int removecolumn, int submatrix[row - 1][column - 1]){
    int newi = 0;
    for (int i = 0; i < row - 1; i++){
        if (i == (removerow - 1)){
            newi++;
        }
        int newj = 0;
        for (int j = 0; j < column - 1; j++){
            if (j == (removecolumn - 1)){
                newj++;
            }
            submatrix[i][j] = 0;
            submatrix[i][j] = matrix[newi][newj];
            newj++;
        }
        newi++;
    }
}
// int main(){
//     int row, column;
//     printf("Enter the number of rows of the Matrix:");
//     scanf("%d", &row);
//     printf("Enter the number of columns each of the Matrix:");
//     scanf("%d", &column);
//     int matrix[row][column];
//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < column; j++){
//             printf("Enter the element in row %d and column %d:", i + 1, j + 1);
//             scanf("%d", &matrix[i][j]);
//         }
//     }
//     printf("Matrix is:\n");
//     for (int i = 0; i < row; i++){
//         printf("[ ");
//         for (int j = 0; j < column; j++){
//             printf("%d ", matrix[i][j]);
//         }
//         printf("]\n");
//     }
//     int removerow, removecolumn;
//     printf("Enter which row of the Matrix to remove:");
//     scanf("%d", &removerow);
//     printf("Enter which column of the Matrix to remove:");
//     scanf("%d", &removecolumn);
//     int submatrix[row - 1][column - 1];
//     subofmatrix(row, column, matrix, removerow, removecolumn, submatrix);
//     for (int i = 0; i < row - 1; i++){
//         printf("[ ");
//         for (int j = 0; j < column - 1; j++){
//             printf("%d ", submatrix[i][j]);
//         }
//         printf("]\n");
//     }
// }
