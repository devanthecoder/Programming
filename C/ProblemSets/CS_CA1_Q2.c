#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct node{
    struct node* np;
    int key;
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
Node* XOR(Node* a, Node* b){
    return (Node *)((uintptr_t)a^(uintptr_t)b);
}
Node* CreateNode(int x){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->key = x;
    node->np = NULL;
    return node;
}
Node* SEARCH(List L, int x){
    Node* prev = NULL, *curr = L.Head;
    while(curr!=NULL && curr->key!=x){
        Node* next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    return curr;
}
void Prepend(List* L, Node* N){
    if(!L->Head){
        L->Head = N;
        L->Tail = N;
    }
    else{
        N->np = L->Head;
        L->Head->np = XOR(L->Head->np, N);
        L->Head = N;
    }
}
void Insert(List* L, Node* toInsert, Node* at){
    Node* prev = NULL, *curr = L->Head;
    while(curr!=NULL && curr!=at){
        Node* next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    if(curr==NULL) return;
    else{
        Node* next = XOR(prev, curr->np);
        if(next!=NULL) {
            curr->np = XOR(prev, toInsert);
            toInsert->np = XOR(curr, next);
            Node* nextnext = XOR(curr, next->np);
            next->np = XOR(toInsert, nextnext);
        }
        else{
            toInsert->np = L->Tail;
            L->Tail->np = XOR(L->Tail->np, toInsert);
            L->Tail = toInsert;
        }
    }
}
void Delete(List* L, Node* toDelete){
    Node* prev = NULL, *curr = L->Head;
    while(curr!=NULL && curr!=toDelete){
        Node* next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    if(curr==NULL) return;
    else{
        Node* temp = curr;
        Node* next = XOR(prev, curr->np);
        if(prev!=NULL){
            Node* prevprev = XOR(prev->np, curr);
            prev->np = XOR(prevprev, next);
        }
        else{
            L->Head = L->Head->np;
        }
        // curr->np = XOR(prev, toInsert);
        // toInsert->np = XOR(curr, next);
        if(next!=NULL) {
            Node* nextnext = XOR(curr, next->np);
            next->np = XOR(prev, nextnext);
        }
        else{
            L->Tail = L->Tail->np;
        }
        free(temp);
    }
}
void PrintList(List L){
    Node* prev = NULL, *curr = L.Head;
    while(curr!=NULL){
        printf("%d->", curr->key);
        Node* next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    printf("NULL\n");
}
void Reverse(List* L){
    Node* temp = L->Head;
    L->Head = L->Tail;
    L->Tail = temp;    
}
int main(){
    List L = DefineList();
    int k;
    scanf("%d", &k);
    int n;
    while(k--){
        scanf("%d", &n);
        if(n==1){
            int x;
            scanf("%d", &x);
            if(SEARCH(L, x)) printf("Element is present\n");
            else printf("Element is not present\n");
        }
        else if(n==2){
            int x;
            scanf("%d", &x);
            Prepend(&L, CreateNode(x));
            PrintList(L);
        }
        else if(n==3){
            int x;
            scanf("%d", &x);
            if(SEARCH(L, x)) {
                Delete(&L, SEARCH(L, x));
                PrintList(L);
            }
            else printf("Element is not present\n");
            // Prepend(&L, CreateNode(x));
        }
        else if(n==4){
            Reverse(&L);
            PrintList(L);
        }
    }
    // printf("%d\n", L.Tail->key);
}