#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int Size;
    int top;
    char* S;
} CharStack;

CharStack InitializeCharStack(int Size, char* S) {
    CharStack SS;
    SS.top = -1;
    SS.Size = Size;
    SS.S = S;
    return SS;
}

void CharPush(CharStack* S, char x) {
    if (S->top == S->Size - 1) {
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE); // Optional: to stop the program
    } else {
        S->top += 1;
        S->S[S->top] = x;
    }
}

int isCharEmpty(CharStack* S) {
    return S->top == -1;
}

char CharPop(CharStack* S) {
    if (isCharEmpty(S)) {
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    } else {
        S->top -= 1;
        return S->S[S->top + 1];
    }
}

char CharTop(CharStack* S) {
    if (isCharEmpty(S)) {
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    } else {
        return S->S[S->top];
    }
}