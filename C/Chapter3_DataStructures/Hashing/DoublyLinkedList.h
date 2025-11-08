#ifndef DLL 
#define DLL
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
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
Node* CreateNode(int key){
    Node* node = (Node *)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->key = key;
    return node;
}
Node* Search(List L, int key){
    Node* curr = L.Head;
    while(curr!=NULL && curr->key!=key)curr=curr->next;
    return curr;
}
void Insert(Node* toInsert, Node* at){
    toInsert->next = at->next;
    at->next = toInsert;
    if(toInsert->next!=NULL) toInsert->next->prev = toInsert;
    toInsert->prev = at;
}
void Delete(List* L, Node* toDelete){
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
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)printf("%d ", curr->key);
    printf("} ");
}
#endif