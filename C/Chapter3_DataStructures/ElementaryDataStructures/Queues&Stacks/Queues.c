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
int isEmpty(Queue S){
    if(S.Head==S.Tail)return 1;
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
    if(isEmpty(*Q)){
        fprintf(stderr, "UNDERFLOW");
        exit(EXIT_FAILURE);
    }
    double x = Q->Q[Q->Head];
    Q->Head = (Q->Head+1)%Q->Size;
    return x;
}
double Head(Queue Q){
    if(isEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return Q.Q[Q.Head];
}
double Tail(Queue Q){
    if(isEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR");
        exit(EXIT_FAILURE);
    }
    return Q.Q[!Q.Tail?Q.Size-1:Q.Tail-1];
}