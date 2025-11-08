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
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)printf("%c -> ", curr->value);
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

int Power(int x1, int x2){
    int result = 1;
    // printf("%d\n", x2);
    for(int i=0;i<x2;i++) result*=x1;
    return result;
}
int Strlen(List L){
    int len=0;
    for(Node* curr=L.Head;curr!=NULL;curr=curr->next)len++;
    return len;
}
int Preference(char c){
    int pref;
    switch(c){
        case '+':
        case '-':
        pref = 1;
        break;
        case '*':
        case '/':
        pref = 2;
        break;
        case '^':
        pref = 3;
        break;
        case '(':
        case ')':
        pref = -1;
        break;
        default:
        pref = 0;
        break;
    }
    return pref;
}
List toPostfix(List infix){
    int len = Strlen(infix)+1;
    List PF = DefineList();
    Stack S = DefineStack(len);
    Node* InCurr = infix.Head;
    // Node* PostCurr = PF.Head;
    while(InCurr!=NULL){
        if(!Preference(InCurr->value)){
            // printf("%c\n", InCurr->value);
            Node* node = CreateNode(InCurr->value);
            InCurr=InCurr->next;
            if(!PF.Head)Prepend(&PF, node);
            else Insert(&PF, node, PF.Tail);
        }
        else if(InCurr->value==')'){
            // printf("%c\n", InCurr->value);
            // printf("HELLO\n");
            while(Top(S)!='('){
                Node* node = CreateNode(Pop(&S));
                if(!PF.Head)Prepend(&PF, node);
                else Insert(&PF, node, PF.Tail);
            }
            Pop(&S);
            InCurr=InCurr->next;
        }
        else{
            if(InCurr->value=='(' || isEmpty(S) || Top(S)=='(' || Preference(InCurr->value)>Preference(Top(S))){
                Push(&S, InCurr->value);
                InCurr = InCurr->next;
            }
            else{
                while(!isEmpty(S) && Top(S)!='('){
                    // char c = Pop(&S);
                    Node* node = CreateNode(Pop(&S));
                    if(!PF.Head)Prepend(&PF, node);
                    else Insert(&PF, node, PF.Tail);
                    // PF[j] = c;
                    // j++;
                }
                // if(Top(S))
            }
        }
    }
    while(!isEmpty(S) && Top(S)!='('){
        Node* node = CreateNode(Pop(&S));
        if(!PF.Head)Prepend(&PF, node);
        else Insert(&PF, node, PF.Tail);
    }
    // PF[j] = '\0';
    return PF;
}
int Evaluate(List Postfix){
    Stack S = DefineStack(Strlen(Postfix));
    Node* PostCurr = Postfix.Head;
    while(PostCurr!=NULL){
        if(!Preference(PostCurr->value)){
            Push(&S, PostCurr->value);
        }
        else{
            int x1 = Pop(&S) - '0';
            int x2 = Pop(&S) - '0';
            int res;
            switch(PostCurr->value){
                case '+':
                res = x1+x2;
                break;
                case '-':
                res = x2-x1;
                break;
                case '*':
                res = x1*x2;
                break;
                case '/':
                res = x2/x1;
                break;
                case '^':
                res = Power(x2, x1);
                break;
            }
            char r = res + '0';
            Push(&S, r);
        }
        PostCurr=PostCurr->next;
    }
    return Top(S)-'0';
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
    List PostFix = toPostfix(L);
    printf("The postfix expression is given by the Linked List: ");
    PrintList(PostFix);
    printf("And the result is: %d\n", Evaluate(PostFix));
}