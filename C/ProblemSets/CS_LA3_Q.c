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
     T.Root->left->left = CreateNode(4);
     T.Root->right->left = CreateNode(5);
     T.Root->right->right = CreateNode(6);
     T.Root->right->left->left = CreateNode(7);
     T.Root->right->left->right = CreateNode(8);
     PreOrder(T.Root); printf("\n");
     InOrder(T.Root); printf("\n");
     PostOrder(T.Root); printf("\n");
    //  LevelOrder(T); printf("\n");
}