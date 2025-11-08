#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
    int hasTraversed;
}Node;
typedef struct{
    Node* Root;
}Tree;
Node* CreateNode(int x){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->hasTraversed = 0;
    node->data = x;
    return node;
}
typedef struct{
    Node** Q;
    int Size;
    int Head;
    int Tail;
}Queue;
Queue DefineQueue(int Size){
    Queue Q;
    Q.Q = (Node**)calloc(Size, sizeof(Node*));
    Q.Head = 0;
    Q.Tail = 0;
    Q.Size = Size;
    return Q;
}
int isQueueEmpty(Queue Q){
    if(Q.Head==Q.Tail)return 1;
    else return 0;
}
void Enqueue(Queue* Q, Node* x){
    if(Q->Head==Q->Tail+1){
        fprintf(stderr, "OVERFLOW");
        exit(EXIT_FAILURE);
    }
    int prevpos = Q->Tail;
    Q->Tail = (Q->Tail+1)%Q->Size;
    Q->Q[prevpos] = x;
}
Node* Dequeue(Queue* Q){
    if(isQueueEmpty(*Q)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    Node* x = Q->Q[Q->Head];
    Q->Head = (Q->Head+1)%Q->Size;
    return x;
}
Node* Head(Queue Q){
    if(isQueueEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return Q.Q[Q.Head];
}
Node* Tail(Queue Q){
    if(isQueueEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return Q.Q[!Q.Tail?Q.Size-1:Q.Tail-1];
}
void LevelOrder(Tree T){
    Queue Q = DefineQueue(100);
    Enqueue(&Q, T.Root);
    while(!isQueueEmpty(Q)){
        Node* node = Dequeue(&Q);
        if (node!=NULL) printf("%d ",node->data);
        if (node->left!=NULL)Enqueue(&Q, node->left);
        if (node->right!=NULL)Enqueue(&Q, node->right);
    }
}
typedef struct{
    Node** S;
    int Size;
    int top;
}Stack;
Stack DefineStack(int Size){
    Stack S;
    S.S = (Node**)calloc(Size, sizeof(Node*));
    S.top = -1;
    S.Size = Size;
    return S;
}
int isStackEmpty(Stack S){
    if(S.top==-1)return 1;
    else return 0;
}
void Push(Stack* S, Node* x){
    if(S->top==S->Size-1){
        fprintf(stderr, "OVERFLOW");
        exit(EXIT_FAILURE);
    }
    S->top += 1;
    S->S[S->top] = x;
}
Node* Pop(Stack* S){
    if(isStackEmpty(*S)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    S->top -= 1;
    return S->S[S->top+1];
}
Node* Top(Stack S){
    if(isStackEmpty(S)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return S.S[S.top];
}
void StackTraverse(Tree T){
    Stack S = DefineStack(100);
    Push(&S, T.Root);
    while(!isStackEmpty(S)){
        Node* node = Pop(&S);
        if (node!=NULL) printf("%d ",node->data);
        if (node->left!=NULL)Push(&S, node->left);
        if (node->right!=NULL)Push(&S, node->right);
    }
}
void Traverse(Tree T){
    if(T.Root == NULL) return;
    Node* curr = T.Root;
    while(curr->left!=NULL)curr=curr->left;
    while(curr!=NULL){
        printf("%d ", curr->data);
        if(curr->right!=NULL){
            curr=curr->right;
            while(curr->left!=NULL)curr=curr->left;
        }
        else{
            while(curr->parent!=NULL && curr->parent->right == curr){
                curr =curr->parent;
            }
            curr=curr->parent;
        }
    }
}
void PostOrder(Node* Root){
    if(Root->left!=NULL)PostOrder(Root->left);
    if(Root->right!=NULL)PostOrder(Root->right);
    if(Root!=NULL)printf("%d ",Root->data);
}
void PreOrder(Node* Root){
    if(Root!=NULL)printf("%d ",Root->data);
    if(Root->left!=NULL)PreOrder(Root->left);
    if(Root->right!=NULL)PreOrder(Root->right);
}
void InOrder(Node* Root){
    if(Root->left!=NULL)InOrder(Root->left);
    if(Root!=NULL)printf("%d ",Root->data);
    if(Root->right!=NULL)InOrder(Root->right);
}
int main(){
    Tree T = {CreateNode(1)};
    T.Root->right = CreateNode(3);
     T.Root->left = CreateNode(2);
     T.Root->right->parent = T.Root;
     T.Root->left->parent = T.Root;
     T.Root->left->left = CreateNode(4);
     T.Root->left->left->parent = T.Root->left;
     T.Root->right->left = CreateNode(5);
     T.Root->right->left->parent = T.Root->right;
     T.Root->right->right = CreateNode(6);
     T.Root->right->right->parent = T.Root->right;
     T.Root->right->left->left = CreateNode(7);
     T.Root->right->left->left->parent = T.Root->right->left;
     T.Root->right->left->right = CreateNode(8);
     T.Root->right->left->right->parent = T.Root->right->left;
     PreOrder(T.Root); printf("\n");
     InOrder(T.Root); printf("\n");
     PostOrder(T.Root); printf("\n");
     LevelOrder(T); printf("\n");
     StackTraverse(T); printf("\n");
     Traverse(T); printf("\n");
}