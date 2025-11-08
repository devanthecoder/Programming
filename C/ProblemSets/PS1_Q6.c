#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char value;
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
Node* CreateNode(char value){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->value = value;
    return node;
}
Node* Search(List L, char value){
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
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)printf("%c->", curr->value);
    printf("NULL\n");
}

typedef struct{
    char* S;
    int Size;
    int top;
}Stack;
Stack DefineStack(int Size){
    Stack S;
    S.S = (char*)calloc(Size, sizeof(char));
    S.top = -1;
    S.Size = Size;
    return S;
}
int isEmpty(Stack S){
    if(S.top==-1)return 1;
    else return 0;
}
void Push(Stack* S, char x){
    if(S->top==S->Size-1){
        fprintf(stderr, "OVERFLOW");
        exit(EXIT_FAILURE);
    }
    S->top += 1;
    S->S[S->top] = x;
}
char Pop(Stack* S){
    if(isEmpty(*S)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    S->top -= 1;
    return S->S[S->top+1];
}
char Top(Stack S){
    if(isEmpty(S)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return S.S[S.top];
}
int isPalin(List L){
    int isP = 1;
    Node* left = L.Head, *right = L.Tail;
    while(1){
        if(left == NULL) break;
        else if(left->value==right->value){
            if(right->value=='c') break;
            left = left->next;
            right = right->prev;
        }
        else{
            isP = 0;
            break;
        }
    }
    return isP;
}
int isPalinStack(List L){
    int isP = 1;
    Node* curr = L.Head;
    Stack S = DefineStack(100);
    while(curr->value != 'c'){
        Push(&S, curr->value);
        curr = curr->next;
    }
    curr = curr->next;
    if((curr!=NULL && isEmpty(S)) || (curr==NULL && !isEmpty(S))) isP = 0;
    else{
        while(curr!=NULL){
            if(isEmpty(S) || curr->value!=Top(S)){
                isP = 0;
                break;
            }
            else{
                if(isEmpty(S)){
                    isP = 0;
                    break;
                }
                else Pop(&S);
                curr=curr->next;
            }
        }
    }
    if(!isEmpty(S)) isP = 0;
    return isP;
}
int main(){
    char c = getchar();
    List L = DefineList();
    while(c != '\n'){
        if(!L.Head) Prepend(&L, CreateNode(c));
        else Insert(&L, CreateNode(c), L.Tail);
        c = getchar();
    }
    PrintList(L);
    printf(isPalin(L)?"String is a palindrome\n":"String is not a palindrome\n");
    printf(isPalinStack(L)?"String is a palindrome\n":"String is not a palindrome\n");
}