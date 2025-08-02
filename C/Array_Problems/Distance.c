#include <stdio.h>
#include <math.h>
int main(){
    int N;
    scanf("%d",&N);
    int x1,x2,y1,y2;
    printf("INPUT:");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    for(int i=1;i<=N-1;i++){
        int tempx=x2,tempy=y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(sqrt(pow(x1-tempx,2)+pow(y1-tempy,2))>=1){
            continue;
        }else{
            dist += sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        }
    }
    printf("%lf",dist);
}