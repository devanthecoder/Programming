#include <stdio.h>
#include "SinglyLinkedList.c"
typedef struct{
    Node* Head;
    Node* Tail;
    int MaxSize;
    int CurrSize;
}Queue;
Queue InitializeQueue(int Size){
    Queue Q;
    Q.Head = NULL, Q.Tail = NULL;
    Q.MaxSize = Size;
    Q.CurrSize = 0;
    return Q;
}
int isEmpty(Queue Q){
    if(Q.Head==NULL && Q.Tail==NULL)return 1;
    else return 0;
}
void Enqueue(Queue* Q, double x){
    if(Q->CurrSize==Q->MaxSize){
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    Q->CurrSize++;
    Node* node = CreateNode(x);
    if(Q->Head == NULL){
        Prepend(node, &(Q->Head));
        Q->Tail = Q->Head;
    }
    else {
        Insert(node, Q->Tail);
        Q->Tail = Q->Tail->next;
    }
}
double Dequeue(Queue* Q){
    if(isEmpty(*Q)){
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    double x = Q->Head->key;
    Delete(&(Q->Head), Q->Head);
    return x;
}
double Head(Queue Q){
    return Q.Head->key;
}
double Tail(Queue Q){
    return Q.Tail->key;
}
int main(){
    // double* arr1 = (double *)calloc(6, sizeof(double)), *arr2 = (double *)calloc(6, sizeof(double));
    Queue Q = InitializeQueue(6);
    Enqueue(&Q, 1);
    Enqueue(&Q, 4);
    Enqueue(&Q, 3);
    printf("%lf\n", Head(Q));
    printf("%lf\n", Dequeue(&Q));
    printf("%lf\n", Tail(Q));
    Enqueue(&Q, 8);
    printf("%lf\n", Tail(Q));
}