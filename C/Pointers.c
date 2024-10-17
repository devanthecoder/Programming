#include <stdio.h>
void merger(int n, int m, int arr1[n],int arr2[m],int merge[n+m]){
    for(int i=0;i<n;i++){
        merge[i]=arr1[i];
    }
    for(int i=0;i<m;i++){
        merge[n+i]=arr2[i];
    }
}
void sort(int n, int arr[n]){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]<arr[j]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
    int merge[n+m];
    merger(n,m,arr1,arr2,merge);
    sort(n+m,merge);
    for(int i=0;i<n+m;i++){
        printf("%d ",merge[i]);
    }
}