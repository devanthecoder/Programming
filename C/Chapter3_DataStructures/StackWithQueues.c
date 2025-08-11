#include <stdio.h>
#include "Queues.c"
typedef struct{
    Queue Q1;
    Queue Q2;
}Stack;
Stack InitializeStack(int Size, double* S1, double* S2){
    Stack S = {InitializeQueue(Size, S1), InitializeQueue(Size, S2)};
    return S;
}
void Push(Stack* S, double x){
    Enqueue(&(S->Q1), x);
}
double Pop(Stack* S){
    while(!isEmpty(&(S->Q1))){
        double x = Dequeue(&(S->Q1));
        Enqueue(&(S->Q2), x);
    }
    double x = Dequeue(&(S->Q2));
    while(!isEmpty(&(S->Q2))){
        double y = Dequeue(&(S->Q2));
        Enqueue(&(S->Q1), y);
    }
    return x;
}
double Top(Stack* S){
    return Tail(&(S->Q1));
}

int main() {
    double* arr1 = (double *)calloc(6, sizeof(double));
    double* arr2 = (double *)calloc(6, sizeof(double));
    Stack S = InitializeStack(6, arr1, arr2);

    Push(&S, 4);
    Push(&S, 1);
    Push(&S, 3);
    printf("%lf\n", Pop(&S));
    Push(&S, 8);
    printf("%lf\n", Pop(&S));
}
