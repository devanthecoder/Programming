#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include "DoublyLinkedList.h"
double Fractional(double x){
    return x-(int)(x);
}
int Floor(double x){
    return (int)x;
}
int HashFunc(int key, int m){
    return key % m;
}
void PrintHT(List* HT, int n){
    printf("[ ");
    for(int i=0;i<n;i++){
        if(HT[i].Head){
            printf("( %d, ", i);
            PrintList(HT[i]);
            printf(") ", i);
        }
        else continue;
    }
    printf("]\n");
}
void TableInsert(List* HT, Node* x, int m){
    // printf("%d", HashFunc(x->key, A, m));
    Prepend(&HT[HashFunc(x->key, m)], x);
}
void TableDelete(List* HT, Node* x, int m){
    Delete(&HT[HashFunc(x->key, m)], x);
}
Node* TableSearch(List* HT, int k, int m){
    return Search(HT[HashFunc(k, m)], k);
}
int main(){
    int m;
    scanf("%d", &m);
    List HashTable[m];
    int n;
    scanf("%d", &n);
    for(int i=0;i<m;i++){
        HashTable[i] = CreateList();
    }
    int ele;
    for(int i=0;i<n;i++){
        scanf("%d", &ele);
        Node* x = CreateNode(ele);
        // printf("I HATE HASHING %d\n", HashFunc(ele, A, m));
        TableInsert(HashTable, x, m);
        // printf("I HATE HASHING %d\n", HashTable[].Head->key);
    }
    // TableDelete(HashTable, TableSearch(HashTable, 68, A, m), A, m);
    PrintHT(HashTable, m);
    // printf("%.10lf %d",Fractional(100.0000001), Floor(1002.5));
}