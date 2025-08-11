#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int Size;
    int top;
    char* S;
} Stack;

Stack InitializeStack(int Size, char* S) {
    Stack SS;
    SS.top = -1;
    SS.Size = Size;
    SS.S = S;
    return SS;
}

void Push(Stack* S, char x) {
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

char Pop(Stack* S) {
    if (isEmpty(S)) {
        fprintf(stderr, "UNDERFLOW\n");
        exit(EXIT_FAILURE);
    } else {
        S->top -= 1;
        return S->S[S->top + 1];
    }
}

char Top(Stack* S) {
    if (isEmpty(S)) {
        fprintf(stderr, "RUNTIME ERROR\n");
        exit(EXIT_FAILURE);
    } else {
        return S->S[S->top];
    }
}
int strlen(char* Str){
    int i;
    for(i=1;Str[i-1]!='\0';i++);
    return i;
}
int ParenthesisMatch(char* Exp){
    int ExpLen = strlen(Exp);
    char* Dummy = (char*) calloc(ExpLen, sizeof(char));
    Stack S = InitializeStack(ExpLen, Dummy);
    for(int i=0;i<ExpLen;i++){
        if(Exp[i]=='(') Push(&S, '(');
        else if(Exp[i]==')') {
            if(isEmpty(&S)) return 0;
            else Pop(&S);
        }
    }
    return isEmpty(&S);
}
int main(){
    char* Exp;
    fgets(Exp, 100, stdin);
    printf("%d", ParenthesisMatch(Exp));
}