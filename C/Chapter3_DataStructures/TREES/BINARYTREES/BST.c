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
    N->parent = NULL;
    return N;
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
void InorderNonRecurse(int n, Tree T){
    Stack S = InitializeStack(n);
    Node* curr = T.ROOT;
    while(curr!=NULL || !isEmpty(&S)){
        while(curr!=NULL){
            Push(&S, curr);
            curr=curr->left;
        }
        curr = Pop(&S);
        printf("%d ", curr->value);
        curr=curr->right;
    }
}
Node* Search(Node* N, int x){
    if(N==NULL || N->value == x)return N;
    if(N->value>x){
        // printf("To the left\n");
        Search(N->left, x);
    }
    else {
        // printf("To the right %d\n", N->right->value);
        Search(N->right, x);
    }
}
Node* Minimum(Node* N){
    Node* curr = N;
    while(curr->left!=NULL) curr=curr->left;
    return curr;
}
Node* Maximum(Node* N){
    Node* curr = N;
    while(curr->right!=NULL) curr=curr->right;
    return curr;
}
Node* RecurseMin(Node* N){
    if(N->left!=NULL) return RecurseMin(N->left);
    else return N;
}
Node* RecurseMax(Node* N){
    if(N->right!=NULL) return RecurseMax(N->right);
    else return N;
}
Node* Successor(Node* N){
    if(N->right!=NULL) return Minimum(N->right);
    else{
        Node* x = N;
        Node* y = x->parent;
        while(x == y->right && y!=NULL){
            x = y;
            y = y->parent;
        }
        return y;
    }
}
Node* Predecessor(Node* N){
    if(N->left!=NULL) return Maximum(N->left);
    else{
        Node* x = N;
        Node* y = x->parent;
        while(y!=NULL && x == y->left){
            x = y;
            y = y->parent;
        }return y;
    }
}
void InsertBST(Tree* T, int x){
    Node* N = CreateNode(x);
    Node* N0 = T->ROOT, *y = NULL;
    while(N0!=NULL){
        y = N0;
        N0 = (N0->value > N->value)?N0->left:N0->right;
    }
    N->parent = y;
    if(y==NULL) T->ROOT = N;
    else if(N->value<y->value) y->left = N;
    else y->right = N;
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
void Transplant(Tree *T, Node* u, Node* v){
    if(u->parent==NULL){
        T->ROOT = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else u->parent->right = v;
    if (v!=NULL) v->parent = u->parent;
}
void DeleteBST(Tree* T, Node* z){
    if(z==NULL)return;
    if(z->left==NULL) {
        Transplant(T, z, z->right);
        free(z);
    }
    else if(z->right==NULL) {
        Transplant(T, z, z->left);
        free(z);
    }
    else {
        Node* zsucc = Minimum(z->right);
        if(zsucc != z->right){
            Transplant(T, zsucc, zsucc->right);
            zsucc->right = z->right;
            zsucc->right->parent = zsucc;
        }
        Transplant(T, z, zsucc);
        zsucc->left = z->left;
        zsucc->left->parent = zsucc;
        free(z);

    }
}
Node* GetTree(int* Preorder, int start, int end){
    if(end+1==start)return NULL;
    Node* Root = CreateNode(Preorder[start]);
    int startr=start+1;
    while(Preorder[startr]<Preorder[start]) startr++;
    Root->left = GetTree(Preorder, start+1, startr-1);
    Root->right = GetTree(Preorder, startr, end);
    return Root;
}
//     return 
// }
int main(){
    // int n;
    // scanf("%d", &n);
    Tree T = DefineTree();
    InsertBST(&T, 10);
    InsertBST(&T, 4);
    InsertBST(&T, 17);
    InsertBST(&T, 1);
    InsertBST(&T, 5);
    InsertBST(&T, 16);
    InsertBST(&T, 21);
    // Insert(CreateNode(8), &T.ROOT->right->left, 0);
    // printf("%d\n", height(T.ROOT));
    // Postorder(T.ROOT); printf("\n");
    // Preorder(T.ROOT); printf("\n");
    // Inorder(T.ROOT); printf("\n");
    LevelOrderQ(7, T.ROOT); printf("\n");
    // LevelOrderQ(8, T.ROOT); printf("\n");
    // NonRecursePrint(8, T.ROOT); printf("\n");
    // InorderNonRecurse(8, T); printf("\n");
    printf("%d\n", Search(T.ROOT, 16)->value);
    printf("%d\n", Minimum(T.ROOT)->value);
    printf("%d\n", Maximum(T.ROOT)->value);
    printf("%d\n", RecurseMin(T.ROOT)->value);
    printf("%d\n", RecurseMax(T.ROOT)->value);
    printf("%d\n", Successor(T.ROOT)->value);
    printf("%d\n", Predecessor(T.ROOT)->value);
    DeleteBST(&T, Search(T.ROOT, 1));
    LevelOrderQ(7, T.ROOT); printf("\n");
    // int* A = (int *)calloc(7, sizeof(int));
    int A[9] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    LevelOrderQ(9, GetTree(A, 0, 8)); printf("\n");
    // printf("%d\n", isLevelOrder(A, 0, 7));

}