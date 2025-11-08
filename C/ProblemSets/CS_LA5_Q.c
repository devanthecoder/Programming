#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    // struct node* parent;
}Node;
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
typedef struct{
    Node* Root;
}BST;
void PrintLevel(int k, Node* Root){
    if(Root==NULL)return;
    if(k==0) printf("%d ", Root->data);
    else{
        PrintLevel(k-1, Root->left);
        PrintLevel(k-1, Root->right);
    }
}
int Height(Node* T){
    if(T==NULL) return 0;
    else{
        return 1 + (Height(T->left)>Height(T->right)?Height(T->left):Height(T->right));
    }
}
void LevelOrder(BST T){
    int h = Height(T.Root);
    for(int i=0;i<h;i++){
        PrintLevel(i, T.Root);
        printf("\n");
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
    if(Search(*T, key)){
        printf("Element is already present inside Tree, so no need to insert.\n");
        return;
    }
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
    LevelOrder(*T);
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
    
    if(!Search(T, key)) printf("ERROR\n");
    else {
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
    }
}
void Delete(BST* T, int key){
    if(!Search(*T, key)) printf("ERROR\n");
    else{
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
    }
    LevelOrder(*T);
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
    BST T = DefineTree();
    Insert(&T, 12);
    Insert(&T, 31);
    Insert(&T, 34);
    Insert(&T, 56);
    // Insert(&T, 6);
    Insert(&T, 78);
    Insert(&T, 89);
    Insert(&T, 91);
    Insert(&T, 32);
    Insert(&T, 56);
    Insert(&T, 81);
    Insert(&T, 100);
    Insert(&T, 2);
    Insert(&T, 55);
    Insert(&T, 21);
    Insert(&T, 99);
    Insert(&T, 121);
    Insert(&T, 67);
    printf("%d\n", Height(T.Root));
    // PrintLevel(4, T.Root);
    // PostOrder(T.Root);printf("\n");
    // PreOrder(T.Root);printf("\n");
    // InOrder(T.Root);printf("\n");
    // printf("%d", Successor(T, Search(T, 100))->data);
    // // LevelOrder(T);
    if(Search(T, 32)) printf("Element with key 32 is present in list.\n");
    else printf("ERROR\n");
    if(Search(T, 56)) printf("Element with key 56 is present in list.\n");
    else printf("ERROR\n");
    if(Search(T, 90)) printf("Element with key 90 is present in list.\n");
    else printf("ERROR\n");
    Insert(&T, 32);
    Insert(&T, 56);
    Insert(&T, 21);
    Insert(&T, 90);
    printf("%d\n",Successor(T, 32)->data);
    printf("%d\n",Successor(T, 56)->data);
    printf("%d\n",Successor(T, 21)->data);
    printf("%d\n",Successor(T, 90)->data);
    Delete(&T, 332);
    Delete(&T, 51);
    Delete(&T, 71);
    Delete(&T, 67);
    // else printf("Element with key 32 is present in list.\n");
    // if(!Search(T, 56)) printf("Element is not present in list.\n");
    // else printf("Element with key 32 is present in list.\n");
    // if(!Search(T, 90)) printf("Element is not present in list.\n");
    // else printf("Element with key 32 is present in list.\n");
}