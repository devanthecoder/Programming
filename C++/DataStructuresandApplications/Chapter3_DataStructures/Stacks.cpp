#include <iostream>
using namespace std;
class Stack{
    private:
    double* S;
    int top;
    public:
    int Size;
    Stack(int Size){
        this -> Size = Size;
        this -> S = new double[this -> Size];
        this -> top = -1;
    }
    ~Stack(){
        delete[] S;
        this -> top = -1;
    }
    int isEmpty(){
        if(this->top==-1)return 1;
        else return 0;
    }
    void Push(double x){
        if(this->top==this->Size-1){
            cerr << "OVERFLOW" << endl;
        }
        else this -> top += 1;
        this->S[this->top] = x;
    }
    double Pop(){
        if (this->isEmpty()){
            cerr << "UNDERFLOW" << endl;
        }
        else this->top -= 1;
        return this->S[this->top+1];
    }
    double Top(){
        if (this->isEmpty()){
            cerr << "RUNTIME ERROR" << endl;
        }
        else return this->S[this->top];
    }
};
class Queue{
    private:
    double* Q;
    int head, tail;
    public:
    int Size;
};
int main(){
    Stack S(6);
    S.Push(4);
    cout << S.Top() << endl;
    S.Push(1);
    cout << S.Top() << endl;
    S.Push(3);
    cout << S.Top() << endl;
    cout << S.Pop() << endl;
    cout << S.Top() << endl;
    S.Push(8);
    cout << S.Top() << endl;
    cout << S.Pop() << endl;
    cout << S.Top() << endl;
    S.~Stack();
}