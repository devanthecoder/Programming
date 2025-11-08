#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    // struct node* parent;
}Node;
typedef struct{
    Node* Root;
}BST;
void PrintLevel(int k, Node* Root, int no_spaces){
    if(Root==NULL) {
        for(int j=0;j<2*no_spaces;j++)printf(" ");
        // if(!Root) printf("  ");
        // for(int j=0;j<no_spaces;j++)printf(" ");
        return;
    }
    if(k==0) {
        for(int j=0;j<no_spaces;j++)printf(" ");
        // if(!Root) printf("  ");
        printf("%d", Root->data);
        for(int j=0;j<no_spaces;j++)printf(" ");
    }
    else{
        PrintLevel(k-1, Root->left, no_spaces);
        PrintLevel(k-1, Root->right, no_spaces);
    }
}
int Height(Node* T){
    if(T==NULL) return 0;
    else{
        return 1 + (Height(T->left)>Height(T->right)?Height(T->left):Height(T->right));
    }
}
void LevelOrderPict(BST T){
    int h = Height(T.Root);
    for(int i=0;i<h;i++){
        int no_spaces = (1 << (h-i+1));
        // for(int j=0;j<no_spaces;j++)printf(" ");
        PrintLevel(i, T.Root, no_spaces);
        // for(int j=0;j<no_spaces;j++)printf(" ");
        printf("\n\n");
    }
}
Node* CreateNode(int x){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = x;
    return node;
}
BST DefineTree(){
    BST T;
    T.Root = NULL;
    return T;
}
Node* Search(BST T, int key){
    Node* curr = T.Root;
    while(curr!=NULL){
        if(key<curr->data) curr=curr->left;
        else if(key>curr->data) curr=curr->right;
        else return curr;
    }
    // if(!curr) printf("ERROR\n");
    return curr;
}
void Insert(BST* T, int key){
    // if(Search(*T, key)){
    //     printf("Element is already present inside Tree, so no need to insert.\n");
    //     return;
    // }
    Node* curr = T->Root;
    Node* N = CreateNode(key);
    // if(curr==NULL) T->Root = N;
    Node* prev = NULL;
    while(curr!=NULL){
        prev = curr;
        if(key<curr->data) curr=curr->left;
        else curr=curr->right;
        // else return curr;
    }
    if(prev==NULL) T->Root = N;
    else if(prev->data<key){
        prev->right = N;
    }
    else prev->left = N;
    // N->parent = prev;
    // return curr;
    // LevelOrder(*T);
}
Node* Maximum(Node* Root){
    Node* Max = Root;
    while(Max->right!=NULL)Max= Max -> right;
    return Max;
}
Node* Minimum(Node* Root){
    Node* Min = Root;
    while(Min->left!=NULL)Min= Min -> left;
    return Min;
}
void Transplant(BST* T, Node* u, Node* v){
    Node* prev = NULL;
    Node* curr = T->Root;
    // Node* prev = NULL;
    while(curr!=u){
        prev = curr;
        if(u->data<curr->data) curr=curr->left;
        else curr=curr->right;
        // else return curr;
    }
    if(prev==NULL) T->Root = v;
    // if(u->parent == NULL) T->Root = v;
    else if(u == prev->right) prev->right = v;
    else prev->left = v;
    // if(v!=NULL)v->parent = u->parent;
}
Node* Successor(BST T, int key){
    
    // if(!Search(T, key)) printf("ERROR\n");
    // else {
        Node* u = Search(T, key);
        if(u->right!=NULL) return Minimum(u->right);
        else{
            Node* Succ = NULL;
            Node* Curr = T.Root;
            while(Curr!=u){
                if(u->data<Curr->data) {
                    Succ = Curr;
                    Curr=Curr->left;
                }
                else Curr=Curr->right;
            }
            return Succ;
        }
    // }
}
void Delete(BST* T, int key){
    // if(!Search(*T, key)) printf("ERROR\n");
    // else{
        Node* toDel = Search(*T, key);
        if(toDel->right == NULL){
            Transplant(T, toDel, toDel->left);
        }
        else if(toDel->left==NULL){
            Transplant(T, toDel, toDel->right);
        }
        else{
            Node* Succ = Minimum(toDel->right);
            if(Succ!=toDel->right){
                Transplant(T, Succ, Succ->right);
                Succ->right = toDel->right;
                // Succ->right->parent = Succ;
            }
            Transplant(T, toDel, Succ);
            Succ->left = toDel->left;
            // Succ->left->parent = Succ;
        }
    // }
    // LevelOrder(*T);
}
Node* returnBST(int* Preorder, int start, int end){
    if(start>end) return NULL;
    if(start==end) return CreateNode(Preorder[start]);
    // BST T = DefineTree();
    Node* Root = CreateNode(Preorder[start]);
    int lstart = start+1;
    int lend=start+1;
    while(lend<=end && Preorder[lend]<Preorder[start])lend++;
    lend--;
    int rstart = lend+1;
    int rend = end;
    // printf("%d %d %d %d\n",lstart,lend,rstart,rend);
    Root->left = returnBST(Preorder, lstart, lend);
    Root->right = returnBST(Preorder, rstart, rend);
    return Root;
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
void LevelOrderLin(BST T){
    Queue Q = DefineQueue(100);
    Enqueue(&Q, T.Root);
    while(!isQueueEmpty(Q)){
        Node* node = Dequeue(&Q);
        if (node!=NULL) printf("%d ",node->data);
        if (node->left!=NULL)Enqueue(&Q, node->left);
        if (node->right!=NULL)Enqueue(&Q, node->right);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);
    int* Preorder = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)scanf("%d", &Preorder[i]);
    BST T = DefineTree();
    T.Root = returnBST(Preorder, 0, n-1);
    LevelOrderLin(T);
    LevelOrderPict(T);
    // PrintLevel(3, T.Root, 5);
    // printf("%d", Height(T.Root));
}