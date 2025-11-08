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
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)printf("%c", curr->value);
    printf("\n");
}
typedef struct{
    List S;
    int Size;
    int CurSize;
    Node* Middle;
}Stack;
Stack DefineStack(int Size){
    Stack S;
    S.S = DefineList();
    S.CurSize = 0;
    S.Size = Size;
    Node* Middle = NULL;
    return S;
}
int isEmpty(Stack S){
    if(S.CurSize==0)return 1;
    else return 0;
}
void Push(Stack* S, int x){
    if(S->CurSize==S->Size){
        fprintf(stderr, "OVERFLOW");
        exit(EXIT_FAILURE);
    }
    S->CurSize++;
    Prepend(&(S->S), CreateNode(x));
    if(S->CurSize==1) S->Middle = S->S.Head;
    else if(S->CurSize%2==1) S->Middle=S->Middle->prev;
    // printf("%d\n", S->Middle->value);
}
int Pop(Stack* S){
    if(isEmpty(*S)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    S->CurSize--;
    int x = S->S.Head->value;
    Delete(&(S->S), S->S.Head);
    if(S->CurSize==0) S->Middle = NULL;
    else if(S->CurSize%2==0) {
        S->Middle=S->Middle->next;
        // printf("%d\n", S->Middle->value);
    }
    return x;
}
int Top(Stack S){
    if(isEmpty(S)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return S.S.Head->value;
}
int findMiddle(Stack S){
    return S.Middle->value;
}
int deleteMiddle(Stack *S){
    S->CurSize--;
    int x = S->Middle->value;
    Node* next = S->Middle->next;
    Node* prev = S->Middle->prev;
    Delete(&(S->S), S->Middle);
    if(S->CurSize==0) S->Middle = NULL;
    else if(S->CurSize%2==0) S->Middle=next;
    else S->Middle = prev;
    // printf("%d\n", next->value);
    return x;
}
int main(){
    Stack S = DefineStack(100);
    int k;
    scanf("%d", &k);
    int n;
    while(k--){
        scanf("%d", &n);
        if(n==1){
            int x;
            scanf("%d", &x);
            Push(&S, x);
        }
        else if(n==2){
            if(isEmpty(S)){
                printf("Stack Underflow\n");
            }
            else{
                printf("%d\n", Pop(&S));
            }
        }
        else if(n==3){
            if(isEmpty(S)){
                printf("Stack Empty\n");
            }
            else{
                printf("%d\n", findMiddle(S));
            }
        }
        else if(n==4){
            if(isEmpty(S)){
                printf("Stack Empty\n");
            }
            else{
                printf("%d\n", deleteMiddle(&S));
            }
        }
    }
    // printf("%d\n", L.Tail->key);
}
