#include <iostream>
#include <cmath>
using namespace std;
class Complex{
    public:
    double Real;
    double Imaginary;
    Complex(double Real, double Imaginary){
        this -> Imaginary = Imaginary;
        this -> Real = Real;
    }
    double Modulus(){
        return sqrt(this->Real*this->Real + this->Imaginary*this->Imaginary);
    }
    void Add(Complex CompNum){
        this -> Real += CompNum.Real;
        this -> Imaginary += CompNum.Imaginary;
    }
    void Subtract(Complex CompNum){
        this -> Real -= CompNum.Real;
        this -> Imaginary -= CompNum.Imaginary;
    }
    void Multiply(Complex CompNum){
        Complex Product = {this->Real*CompNum.Real - this->Imaginary*CompNum.Imaginary, this->Real*CompNum.Imaginary + this->Imaginary*CompNum.Real};
        this->Real = Product.Real;
        this->Imaginary = Product.Imaginary;
    }
    void Divide(Complex CompNum){
        double mod = CompNum.Modulus();
        this->Real /= mod;
        this->Imaginary /= mod;
        Multiply({CompNum.Real, -CompNum.Imaginary});
    }
    void PrintComp(){
        cout << this->Real << " + i" << this->Imaginary;
    }
};
int main(){
    Complex Z1(1, 1);
    Complex Z2(1, -1);
    cout << Z1.Modulus() << endl;
    Z1.Multiply(Z2);
    Z1.PrintComp();
}