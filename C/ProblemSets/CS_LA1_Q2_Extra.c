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
    Queue Q1;
    Queue Q2;
}Stack;
Stack DefineStack(int Size){
    Stack S = {DefineQueue(Size), DefineQueue(Size)};
    return S;
}
int isStackEmpty(Stack S){
    if(isQueueEmpty(S.Q1) && isQueueEmpty(S.Q2)) return 1;
    else return 0;
}
void Push(Stack* S, double x){
    Enqueue(&(S->Q1), x);
}
double Pop(Stack* S){
    double x;
    while(!isQueueEmpty(S->Q1)){
        x = Dequeue(&(S->Q1));
        if(!isQueueEmpty(S->Q1)) Enqueue(&(S->Q2), x);
        // else break;
    }
    Queue temp = S->Q1;
    S->Q1 = S->Q2;
    S->Q2 = temp;
    return x;
}
double Top(Stack S){
    return Tail(S.Q1);
}
int main(){
    int n;
    Stack S = DefineStack(100);
    while(1){
        scanf("%d", &n);
        if(n==1){
            double x;
            scanf("%lf", &x);
            Push(&S, x);
        }
        else if(n==2){
            if(isStackEmpty(S)) printf("Stack is Empty\n");
            else{
                double x = Pop(&S);
                printf("Popped: %.0lf\n", x);
            }
        }
        else if(n==3){
            printf("Exiting program...");
            break;
        }
    }
}