#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Size;
    int head, tail;
    double* Q;
}Queue;
Queue InitializeQueue(int Size, double* Q){
    Queue QQ;
    QQ.head = 0;
    QQ.tail = 0;
    QQ.Size = Size;
    QQ.Q = Q;
    return QQ;
}
int isEmpty(Queue* Q){
        if(Q->head==Q->tail)return 1;
        else return 0;
}
void Enqueue(Queue* Q, double x){
    if(Q->head==(Q->tail+1)%Q->Size){
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else Q->Q[Q->tail] = x;
    Q->tail=(Q->tail+1)%Q->Size;
}
double Dequeue(Queue* Q){
    if (isEmpty(Q)){
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else {
        double x = Q->Q[Q->head];
        Q->head=(Q->head+1)%Q->Size;
        return x;
    }
}
double Head(Queue* Q){
    if (isEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    }
    else return Q->Q[Q->head];
}
double Tail(Queue* Q){
    if (isEmpty(Q)){
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    }
    else return Q->Q[Q->tail-1];
}
