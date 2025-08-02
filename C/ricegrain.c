#include <stdio.h>
int main(){
    long unsigned int R;
    scanf("%lu",&R);
    long long int temp=R;
    long unsigned int sum=0;
    long unsigned int div =1;
    for(int i=0;i<49;i++){
        if(temp/div==0){
            printf("NO\n%d\n",i);
            break;
        }
        temp-=div;
        div*=2;
    }
    div=1;
    for(int i=0;i<49;i++){
        sum+=div;
        div*=2;
    }
    if(R>=sum){
        printf("YES\n%lu",temp);
    }
}