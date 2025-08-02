#include <stdio.h>
#include <math.h>
int determinant(int n, int matrix[n][n]){
    int det=0;
    if(n==1){
        return matrix[0][0];
    }
    else{
        for(int k=0;k<n;k++){
            int subarray[n-1][n-1];
            int newi=0;
            for(int i=0;i<n-1;i++){
                if(i==k){
                    newi++;
                }
                int newj=0;
                for(int j=0;j<n-1;j++){
                    if(j==0){
                        newj++;
                    }
                    subarray[i][j] = 0;
                    subarray[i][j]=matrix[newi][newj];
                    newj++;
                }
                newi++;
            }
        det+=(matrix[k][0])*((int)pow(-1,k))*determinant(n-1,subarray);
        }
    }
    return det;
}
// int main(){
//     int n;
//     printf("Enter size of the Matrix:");
//     scanf("%d", &n);
//         int matrix[n][n];
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 printf("Enter the element in row %d and column %d:",i+1,j+1);
//                 scanf("%d",&matrix[i][j]);
//             }
//         }
//     printf("%d",determinant(n,matrix));
// }