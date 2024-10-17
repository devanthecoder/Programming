#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[2*n-1][2*n-1];
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            arr[i][j]=0;
            for(int k=1;k<=n;k++){
                if((i<=(2*n-k-1)&&i>=(k-1))&&(j==n-k||j==n+k-2)){
                    arr[i][j]=k;
                    printf("%d",k);
                }
            }
            if(arr[i][j]==0)printf(" ");

        }
        printf("\n");
    }
}