#include <stdio.h>
void StringReverse(char string[20]){
    int i=0;
    while(string[i]!='\0')i++;
    for(int j=0;j<i/2;j++){
        char temp=string[j];
        string[j]=string[i-j-1];
        string[i-j-1]=temp;
    }
}
int sumarr(int n, int* arr){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    char s[20];
    scanf("%s",s);
    printf("%s\n",s);
    StringReverse(s);
    printf("%s\n",s);
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    printf("%d",sumarr(n,arr));
}