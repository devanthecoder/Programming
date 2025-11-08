#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    double value;
    struct node* prev;
    struct node* next;
}Node;
typedef struct{
    Node* Head;
}List;
List CreateList(){
    List L;
    L.Head = NULL;
    return L;
}
Node* CreateNode(int key, double value){
    Node* node = (Node *)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->key = key;
    node->value = value;
    return node;
}
Node* ListSearch(List* L, double value){
    Node* curr = L->Head;
    while(curr!=NULL && curr->value!=value)curr=curr->next;
    return curr;
}
void ListInsert(Node* toInsert, Node* at){
    toInsert->next = at->next;
    at->next = toInsert;
    if(toInsert->next!=NULL) toInsert->next->prev = toInsert;
    toInsert->prev = at;
}
void ListDelete(List* L, Node* toDelete){
    Node* temp = toDelete;
    // else{
        if(toDelete->prev!=NULL)toDelete->prev->next = toDelete->next;
        else L->Head = toDelete->next;
        if(toDelete->next!=NULL)toDelete->next->prev = toDelete->prev;
    // }
    free(temp);
}
void Prepend(List* L, Node* x){
    x->next = L->Head;
    if(L->Head!=NULL) L->Head->prev = x;
    L->Head = x;
}
void PrintList(List L){
    printf("{ ");
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)printf("(%d, %.2lf) ", curr->key, curr->value);
    printf("} ");
}
List* CreateDAT(int n){
    List *DAT = (List *)calloc(n, sizeof(List));
    for(int i=0;i<n;i++)DAT[i] = CreateList();
    return DAT;
}
void Insert(List* DAT, Node* x){
    // printf("AHHHHHHH");
    if(DAT[x->key].Head!=NULL){
        // printf("AHHHHHHH");
        ListInsert(x, DAT[x->key].Head);  
    } 
    else {
        // printf("AHHHHHHH\n");
        Prepend(&DAT[x->key], x);
    }
}
void Delete(List* DAT, Node* x){
    ListDelete(&DAT[x->key], x);
    // DAT[x->key].key = 0;
    // DAT[x.key] = CreateList(n+1, 0);
}
Node* Search(int n, List* DAT, int key, double value){
    // printf("%d %d",DAT[key].key);
    return ListSearch(&DAT[key], value);
}
void PrintDAT(List* DAT, int n){
    printf("[ ");
    for(int i=0;i<n;i++){
        PrintList(DAT[i]);
    }
    printf("]\n");
}
int main(){
    int n;
    scanf("%d", &n);
    List* DAT = CreateDAT(n);
    for(int i=-n+1;i<n;i++){
        // printf("FUCK PROGRAMMING %d\n", i);
        Insert(DAT, CreateNode(abs(i), i));
    }
    Node* x = CreateNode(0, 10);
    Insert(DAT, x);
    Insert(DAT, CreateNode(0, 20));
    PrintDAT(DAT, n);
    Delete(DAT, x);
    PrintDAT(DAT, n);
    // Insert()
}