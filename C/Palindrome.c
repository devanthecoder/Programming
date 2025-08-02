#include <stdio.h>
#include <math.h>
int main(){
    int start, end, max_pal=0;
    scanf("%d %d",&start,&end);
    for(int i=start;start<=end;start++;j++){
            if(start%j==0){
                printf("Number is not prime.");
                break;
            }){
        for(int j=2;j<=(start+1)/2){
            if(j==(start+1)/2){
                int digits=0,temp=start;
                while(temp!=0){
                    digits+=1;
                    temp/=10;
                }
                temp=start;
                for(int l = 1;l<=(start+1)/2;l++){
                    if(temp%10!=temp/(int)pow(10,digits-l)){
                        printf("Number is not a prime palindrome.");
                        break;
                    }
                    temp%=(int)pow(10,digits-l);
                    temp/=10;
                    digits--;
                    if(temp==0){
                        if(max_pal<=start){
                        max_pal = start;
                
                        }
                    }
                }
            }    
        }
    }
    printf("Greatest prime palindrome is %d.",max_pal);
}