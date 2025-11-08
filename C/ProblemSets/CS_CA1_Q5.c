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
    Node* node = (Node*)calloc(1, sizeof(Node));
    // node->prev = NULL;
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
    if(at->next==NULL)L->Tail = toInsert;;
    // else 
    at->next = toInsert;
    // toInsert->prev = at;
}
void Delete(List* L, Node* N){
    if(!N)return;
    Node* temp = N;
    if(N==L->Head){
        L->Head = L->Head->next;
    }
    else{
        Node* prev = L->Head;
        while(prev->next!=N && prev!=NULL){
            prev = prev->next;
        }
        if(prev!=NULL) prev->next = N->next;
    }
    free(temp);

}
void Prepend(List* L, Node* N){
    if(L->Head==NULL) {
        L->Head = N;
        L->Tail = N;
    }
    else{
        N->next = L->Head;
        // L->Head->prev = N;
        L->Head = N;
    }
}
typedef struct{
    List S;
    int Size;
    int CurSize;
}Stack;
Stack DefineStack(int Size){
    Stack S;
    S.S = DefineList();
    S.CurSize = 0;
    S.Size = Size;
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
}
int Pop(Stack* S){
    if(isEmpty(*S)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    S->CurSize--;
    int x = S->S.Head->value;
    Delete(&(S->S), S->S.Head);
    return x;
}
int Top(Stack S){
    if(isEmpty(S)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return S.S.Head->value;
}

void SortStack(Stack* S){
    if(S->CurSize==1)return;
    int x = Pop(S);
    SortStack(S);
    Stack Dummy = DefineStack(S->CurSize);
    while(!isEmpty(*S) && x<Top(*S)){
        Push(&Dummy, Pop(S));
    }
    Push(S, x);
    while(!isEmpty(Dummy)){
        Push(S, Pop(&Dummy));
    }
}
void PrintStack(Stack S){
    Stack Dummy = DefineStack(S.CurSize);
    while(!isEmpty(S)){
        int x = Pop(&S);
        printf(isEmpty(S)?"%d\n":"%d ", x);
        Push(&Dummy, x);
    }
    // int x = Pop(&S);
    // printf("%d\n", x);
    // Push(&Dummy, x);
    while(!isEmpty(Dummy)){
    // for(int i=0;i<S.CurSize;i++){
        int x = Pop(&Dummy);
        // printf("%d ", x);
        Push(&S, x);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    Stack S = DefineStack(n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        Push(&S, x);
    }
    // PrintStack(S);
    SortStack(&S);
    PrintStack(S);
}