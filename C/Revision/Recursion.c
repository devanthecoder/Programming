#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int n, int* arr, int s, int t, int x){
    int middle = (s+t)/2;
    if(arr[middle]<x)BinarySearch(n, arr, middle, t, x);
    else if(arr[middle]>x)BinarySearch(n, arr, s, middle, x);
    else if(arr[middle]==x)return middle;
    else return -1;
}
int floorofroot(int n){
    int *arr;
    int i=0;
    while(i*i<=n){
        arr = (int *)realloc(arr, sizeof(int)*(i+1));
        arr[i]=i*i;
        i++;
    }
    return i;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",floorofroot(n));
}