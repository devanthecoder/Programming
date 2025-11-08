#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node* next;
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
    Node* node = (Node *)calloc(1, sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}
void Append(List* L, Node* toAppend){
    if(!(L->Head)){
        L->Head = toAppend;
        L->Tail = toAppend;
    }
    else{
        L->Tail->next = toAppend;
        L->Tail = toAppend;
    }
}
Node* Delete(List* L, Node* N){
    if(!N)return NULL;
    Node* temp = N;
    // Node* temp2 = N->prev;
    Node* prev = L->Head;
    while(prev->next!=N && prev!=NULL){
        prev = prev->next;
    }
    // if(!prev)return;
    if(prev!=NULL) prev->next = N->next;
    else L->Head = N->next;
    // if(N->next!=NULN->prev;
    // free(temp);
    temp->next = NULL;
    return temp;
}
void ReArrange(List* L){
    Node* Even = L->Head->next;
    while(Even!=NULL && Even->next!=NULL){
        Node* temp = Even;
        Even = Even->next->next;
        Append(L, Delete(L, temp));
    }
}
void PrintList(List L){
    Node* curr;
    for(curr=L.Head;curr->next!=NULL;curr=curr->next)printf("%d ", curr->value);
    printf("%d\n", curr->value);
}
int main(){
    int x;
    scanf("%d", &x);
    List L = DefineList();
    while(x!=-1){
        Node* N = CreateNode(x);
        Append(&L, N);
        scanf("%d", &x);
    }
    // PrintList(L);
    ReArrange(&L);
    PrintList(L);
}