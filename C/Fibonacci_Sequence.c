#include <stdio.h>
int fibonacci(unsigned int n){
    if (n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
int main(){
    int n;
    scanf("%u",&n);
    printf("Number %d is in position %d of the Fibonacci sequence.",fibonacci(n),n);
}