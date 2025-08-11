#include <iostream>
using namespace std;
class Queue{
    private:
    double* S;
    int head, tail;
    public:
    int Size;
    Queue(int Size){
        this -> Size = Size;
        this -> S = new double[this -> Size];
        this -> tail = 0;
        this -> head = 0;
    }
    ~Queue(){
        delete[] S;
        this -> tail = 0;
        this -> head = 0;
    }
    int isEmpty(){
        if(!this->head&&!this->tail)return 1;
        else return 0;
    }
    void Enqueue(double x){
        if(this->head==(this->tail+1)%this->Size){
            cerr << "OVERFLOW" << endl;
        }
        else this->S[this -> tail] = x;
        this->tail=(this->tail+1)%this->Size;
    }
    double Dequeue(){
        if (this->isEmpty()){
            cerr << "UNDERFLOW" << endl;
        }
        else {
            double x = this->S[this->head];
            this->head=(this->head+1)%this->Size;
            return x;
        }
    }
    double Head(){
        if (this->isEmpty()){
            cerr << "RUNTIME ERROR" << endl;
        }
        else return this->S[this->head];
    }
    double Tail(){
        if (this->isEmpty()){
            cerr << "RUNTIME ERROR" << endl;
        }
        else return this->S[this->tail-1];
    }
};
int main(){
    Queue Q(6);
    Q.Enqueue(4);
    Q.Enqueue(1);
    Q.Enqueue(3);
    cout << Q.Dequeue()<<endl;
    Q.Enqueue(8);
    cout << Q.Dequeue()<<endl;
}