int main(void) {
//     int T;
//     scanf("%d", &T);
    
//     int sizearr[T];
//     double** records = (double **)calloc(T,sizeof(double *)); // allocate memory as per your requirement
    
//     for(int i=0;i<T;i++){
//         double input;
//         double *arr=NULL;
//         int size=0;
//         while(1){
//             if(scanf("%lf",&input)==1){
//                 arr=(double *)realloc(arr,(size+1)*(sizeof(double)));
//                 *(arr+size)=input;
//                 size++;
//             }
//             char c=getchar();
//             if(c=='\n')break;
//         }
//         *(records+i)=arr;
//         *(sizearr+i)=size;
        
//     }
//     for(int i=0;i<T;i++){
//         printf("[ ");
//         for(int j=0;j<*(sizearr+i);j++){
//             printf("%lf ",*(*(records +i )+j));
//         }
//         printf("]\n");
//     }
    
    
//     // printf("%lf", TestStatistic(T, flag, medians));
    
//     return 0;
// }