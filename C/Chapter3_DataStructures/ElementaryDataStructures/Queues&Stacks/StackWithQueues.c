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
double Top(Stack* S){
    return Tail(&(S->Q1));
}
double Pop(Stack* S){
    double x;
    while(!isEmpty(&(S->Q1))){
        x = Dequeue(&(S->Q1));
        if(!isEmpty(&(S->Q1))) Enqueue(&(S->Q2), x);
    }
    Queue temp = S->Q1;
    S->Q1 = S->Q2;
    S->Q2 = temp;
    return x;
}

int main() {
    double* arr1 = (double *)calloc(6, sizeof(double));
    double* arr2 = (double *)calloc(6, sizeof(double));
    Stack S = InitializeStack(6, arr1, arr2);

    Push(&S, 4);
    Push(&S, 1);
    printf("%lf\n", Top(&S));
    Push(&S, 3);
    printf("%lf\n", Top(&S));
    printf("%lf\n", Pop(&S));
    printf("%lf\n", Top(&S));
    Push(&S, 8);
    printf("%lf\n", Top(&S));
    printf("%lf\n", Pop(&S));
    printf("%lf\n", Top(&S));
}
