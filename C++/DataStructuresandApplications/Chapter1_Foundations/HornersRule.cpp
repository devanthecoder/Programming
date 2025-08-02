#include <iostream>
using namespace std;
double P_h(int n, double* arr, double x){
    double p=0;
    for(int i=n-1;i>=0;i--){
        p = arr[i] + x*p;
    }
    return p;
}
int main(){
    int n;
    cout << "Enter the degree of your polynomial, P(x): ";
    cin >> n;
    string order;
    switch(n%10){
        case 1:
        order = to_string(n) + "st";
        break;
        case 2:
        order = to_string(n) + "nd";
        break;
        case 3:
        order = to_string(n) + "rd";
        break;
        default:
        order = to_string(n) + "th";
    }
    double *arr = new double[n+1];
    string polynomial = "";
    for(int i=0;i<=n;i++){
        cout << "Enter the coefficient of x^" << i << " in your " + order + " degree polynomial: ";
        cin >> arr[i];
        polynomial = (i!=n?(arr[i]<0?" - ":" + "):"") + (arr[i]==1?"":to_string(arr[i]<0?-arr[i]:arr[i])) + (!i?"":("x" + (i==1?"":("^" + to_string(i))))) + polynomial;
    }
    cout << "Your polynomial is: " << polynomial << endl;
    double x;
    cout << "Enter the value of x at which you want to evaluate the Polynomial, P(x): ";
    cin >> x;
    
    cout << "The value of P(x) at x = " << x << " is " << P_h(n+1, arr, x) << ".";
}