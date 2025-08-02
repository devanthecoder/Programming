#include <stdio.h>
#include <math.h>
int main(){
    unsigned int num;
    printf("Enter number:\n");
    scanf("%u",&num);
    for(unsigned int i =2;i<=num/2;i++){
        if(num%i==0){
            printf("The number %d is not prime, as it is divisble by %d.\n",num,i);
            break;
        }

    }
    printf("Number is prime.");
}