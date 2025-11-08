#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int key;
    double value;
}Node;
Node* CreateDAT(int n){
    Node* DAT = (Node *)calloc(n, sizeof(Node));
}
Node CreateNode(int key, double value){
    Node N = {key, value};
    return N;
}
void Insert(Node* DAT, Node x){
    DAT[x.key] = x;
}
void Delete(int n, Node* DAT, Node x){
    DAT[x.key] = CreateNode(n+1, 0);
}
Node Search(int n, Node* DAT, int key){
    return DAT[key];
}
void PrintDAT(Node* DAT, int n){
    printf("[ ");
    for(int i=0;i<n;i++){
        if(DAT[i].key != n+1) printf("{%d, %.2lf} ", DAT[i].key, DAT[i].value);
    }
    printf("]\n");
}
double Max(Node* DAT, int n){
    int i=0;
    while(DAT[i].key==n+1)i++;
    double max = DAT[i].value;
    for(;i<n;i++){
        if(DAT[i].key != n+1 && max < DAT[i].value) max = DAT[i].value;
    }
    return max;
}
int main(){
    int n;
    scanf("%d", &n);
    Node* DAT = CreateDAT(n);
    for(int i=0;i<n;i++){
        Insert(DAT, CreateNode(i, 2*i));
    }
    Delete(n, DAT, Search(n, DAT, 0));
    PrintDAT(DAT, n);
    printf("%.2lf", Max(DAT, n));
}