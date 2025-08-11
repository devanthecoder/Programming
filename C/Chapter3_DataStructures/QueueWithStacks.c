#include "Stacks.c"
typedef struct{
    Stack S1;
    Stack S2;
}Queue;
Queue InitalizeQueue(int Size, double* Q1, double* Q2){
    Queue QQ = {InitializeStack(Size, Q1), InitializeStack(Size, Q2)};
    return QQ;
}
int IsEmpty(Queue Q){
    if(Q.S1.top==-1&&Q.S2.top==-1) return 1;
    else return 0;
}
void Enqueue(Queue* Q, double x){
    while(!isEmpty(&(Q->S1))){
        double y = Pop(&(Q->S1));
        Push(&(Q->S2), y);
    }
    Push(&(Q->S1), x);
    while(!isEmpty(&(Q->S2))){
        double y = Pop(&(Q->S2));
        Push(&(Q->S1), y);
    }
}
double Dequeue(Queue* Q){
    return Pop(&(Q->S1));
}
double Head(Queue Q){
    return Top(&(Q.S1));
}
double Tail(Queue Q){
    double y;
    while(!isEmpty(&(Q.S1))){
        y = Pop(&(Q.S1));
        Push(&(Q.S2), y);
    }
    while(!isEmpty(&(Q.S2))){
        double z = Pop(&(Q.S2));
        Push(&(Q.S1), z);
    }
    return y;
}
int main(){
    double* arr1 = (double *)calloc(6, sizeof(double)), *arr2 = (double *)calloc(6, sizeof(double));
    Queue Q = InitalizeQueue(6, arr1, arr2);
    Enqueue(&Q, 1);
    Enqueue(&Q, 4);
    Enqueue(&Q, 3);
    printf("%lf\n", Head(Q));
    printf("%lf\n", Dequeue(&Q));
    printf("%lf\n", Head(Q));
    // Enqueue(&Q, 8);
    // printf("%lf\n", Dequeue(&Q));
}