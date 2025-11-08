#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
}Node;
typedef struct{
    Node* Head;
    Node* Tail;
}List;
List DefineList(){
    List L;
    L.Head = NULL;
    L.Tail = NULL;
    return L;
}
Node* CreateNode(int value){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->value = value;
    return node;
}
Node* Search(List L, int value){
    Node* curr = L.Head;
    while(curr!=NULL && curr->value!=value)curr=curr->next;
    return curr;
}
void Insert(List* L, Node* toInsert, Node* at){
    toInsert->next = at->next;
    if(at->next!=NULL)at->next->prev = toInsert;
    else L->Tail = toInsert;
    at->next = toInsert;
    toInsert->prev = at;
}
Node* Delete(List* L, Node* N){
    if(!N)return NULL;
    Node* temp = N;
    // Node* temp2 = N->prev;
    if(N->prev!=NULL) N->prev->next = N->next;
    else L->Head = N->next;
    if(N->next!=NULL) N->next->prev = N->prev;
    else L->Tail = N->prev;
    // free(temp);
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void Prepend(List* L, Node* N){
    if(L->Head==NULL) {
        L->Head = N;
        L->Tail = N;
    }
    else{
        N->next = L->Head;
        L->Head->prev = N;
        L->Head = N;
    }
}
void PrintList(List L){
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)printf("%d", curr->value);
    printf("\n");
}
void InsertionSort(List* L, int n){
    for(int size=1;size<n;size++){
        Node* toInsert = L->Head;
        for(int i=0;i<size;i++)toInsert=toInsert->next;
        Node* Insprev = toInsert->prev;
        Node* Ins = Delete(L, toInsert);
        while(Insprev!=NULL && Ins->value<Insprev->value){
            Insprev=Insprev->prev;
        }
        if(Insprev==NULL)Prepend(L, Ins);
        else Insert(L, Ins, Insprev);
    }
}
int main(){
    List L = DefineList();
    int n;
    scanf("%d", &n);
    // Stack S = DefineStack(n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        if(!L.Head)Prepend(&L, CreateNode(x));
        else Insert(&L, CreateNode(x), L.Tail);
    }
    // PrintStack(S);
    InsertionSort(&L, n);
    // printf("%d", L.Head->value);
    PrintList(L);
}