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
    Node* curr;
    for(curr=L.Head;curr->next!=NULL;curr=curr->next)printf("%.2lf ", curr->value);
    printf("%.2lf\n", curr->value);
}
void Reverse(List* L){
    Node* Curr = L->Head;
    while(Curr!=NULL){
        Node* temp = Curr->next;
        Curr->next = Curr->prev;
        Curr->prev = temp;
        Curr = temp;
    }
    Node* temp = L->Head;
    L->Head = L->Tail;
    L->Tail = temp;
}
int main(){
    int n;
    scanf("%d", &n);
    List L = DefineList();
    double x;
    for(int i=0;i<n;i++){
        scanf("%lf", &x);
        if(!L.Head)Prepend(&L, CreateNode(x));
        else Insert(&L, CreateNode(x), L.Tail);
    }
    PrintList(L);
    Reverse(&L);
    PrintList(L);
    Delete(&L, Search(L, 5));
    PrintList(L);
}