#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;
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
void LevelOrderLin(Node* Root){
    Queue Q = DefineQueue(100);
    Enqueue(&Q, Root);
    while(!isQueueEmpty(Q)){
        Node* node = Dequeue(&Q);
        if (node!=NULL) printf("%d ",node->data);
        if (node->left!=NULL)Enqueue(&Q, node->left);
        if (node->right!=NULL)Enqueue(&Q, node->right);
    }
    printf("\n");
}
Node* CreateNode(int x){
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = x;
    return node;
}
int RetrieveTree(char* buffer, char*** TreeArray){
    char arr[125][5];
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
    // char TreeArray[size][5];
    *TreeArray = malloc(size * sizeof(char*));
    for(int i = 0; i < size; i++){
        (*TreeArray)[i] = malloc(5 * sizeof(char));  // 4 chars + '\0'
        strcpy((*TreeArray)[i], arr[i]);
    }
    // for(int i=0;i<size;i++)strcpy(TreeArray[i],arr[i]);
    return size;
}
Node* returnTree(char** TreeArr, int start, int end){
    if(start>end) return NULL;
    if(!strcmp(TreeArr[start], "NULL")) return NULL;
    Node* Root = CreateNode(atoi(TreeArr[start]));
    Root->left = returnTree(TreeArr, 2*start+1, end);
    Root->right = returnTree(TreeArr, 2*start+2, end);
    return Root;
}
void Preorder(Node* Root){
    Stack S = DefineStack(100);
    Push(&S, Root);
    while(!isEmpty(S)){
        Node* x = Pop(&S);
        if(x!=NULL) {
            printf("%d ", x->data);
            Push(&S, x->right);
            Push(&S, x->left);
        }
    }
}
void Postorder(Node* Root, int size){
    Stack S = DefineStack(100);
    Push(&S, Root);
    int* arr = (int *)calloc(size, sizeof(int));
    int i=0;
    while(!isEmpty(S)){
        Node* x = Pop(&S);
        if(x!=NULL) {
            arr[i] = x->data;
            i++;
            Push(&S, x->left);
            Push(&S, x->right);
        }
    }
    for(int j=i-1;j>-1;j--) printf("%d ", arr[j]);
}
void Inorder(Node* Root){
    Stack S = DefineStack(100);
    Node* Curr = Root;
    while(Curr!=NULL || !isEmpty(S)){
        while(Curr!=NULL){
            Push(&S, Curr);
            Curr=Curr->left;
        }
        Curr = Pop(&S);
        printf("%d ", Curr->data);
        Curr=Curr->right;
    }
}
int main(){
    int k;
    scanf("%d", &k);
    getchar();
    char s[500];
    while(k--){
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';
        char** TreeArray;
        int size = RetrieveTree(s, &TreeArray);
        // printf("IT WORKED: %d %s", size, TreeArray[0]);
        Node* Root = returnTree(TreeArray, 0, size-1);
        // LevelOrderLin(Root);
        printf("\n");
        Inorder(Root);printf("\n");
        Preorder(Root);printf("\n");
        Postorder(Root, size);printf("\n");
    }
}