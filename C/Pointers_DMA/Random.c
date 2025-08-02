#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int *arr=(int *)calloc(10,sizeof(int));
    for(int i=0;i<10;i++){
        *(arr+i)=rand();
        printf("%d ",*(arr+i));
    }
    printf("\nWant to add more elements?[y/n]");
    char c=getchar();
    if(c=='y'){
        printf("How many elements do you want to add?");
        int extra;
        scanf("%d",&extra);
        arr=(int *)realloc(arr,(10+extra)*sizeof(int));
        for(int i=10;i<10+extra;i++){
            *(arr+i)=rand();
        }
        for(int i=0;i<10+extra;i++){
            printf("%d ",*(arr+i));
        }
    }
    else printf("Okay");
}