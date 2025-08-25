#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Size;
    int top;
    double* S;
} Stack;

Stack InitializeStack(int Size, double* S) {
    Stack SS;
    SS.top = -1;
    SS.Size = Size;
    SS.S = S;
    return SS;
}

void Push(Stack* S, double x) {
    if (S->top == S->Size - 1) {
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE); // Optional: to stop the program
    } else {
        S->top += 1;
        S->S[S->top] = x;
    }
}

int isEmpty(Stack* S) {
    return S->top == -1;
}

double Pop(Stack* S) {
    if (isEmpty(S)) {
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    } else {
        S->top -= 1;
        return S->S[S->top + 1];
    }
}

double Top(Stack* S) {
    if (isEmpty(S)) {
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    } else {
        return S->S[S->top];
    }
}
