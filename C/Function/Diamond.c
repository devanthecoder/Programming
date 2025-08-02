#include <stdio.h>
void PrintDiamond(int n){
    int arr[2*n-1][2*n-1];
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            arr[i][j]=0;
            for(int k=1;k<=n;k++){
                if((j==(n-k+1) || j==(n+k-1))&&(i<=2*n-k && i>=k)){
                    arr[i][j]=k;
                    printf("%d", arr[i][j]);
                }
            }
            if(arr[i][j]==0){
                    printf(" ");
                }
        }
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    PrintDiamond(n);
}