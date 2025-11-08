#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;
typedef struct{
    Node* Root;
}Tree;
Node* CreateNode(int x){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = x;
    return node;
}
void Insert(Node* Root, int key, int isLeft){
    Node* node = CreateNode(key);
    if(isLeft) Root->left = node;
    else Root->right = node;
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
Node* returnTree(int* Inorder, int* Preorder, int istart, int iend, int pstart, int pend){
    if(istart>iend){
        return NULL;
    }
    if(istart==iend){
        return CreateNode(Inorder[istart]);
    }
    int Root = Preorder[pstart];
    Node* ROOT = CreateNode(Root);
    int RootIndex = istart;
    for(;Inorder[RootIndex]!=Root;RootIndex++);
    // if(RootIndex==iend+1){
    //     fprintf(stderr, "ERROR");
    //     return NULL;
    // }
    int istart1 = istart;
    int iend1 = RootIndex-1;
    int istart2 = RootIndex+1;
    int iend2 = iend;
    int pstart1 = pstart+1;
    int pend1 = iend1+pstart-istart+1;
    int pstart2 = pend1+1;
    int pend2 = pend;
    ROOT->left = returnTree(Inorder, Preorder, istart1, iend1, pstart1, pend1);
    ROOT->right = returnTree(Inorder, Preorder, istart2, iend2, pstart2, pend2);
    return ROOT;
}
int main(){
    int k;
    scanf("%d", &k);
    while(k--){
        int n;
        scanf("%d", &n);
        int* P = (int*)calloc(n, sizeof(int));
        int* I = (int*)calloc(n, sizeof(int));
        for(int i=0;i<n;i++)scanf("%d", &I[i]);
        for(int i=0;i<n;i++)scanf("%d", &P[i]);
        Tree T = {returnTree(I, P, 0, n-1, 0, n-1)};printf("\n");
        PreOrder(T.Root);printf("\n");
        PostOrder(T.Root);printf("\n");
        InOrder(T.Root);printf("\n");
    }
}