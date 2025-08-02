#include <stdio.h>
int median(int N, int arr[N]){
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return N%2==0?(arr[(N/2)-1]+arr[N/2])/2:arr[N/2];
}
int main(){
    int N;
    scanf("%d",&N);
    double arr[N];
    for(int I=0;I<N;I++){
    scanf("%d",&arr[I]);
    }
    printf("%d\n",median(N,arr));
    for(int I=0;I<N;I++){
    printf("%d ",arr[I]);
    }
}