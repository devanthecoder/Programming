#include <stdio.h>
#include <stdlib.h>

double min(double first, double second) {
    return ((first < second) ? first : second);
}
double median(int N, double *arr){
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(*(arr+i)<*(arr+j)){
                double temp=*(arr+i);
                *(arr+i)=*(arr+j);
                *(arr+j)=temp;
            }
        }
    }
    return N%2==0?(*(arr+(N/2)-1)+*(arr+(N/2)))/2:*(arr+((N+1)/2)-1);
}
    
double SequenceStatistic(int N, double *arr) {
    double *transarr = arr;
    for(int i=0;i<N;i++){
        *(transarr+i)=(i+1)*(*(arr+i));
    }
    return median(N,transarr);
}

double TestStatistic(int N, int flag, double *median) {
    double answer = 0.0;
    if(flag) {
        answer = *median;
        for(int i=1;i<N;i++){
            double answer = min(answer,*(median+i));
        }
        return answer;
    } else {
        for(int i=0;i<N;i++){
            answer+=*(median+i);
        }
        return answer/N;
        
    }
}

int main(void) {
    
    int T,flag;
    scanf("%d %d", &T,&flag);
    double** records = (double**)calloc(T, sizeof(double*));
    int size[T];
    double median[T];
    for(int i=0;i<T;i++){
        double *arr=NULL;
        int j=0;
        double input;
        while(1){
            if(scanf("%lf",&input)==1){
                arr = (double*)realloc(arr,(j+1)*sizeof(double));
                *(arr+j)=input;
                j++;
            }
            char c;
            scanf("%c",&c);
            if(c=='\n'){
                break;
            }
        }
        *(records+i)=arr;
        *(size+i)=j;
        *(median+i)=SequenceStatistic(*(size+i),*(records+i));
    }
    for(int i=0;i<T;i++){
        printf("[");
        for(int j=0;j<*(size+i);j++){
            printf("%lf ",*((records+i)+j));
        }
        printf("]\n");
    }
    // for(int i=0;i<T;i++){
    //     *(median+i)=SequenceStatistic(*(size+i),*(records+i));
    // }
    printf("%lf", TestStatistic(T, flag, median));
    
    return 0;
}