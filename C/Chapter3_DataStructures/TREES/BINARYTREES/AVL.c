#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node* left;
    struct node* right;
    struct node* parent;
    int value;
    int height;
}Node;
typedef struct T{
    Node* ROOT;
}AVLTree;
Node* CreateNode(int x){
    Node* N = (Node *)calloc(1, sizeof(Node));
    N->value = x;
    N->left = NULL;
    N->right = NULL;
    N->parent = NULL;
    N->height = 1;
    return N;
}
AVLTree DefineTree(){
    AVLTree T;
    T.ROOT = NULL;
    return T;
}
Node* Minimum(Node* N){
    Node* curr = N;
    while(curr->left!=NULL) curr=curr->left;
    return curr;
}
void UpdateHeight(Node* N){
    int hl = N->left?N->left->height:0;
    int hr = N->right?N->right->height:0;
    N->height = 1 + (hl>hr?hl:hr);
}
int BalanceFactor(Node* N){
    return (N->left?N->left->height:0) - (N->right?N->right->height:0);
}
void LeftRotate(AVLTree* T, Node* x){
    Node* y = x->right;
    Node* temp = y->left;
    y->left = x;
    x->right = temp;
    if(temp!=NULL) temp->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL) T->ROOT = y;
    else if(x->parent->left == x) x->parent->left = y;
    else x->parent->right = y;
    x->parent = y;
    UpdateHeight(x);
    UpdateHeight(y);
}
void RightRotate(AVLTree* T, Node* x){
    Node* y = x->left;
    Node* temp = y->right;
    y->right = x;
    x->left = temp;
    if(temp!=NULL) temp->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL) T->ROOT = y;
    else if(x->parent->left == x) x->parent->left = y;
    else x->parent->right = y;
    x->parent = y;
    UpdateHeight(x);
    UpdateHeight(y);
}
void ROTATION(AVLTree* T, Node* z) {
    if(BalanceFactor(z) > 1){
        if(BalanceFactor(z->left)>=0){
            RightRotate(T, z);
        }
        else{
            LeftRotate(T, z->left);
            RightRotate(T, z);
        }
    }
    else if(BalanceFactor(z) < -1){
        if(BalanceFactor(z->right) <= 0){
            LeftRotate(T, z);
        }
        else{
            RightRotate(T, z->right);
            LeftRotate(T, z);
        }    
    }
    else return;
}
void INSERTION(AVLTree* T, int x){
    Node* N = CreateNode(x);
    Node* N0 = T->ROOT, *y = NULL;
    while(N0!=NULL){
        y = N0;
        N0 = (N0->value > N->value)?N0->left:N0->right;
    }
    // if(!y->height) SteAll(T);
    N->parent = y;
    if(y==NULL) T->ROOT = N;
    else if(N->value<y->value) y->left = N;
    else y->right = N;
    Node* z = N;
    while(z!=NULL){
        UpdateHeight(z);
        ROTATION(T, z);
        z = z->parent;
    }
}
void Transplant(AVLTree *T, Node* u, Node* v){
    if(u->parent==NULL){
        T->ROOT = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else u->parent->right = v;
    if (v!=NULL) v->parent = u->parent;
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
void DELETION(AVLTree* T, int x){
    Node* z = Search(T->ROOT, x);
    if(z==NULL)return;
    Node* ReBalance = NULL;
    if(z->left==NULL) {
        ReBalance = z->parent;
        Transplant(T, z, z->right);
        // while(z!=NULL){
        //     UpdateHeight(z);
        //     ROTATION(T, z);
        //     z = z->parent;
        // }
        // UpdateHeight(z->right->parent);
        free(z);
    }
    else if(z->right==NULL) {
        ReBalance = z->parent;
        Transplant(T, z, z->left);
        // UpdateHeight(z->left->parent);
        free(z);
    }
    else {
        Node* zsucc = Minimum(z->right);
        if(zsucc != z->right){
            ReBalance = zsucc->parent;
            Transplant(T, zsucc, zsucc->right);
            zsucc->right = z->right;
            zsucc->right->parent = zsucc;
            // UpdateHeight(zsucc);
            // UpdateHeight(z->right);
            // ROTATION(T, z->right);
        }
        else{
            ReBalance = zsucc;
        }
        Transplant(T, z, zsucc);
        zsucc->left = z->left;
        zsucc->left->parent = zsucc;
        // UpdateHeight(zsucc->parent);
        free(z);
    }
    while(ReBalance!=NULL){
        UpdateHeight(ReBalance);
        ROTATION(T, ReBalance);
        ReBalance = ReBalance->parent;
    }
}
void Inorder(Node* N){
    if(!N) return;
    Inorder(N->left);
    printf("%d ", N->value);
    Inorder(N->right);
}
int main(){
    // int n;
    // scanf("%d", &n);
    AVLTree T = DefineTree();
    INSERTION(&T, 1);
    INSERTION(&T, 2);
    INSERTION(&T, 3);
    // INSERTION(&T, 4);
    // INSERTION(&T, 5);
    // INSERTION(&T, 6);
    // INSERTION(&T, 7);
    // INSERTION(&T, 8);
    // INSERTION(&T, 9);
    
    // Insert(CreateNode(8), &T.ROOT->right->left, 0);
    printf("%d\n", T.ROOT->value);
    // Postorder(T.ROOT); printf("\n");
    // Preorder(T.ROOT); printf("\n");
    Inorder(T.ROOT); printf("\n");
    DELETION(&T, 1);
    Inorder(T.ROOT); printf("\n");
    // LevelOrderQ(7, T.ROOT); printf("\n");
    // LevelOrderQ(8, T.ROOT); printf("\n");
    // NonRecursePrint(8, T.ROOT); printf("\n");
    // InorderNonRecurse(8, T); printf("\n");
    // printf("%d\n", Search(T.ROOT, 16)->value);
    // printf("%d\n", Minimum(T.ROOT)->value);
    // printf("%d\n", Maximum(T.ROOT)->value);
    // printf("%d\n", RecurseMin(T.ROOT)->value);
    // printf("%d\n", RecurseMax(T.ROOT)->value);
    // printf("%d\n", Successor(T.ROOT)->value);
    // printf("%d\n", Predecessor(T.ROOT)->value);
    // DeleteBST(&T, Search(T.ROOT, 1));
    // LevelOrderQ(7, T.ROOT); printf("\n");
    // int* A = (int *)calloc(7, sizeof(int));
    // int A[9] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    // LevelOrderQ(9, GetTree(A, 0, 8)); printf("\n");
    // printf("%d\n", isLevelOrder(A, 0, 7));
}