#include <stdlib.h>
#include <stdio.h>
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
typedef struct{
    Stack S1;
    Stack S2;
}Queue;
Queue DefineQueue(int Size){
    Queue Q = {DefineStack(Size), DefineStack(Size)};
    return Q;
}
int isQueueEmpty(Queue Q){
    if(isStackEmpty(Q.S1) && isStackEmpty(Q.S2))return 1;
    else return 0;
}
void Enqueue(Queue* Q, double x){
    // double x;
    while(!isStackEmpty(Q->S1)){
        Push(&(Q->S2), Pop(&(Q->S1)));
    }
    Push(&(Q->S1), x);
    while(!isStackEmpty(Q->S2)){
        Push(&(Q->S1), Pop(&(Q->S2)));
    }
}
double Dequeue(Queue* Q){
    return Pop(&(Q->S1));
}
double Head(Queue Q){
    return Top(Q.S1);
}
double Tail(Queue Q){
    double x;
    while(!isStackEmpty(Q.S1)){
        x = Pop(&(Q.S1));
        Push(&(Q.S2), x);
    }
    while(!isStackEmpty(Q.S2)){
        Push(&(Q.S1), Pop(&(Q.S2)));
    }
    return x;
}
int main(){
    int n;
    Queue Q = DefineQueue(100);
    while(1){
        scanf("%d", &n);
        if(n==1){
            double x;
            scanf("%lf", &x);
            Enqueue(&Q, x);
        }
        else if(n==2){
            if(isQueueEmpty(Q)) printf("Queue is Empty\n");
            else{
                double x = Dequeue(&Q);
                printf("Dequeued: %.0lf\n", x);
            }
        }
        else if(n==3){
            printf("Exiting program...");
            break;
        }
    }
}