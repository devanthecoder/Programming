#include <stdio.h>
#include <stdlib.h>
#include "CharStacks.c"
#include "Stacks.c"
int strlen(char* Str){
    int size=0;
    while(Str[size]!='\0')size++;
    return size;
}
int isOper(char c){
    return (c=='+'||c=='-'||c=='/'||c=='*');
}
int Preference(char c){
    if(c=='-'||c=='+')return 1;
    if(c=='/'||c=='*')return 2;
}
char* toPostfix(char* Exp){
    int ExpLen = strlen(Exp);
    char* PostExp = (char*)calloc(ExpLen+1, sizeof(char));
    char* Dummy = (char*)calloc(ExpLen, sizeof(char));
    CharStack S = InitializeCharStack(ExpLen, Dummy);
    int j=0, i=0;
    while(Exp[i]!='\0'){
        if(!isOper(Exp[i])){
            PostExp[j]=Exp[i];
            j++;
            i++;
        }
        else{
            if(isCharEmpty(&S) || (Preference(CharTop(&S))<Preference(Exp[i]))) {
                CharPush(&S, Exp[i]);
                i++;
            }
            else{
                while(!isCharEmpty(&S)){
                    PostExp[j] = CharPop(&S);
                    j++;
                }
            }
        }
    }
    while(!isCharEmpty(&S)){
        PostExp[j] = CharPop(&S);
        j++;
    }
    PostExp[j]='\0';
    return PostExp;
}
double Evaluate(char* Exp){
    int ExpLen = strlen(Exp);
    char* Postfix = toPostfix(Exp);
    double* Dummy = (double *)calloc(ExpLen, sizeof(double));
    Stack S = InitializeStack(ExpLen, Dummy);
    for(int i=0;i<ExpLen;i++){
        if(!isOper(Postfix[i])) Push(&S, Postfix[i]-'0');
        else{
            double x2 = Pop(&S);
            double x1 = Pop(&S);
            double res;
            switch(Postfix[i]){
                case '+':
                res = x1+x2;
                break;
                case '-':
                res = x1-x2;
                break;
                case '/':
                res = x1/x2;
                break;
                case '*':
                res = x1*x2;
                break;
            }
            Push(&S, res);
        }
    }
    return Top(&S);
}
int main(){
    char Exp[100];
    scanf("%s", Exp);
    printf("%s\n", toPostfix(Exp));
    printf("%.2lf", Evaluate(Exp));
}