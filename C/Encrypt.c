#include <stdio.h>
#include <math.h>
int main(){
    long unsigned int N;
    int K;
    scanf("%lu %d",&N,&K);
    long unsigned int temp=N;
    int num_block=0;
    while(temp!=0){
        temp = temp/(long int)pow(10,K);
        num_block++;
    }
    printf("%d\n",num_block);
    for(int i=num_block;i>0;i--){
        long int block = N/(long int)pow(10,K*(i-1));
        printf("%d\n",block);
        block = block+block%10;
        block%=(long int)pow(10,K);
    }
}
//     }
// for(int j=K;j>=1;j--){
//             if((block<pow(10,j))&&(block>=pow(10,j-1))){
//                 for(int k=0;k<=j;k++){
//                     printf("0");
//                 }
//                 printf("%d",block);
//             }