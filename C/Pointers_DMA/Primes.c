#include <stdio.h>
#include <stdlib.h>
int isPrime(int p){
    for(int i=2;i*i<=p;i++){
        if(p%i==0){
            return 0;
        }
    }
    return 1;
}
int* find_primes(int n){
    int *arr = (int *)calloc(n,sizeof(int));
    int p=2,i=0;
    while(i<n){
        if(isPrime(p)){
            *(arr+i)=p;
            i++;
        }
        p++;

    }
    return arr;
}
int main(){
    int n;
    scanf("%d",&n);
    int *primes = find_primes(n);
    for(int i=0;i<n;i++){
        printf("%d ",*(primes+i));
    }
}