#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.c"
typedef struct{
    Node* Head;
    int MaxSize;
    int CurrSize;
}Stack;
Stack InitializeStack(int Size){
    Stack S;
    S.MaxSize = Size;
    S.CurrSize = 0;
    S.Head = NULL;
    return S;
}
void Push(Stack* S, double x){
    if(S->CurrSize==S->MaxSize){
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else S->CurrSize++;
    Node* node = CreateNode(x);
    Prepend(node, &(S->Head));
}
double Top(Stack S){
    return S.Head->key;
}
int isEmpty(Stack S){
    if(S.Head == NULL)return 1;
    else return 0;
}
double Pop(Stack* S){
    if (isEmpty(*S)) {
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    S->CurrSize--;
    double x = (S->Head)->key;
    Delete(&(S->Head), (S->Head));
    return x;
}
int main() {
    Stack S = InitializeStack(6);
    Push(&S, 4);
    Push(&S, 1);
    printf("%lf\n", Top(S));
    Push(&S, 3);
    printf("%lf\n", Top(S));
    printf("%lf\n", Pop(&S));
    printf("%lf\n", Top(S));
    Push(&S, 8);
    printf("%lf\n", Top(S));
    printf("%lf\n", Pop(&S));
    printf("%lf\n", Top(S));
}