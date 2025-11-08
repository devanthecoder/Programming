#include <stdlib.h>
#include <stdio.h>
typedef struct{
    double* Q;
    int Size;
    int Head;
    int Tail;
}Queue;
Queue DefineQueue(int Size){
    Queue Q;
    Q.Q = (double*)calloc(Size, sizeof(double));
    Q.Head = 0;
    Q.Tail = 0;
    Q.Size = Size;
    return Q;
}
int isQueueEmpty(Queue Q){
    if(Q.Head==Q.Tail)return 1;
    else return 0;
}
void Enqueue(Queue* Q, double x){
    if(Q->Head==Q->Tail+1){
        fprintf(stderr, "OVERFLOW");
        exit(EXIT_FAILURE);
    }
    int prevpos = Q->Tail;
    Q->Tail = (Q->Tail+1)%Q->Size;
    Q->Q[prevpos] = x;
}
double Dequeue(Queue* Q){
    if(isQueueEmpty(*Q)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    double x = Q->Q[Q->Head];
    Q->Head = (Q->Head+1)%Q->Size;
    return x;
}
double Head(Queue Q){
    if(isQueueEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return Q.Q[Q.Head];
}
double Tail(Queue Q){
    if(isQueueEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return Q.Q[!Q.Tail?Q.Size-1:Q.Tail-1];
}

typedef struct{
    double* S;
    int Size;
    int top;
}Stack;
Stack DefineStack(int Size){
    Stack S;
    S.S = (double*)calloc(Size, sizeof(double));
    S.top = -1;
    S.Size = Size;
    return S;
}
int isStackEmpty(Stack S){
    if(S.top==-1)return 1;
    else return 0;
}
void Push(Stack* S, double x){
    if(S->top==S->Size-1){
        fprintf(stderr, "OVERFLOW");
        exit(EXIT_FAILURE);
    }
    S->top += 1;
    S->S[S->top] = x;
}
double Pop(Stack* S){
    if(isStackEmpty(*S)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    S->top -= 1;
    return S->S[S->top+1];
}
double Top(Stack S){
    if(isStackEmpty(S)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return S.S[S.top];
}

void ReverseK(Queue* Q, int k, int n){
    Stack S = DefineStack(k+1);
    for(int i=0;i<k;i++){
        double x = Dequeue(Q);
        Push(&S, x);
    }
    for(int i=0;i<k;i++){
        double x = Pop(&S);
        Enqueue(Q, x);
    }
    for(int i=0;i<n-k;i++){
        double x = Dequeue(Q);
        // double x = Pop(&S);
        Enqueue(Q, x);
    }
}
void PrintQueue(Queue Q, int n){
    Queue Dummy = DefineQueue(n);
    while(!isQueueEmpty(Q)){
        double x = Dequeue(&Q);
        printf("%lf ", x);
        Enqueue(&Dummy, x);
    }
    printf("\n");
    while(!isQueueEmpty(Dummy)){
        double x = Dequeue(&Dummy);
        // printf("%lf ", x);
        Enqueue(&Q, x);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    Queue Q = DefineQueue(n+1);
    for(int i=0;i<n;i++){
        double x;
        scanf("%lf", &x);
        Enqueue(&Q, x);
    }
    int k;
    scanf("%d", &k);
    PrintQueue(Q, n);
    ReverseK(&Q, k, n);
    PrintQueue(Q, n);
}