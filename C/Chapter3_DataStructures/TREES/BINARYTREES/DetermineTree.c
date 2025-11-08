#include <stdio.h>
#include <stdlib.h>
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
// void Preorder(Node* N){
//     if(!N) return;
//     printf("%d ", N->value);
//     Preorder(N->left);
//     Preorder(N->right);
// }
// void Inorder(Node* N){
//     if(!N) return;
//     Inorder(N->left);
//     printf("%d ", N->value);
//     Inorder(N->right);
// }
int LinearSearch(int start, int end, int* arr, int x){
    // int index=-1;
    for(int i=start;i<=end;i++){
        if(x==arr[i]){
            return i;
        }
    }
    return -1;
}
Node* GiveTree(int* Inorder, int* Preorder, int starti, int endi, int startp, int endp){
    if(starti==endi+1){
        return NULL;
    }
    if(startp==endp+1){
        return NULL;
    }
    int Root = Preorder[startp];
    int RootIndex = LinearSearch(starti, endi, Inorder, Root);
    Node* node = CreateNode(Root);
    // printf("%d", node->value);
    node->left = GiveTree(Inorder, Preorder, starti, RootIndex-1, startp+1, startp + RootIndex - starti);
    node->right = GiveTree(Inorder, Preorder, RootIndex+1, endi, startp + RootIndex - starti+1, endp);
    return node;
}
int main(){
    int n;
    scanf("%d", &n);
    int* Inorder = (int *)calloc(n, sizeof(int)), *Preorder = (int *)calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", &Preorder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &Inorder[i]);
    }
    Node* ROOT = GiveTree(Inorder, Preorder, 0, n-1, 0, n-1);
    // printf("%d\n", ROOT->value);
    Postorder(ROOT);
}