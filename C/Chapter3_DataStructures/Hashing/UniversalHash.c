#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DoublyLinkedList.h"
int HashFunc(int key, int m, int p){
    int a = 1 + rand()%(p-1);
    int b = rand()%(p);
    return ((a*key+b) % p) % m;
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
void TableInsert(List* HT, Node* x, int m, int p){
    // printf("%d", HashFunc(x->key, A, m, p));
    Prepend(&HT[HashFunc(x->key, m, p)], x);
}
void TableDelete(List* HT, Node* x, int m, int p){
    Delete(&HT[HashFunc(x->key, m, p)], x);
}
Node* TableSearch(List* HT, int k, int m, int p){
    return Search(HT[HashFunc(k, m, p)], k);
}
int main(){
    srand(time(NULL));
    int m, p;
    scanf("%d %d", &m, &p);
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
        TableInsert(HashTable, x, m, p);
        // printf("I HATE HASHING %d\n", HashTable[].Head->key);
    }
    // TableDelete(HashTable, TableSearch(HashTable, 68, A, m), A, m);
    PrintHT(HashTable, m);
    // printf("%.10lf %d",Fractional(100.0000001), Floor(1002.5));
}