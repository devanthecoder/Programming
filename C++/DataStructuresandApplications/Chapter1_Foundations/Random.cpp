#include <bits/stdc++.h>
using namespace std; 
int RANDOM(int a, int b){
    return a>b?-1:(a+(rand()%(b-a+1)));
}
void RANDOMPERMUT(int n, double* arr){
    for(int i=0;i<n;i++){
        int random = RANDOM(i, n-1);
        double temp = arr[i];
        arr[i] = arr[random];
        arr[random]=temp;
    }
}
int main(){
    srand(time(0));
    int n;
    cin >> n;
    double* arr = new double[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    RANDOMPERMUT(n, arr);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}