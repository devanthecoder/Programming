#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;
typedef struct{
    Node* Root;
}Tree;
typedef struct{
    Node** Q;
    int Size;
    int Head;
    int Tail;
}Queue;
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
int isEmpty(Stack S){
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
    if(isEmpty(*S)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    S->top -= 1;
    return S->S[S->top+1];
}
Node* Top(Stack S){
    if(isEmpty(S)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return S.S[S.top];
}
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
Node* returnTree(char** Inorder, char** Preorder, int istart, int iend, int pstart, int pend){
    if(istart>iend){
        return NULL;
    }
    if(istart==iend){
        return CreateNode(atoi(Inorder[istart]));
    }
    int Root = atoi(Preorder[pstart]);
    Node* ROOT = CreateNode(Root);
    int RootIndex = istart;
    for(;atoi(Inorder[RootIndex])!=Root;RootIndex++);
    // if (RootIndex > iend) return NULL;
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
    // if(atoi(Preorder[pend1])!=atoi(Inorder[iend1]) || atoi(Preorder[pend2])!=atoi(Inorder[iend2])) return NULL;
    ROOT->left = returnTree(Inorder, Preorder, istart1, iend1, pstart1, pend1);
    ROOT->right = returnTree(Inorder, Preorder, istart2, iend2, pstart2, pend2);
    return ROOT;
}
void TreeArray(Node* Root){
    Queue Q = DefineQueue(100);
    Enqueue(&Q, Root);
    while(!isQueueEmpty(Q)){
        Node* node = Dequeue(&Q);
        if (node!=NULL) {
            printf("%d ",node->data);
            if (node->left!=NULL || (node->left==NULL && node->right!=NULL))Enqueue(&Q, node->left);
            if (node->right!=NULL || (node->right==NULL && node->left!=NULL))Enqueue(&Q, node->right);
        }
        else printf("NULL ");
    }
    printf("\n");
}
int RetrieveArray(char* buffer, char*** TreeArray, int eleSize){
    char arr[125][eleSize];
    char* token= strtok(buffer, " ");
    int i=0;
    while(token!=NULL){
        strcpy(arr[i], token);
        // printf("%s ", token);
        token = strtok(NULL, " ");
        i++;
    }
    int size = i;
    // printf("%d\n", size);
    // char TreeArray[size][eleSize];
    *TreeArray = malloc(size * sizeof(char*));
    for(int i = 0; i < size; i++){
        (*TreeArray)[i] = malloc(eleSize * sizeof(char));  // 4 chars + '\0'
        strcpy((*TreeArray)[i], arr[i]);
    }
    // for(int i=0;i<size;i++)strcpy(TreeArray[i],arr[i]);
    return size;
}
int isValid(char** preorder, Node* root){
    Stack S = DefineStack(100);
    Push(&S, root);
    int i=0;
    int isV=1;
    while(!isEmpty(S)){
        Node* x = Pop(&S);
        if(x!=NULL) {
            if(x->data!=atoi(preorder[i])){
                isV=0; break;
            }
            else{
                i++;
            }
            Push(&S, x->right);
            Push(&S, x->left);
        }
    }
    return isV;
}
int main(){
    int k;
    scanf("%d", &k);
    getchar();
    char I[500], P[500];
    while(k--){
        fgets(I, sizeof(I), stdin);
        I[strcspn(I, "\n")] = '\0';
        fgets(P, sizeof(P), stdin);
        P[strcspn(P, "\n")] = '\0';
        char** inorder;
        int sizeI = RetrieveArray(I, &inorder, 5);
        char** preorder;
        int sizeP = RetrieveArray(P, &preorder, 5);
        Node* Root = returnTree(inorder, preorder, 0, sizeI-1, 0, sizeP-1);
        printf("\n");
        // PostOrder(Root);
        if(!isValid(preorder, Root))printf("ERROR\n");
        else TreeArray(Root);
        printf("\n");
    }
}