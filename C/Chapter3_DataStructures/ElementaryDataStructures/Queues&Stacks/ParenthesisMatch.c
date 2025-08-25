#include <stdio.h>
#include <stdlib.h>
#include "CharStacks.c"
int strlen(char* Str){
    int i;
    for(i=1;Str[i-1]!='\0';i++);
    return i;
}
int ParenthesisMatch(char* Exp){
    int ExpLen = strlen(Exp);
    char* Dummy = (char*) calloc(ExpLen, sizeof(char));
    CharStack S = InitializeCharStack(ExpLen, Dummy);
    for(int i=0;i<ExpLen;i++){
        if(Exp[i]=='(') CharPush(&S, '(');
        else if(Exp[i]==')') {
            if(isEmpty(&S)) return 0;
            else CharPop(&S);
        }
    }
    return isCharEmpty(&S);
}
int main(){
    char Exp[100];
    fgets(Exp, 100, stdin);
    printf("%d", ParenthesisMatch(Exp));
}