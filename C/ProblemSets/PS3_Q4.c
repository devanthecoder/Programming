#include <stdio.h>
#include <stdlib.h>
// #include <time.h>
typedef struct node{
    struct node* next;
    struct node* prev;
    int data;
}Node;
typedef struct{
    Node* Head;
    Node* Tail;
}List;
typedef struct{
    List* L;
}HT;
HT DefineTable(int Size){
    HT Hashtable;
    Hashtable.L = (List *)calloc(Size, sizeof(List));
    return Hashtable;
}
Node* CreateNode(int key){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = key;
    return node;
}
void Prepend(List* L, int x){
    Node* N = CreateNode(x);
    if(!L->Head){
        L->Head = N;
        L->Tail = N;
    }
    else{
        N->next = L->Head;
        L->Head->prev = N;
        L->Head = N;
    }
}
Node* Search(List L, int x){
    Node* Curr = L.Head;
    while(Curr!=NULL && Curr->data!=x)Curr=Curr->next;
    return Curr;
}
void Delete(List* L, int x){
    Node* N = Search(*L, x);
    if(!N) return;
    Node* temp = N;
    if(N->prev!=NULL)N->prev->next = N->next;
    if(N->next!=NULL)N->next->prev = N->prev;
    free(temp);
}
// int RANDOM(int a, int b){
//     return a + rand()%(b-a+1);
// }
int Hash(int key, int m){
    // int a = RANDOM(1, p-1);
    // int b = RANDOM(0, p-1);
    return key%m;
}
void InsertHT(HT* ht, int key, int m){
    Prepend(&(ht->L[Hash(key, m)]), key);
}
void DeleteHT(HT* ht, int key, int m){
    Delete(&(ht->L[Hash(key, m)]), key);
}
Node* SearchHT(HT ht, int key, int m){
    return Search(ht.L[Hash(key, m)], key);
}
void PrintList(List L){
    for(Node* Curr=L.Head; Curr!=NULL;Curr=Curr->next){
        printf("%d ", Curr->data);
    }
}
void PrintHT(HT ht, int m){
    printf("[ ");
    for(int i=0;i<m;i++){
        printf("%d: { ", i);
        PrintList(ht.L[i]);
        printf("}, ");
    }
    printf("]\n");
}
int main(){
    // srand(time(NULL));
    int m;
    scanf("%d", &m);
    HT ht = DefineTable(m);
    int n;
    scanf("%d", &n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        InsertHT(&ht, x, m);
    }
    PrintHT(ht, m);
}