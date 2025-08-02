#include <stdio.h>
#include <math.h>
int main(){
    long long int n;
    int k;
    scanf("%lld %d",&n,&k);
    long long int temp = n;
    int digits = 0;
    int t = 0;
    while(temp!=0){
        temp/=10;
        digits ++;
    }
    temp = n;
    int curlen = 1;
    while(curlen<=digits){
        long long int div = pow(10,curlen);
        while(temp!=0){
            if(temp/(div/10)>0){
                long long int subarray = temp%div;
                long long int digsum = 0;
                printf("%d\n", subarray);
                while(subarray!=0){
                    digsum+=subarray%10;
                    subarray/=10;
                    }
                if(digsum<=k){
                    t++;
                }
                temp/=10;
            }
            else{
                break;
            }
        }
        curlen++;
        temp = n;
    }
    long long int tworec = 1;
    int x = 0;
    while(tworec<=pow(2,t)){
        tworec = pow(2,tworec);
        x++;
    }
    printf("%d",t+x);
}