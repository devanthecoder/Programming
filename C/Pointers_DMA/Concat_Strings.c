#include <stdio.h>
#include <stdlib.h>
int strlength(char *str){
    int size=0;
    while(*(str+size)!=0)size++;
    return size;
}
char *concat_strings(char **strs, int count){
    char *constr=NULL;
    int totalsize=0;
    for(int i=0;i<count;i++){
        int size=strlength(*(strs+i));
        constr = (char *)realloc(constr,totalsize+size);
        for(int j=0;j<size;j++){
            *(constr+totalsize+j)=*(*(strs+i)+j);
        }
        totalsize+=size;
    }
    *(constr+totalsize)='\0';
    return constr;
}
int main(){
    int count;
    scanf("%d",&count);
    getchar();
    char **strs = (char **)calloc(count,sizeof(char*));
    for(int i=0;i<count;i++){
        int j=0;
        *(strs+i)=NULL;
        while(1){
            char c;
            c=getchar();
            if (c==' '){
                break;
            }
            *(strs+i)=(char *)realloc(*(strs+i),j+1);
            *(*(strs+i)+j)=c;
            j++;
        }
        *(*(strs+i)+j)='\0';
    }
    char *totalstr = concat_strings(strs,count);
    printf("%s",totalstr);
}