#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    double value;
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
Node* CreateNode(double value){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->value = value;
    return node;
}
Node* Search(List L, double value){
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
void Delete(List* L, Node* N){
    if(!N)return;
    Node* temp = N;
    // Node* temp2 = N->prev;
    if(N->prev!=NULL) N->prev->next = N->next;
    else L->Head = N->next;
    if(N->next!=NULL) N->next->prev = N->prev;
    else L->Tail = N->prev;
    free(temp);
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
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)printf("%.2lf->", curr->value);
    printf("NULL\n");
}
int main(){
    List L = DefineList();
    Prepend(&L, CreateNode(1.99));
    Prepend(&L, CreateNode(9.92));
    Prepend(&L, CreateNode(1.78));
    Insert(&L, CreateNode(1.2), L.Head);
    PrintList(L);
    Delete(&L, Search(L, 1.99));
    PrintList(L);
}