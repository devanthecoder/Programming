#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int max_num = ((a>b)?a:b)>c?((a>b)?a:b):c;
    printf("%d",max_num);
}