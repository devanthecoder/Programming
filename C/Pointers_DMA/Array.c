#include <stdio.h>
#include <stdlib.h>
int **create_2d_array(int rows, int cols){
    int **arr=(int**)calloc(rows,sizeof(int*));
    for(int i=0;i<rows;i++){
        *(arr+i)=(int*)realloc(*(arr+i),cols*sizeof(int));
        for(int j=0;j<cols;j++){
            *(*(arr+i)+j)=i*j;
        }
    }
    return arr;
}
int main(){
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    int **arr = create_2d_array(rows,cols);
    for(int i=0;i<rows;i++){
        printf("[ ");
        for(int j=0;j<cols;j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("]\n");
    }
}