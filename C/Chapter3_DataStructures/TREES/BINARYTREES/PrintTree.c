#include <stdio.h>
#include <stdlib.h>
#define ENQUEUENULL(N, Q) if (N!=NULL) Enqueue(&Q, N)
typedef struct node{
    struct node* left;
    struct node* right;
    struct node* parent;
    int value;
}Node;
typedef struct T{
    Node* ROOT;
}Tree;
Node* CreateNode(int x){
    Node* N = (Node *)calloc(1, sizeof(Node));
    N->value = x;
    N->left = NULL;
    N->right = NULL;
}
Tree DefineTree(){
    Tree T;
    T.ROOT = NULL;
    return T;
}
void Insert(Node* x, Node** y, int isLeft){
    // printf("%d ", x->value);
    // printf("%d", *y==NULL);
    if(*y==NULL){
        // printf("%d ", x->value);
        *y = x;
        return;
    }
    else{
        if(isLeft){
            (*y)->left = x;
            // printf("%d ", x->value);
        }
        else {
            (*y)->right = x;
            // printf("%d ", x->value);
        }
        x->parent = *y;
    }
}
void Postorder(Node* N){
    if(!N) return;
    Postorder(N->left);
    Postorder(N->right);
    printf("%d ", N->value);
}
void Preorder(Node* N){
    if(!N) return;
    printf("%d ", N->value);
    Preorder(N->left);
    Preorder(N->right);
}
void Inorder(Node* N){
    if(!N) return;
    Inorder(N->left);
    printf("%d ", N->value);
    Inorder(N->right);
}
int height(Node* N){
    if(!N) return 0;
    int LH = height(N->left);
    int RH = height(N->right);
    return LH>RH?LH:RH + 1;
}
void PrintLevel(Node* ROOT, int Level){
    if(!ROOT)return;
    if(Level == 1)printf("%d ", ROOT->value);
    PrintLevel(ROOT->left, Level-1);
    PrintLevel(ROOT->right, Level-1);
}
void LevelOrder(Node* ROOT){
    int H = height(ROOT);
    for(int i=1;i<=H+1;i++){
        PrintLevel(ROOT, i);
    }
}

typedef struct{
    int Size;
    int top;
    Node** S;
} Stack;

Stack InitializeStack(int Size) {
    Stack SS;
    SS.top = -1;
    SS.Size = Size;
    SS.S = (Node **)calloc(Size, sizeof(Node*));
    return SS;
}

void Push(Stack* S, Node* x) {
    if (S->top == S->Size - 1) {
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE); // Optional: to stop the program
    } else {
        S->top += 1;
        S->S[S->top] = x;
    }
}

int isEmpty(Stack* S) {
    return S->top == -1;
}

Node* Pop(Stack* S) {
    if (isEmpty(S)) {
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    } else {
        S->top -= 1;
        return S->S[S->top + 1];
    }
}

Node* Top(Stack* S) {
    if (isEmpty(S)) {
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    } else {
        return S->S[S->top];
    }
}

typedef struct{
    int Size;
    int head, tail;
    Node** Q;
}Queue;
Queue InitializeQueue(int Size){
    Queue QQ;
    QQ.head = 0;
    QQ.tail = 0;
    QQ.Size = Size;
    QQ.Q = (Node**)calloc(Size, sizeof(Node*));
    return QQ;
}
int IsEmpty(Queue* Q){
        if(Q->head==Q->tail)return 1;
        else return 0;
}
void Enqueue(Queue* Q, Node* x){
    if(Q->head==(Q->tail+1)%Q->Size){
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else Q->Q[Q->tail] = x;
    Q->tail=(Q->tail+1)%Q->Size;
}
Node* Dequeue(Queue* Q){
    if (IsEmpty(Q)){
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else {
        Node* x = Q->Q[Q->head];
        Q->head=(Q->head+1)%Q->Size;
        return x;
    }
}
Node* Head(Queue* Q){
    if (IsEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    }
    else return Q->Q[Q->head];
}
Node* Tail(Queue* Q){
    if (IsEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    }
    else return Q->Q[Q->tail-1];
}

void LevelOrderQ(int n, Node* N){
    Queue Q = InitializeQueue(n);
    ENQUEUENULL(N, Q);
    else return;
    while(!IsEmpty(&Q)){
        Node* x = Dequeue(&Q);
        printf("%d ", x->value);
        ENQUEUENULL((x->left), Q);
        ENQUEUENULL((x->right), Q);
        // if(x->left!=NULL)Enqueue(&Q, x->left);
        // if(x->right!=NULL)Enqueue(&Q, x->right);
    }
}
void NonRecursePrint(int n, Node* ROOT){
    Stack S = InitializeStack(n);
    Node* curr = ROOT;
    while(curr!=NULL){
        printf("%d ", curr->value);
        // Push(&S, curr->right);
        if(curr->right!=NULL) Push(&S, curr->right);
            // printf("I'M NOT NULL");
        curr = curr->left;
    }
    while(!isEmpty(&S)){
        Node* curr = Pop(&S);
        while(curr!=NULL){
            printf("%d ", curr->value);
            if(curr->right!=NULL)Push(&S, curr->right);
            curr = curr->left;
        }
    }
}
void treeWalk(Node* root) {
    if (root == NULL) return;

    Node* prev = NULL;
    Node* curr = root;
    Node* next;

    while (curr != NULL) {
        if (prev == curr->parent) {
            // Came down from parent (or starting at root)
            printf("%d ", curr->value);

            if (curr->left != NULL) {
                next = curr->left;
            } else if (curr->right != NULL) {
                next = curr->right;
            } else {
                next = curr->parent;
            }
        }
        else if (prev == curr->left) {
            // Came up from left child
            if (curr->right != NULL) {
                next = curr->right;
            } else {
                next = curr->parent;
            }
        }
        else {
            // Came up from right child
            next = curr->parent;
        }

        prev = curr;
        curr = next;
    }
}
int main(){
    // Tree T = DefineTree();
    Tree T = DefineTree();
    Insert(CreateNode(10), &T.ROOT, 0);
    Insert(CreateNode(4), &T.ROOT, 1);
    Insert(CreateNode(17), &T.ROOT, 0);
    Insert(CreateNode(1), &T.ROOT->left, 1);
    Insert(CreateNode(5), &T.ROOT->left, 0);
    Insert(CreateNode(16), &T.ROOT->right, 1);
    Insert(CreateNode(21), &T.ROOT->right, 0);
    printf("%d\n", height(T.ROOT));
    Postorder(T.ROOT); printf("\n");
    Preorder(T.ROOT); printf("\n");
    Inorder(T.ROOT); printf("\n");
    LevelOrder(T.ROOT); printf("\n");
    LevelOrderQ(8, T.ROOT); printf("\n");
    NonRecursePrint(8, T.ROOT); printf("\n");
    treeWalk(T.ROOT); printf("\n");
}