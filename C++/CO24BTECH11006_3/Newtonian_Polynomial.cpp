#include <iostream>
#include <cmath>
using namespace std;
double forward_delf(int k, int index, double* funcarr) {
    double** DELF = new double*[k+1];
    for(int i=0;i<=k;i++) DELF[i] = new double[k+1];
    for(int i=0;i<=k;i++) DELF[i][0] = funcarr[index+i];
    for(int j=1;j<=k;j++){
        for(int i=0;i<=k-j;i++){
            DELF[i][j] = DELF[i+1][j-1]-DELF[i][j-1];
        }
    }
    double result = DELF[0][k];
    for(int i=0;i<=k;i++) delete[] DELF[i];
    delete[] DELF;
    return result;
}
int return_index(double x, int k, int n, double* arr){
    int i = 0;
    while(*(arr+i)<x) i++;
    i -= 1;
    while((n-i)<k) i--;
    return i;
}
double Newtonian_Polynomial_equispaced_value(int n, double* arr, int k, double *funcarr, double x){
    double h = arr[1]-arr[0];
    int index = return_index(x, k+1, n, arr);
    double r = (x-arr[index])/h;
    double Pk = 0;
    for(int i=0;i<=k;i++){
        double r_factor = forward_delf(i, index, funcarr);
        double term = 1;
        for(int j=0;j<i;j++) term *= (r-j)/(j+1);
        Pk += r_factor*term;
    }
    return Pk;
}
int main(){
    int n;
    cout << "Enter the number of input values: ";
    cin >> n;
    double *arr = new double[n];
    double *funcarr = new double[n];
    for(int i=0;i<n;i++){
        cout << "Enter input value "<< i+1 << ": ";
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cout << "Enter output value "<< i+1 << ": ";
        cin >> funcarr[i];
    }
    double x;
    cout << "Enter input value 'x' for which you want value of f(x): ";
    cin >> x;
    int k;
    cout << "Enter order of the Newtonian polynomial Pk(x) used to approximate value of f(x): ";
    cin >> k;
    double Pk = Newtonian_Polynomial_equispaced_value(n, arr, k, funcarr, x);
    cout << "Exact value of f(x) is : "<< expm1(0.8*x) << endl;
    cout << "Approx. value of f(x), i.e., value of kth order Newtonian polynomial Pk(x) is: "<< Pk << endl;
    cout << "Error in "<< k <<"th order polynomial is: "<< abs(expm1(0.8*x) - Pk) << endl;
}